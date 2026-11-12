<?php
$variable = 17;
// Uncommentaire
/* Un Uncommentaire
sur plusieurs lignes */

//String
echo 'The count is $count' //non evaluated, var nor replaced
echo "The count is $count" //evaluated, var is replaced
  //Concaténation
  'Le visiteur a ' . $age_du_visiteur . ' ans';

//Opérations
Comme python sauf quotient
$variable++ //Inceémentation
//Conditions
Tests comme python sauf ===
if (condition){code;} //not -> if (! condition)
elseif (condition){code;}
else {code;}
switch($variable){ //Ne teste que l'égalité
  case 0:
    code;
  break;

  case 1:
    code;
  break;

  default:
    code;}
$majeur = ($age >= 18) ? true : false;
while (condition) {code;}
for ($nombre_de_lignes = 1; $nombre_de_lignes <= 100; $nombre_de_lignes++){code;}
AND -> &&
OR -> ||

//Typecast
Comme en c
$string = (string)$int;

//Arrays
Tableau numéroté
  $prenoms = array ('François', 'Michel', 'Nicole', 'Véronique', 'Benoît');
  $prenoms[0] // Accession ou ecriture sur la valeur
  foreach($prenoms as $element){echo $element . '<br />';}
Tableau associatif
  $coordonnees = array (
      'prenom' => 'François',
      'nom' => 'Dupont',
      'adresse' => '3 Rue du Paradis',
      'ville' => 'Marseille');
  $coordonnees['cle'] // Accession ou ecriture sur la valeur
  foreach($coordonnees as $cle => $element) ?
Methodes speciales
  print_r($array)
  array_key_exists('cle', $array) // Pour la clé
  in_array('value', $array) // Pour une valeur
  array_search('value', $array)// Cherche une valeur, renvoie la clé correspondante, sinon false
  count($array) //give the length
  array_push(array_name, value1, value2...) //ajouter des elems

//Fonctions
strlen() // Longueur chaîne carac
str_replace('b', 'p', 'bim bam boum') // pim pam poum
str_shuffle() // Mélange caractères
strtolower() /* Écrit en minuscules */ strtoupper()
date('lettre') // Y:année m:mois d:jour H:heure i:minute
gettype($var) // Get variable type
function DireBonjour($nom) {echo 'Bonjour ' . $nom . ' !<br />';}
include("menus.php"); // Inclus un autre fichier à cet endroit (fichier php ne contenant que du html)
function static hello(){}
ClassName::hello(); //calling a static function

// Param url
<a href="bonjour.php?nom=Dupont&amp;prenom=Jean">Dis-moi bonjour !</a> // ENvoyer le param
$_GET['nom'] -> Dupont
isset($_GET['prenom'] // True si param existe
(int) $_GET['repeter'] // Etre sur que c'est bien du type int

//Formulaire
<form method="post" traitement="prgm.php">
// prgm.php page load quand validation formulaire
$_POST['name_input'] // chope valeur dans input dont name="name_input"
// dans le cas de select retourne la value
// dans le cas de checkbox vaut "on" si coché, non défini sinon
// dans le cas de radio prend value du sélectionné
/!\ htmlspecialchars($_POST['prenom']) // éviter faille XSS, striptags pour suppr balises
Envoi de fichiers : "https://openclassrooms.com/en/courses/918836-concevez-votre-site-web-avec-php-et-mysql/913099-transmettez-des-donnees-avec-les-formulaires" //2eme partie

//Variables superglobales
$_SERVER //Infos serveur
  $_SERVER["REMOTE_ADDR"] //adresse ip client
$_ENV //Variables environnement serveur
$_SESSION //Variables stockées le temps de la visite
  session_start() //À lancer à chaque début (avant <!DOCSTRING>) de page où on a besoin des sessions
  session_destroy() //Ferme la session (fait automatiquement au bout de quelques minutes)
$_COOKIE
  setcookie("nom", "valeur", time()+365*24*3600 /*Cookie gardé 1 an */, null, null, false, true); //true pour httpOnly (contre XSS)
  //À lancer avant <!DOCSTRING> pour que ça marche
  $_COOKIE["nom"] //Récupérer la valeur stockée
  //Pour modifier on set à nouveau
$_GET //Données en paramètre de l'url
$_POST //Données du formulaire
$_FILES //Fichiers envoyés par le formulaire

//Gestion de Fichiers
Aller sur ftp prendre fichier dans lequel on veut ecrire et autoriser ecriture au public (set à 7)
$monfichier = fopen('compteur.txt', 'r+'); /*
  r : lecture seule
  r+ : lecture ecriture
  a : ecriture seule(crée le fichier en +)
  a+ : ouvre en lecture et ecriture, cree le fichier (marche que si bon chmod sur dossier)*/
$caractere = fgetc($monfichier); //Lit un caractère
$ligne = fgets($monfichier); //Lit une ligne
fputs($monfichier, 'Texte à écrire'); //Ecrit dans le fichier à l'emplacement du curseur en r+ ou à la fin en a/a+
fseek($monfichier, 0); //Place le curseur en position 0 si mode r+
fclose($monfichier);

// Retourner vers un autre site
header('Location: minichat.php')
?>

//Classes
class Fruit {
  // Properties
  public $name;
  public $color;

  // Methods
  function __construct($name, $color){
	$this->name = $name;
	$this->color = $color;
  }

  function set_name($name) {
    $this->name = $name;
  }
  function get_name() {
    return $this->name;
  }
}

$apple = new Fruit("Apple", "green");

//Trafiquer des images en php
"https://openclassrooms.com/en/courses/918836-concevez-votre-site-web-avec-php-et-mysql/916429-creez-des-images-en-php"
