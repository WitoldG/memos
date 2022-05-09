## Bus commands

AUTO -> 0 NO -> 0

date&hour
`busctl call --user com.neyrpic.tru_v1.processing /com/neyrpic/tru_v1/processing com.neyrpic.tru_v1.processing parameters_set ss "timesetting.hour_date" "04/01/2022 16:56:00"`

timesetting_mode
`busctl call --user com.neyrpic.tru_v1.processing /com/neyrpic/tru_v1/processing com.neyrpic.tru_v1.processing parameters_set ss "timesetting.mode" "0"`

ip\_server\_ntp
`busctl call --user com.neyrpic.tru_v1.processing /com/neyrpic/tru_v1/processing com.neyrpic.tru_v1.processing parameters_set ss "timesetting.ip_server_ntp" "42.0.0.42"`

auto_aquit to yes
`busctl call --user com.neyrpic.tru_v1.processing /com/neyrpic/tru_v1/processing com.neyrpic.tru_v1.processing parameters_set ss "general.auto_aquit" "1"`

monitor the hardware
`busctl monitor --user com.neyrpic.tru_v1.hardware`

monitor the processing but only the parameters updates
`busctl monitor --user --match="member='parameters_value_updated'"`

alias buzstop ="busctl call --user com.neyrpic.tru\_v1.processing /com/neyrpic/tru\_v1/processing com.neyrpic.tru\_v1.processing parameters\_set ss \\"general.auto\_aquit\\" \\"1\\"; busctl call --user com.neyrpic.tru\_v1.processing /com/neyrpic/tru\_v1/processing com.neyrpic.tru\_v1.processing parameters_set ss \\"general.duration\\" \\"0\\""

`busctl call --user com.neyrpic.tru_v1.processing /com/neyrpic/tru_v1/processing com.neyrpic.tru_v1.processing parameters_get_simple s ""`