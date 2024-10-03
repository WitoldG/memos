static void prefixed_log(const char* prefix, const char* format, va_list args, uint32_t ticksToWait,
                         bool sendToGUI)
{
    int prefix_len = strlen(prefix);
    int buf_len = vsnprintf(NULL, 0, format, args) + 1;
    char buffer[buf_len];
    vsnprintf(buffer, buf_len, format, args);

    if (strlen(buffer) > MAX_LOG_SIZE - (prefix_len + 2))
    {
        char modified_buffer[MAX_LOG_SIZE - (prefix_len + 1)];
        strncpy(modified_buffer, buffer, MAX_LOG_SIZE - (prefix_len + 2));
        modified_buffer[MAX_LOG_SIZE - (prefix_len + 2)] = '\0';
        structQueueLOGS.size = fc_snprintf((char *)structQueueLOGS.message,
                                           sizeof(structQueueLOGS.message),
                                           "%s%s\n", prefix, modified_buffer);
    }
    else
    {
        structQueueLOGS.size = fc_snprintf((char *)structQueueLOGS.message,
                                           sizeof(structQueueLOGS.message),
                                           "%s%s\n", prefix, buffer);
    }
    xQueueSend(xQueueLOGS, &structQueueLOGS, ticksToWait);

    if (sendToGUI)
    {
        for (size_t logId = 0; logId < MAX_NB_LOGS; logId++)
        {
            if (!GUI_LOG_TABLE.logs[logId][0]) // means if log is empty
            {
                fc_snprintf((char *)GUI_LOG_TABLE.logs[logId], MAX_LOG_SIZE,
                            (char *)structQueueLOGS.message);
                break;
            }
        }
    }
}

void log_info(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    prefixed_log("INFO: ", format, args, 0, false);
    va_end(args);
}

void pid_compute(pid_fc_t pid)
{
    log_debug("----- PID COMPUTE -------------------------------------");
    // Check if control is enabled
    if (!pid->automode)
        return ;

    float in = *(pid->input);
    float error = (*(pid->setpoint)) - in;
    // Compute integral
    log_debug("IN: %f, TARGET: %f, ERR: %f", in, *(pid->setpoint), error);
    float old_iterm = pid->iterm;
    pid->iterm += (pid->Ki * error);
    log_debug("OLD_IT: %f, NEW IT PART: %f, IT: %f", old_iterm, pid->Ki * error, pid->iterm);
    // Compute differential on input
    float dinput = in - pid->lastin;
    // Compute PID output
    float out = pid->Kp * error + pid->iterm - pid->Kd * dinput;
    // Apply transfer function on output
    float out_transfered = pid->transferFunctionPtr(out);
    // Apply limit to output value
    if (out_transfered > pid->omax)
        out_transfered = pid->omax;
    else if (out_transfered < pid->omin)
        out_transfered = pid->omin;
    // Output to pointed variable
    log_debug("OUT: %f, OUT AFTER TRANSFER: %f, IT HERE: %f", out, out_transfered, pid->iterm);
    (*pid->output) = out_transfered;
    // Keep track of some variables for next execution
    pid->lastin = in;
}
