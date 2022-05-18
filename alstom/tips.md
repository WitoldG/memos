## Compilation
/home/dev/oms/build/ -> ninja ipks
windows compil pour outils débarqués

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

## Netbox
Ssh connection: ssh 231
web connection: https://10.25.65.231/
# Netbox bug
sv restart oms_restapi
sv restart oms_mgr


## Conventions
branch: wgu/ticket_nb/title
formatting script: /tools/lazybox/clangformat.sh

## Log Debug
Netbox > /etc/sv/oms_mgr/run
near end > machin.elf > add "-v DEBUG" at the end of the line 
