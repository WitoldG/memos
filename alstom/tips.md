## Compilation
/home/dev/oms/build/ -> ninja ipks
windows compil pour outils débarqués
/home/dev/oms/build_windows/ -> ninja

## Application des modifs
Connection filezilla 10.25.65.231 root HL3H
Hard:       \\10.1.1.254\dev\
    /dev/oms/build/ipk/<modified_ipk> -> /recovery/netbox2/packages_addon
    on the netbox:
        touch /recovery/NOW <- pour tout reflash
        opkg install --force-reinstall /recovery/netbox2/packages_addon/my_ipk <- reinstall que mon ipk
    reboot; exit
Soft:
    /dev/oms/build/ipk/<modified_ipk> -> /root/ipk/
    on the netbox: ipki
Envoi binaire:
    ninja bin/oms_terra.elf && scp bin/oms_terra.elf 234:/usr/oms/bin/
Launch config files generation
    /dev/oms/build/ipk/oms_project_configuration_armv7ahf-neon.ipk -> /root/ipk
    on the netbox: ipki
    reboot; exit

## Tests launch
https://wiki-vbn.alstom.hub/xwiki/wiki/wikipes/view/wikiPES/OMS_testing/#HRuntests
PYMODAL=Y TARGET=231 SUBTEST=016 ninja tr_terra
 -> on netbox 231, lauch the test 016 of terra
OPT='-k test_Terra_006_01_01'
 -> launches only the test case test_Terra_006_01_01
### Pause / Debugging
`import pdb`
`pdb.set_trace()`

## Use embedded tester / testeur embarqué
- add a function in .cpp and .hpp
- do not forget to add function in map (top of .cpp file)
- compile needed tester `ninja storage_tester.elf`
- transfer tester in the box (it's in `build/bin_unstripped`)
- launch program `./storage_tester.elf <function> <output_file> <argv0> <argv1> ...`

## Capture reseau sur box
`tcpdump -i eth0 -w <file_name.pcap>`

## Test if flaky
python3 ./test/tools/analyze_ci_stability.py --filter --depth 40 --job bundle
depth to specify the nb analysed, job to specify which job to launch

## Windows tests
Installation instructions: wiki/Testing environment/pytest_modal 3.0.0
Launching:
Execute `bw` from Linux\
Enter into virtual test environment: `C:\Users\e_wguill\.virtualenvs\pymodal\Scripts\activate`\
    if it doesn't work, open Powershell as admin `set-executionpolicy unrestricted`\
Go to C:\Users\e_wguill\Documents\dev\oms\test\components\swint_project_conf_gen\Automatisation\
Launch `pytest --color=yes -v --run=tr --xml-output=modal TS_SwInt_ConfChecker_xxx.py`

``` bash
cd C:\Users\e_wguill\.virtualenvs\pymodal\Scripts\
.\activate
cd C:\Users\e_wguill\Documents\dev\oms\test\components\swint_configuration\Automatisation
pytest --color=yes -v --run=tr --xml-output=modal TS_SwInt_ConfChecker_001.py
```
Debug C++:

``` cpp
#include <iostream>
#include <fstream>
std::ofstream outfile;
this->outfile.open("C:\\Users\\e_wguill\\Documents\\tmp\\wgu_out_file.txt", std::ios::out);
this->outfile << "Log" << "\n";
```

## Tester project_conf_gen
project_conf_gen est l'outil débarqué qu'on fournit aux clients pour qu'ils puissent générer un ipk de conf à partir de leur oms_user.json
Pour faire le build : `./test/conf/automation/build.sh ~/oms/`
Aller dans oms/project_conf_gen/src/out, desarchiver le zip sous windows
Créer un dossier in/ à côté de private, y mettre le oms_user.json (et souvent un sous rep edr)
Lancer le bat oms_project_conf_gen -> génère l'ipk dans out

## Génération website
- `cd /home/dev/oms/web/frontend`
- `./build.sh`
- `./setup-v2.sh`
- l'ipk est dans `frontend/build/ipk`

## Netbox
Ssh connection: ssh 231
web connection: https://10.25.65.231/
Start all services `oms start`
Start a given service `sv start oms_storage`
Stop all services `oms stop`

## Log Debug
Netbox > /etc/sv/oms_mgr/run
near end > machin.elf > add "-v DEBUG" at the end of the line

## Database / Sql requests (persistent db)
Sur la box `sqlite3 /usr/oms/var/lib/oms_uic_data.db "command"`
Reset database:
- `rm /usr/oms/var/lib/oms_uic_data.db`
- `sv restart oms_storage`
## Redis database (transcient db)
`redcli scan 0 count 1000` -> show all collections
pres in `Z:\etrainc\doc\_OMS\06_Software\999_Others\Presentations\Technical\redis_in_oms_context.pptx`
remote_software_upload_definition|{"identifier":"first_definition_identifier","name":"first_name","version":"1","size_in_bytes":300000,"software_item_definitions":[{"identifier":"first_si_identifier","hash":"first_si_hash","name":"first_si","description":"first si description","date":"19-07-96","version":"1","type":"file","size_in_bytes":300000,"generated_id":"first_oms_identifier","reprog_delay_in_sec":30,"checksum":"first_si_checksum","url":"first_si_url"},{"identifier":"second_si_identifier","hash":"second_si_hash","name":"second_si","description":"second si description","date":"19-07-96","version":"1","type":"file","size_in_bytes":300000,"generated_id":"second_oms_identifier","reprog_delay_in_sec":30,"checksum":"second_si_checksum","url":"second_si_url"}]}

A TRAITEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEER
remote_software_upload_repository_status|1
remote_software_upload_definition_identifier|first_definition_identifier
remote_software_upload_definition|{\"identifier\":\"first_definition_identifier\",\"name\":\"first_name\",\"version\":\"1\",\"size_in_bytes\":300000,\"software_item_definitions\":[{\"identifier\":\"first_si_identifier\",\"hash\":\"first_si_hash\",\"name\":\"first_si\",\"description\":\"first si description\",\"date\":\"19-07-96\",\"version\":\"1\",\"type\":\"file\",\"size_in_bytes\":300000,\"generated_id\":\"first_oms_identifier\",\"reprog_delay_in_sec\":30,\"checksum\":\"first_si_checksum\",\"url\":\"first_si_url\"},{\"identifier\":\"second_si_identifier\",\"hash\":\"second_si_hash\",\"name\":\"second_si\",\"description\":\"second si description\",\"date\":\"19-07-96\",\"version\":\"1\",\"type\":\"file\",\"size_in_bytes\":300000,\"generated_id\":\"second_oms_identifier\",\"reprog_delay_in_sec\":30,\"checksum\":\"second_si_checksum\",\"url\":\"second_si_url\"}]}
remote_software_upload_repository_status|4

[root@netbox-000000000000145 /usr/web/oms]$ redcli hgetall remote_software_hash
1) "second_oms_identifier"
2) "{\"status\":\"synchronized\",\"path\":\"1ed7e345-89fa-5c85-900d-7a37ea2e7742/\"}"
3) "first_oms_identifier"
4) "{\"status\":\"synchronized\",\"path\":\"1ed7e345-89fa-5c85-900d-7a37ea2e7742/\"}"


