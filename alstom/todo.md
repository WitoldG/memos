Proxy story
-> V regarder pour wsdp si y a un proxy, dans ce cas le mettre à 3131 -> deja fait
-> V push les modifs de word
-> V 6.1.10.4.3.2 à compléter dans le AD
-> V finir le merge

-> V modif content dans swRS, demande à AC si JH peut modif à la volée syID

Trace status story
-> V compléter les ITD avec 2 tests CFM/CT (s'inspirer du 15)


Story tests 90285
-> ajouter des tests sur pour la table SelectedTrace dont la gesiton est modifiée dans les commits
    https://alm.alstom.com/git/OMS/soft/oms/-/merge_requests/907/diffs?commit_id=9b1fff5ad162daeab5dc46d48fb8253f633cfcfc
    https://alm.alstom.com/git/OMS/soft/oms/-/merge_requests/907/diffs?commit_id=ed78faf956695f91a3d05ea9f304f0de45e4353e
  -> pour ça ajouter un test similaire à test/components/swint_storage/Automatisation/TS_Swint_Storage_26 (qui lui est sur la table DeviceAppearanceDate)
-> faire aussi les ITD

Story status traces
-> merge




Syslog : concentre tous les logs et a un système de règles pour les répartir
1ere partie dans OMS logger.hpp::~120 une categorie pour log cyber
2 eme partie logger/src_c/logger.h:~70 nouvelle categoeir

peut déjà commecer à implémenter leslogs cyber demandés
ils doivent être générés au démarrage de mgr
pourcela il doit avoir les information, il va falloir les ajouter dans les fichiers target de config -> /etc/oms/mgr_config.json
  pour cela il faut aller dans dyco et ajoter la génération de ces deux noeuds
  software version : oms_private/oms_version et config -> oms_user/verison ipk
quand mgr démarrera il faudra qu'il log ces infos

thirdparty/?/syslog-ng.conf
