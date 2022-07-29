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

## Windows tests
Installation instructions: wiki/Testing environment/pytest_modal 3.0.0
Launching:
    Enter into virtual test environment: C:\Users\e_wguill\.virtualenvs\pymodal\Scripts\activate
    Go to C:\Users\e_wguill\Documents\dev\oms\test\components\swint_project_conf_gen\Automatisation
    Launch `pytest --color=yes -v --run=tr --xml-output=modal TS_SwInt_ConfChecker_xxx.py`

## Netbox
Ssh connection: ssh 231
web connection: https://10.25.65.231/

## Netbox bug
sv restart oms_restapi
sv restart oms_mgr

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

## Sql requests
Sur la box sqlite3 /usr/oms/var/lib/oms_uic_data.db "command"

## Gdb
Lancer un main avec gdb: ils sont dans /usr/oms/bin

## Simu CFM
submodules/simu/ground_server.py
    l.17 -> uncomment & 4334
    launch

## Livraison
- Launch alchemist with windows searchbar: it's called configuration workbench
- Create a RTC task called "Delivery x.x.x"
- Prendre le token de merge
- Execute the 2.6 part of SwPM
- In Teams/FR_SW_OMS/Livraisons, create folder LIV_OMS_Vx.x.x_ALPHAx, copy into the folder oms_delivery
- if webportal version has changed, create folder nbx_web_portal next to oms_delivery and copy into
  liv/build/ipk/nbx_web_portal_armv7ahf-neon.ipk
- Message Teams du type
    [4.4.0 ALPHA5] Binaires disponibles
    Hello FR_SW_OMS, les binaires sont disponibles dans test LIV_OMS_V4.4.0_ALPHA5 !
- Wait for confidence tests to be completed
- Execute the 2.7 part of SwPM
    2.7.2.3 -> Downlaod TR and TS = go on the CI master pipeline and click Download button in front of Report
            -> Run the script: give previous zip file as an argument, must be admin for auto cc checks in
            -> Create a new label: go on TypesExplorer Program, select etrainc for VOB, click list in upper bar then
               labels, right click in the void and create for a new label and keep second dialog window open
- Mettre le PM en relecture, rendre le token
- In <local_path>/oms/scripts, execute archive_for_delivery.sh
- Copy <local_path>/oms/out/oms_delivery.tar.gz in Teams, REF_SOL Teams, Sw_OMS, Files, Livraison

## Utiliser le DMI
Simulator of the interface in the train
See wiki OMS_testing/DMI_SDK
cd C:\Users\e_wguill\AppData\Roaming\Alstom\DMIWebInterfaceSDK
\WebClientWISDK.exe https://serveng:HL3HcfkG@10.25.65.231/


chpst -u oms_ground:oms:oms_core:oms_redis /usr/oms/bin/oms_terra.elf

## Lancer une endurance
Pour canaltrain endurance
Lancer le simu avec la conf de clearcase (40/endurance/config_files) -> à copier dans usbmodules/simu/
Modifier ground_server.py au même endroit (decommenter l.19 et mettre config.jsn en arg)
Lancer le simu depuis Win

Modifier scrit endurance (comment l.68)
Dans la vm, depuis build ../test/tools/launch_endurance.sh
-> il dit avec quels parametres le lancer

10213 oms_tra+  20   0  128488  52708  21916 S   4.0  5.5   0:33.30 WSDP_main
10214 oms_tra+  20   0   25912  23252   3612 S   0.0  2.4   0:00.03 oms_tcms2diag_s
10252 oms_tra+  20   0   21868  20860   1244 S   0.0  2.2   0:00.03 T2D_CLIENT_main
10250 oms_core  20   0   49148  18372  10656 S   1.7  1.9   0:27.02 MGR_main
10242 oms_core  20   0   37284  15728   8892 S   0.0  1.6   0:01.32 STORAGE_main
10209 oms_gro+  20   0  142976  14456  11584 S   0.0  1.5   0:00.72 TERRA_main
10599 root     -39   0   21232  13716  12416 S   1.0  1.4   0:10.18 CIPDP_main
10207 oms_res+  20   0   75576  10532   9488 S   0.0  1.1   0:00.29 oms_restapi.elf
0212 oms_tra+  20   0   24504   9864   8964 S   0.0  1.0   0:00.42 VDP_main

10213 oms_tra+  20   0  128488  52724  21916 S   5.0  5.5 126:38.52 WSDP_main
10214 oms_tra+  20   0   25912  23252   3612 S   0.0  2.4   0:00.03 oms_tcms2diag_s
10252 oms_tra+  20   0   21868  20860   1244 S   0.0  2.2   0:00.85 T2D_CLIENT_main
10250 oms_core  20   0   50304  19380  10656 S   1.7  2.0 109:42.95 MGR_main
10209 oms_gro+  20   0  145616  17268  11784 S   0.0  1.8   2:09.42 TERRA_main
10242 oms_core  20   0   37284  15728   8892 S   0.0  1.6   0:10.80 STORAGE_main
10599 root     -39   0   21232  13716  12416 S   0.7  1.4  42:45.19 CIPDP_main
10207 oms_res+  20   0   75576  10532   9488 S   0.0  1.1   1:05.76 oms_restapi.elf
10212 oms_tra+  20   0   24504   9864   8964 S   0.3  1.0   1:32.97 VDP_main
