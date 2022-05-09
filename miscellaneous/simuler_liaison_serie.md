**connecter le SP :**
- `socat -d -d pty,raw,echo=0 pty,raw,echo=0`
- mettre le peremier resultat dans les constantes
- sur le second `echo -e -n "FRQ11000.00\x0d\x0a" > /dev/pts/9`