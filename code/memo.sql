SELECT
  WHERE
    SELECT * FROM jeux_video WHERE possesseur='Patrick'
    SELECT * FROM jeux_video WHERE possesseur='Patrick' AND prix < 20
  ORDER BY
    SELECT * FROM jeux_video ORDER BY prix
    SELECT * FROM jeux_video ORDER BY prix DESC --decroissant
  LIMIT
    SELECT * FROM jeux_video LIMIT 0, 20 --nb premiere entree, nb entrees
    LIMIT 5, 10 --6eme a 15eme entree
  SELECT nom, possesseur, console, prix FROM jeux_video WHERE console='Xbox' OR console='PS2' ORDER BY prix DESC LIMIT 0,10
  Combination
    SELECT * FROM Notes, Eleves... Rassemble les 2
  Jointure cinditionelle
    SELECT * FROM Notes, Eleves WHERE Notes.prenom = Eleves.prenom AND Notes.nom = Eleves.nom;
  Imbriquées --Qui a eu moins que Dark Vador en BDD
    SELECT * FROM Notes WHERE cours = 'Bases de Données' AND note <= (SELECT note FROM Notes WHERE cours = 'Bases de Données' AND prenom = 'Dark' AND nom = 'VADOR');
  (NOT) IN
    SELECT nom FROM Eleves WHERE nom NOT IN (SELECT nom FROM Notes); --Les eleves qui n'ont pas de notes
  (NOT) EXISTS
    SELECT nom FROM Eleves e WHERE NOT EXISTS (SELECT * FROM Notes n WHERE e.nom = n.nom);
  UNION INTERSECT EXCEPT(MINUS en Oracle)
    SELECT prenom, nom FROM ??


INSERT INTO
  INSERT INTO jeux_video(ID, nom, possesseur, console, prix, nbre_joueurs_max, commentaires) VALUES('', 'Battlefield 1942', 'Patrick', 'PC', 45, 50, '2nde guerre mondiale')
  INSERT INTO jeux_video VALUES('', 'Battlefield 1942', 'Patrick', 'PC', 45, 50, '2nde guerre mondiale')

UPDATE
  UPDATE jeux_video SET prix = 10, nbre_joueurs_max = 32 WHERE ID = 51
  UPDATE jeux_video SET possesseur = 'Florent' WHERE possesseur = 'Michel'

DELETE
  DELETE FROM jeux_video WHERE nom='Battlefield 1942' --Si on oublie le where ça delete tout

--Create an alias
FROM Notes n;

-- Scalar functions
SELECT UPPER(nom) AS nom_maj FROM jeux_video
SELECT UPPER(nom) AS nom_maj, possesseur, console, prix FROM jeux_video
UPPER ->maj, LOWER ->min, LENGTH -> compte nb carac, ROUND(nb, 2)

-- Aggregate functions
SELECT AVG(prix) AS prix_moyen FROM jeux_video -- Sur le php besoin d'appeller fetch qu'une seule fois
AVG, SUM, MAX, MIN
COUNT: SELECT COUNT(*) AS nbjeux FROM jeux_video -- Donne nombre entrées
       SELECT COUNT(nbre_joueurs_max) AS nbjeux FROM jeux_video -- Omet ceux avec NULL pour nb max de joueurs
       SELECT COUNT(DISTINCT possesseur) AS nbpossesseurs FROM jeux_video

GROUP BY - HAVING
SELECT AVG(prix) AS prix_moyen, console FROM jeux_video GROUP BY console
SELECT AVG(prix) AS prix_moyen, console FROM jeux_video GROUP BY console HAVING prix_moyen <= 10 -- Fonctionne que sur agrégats, sinon where

-- Gestion dates
SELECT pseudo, message, date_post  FROM minichat WHERE date_post = '2010-04-02'
SELECT pseudo, message, date_post FROM minichat WHERE date_post BETWEEN '2010-04-02 00:00:00' AND '2010-04-18 00:00:00'
-- Get date
  NOW() -> AAAA-MM-JJ HH:MM:SS
  CURDATE() -> AAAA-MM-JJ
  CURTIME() -> HH:MM:SS
-- Operations on date
  DAY(), MONTH(), YEAR(), HOUR(), MINUTE(), SECONDE()
-- Adapter format date
  SELECT pseudo, message, DATE_FORMAT(date_post, '%d/%m/%Y %Hh%imin%ss') AS date_post FROM minichat
-- Operations on dates
  SELECT pseudo, message, DATE_ADD(date, INTERVAL 15 DAY) AS date_expiration FROM minichat

-- Jointures
  -- Jointures internes : données qui ont une correspondance entre les 2 tables
    -- WHERE syntax
      SELECT jeux_video.nom AS nom_jeu, proprietaires.prenom AS prenom_proprietaire FROM proprietaires, jeux_video WHERE jeux_video.ID_proprietaire = proprietaires.ID
      SELECT j.nom AS nom_jeu, p.prenom AS prenom_proprietaire FROM proprietaires AS p, jeux_video AS j WHERE j.ID_proprietaire = p.ID
      SELECT j.nom nom_jeu, p.prenom prenom_proprietaire FROM proprietaires p, jeux_video j WHERE j.ID_proprietaire = p.ID
    -- Join syntax (recommandée)
      SELECT j.nom nom_jeu, p.prenom prenom_proprietaire FROM proprietaires p INNER JOIN jeux_video j ON j.ID_proprietaire = p.ID
  -- Jointures externes : toutes les données
    SELECT j.nom nom_jeu, p.prenom prenom_proprietaire FROM proprietaires p LEFT JOIN jeux_video j ON j.ID_proprietaire = p.ID
    --LEFT JOIN : prend toute la table de gauche (proprietaire) et associe les data qu'elle peut trouver dans jeux_video
