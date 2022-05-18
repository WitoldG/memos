1
curl -v -T test/components/swint_dasdp/input/DAS_UIC_ok.json http://10.25.65.231/dasuic/wrong/uri/path
curl -v -X GET http://10.25.65.231/dasuic/2/DAS_UIC.json
2
curl -v -T test/components/swint_dasdp/input/DAS_UIC_syntax_error.json http://10.25.65.231/dasuic/2/DAS_UIC.json
3
curl -v -T test/components/swint_dasdp/input/DAS_UIC_wrong_interface.json http://10.25.65.231/dasuic/2/DAS_UIC.json
4
sv stop oms_redis
curl -v -T test/components/swint_dasdp/input/DAS_UIC_ok.json http://10.25.65.231/dasuic/2/DAS_UIC.json
5
sv start oms_redis
curl -v -T test/components/swint_dasdp/input/DAS_UIC_ok.json http://10.25.65.231/dasuic/2/DAS_UIC.json
redcli get "das_data_string"
6
curl -v -T test/components/swint_dasdp/input/DAS_UIC_ok2.json http://10.25.65.231/dasuic/2/DAS_UIC.json
redcli get "das_string"