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
  Jointure conditionelle
    SELECT * FROM Notes, Eleves WHERE Notes.prenom = Eleves.prenom AND Notes.nom = Eleves.nom;
  Imbriquées --Qui a eu moins que Dark Vador en BDD
    SELECT * FROM Notes WHERE cours = 'Bases de Données' AND note <= (SELECT note FROM Notes WHERE cours = 'Bases de Données' AND prenom = 'Dark' AND nom = 'VADOR');
  (NOT) IN
    SELECT nom FROM Eleves WHERE nom NOT IN (SELECT nom FROM Notes); --Les eleves qui n'ont pas de notes
  (NOT) EXISTS
    SELECT nom FROM Eleves e WHERE NOT EXISTS (SELECT * FROM Notes n WHERE e.nom = n.nom);
  UNION INTERSECT EXCEPT(MINUS en Oracle)
    SELECT prenom, nom FROM ??
  CASE
    WHEN followers >= 700000 THEN 'Highly Popular'
    WHEN followers BETWEEN 300000 AND 699999 THEN 'Moderately Popular'
    ELSE 'Less Popular'
  END AS popularity_category
  JSON
    attributes = '{"nbTruc": 0, "origine": "Portugal"}'
    attributes::json->>'nbTruc' -- Choisit valeur attribut nbTruc

WHERE CONDITIONS
  = 	      Equal 	
  > 	      Greater than 	
  < 	      Less than 	
  >= 	      Greater than or equal 	
  <= 	      Less than or equal 	
  <> 	      Not equal. Note: In some versions of SQL this operator may be written as != 	
  BETWEEN 	Between a certain range 	
  LIKE 	    Search for a pattern 	
  IN 	      To specify multiple possible values for a column

CREATE
  CREATE TABLE Eleves(
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    nom VARCHAR(100),
    prenom VARCHAR(100),
    date_naissance DATE
  )
  CREATE TABLE Notes(
    id INT PRIMARY KEY NOT NULL,
    nom VARCHAR(100),
    prenom VARCHAR(100),
    matiere VARCHAR(20),
    note INT
  )

INSERT INTO
  INSERT INTO jeux_video(ID, nom, possesseur, console, prix, nbre_joueurs_max, commentaires) VALUES('', 'Battlefield 1942', 'Patrick', 'PC', 45, 50, '2nde guerre mondiale')
  INSERT INTO jeux_video VALUES('', 'Battlefield 1942', 'Patrick', 'PC', 45, 50, '2nde guerre mondiale', '{"id": 17}'::jsonb)
  
UPDATE
  UPDATE jeux_video SET prix = 10, nbre_joueurs_max = 32 WHERE ID = 51
  UPDATE jeux_video SET possesseur = 'Florent' WHERE possesseur = 'Michel'

DELETE
  DELETE FROM jeux_video WHERE nom='Battlefield 1942' --Si on oublie le where ça delete tout


TRUNCATE
  TRUNCATE TABLE `table` -- Supprime tous les éléments de la table mais pas la table
  TRUNCATE TABLE `table` CASCADE -- Pareil mais répercute dans tt les tables où elle est référencée


-- Random commands
  \d table_name           -- Get table info, columns
  \sf function_name       -- Get function code, test its existence 
  \dT+                    -- Give enum values
  EXPLAIN ANALYZE <query> -- Analyze a query, in term of time elapsed in each operation
  command \watch 5        -- Relance command toutes les 5 sec


-- Special tables
  pg_tables   -- Contient liste des tables de la DB


-- Scalar functions
  SELECT UPPER(nom) AS nom_maj FROM jeux_video
  SELECT UPPER(nom) AS nom_maj, possesseur, console, prix FROM jeux_video
  UPPER ->maj, LOWER ->min, LENGTH -> compte nb carac, ROUND(nb, 2)


-- Aggregate functions
  SELECT AVG(prix) AS prix_moyen FROM jeux_video -- Sur le php besoin d'appeller fetch qu'une seule fois
  COUNT: SELECT COUNT(*) AS nbjeux FROM jeux_video -- Donne nombre entrées
        SELECT COUNT(nbre_joueurs_max) AS nbjeux FROM jeux_video -- Omet ceux avec NULL pour nb max de joueurs
        SELECT COUNT(DISTINCT possesseur) AS nbpossesseurs FROM jeux_video
  - COUNT() counts the number of rows in a specified column
  - SUM() computes the sum of values within a specified column
  - AVG() calculates the average of a selected group of values
  - MIN() retrieves the lowest value from a particular column
  - MAX() fetches the highest value from a specific column
  - FIRST_VALUE() returns the first value in a designated column
  - LAST_VALUE() provides the last value in a given column