sqlite3 /usr/oms/var/lib/oms_uic_data.db "UPDATE KeyValue SET Value = '{\"identifier\":\"first_definition_identifier\",\"name\":\"first_name\",\"version\":\"1\",\tions\":[{\"identifier\":\"first_si_identifier\",\"hash\":\"first_si_hash\",\"name\":\"first_si\",\"description\":\"first si description\",\"date\":\"19-07-96\",\"version\":\"1\",\"type\":\"file\first_oms_identifier\",\"reprog_delay_in_sec\":30,\"checksum\":\"first_si_checksum\",\"url\":\"first_si_url\"},{\"identifier\":\"second_si_identifier\",\"hash\":\"second_si_hash\",\"name\":\"secon\",\"date\":\"19-07-96\",\"version\":\"1\",\"type\":\"file\",\"size_in_bytes\":300000,\"generated_id\":\"second_oms_identifier\",\"reprog_delay_in_sec\":30,\"checksum\":\"second_si_checksum\",\"e_software_upload_definition'"
JUSQICIIIIIIIIIIIIIIIIIIII


## Gdb
Lancer un main avec gdb: ils sont dans /usr/oms/bin

## Simu CFM
submodules/simu/ground_server.py
    l.17 -> uncomment & 4334
    launch

## Netbox directories
`/var/log/oms/current` logs classiques
`/var/log/auth/current` logs auth
`/usr/oms/var` crl storage

## Livraison
- Execute the 2.7 part of SwPM
    2.7.3.3 -> Download TR and TS = go on the CI master pipeline (the one with 4 steps) and click Download button in front of Report
            -> Run the script: give previous zip file as an argument, must be admin for auto cc checks in
            -> To run scrpits use Powershell and .bat from windows (update the windows oms clone)
            -> If test scripts bugs, launch clearcase
            -> Create a new label: go on TypesExplorer Program, select etrainc for VOB, click list in upper bar then
               labels, right click in the void and create for a new label and keep second dialog window open
