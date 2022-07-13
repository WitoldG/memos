## Compilation
/home/dev/oms/build/ -> ninja ipks
windows compil pour outils débarqués
/home/dev/oms/build_windows/ -> ninja

## Application des modifs
Connection filezilla 10.25.65.231 root HL3H
Hard:
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
