**Lancement :**

- se mettre en root `sudo su`
- pour lancer le daemon, faire la commande `/usr/sbin/snmpd -V -Lod -u Debian-snmp -g Debian-snmp -I -smux,mteTrigger,mteTriggerConf -f -p /run/snmpd.pid`

**A faire pour config**

- ajouter le truc au cmakelist
- Modifier le init pour qu'il instancie le proxy
- Ajouter cette init dans le dtrmib
- enlever le corps de chacune fonction et le remplacer par ce dont j'ai l'habitude

PS1="\[\\e\[0;31m\]\[\\D{%H:%M:%S}\]\[\\e\[m\]·\[\\e\[0;32m\]!\[\\e\[m\]·\[\\e\[0;34m\]witold:\\W\[\\e\[m\]· "