- Mettre le PM en relecture, rendre le token
<!-- - In <local_path>/oms/scripts, execute archive_for_delivery.sh
- Copy <local_path>/oms/out/oms_delivery.tar.gz in Teams, REF_SOL Teams, Sw_OMS, Files, Livraison -->

## Génération à l'identique
- Dl les binaires de livraison deouis Teams
- checkout master, supprimer son dossier build et tout recompiler
- faire la procédure de génération de project_conf_gen, prendre le `project_conf_gen.zip` et le mettre dans build 
- faire la procédure de génération du website, prendre l'ipk généré et le mettre dans build 
- copier `container/data/lxc/rootfs.tgz` dans build
- comparer build aux binaires téléchargés avec BeyondCompare

## Tests de confiance
### Flash de la box
prendre tous les ipk de la livraison et les mettre sur la box dans recovery/netbox2/packages_addon
générer l'ipk project_conf_gen avec le zip livré et le mettre au même endroit
reflash la box, puis tester ce qu'on a à tester
### En pratique
pour savoir quoi tester prendre la liste dans Teams et demander aux personnes concernées comment leur truc se teste
ne jamais utiliser les TI
Si par exemple je veux tester ce que OMS produit quand un serveur ground lui envoie x truc, je me bidouille un serveur ground à partir de celui dans simu (voir le README) et je lance OMS de l'autre côté
### Test end-to-end de CRL par exemple
On veut tester le fait que OMS récupère bien une CRL à intervalle régulier sur le serveur sol, donc
- configurer `/etc/hosts` sur la box en ajoutant la ligne `<ip_ordi> ground_simulator` (ip de la machine windows type 10.25.37.253) pour que la box puisse trouver le simulateur
- dans `/etc/oms/terra_config.json` modifier l'url de remote crl par `ground_simulator:4334` et supprimer le proxy
- dans `/etc/oms/mgr_config.json` modifier la monitoring period de la CRL pour la raccourcr et que le get de nouvelle CRL soit trigger bien plus souvent
- faire un fichier de config de simu semblable à ce qui y a dans les tests, qui répond de manière constante à `remote_crl_definition` par un fichier de défnition qui pointe sur le second end-point du fichier de config du simu `remote_crl_download`
- lancer sur la vm (depuis `submodules/simu/`) `python -m ground_server -p 4334 -c /home/dev/crl_config.json`
### Test end-to-end général
- configurer `/etc/hosts` sur la box en ajoutant la ligne `<ip_ordi> ground_simulator`
- dans `/etc/oms/terra_config.json` modifier l'url de ce dont on a besoin par `ground_simulator:4334` et supprimer le proxy
- lancer sur la vm (depuis `submodules/simu/`) `python -m ground_server -p 4334 ground_server/config.json`


## Setup le simulateur ground_server
En utilisant des certificats
- lancer le script install_ground_server.sh, avec le ca de `test/components/swint_end_to_end/input/config/certificates/CFM/ca.pem`
- lancer le ground server (depuis `submodules/simu/`) : `sudo python -m ground_server -p 443 -c ground_server/input/config.json`
    -> pour le port, soit 443, alors pas besoin de modif la config, mais lancement du ground_serveur en sudo et le port doit être forwardé sur la vm
                     soit 4334, alors pas besoin de toucher à la VM, mais faut ajouter le port dans les URL (config et SI)
    -> si besoin de debug, regarder les logs OMS et SQUID
/!\ Prendre le bon ca.pem !
/!\ On doit forcément utiliser les URL CFM 6.7.0 pour que ça fonctionne (dans le hosts et le terra_config.json)
    sed -i -e "s,http://com-traintracer-pprod,http://preprod-com-traintracer," /etc/oms/terra_config.json
    10.25.37.253 preprod-com-traintracer.alstom.hub

## Proxy pout test

## Soap UI
Au lancement pour obtenir les services d'OMS -> https://wiki-vbn.alstom.hub/xwiki/wiki/wikipes/view/Produits/OMS/OMS_testing/#HLoadworkspace

## Use the DMI
Simulator of the interface in the train
See wiki OMS_testing/DMI_SDK
cd C:\Users\e_wguill\AppData\Roaming\Alstom\DMIWebInterfaceSDK
.\Browser\WebClientWISDK.exe https://serveng:HL3HcfkG@10.25.65.231/
.\Browser\WebClientWISDK.exe https://prodadmin:n%26tS%40n8x@10.25.65.231/
.\Browser\WebClientWISDK.exe https://maintainer:n%26tR%40n8x@10.25.65.231/