OVER
  Peut utiliser fonction aggregation de manière incrémentale le long d une table
  SELECT article, SUM(prix) OVER (ORDER BY date_) AS sum_prix -- sum_prix de la ligne n est la somme de prix des lignes 1 à n
  SELECT article, SUM(prix) OVER () AS sum_prix -- sum_prix est la somme de toutes les lignes, répétée à chq fois
  SELECT article, SUM(prix)
    OVER (ORDER BY date_ PARTITION BY type_)
    AS sum_prix -- même chose mais groupé par catégorie et la somme recommence au début de chaque partition


-- Operators
  = 3
  = 'Jacob Collier'
  != 'CREATED'
  is NULL
  WHEN x >= 8.0 THEN 'High'
  WHEN x BETWEEN 6.0 AND 7.9 THEN 'Moderate'
  WHEN x < 6.0 THEN 'Low'


GROUP BY - HAVING
  SELECT AVG(prix) AS prix_moyen, console FROM jeux_video GROUP BY console
  SELECT AVG(prix) AS prix_moyen, console FROM jeux_video GROUP BY console HAVING prix_moyen <= 10 -- Fonctionne que sur agrégats, sinon where
  -- Regroupement des autres valeurs pour chaque valeur distincte de console
  -- Il faut donc utiliser un aggrégat sur les autres valeurs


-- Gestion dates
  SELECT pseudo, message, date_post  FROM minichat WHERE date_post = '2010-04-02'
  SELECT pseudo, message, date_post FROM minichat WHERE date_post BETWEEN '2010-04-02 00:00:00' AND '2010-04-18 00:00:00'
  -- Get date
    NOW() -> AAAA-MM-JJ HH:MM:SS
    CURDATE() -> AAAA-MM-JJ
    CURTIME() -> HH:MM:SS
  -- Operations on date
    DAY(), MONTH(), YEAR(), HOUR(), MINUTE(), SECONDE()
    pr.dateAdded < now() - INTERVAL '2min'
  -- Adapter format date
    SELECT pseudo, message, DATE_FORMAT(date_post, '%d/%m/%Y %Hh%imin%ss') AS date_post FROM minichat
  -- Operations on dates
    SELECT pseudo, message, DATE_ADD(date, INTERVAL 15 DAY) AS date_expiration FROM minichat
  -- Timestamp
    "2025-01-01 00:00:01.00+00"


-- Jointures : Combinaison des données de 2 tables en établissant une relation entre un champ de l'une et un de l'autre
  INNER JOIN / JOIN -- Ne prend que les lignes des 2 tables pour lesquelles une correspondance a été trouvée
    SELECT j.nom nom_jeu, p.prenom prenom_proprietaire FROM proprietaires p INNER JOIN jeux_video j ON j.ID_proprietaire = p.ID
    -- les jeux dont l'id n'apparaissent pas dans les propriétaires et les propriétaires n'ayant aucun jeu associés à leur ID ne seront pas donnés par cette commande
  LEFT JOIN -- Prend toutes les lignes de la table de gauche et seulement les lignes de celles de droite pour lesquelles une correspondance a été trouvée
    SELECT j.nom nom_jeu, p.prenom prenom_proprietaire FROM proprietaires p LEFT JOIN jeux_video j ON j.ID_proprietaire = p.ID
    -- mêmes résultats qu'au dessus mais avec en plus les propriétaires n'ayant pas de jeu associé, dans ce cas nom_jeu sera à NULL
    RIGHT JOIN -- existe aussi mais à ne pas utiliser, toujours mettre dans le sens LEFT
  FULL OUTER JOIN -- Prend toutes les lignes des 2 tables et match quand il peut
    SELECT j.nom nom_jeu, p.prenom prenom_proprietaire FROM proprietaires p FULL OUTER JOIN jeux_video j ON j.ID_proprietaire = p.ID
    -- mêmes résultats qu'au dessus avec en plus les jeux vidéo n'ayant pas de propriétaire associé qui est du coup display à NULL


-- For
FOR v_day IN 0..6 LOOP instructions; END LOOP; -- iterate on int array
DECLARE -- Iterate on str array
    tables TEXT[] := ARRAY['public.objectposition', 'history.message'];
    t TEXT;
BEGIN
    FOREACH v_tablename IN ARRAY v_tablenames LOOP instructions; END LOOP;
END $$ LANGUAGE PLPGSQL;




-- Commandes en vrac
PERFORM -- Like select but doesn't return anything
LEFT(attributes::Text, 25) -- Ne donne que les n premiers char d'un texte


------------------------------------------------------------------------------------------------------------------------
----------------------------------------------- POSTGRESQL -------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------
-- FUNCTION
CREATE FUNCTION functionName(arg1 BIGINT) RETURNS void AS
$$
DECLARE
  var BIGINT;
BEGIN
END;
$$ LANGUAGE PLPGSQL;
fct1(arg1 BIGINT[]) -> fct1(ARRAY[1,2,3]) || fct1('{1,2,3}')

-- FOR
FOR elem IN (SELECT * FROM mytable) -- elem must be declared as RECORD
FOREACH elem IN ARRAY arr           -- elem BIGINT et arr BIGINT[]
LOOP
LOOP END;


