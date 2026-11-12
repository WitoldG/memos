// Create a task
xTaskCreate(vTask1,         /* Pointer to the function that implements the task. */
            "Task 1",       /* Text name for the task.  This is to facilitate debugging only. */
            1000,           /* Stack depth - number of words to allocate for use as the task's stack */
            pvParameters,   /* Pointer to parameters, else null. */
            1,              /* Priority of the task. The higher the priority the most important the task */
            xTaskHandle);  /* Task handle (type TaskHandle_t). Allow to adress the task and perform given actions */


// Task function
void vTask1( void *pvParameters )
{
const char *pcTaskName = "Task 1 is running\r\n";
volatile uint32_t ul;

/* Need to be set if vTaskDelayUntil is used, then this variable will be
automatically handled */
TickType_t xLastWakeTime = xTaskGetTickCount();

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		vPrintString( pcTaskName );
        /* Other print function */
        vPrintStringAndNumber("string", 5);

        /* Delay task while allowing the others to work. Takes tick as argument,
        use macro pdMS_TO_TICKS() to convert ms into ticks.
        The task will be awaken 250ms after this line execution, this is a relative time */
		vTaskDelay( xDelay250ms );
        /* Also delays but computes an asolute time on which it will be awakaned
        Need to give last wakeup time and delay for it to add them */
		vTaskDelayUntil( &xLastWakeTime, xDelay250ms );
        /* Without delay, task will just run over and over */

    	/* Query the priority at which this task is running - passing in NULL means
    	"return our own priority". */
    	UBaseType_t uxPriority;
        uxPriority = uxTaskPriorityGet( NULL );

        /* Setting a task priority */
        vTaskPrioritySet( xTaskHandle, ( uxPriority + 1 ) );    // A given task
		vTaskPrioritySet( NULL, ( uxPriority - 2 ) );           // Its own priority

        /* Delete a task */
    	vTaskDelete( xTaskHandle );

	}
}

/* Start the scheduler to start the tasks executing. */
vTaskStartScheduler();

/*************************************/
/*************** QUEUE ***************/
/*************************************/
#include "queue.h"
/* Declare the queue, accessible by all tasks */
QueueHandle_t xQueue;
/* Create the queue (to hold a maximum of 5 long values) */
xQueue = xQueueCreate( 5, sizeof( int32_t ) );
/* Send on the queue */
xStatus = xQueueSendToBack( xQueue, &lValueToSend, 0 );
    /* 1st: Queue to which data is being sent
     * 2nd: Address of the data to send
     * 3rd: Block time: the time (as ticks) the task should be kept in the 
	        Blocked state to wait for space to become available on the queue
       ret: pdTRUE if the item was successfully posted, otherwise errQUEUE_FULL */
/* Receive from the queue */
xStatus = xQueueReceive( xQueue, &lReceivedValue, xTicksToWait );
    /* 1st: Queue from which receive the data
     * 2nd: buffer into which the received data will be placed.
            can only be the address of a variable that has the required size to hold the received data
     * 3rd: Block time: the time (as ticks) the task should be kept in the 
	        Blocked state to wait for data to be available on the queue
       ret: pdTRUE if an item was successfully received from the queue, otherwise pdFALSE */
/* Get the number of messages waiting in the queue */
nbMessages = uxQueueMessagesWaiting( xQueue )

/* Queue set declaration */
static QueueSetHandle_t xQueueSet = NULL;
/* Queue set creation, arg: sum of length of queues added to set */
xQueueSet = xQueueCreateSet( length1 + length2 );
/* Add a queue to the set. Queue mus be empty */
xQueueAddToSet( xQueue, xQueueSet );
/* Get a queue that contains data
 * Receive must not be performed on a member of a queue set unless this function is called to get the handler*/
xQueueThatContainsData = ( QueueHandle_t ) xQueueSelectFromSet( xQueueSet, portMAX_DELAY );
    /* 1st: Queue set to query
     * 2nd: Block time: the time (as ticks) the task should be kept in the 
	        Blocked state to wait for data to be available in a queue
     * ret: handle of a queue if found, else NULL */


/********************************************/
/*************** INTERRUPTION ***************/
/********************************************/
/*Numbers 0 to 2 are used by the FreeRTOS Windows port itself, so 3
is the first number available to the application. */
#define mainINTERRUPT_NUMBER 3
/* Defintion of the interruption handler */
static uint32_t ulExampleInterruptHandler( void );
/* Install the handler for the software interrupt. Syntax dependent
 * on the FreeRTOS port being used. Should be placed in main before scheduler start? */
vPortSetInterruptHandler( mainINTERRUPT_NUMBER, ulExampleInterruptHandler );
/* Simulate interruption */
vPortGenerateSimulatedInterrupt( mainINTERRUPT_NUMBER );



/**************************************/
/*************** OTHERS ***************/
/**************************************/
/* QML object with property objectName: "my_name" can be referenced in C++ by */
QObject *rect = object->findChild<QObject*>("rect");
if (rect)
    rect->setProperty("color", "red");


/*
Dans l'archive:
- ce fichier
- le projet npc
code example freertos: https://www.freertos.org/Documentation/code/
pdf freertos: https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwi-6P-Y7_-BAxW0U6QEHaLpAFIQFnoECA8QAQ&url=https%3A%2F%2Ffreertos.org%2FDocumentation%2F161204_Mastering_the_FreeRTOS_Real_Time_Kernel-A_Hands-On_Tutorial_Guide.pdf&usg=AOvVaw00vCuotX-YshFXjovqhhuJ&opi=89978449
*/