## Simulator RestAPI
Lancer à la main :
runuser -u web_app -g web -- python3 /usr/web/simu_restapi/rest_server.py

chpst -u oms_ground:oms:oms_core:oms_redis /usr/oms/bin/oms_terra.elf

## Restapi simulator
In /home/dev/simu/
To modify what the server responds: simu/rest_api/src/server_config.json
To deploy a new simulator version: simu/rest_api/deploy_simu.sh 10.25.65.231
To start the simulator: simu/rest_api/start_simu.sh 10.25.65.231

## Deploy
223 -> ssh-keygen -f "/home/dev/.ssh/known_hosts" -R "10.25.65.231"

## Se connecter à un server Traintracer
F.e. le 5: `ssh root@10.25.65.245` mdp: root5
busctl get-property org.freedesktop.login1 /org/freedesktop/login1 org.freedesktop.login1.Manager ScheduledShutdown <!-- savoir quand shutdown is sheduled -->
/var/run/systemd/shutdown/scheduled <!-- fichier qui dit quand le shutdown est sheduled -->

## Se connecter en liaison série
telnet 10.26.65.200 4015

## Lancer une endurance
### Cfm endurance
aller sur la dernière version de dev, pull et compiler
Vérifier de bien avoir une Remote Trace config et une Remote Dashboard definition déployées sur la box avec Traintracer (id:e_wguill ou log direct sur Chrome)
Lancer launch_endurance.sh
Pour savoir si les catalogues sont bien appliqués :
    Aller dans les events sur la box, filtrer tous les AX (AX03 ceux d'OMS, AX021 ceux de Netbox)
    Regarder les détails des evts qui vont dire si les catalogues sont bien appliqués

### Analyse endurance
Lancer le script `test/tools/retrieve_endurance_logs.sh`
Dans l'archive générée regarder :
1. Dossier core -> si contient des fichiers les analyser
2. Regarde le fichier netbow/install.org, CTRL+F "errors"
3. Check le fichier VERSION que c'est bien le commmit attendu
4. Dans timemachine, dans chaque csv regarder les colonnes underfow et overflow, et regarder si pour chaque ligne avec un nom on a bien un certazin nombre d'events générés (colonne 0)
5. Aller sur train tracer
    - dans "Event/Event import data", regarder qu'il ya  bien eu des events réguliers tout le week-end
    - dans "Remote dashboard/Files/Files list" pareil
    - dans "Remote Traces/Display" pareil
6. Fichier current dans le dossier log
    Virer
    - tout ce qui y a les 1eres secondes/minutes
    - ../mgr/src/device/device_state/not_present.cpp: 0045 ;NotPresent	;[Device(UIC1)] ?
    - ../mgr/src/device/device_state/configuring.cpp: 0055 ;Configuring	;[Device(UIC1)] ?
    - ../mgr/src/device/device_state/operational.cpp: 0045 ;Operational	;[Device(UIC1)] ?
    - ../wsdp/src/services/WEB-EDL/1/service.cpp: 0084 ;request_new_conf	;[device: NPU-32]
    - ../time_machine/src/time_machine_api/time_machine.cpp: 0078 ;TimeMachineManager	;Time machine library loaded
    - ../dyco/src/atml2json/conversion_status.cpp: 0326 ;log_errors	;No errors in conversion
    - ../dyco/src/atml2json/conversion_status.cpp: 0342 ;log_warnings	;No warnings in conversion
    - ../terra/src/t2g/remote_traces_status_notification/ground_client.cpp: 0110 ;process_valid_transmission	;Transmission to ground successful.
    - ../wsdp/src/services/WEB-EVT/51/server/server.cpp: 0115 ;evtNotification	;IP address 172.16.16.1 sent an automatic notification. Returning an empty response to stop its notification.
    - ../wsdp/src/device/uic_device.cpp: 0193 ;is_remote_traces_supported	;Device UIC7 does not support remote traces, webservice WEB-TRC is missing, webservice WEB-EXTSYMB is missing
    - ../terra/src/t2g/ground_client_base.cpp: 0131 ;send_until_success	;Retry connection
    - ../terra/src/t2g/remote_traces_archive_notification/ground_client.cpp: 0146 ;process_valid_transmission	;Transmission to ground successful


Pour canaltrain endurance
Lancer le simu avec la conf de clearcase (40/endurance/config_files) -> à copier dans usbmodules/simu/
Modifier ground_server.py au même endroit (decommenter l.19 et mettre config.jsn en arg)
Lancer le simu depuis Win

Modifier scrit endurance (comment l.68)
Dans la vm, depuis build ../test/tools/launch_endurance.sh
-> il dit avec quels parametres le lancer

## Documentation
events -> \maintref\doc\RefSol\04_System\010_Specification\Interfaces\SyID_RefSol_UIC559_External_Interfaces.docx

## Fonctionnement MGR Terra
Par ex RSU
1. MGR envoie sur le bus un message qui trigger le callback terra/src/bus_handler.hpp:on_request_remote_software_upload_definition (dans le thread bus)
2. Dans terra/src/t2g/ground_client_base.cpp:add_pulse (thread main) on ajoute le pulse dans une queue pour qu'il soit consommé par le thread concerné
3. Dans terra/src/t2g/rsud/ground_client.cpp:handle_pulse (thread RSU) le pulse est récupéré
4. terra/src/t2g/ground_client_base.cpp:send_until_success est appelé
5. terra/src/t2g/ground_client_base.cpp:run_http_client est appelé (il utilise les fonctions de type create_http_header)
6. terra/src/t2g/ground_client_base.cpp:process_response est appelé
7. Cette fonction redistribue sur les fonctions dans ls différents t2g

## Simuler appel bus
`redcli PUBLISH message_type_name msg`
`redcli PSUBSCRIBE message_type_name`
ex: test si terra gère le reques de CRL
`redcli PUBLISH REMOTE_CRL_DEFINITION_C2P_CH '{"request_id": "0001"}'`
`redcli psubscribe REMOTE_CRL_DEFINITION_P2C_CH`

## Espionner le bus
`redcli PSUBSCRIBE "*"`
Mesasages initiate : provider pret pour rep à mgr
AUTHORIZATION_C2P_CH : mgr dit  à terra de balancer des notifs periodiques
REMOTE_LOG_DOWNLOAD_MANAGER_C2P_CH: mgr dit à Terra de recup uun rldm
REMOTE_LOG_DOWNLOAD_MANAGER_P2C_CH terra repond ce qu'il a recup
    si que req_id il a rien recup sinon il serait a cote

## SOAP UI configuration
- Configurer le device dont on veut se servir pour qu'ilpointe sur l'adr ip de notre pc
"{\"req_id\":\"873aeb3a-4435-4131-b15d-dd9e5cac1c7b\",\"device_name\":\"netbox\",\"selected_traces_ids\":[],\"next_request_timeout_s\":30}"
```xml
<soapenv:Envelope xmlns:soapenv="http://schemas.xmlsoap.org/soap/envelope/" xmlns:urn="urn:WEB-TRC" xmlns:urn1="urn:WEB-COMTRC">
   <soapenv:Header/>
   <soapenv:Body>
      <urn:GetTracerConfigurationResponse>
         <urn:Configuration>
            <!--Zero or more repetitions:-->
            <urn1:TraceSummary>
               <urn1:TraceId>1</urn1:TraceId>
               <urn1:TraceName>name</urn1:TraceName>
               <urn1:TraceType>DASHBOARD</urn1:TraceType>
               <urn1:DefinitionType>CUSTOM</urn1:DefinitionType>
               <urn1:DelayedTrace>false</urn1:DelayedTrace>
               <!--1 or more repetitions:-->
               <urn1:Pn Pi="0" Si=""/>
               <!--Optional:-->
               <urn1:FilmInfo TraceSize="10" NbFilm="8" OldestFilm="3"/>
               <urn1:TraceState>DISABLED</urn1:TraceState>
            </urn1:TraceSummary>
            <!--Zero or more repetitions:-->
            <urn1:SoftSummary Pi="0" Si=""/>
            <urn1:TotalUsedSize>4096</urn1:TotalUsedSize>
            <urn1:TotalSize>8192</urn1:TotalSize>
         </urn:Configuration>
      </urn:GetTracerConfigurationResponse>
   </soapenv:Body>
</soapenv:Envelope>
```


## Simu CIP not working
Go on train tracer server `ssh 245` mdp:root5
`/root/bridgeUp.sh`simu
`sh /usr/fleetsimulator/simu/tcms2diag_server/vv_oms/stop_t2d.sh ; sh /usr/fleetsimulator/pycip/vv_oms/stop_pycip.sh`
`sh /usr/fleetsimulator/simu/tcms2diag_server/vv_oms/start_t2d.sh &>/dev/null`
`sh /usr/fleetsimulator/pycip/vv_oms/run_all.sh &>/dev/null`
reboot la box

# Mdp
root        Hl3HcfkG
prodeng     Hl3HcfkG
prodadmin   n&tS@n8x
