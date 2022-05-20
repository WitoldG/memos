## Compilation
/home/dev/oms/build/ -> ninja ipks
windows compil pour outils débarqués
/home/dev/oms/build_windows/ -> ninja

## Application des modifs
Connection filezilla 10.25.65.231 root HL3H
Hard:
    /dev/oms/build/ipk/<modified_ipk> -> /recovery/netbox2/packages_addon
    on the netbox:
    touch /recovery/NOW
    reboot; exit
Soft:
    /dev/oms/build/ipk/<modified_ipk> -> /root/ipk/
    on the netbox: ipki
Lauch config files generation
    /dev/oms/build/ipk/oms_project_configuration_armv7ahf-neon.ipk -> /root/ipk
    on the netbox: ipki
    reboot; exit

## Modifs ClearCase
check out the document
modify username
add line on history
make modifs
check in document
Teams > Relectures doc: copy new rev in Files
Create new conversation

## Tests launch
https://wiki-vbn.alstom.hub/xwiki/wiki/wikipes/view/wikiPES/OMS_testing/#HRuntests
PYMODAL=Y TARGET=231 SUBTEST=016 ninja tr_terra
 -> on netbox 231, lauch the test 016 of terra

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
