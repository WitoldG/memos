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

## Modifs ClearCase
check out the document
modify username
Fichier > Information > Propriété > Propriétés avancées > Catégorie
add line on history
make modifs
check in document
Teams > Relectures doc: copy new rev in Files
Create new conversation

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

## Analyse core
-> When binary produces "Aborted (core dumped)"
- go into `/var/core` (in the netbox)
- take last core and `tar -xzf <core_file> core.gz`
- `gunzip core.gy`
- `gdb <binary_path> core`
(if gdb not installed, take it from Doc/tools to /recovery and `./pkg_install.sh <gdb_file>`)

## Capture reseau sur box
`tcpdump -i eth0 -w <file_name>`

## Test if flaky
python3 ./test/tools/analyze_ci_stability.py --filter --depth 40 --job bundle
depth to specify the nb analysed, job to specify which job to launch

## Windows tests
Installation instructions: wiki/Testing environment/pytest_modal 3.0.0
Launching:
    Enter into virtual test environment: C:\Users\e_wguill\.virtualenvs\pymodal\Scripts\activate
    Go to C:\Users\e_wguill\Documents\dev\oms\test\components\swint_project_conf_gen\Automatisation
    Launch `pytest --color=yes -v --run=tr --xml-output=modal TS_SwInt_ConfChecker_xxx.py`

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

## Process fin ticket
Distribute modifs into appropriated commits
git fecth dev
git rebase dev
./tools/lazybox/clang_format.sh
merge request

## Conventions
branch: wgu/ticket_nb/title
formatting script: /tools/lazybox/clangformat.sh

## Log Debug
Netbox > /etc/sv/oms_mgr/run
near end > machin.elf > add "-v DEBUG" at the end of the line

## Where to find specific files
targets -> /etc/oms/
logs -> /var/log/oms/current
SyID -> maintref/doc/refsol/04/010/Interfaces/
SyAD -> maintref/doc/refsol/04/020

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
- dans oms `git pull --recurse`
- pareil dans oms/achemist-artefact/
- Create a RTC task called "Delivery x.x.x"
- Prendre le token de merge
<!-- - mettre à jour les dépots de submodule pour pointer sur la version de leur master
  - depuis oms `git submodule`
  - regarder dans les graph de chaque submodule (surtout ceux qui ont été modif) que le dernier sha correspond à celui de l'étape précédente
  - si màj nécessaire (ex. sur simu)
    - go dans `submodules/simu`, `git pull --recurse`
    - revenir dans oms `git add -p`
    - verifier si c'est le bon commit maintenant (et pas de -dirty)
    - puis commit avec message "[submodules][simu] Update reference ( WI xxxxxx )" -->
- Launch alchemist with windows searchbar: it's called configuration workbench
- Ouvrir le SwPM, modifs champs version, n°ticket, delivery id
- Execute the 2.6 part of SwPM
- In Teams/FR_SW_OMS/Livraisons, create folder LIV_OMS_Vx.x.x_ALPHAx, copy into the folder oms_delivery (yes folder no its content)
- if webportal version has changed, create folder nbx_web_portal next to oms_delivery and copy into
  liv/build/ipk/nbx_web_portal_armv7ahf-neon.ipk
- Message Teams du type
    [5.1.0 ALPHA4] Binaires disponibles
    Hello FR_SW_OMS, les binaires sont disponibles dans test LIV_OMS_V5.1.0_ALPHA5 !
- Wait for confidence tests to be completed
- Execute the 2.7 part of SwPM
    2.7.3.3 -> Download TR and TS = go on the CI master pipeline (the one with 4 steps) and click Download button in front of Report
            -> Run the script: give previous zip file as an argument, must be admin for auto cc checks in
            -> To run scrpits use Powershell and .bat from windows (update the windows oms clone)
            -> If test scripts bugs, launch clearcase
            -> Create a new label: go on TypesExplorer Program, select etrainc for VOB, click list in upper bar then
               labels, right click in the void and create for a new label and keep second dialog window open
- Mettre le PM en relecture, rendre le token
- In <local_path>/oms/scripts, execute archive_for_delivery.sh
- Copy <local_path>/oms/out/oms_delivery.tar.gz in Teams, REF_SOL Teams, Sw_OMS, Files, Livraison

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
Vérifier de bien avoir une Remote Trace config et une Remote Dashboard definition déployées sur la box avec Traintracer
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
