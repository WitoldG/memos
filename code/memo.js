<script src="hello.js"></script> // à placer juste avant </body>

var myVariable; //Déclaration d'une variable
var myVariable = 5.5; //+affectation
var myVariable1, myVariable2 = 4, myVariable3; //def de 3 var et affectation 2eme
myVariable1 = myVariable2 = 2; // Affecter une valeur à 2 variables
typeof myVariable
//opérateurs : + - * / %
//incrémentation :
  myVar += 1
  myVar++, myVar-- //Renvoie la valeur avant incrémentation
  ++myVar, --myVar //Renvoie la valeur après incrémentation
//concaténation : comme python +, concaténation nb change son type
//opérateurs : comme python avec le ===
//opérateurs logiques : &&, ||, !
alert(conditionTest1 || conditionTest2); //Renvoie première valeur à True
var userName = prompt('Entrez votre prénom :'); //input
parseInt(string, base) //Convertit string en nb suivant la base
isNan() //isNotANumber return bool
confirm("Voulez vous vraiment faire ça ?"); //popup avec demande de confirmation

//string
string.length; string["length"]
string.toUpperCase() / string.toLowerCase()
string.split(' ')

//array
var myArray = [42, 'Sébastien', 12, 'Laurence'];
var myArray = new Array('Sébastien', 'Laurence', 'Ludovic', 'Pauline', 'Guillaume'); //deprecated
myArray[1] //accéder/modifier la valeur
myArray.push('Pauline', 'Guillaume'); myArray.unshift('Luc')// Ajoute à la fin resp au début
myArray.pop(); myArray.shift(); // Retire à la fin resp au début
array.join('-') // Create string
//parcourir Array
for (var i = 0, c = myArray.length; i < c; i++) {alert(myArray[i]);} //on def c puis on l'utilise pour pas avoir à calc la length à chaque fois

//objet littéral
var family = {self: 'Sébastien', sister: 'Laurence', brother: 'Ludovic'};
family.sister; family["sister"] //accès/ajout aux éléments
for (var id in family) {alert(family[id]);} //parcours


//conditions/loops
if ( /* condition */ ) {
    // Du code…
} else if ( /* condition */ ) {
    // Du code...
} else {
    // Du code…
}
if(string){} // false si string='' || 0

var drawer = parseInt(prompt('Choisissez le tiroir à ouvrir (1 à 2) :'));
switch (drawer) { //Tests de la forme ===
    case 1:
        alert('Contient divers outils pour dessiner : du papier, des crayons, etc.'); break;
    case 2:
        alert('Contient du matériel informatique : des câbles, des composants, etc.'); break;
    default:
        alert("Info du jour : le meuble ne contient que 2 tiroirs et, jusqu'à preuve du contraire, les tiroirs négatifs n'existent pas.");
}

while (condition){instructions}
do {instructions} while(condition) //Exécutée au moins une fois

for (init_var; cdt; incrementation) : for (var i = 0, nicks = '', nick; true; i++) //Variables initialisées ici seront gardées

adult = confirm('Êtes-vous majeur ?');
category = adult ? '18+' : '-18';


alert("Hello world!") //Ouvre une boîte de dialogue

//Functions
function myFunction(arguments) {
    // Le code que la fonction va devoir exécuter
if (typeof allowCancel === 'undefined') { // Valeur par défaut argument
    allowCancel = false;
}
function (arguments) { //fonction anonyme
    // Le code de votre fonction anonyme
}
(function test() { //Appeler une fonction au moment de sa déclaration (IIFE)
    // Code.
})();



// Les objets
constructeur : code appelé à la création de l'objet
propriété : variable concernant l'objet
méthode : fonctions contenues dans l'objet permettant de réaliser des actions dessus

//Débogage
console.log(string) //Affiche string dans la console
console.log(var) //Affiche une variable danss la console
console.warn(); console.error(); //affiche en différentes couleurs
console.group(); console.groupEnd(); //groupe les erreur
developers.google.com/chrome-developer-tools/docs/console-api //liste complete commandes debug
on peut modifier les var globales directement dans la console
section debug on peut placer des points d'arret sur le js

//Interaction avec html
  //window
  objet global window, sous entendu pour window.alert() //alert est une méthode de l'objet window
  déclaration de var sans var devant -> deveint un objet de window et donc global
  //document
  objet qui représente balise <html>
  document.getElementById('myDiv') //return elt qui a l'id myDiv
  document.getElementsByTagName('div') //return array of elts of type div
    //En paramètre de cette méthode vous pouvez mettre une chaîne de caractères contenant un astérisque * qui récupérera tous les éléments HTML contenus dans l'élément ciblé.
  //querySelector
  donne en arg un string qui correspond à une spécification css
  document.querySelector('#menu .item span') //renvoie le premier elt correspondant
  document.querySelectorAll('#menu .item span') //renvoie array avec ts les items correpondants
  //attributs
  chaque truc html fait partie de plusieurs objets et hérite de leurs attributs et méthodes
    //Element
    a.getAttribute('href'); href = a.href; //différences mineures : getAttribute doesn't compute
    a.setAttribute('href', 'alwan-ceramique.fr'); a.href = 'http://www.alwan-ceramique.fr';
    pour modifier la classe il faut ecrire className et pour le for, htmlFor
      //classList
      div.classList //array with different classes
      div.classList.add('new-class');
      div.classList.remove('new-class');
      div.classList.toggle('toggled-class');
      div.classList.contains('old-class')
      //innerHTML
      div.innerHTML //string with html inside div
      document.getElementById('myDiv').innerHTML = '<blockquote>Je mets une citation à la place du paragraphe</blockquote>';
      on peut aussi utiliser += pour rajouter du HTML
      opération très coûteuse, pour plusieurs fois vaut mieux concaténer avant
    div.textContent //pareil que innerHTML mais sans les balises
    //Node
    parent = elt.parentNode;
    elt.firstChild; //first child
    elt.lastChild;
    elt.firstElementChild; //first child of type elt
    elt.lastElementChild;
    elt.childNodes; //array of child
    elt.nextSibling;
    elt.previousSibling;
    elt.nextElementSibling;
    elt.previousElementSibling;
      //boucler sur les children
      while(child){...; child = child.next_sibling;}
    elt.nodeNAme;
      //nodeType
      elt.nodeType;
      1 Nœud élément = Node.ELEMENT_NODE
      3 Nœud texte = Node.TEXT_NODE
      7 Nœud pour instruction de traitement = Node.PROCESSING_INSTRUCTION_NODE
      8 Nœud pour commentaire = Node.COMMENT_NODE
      9 Nœud document = Node.DOCUMENT_NODE
      10 Nœud type de document = Node.DOCUMENT_TYPE_NODE //<!DOCTYPE html>
      11 Nœud de fragment de document = Node.DOCUMENT_FRAGMENT_NODE
        //deprecated
        2 Nœud attribut
        4 Nœud pour passage CDATA (relatif au XML)
        5 Nœud pour référence d'entité
        6 Nœud pour entité
        12 Nœud pour notation
  //Creer et inserer des elts
    //Creation
    var newLink = document.createElement('a'); //cree un pointeur vers l'elt
    //Affectation des attributs
    newLink.id    = 'sdz_link';
    newLink.href  = 'http://www.siteduzero.com';
    newLink.title = 'Découvrez le Site du Zéro !';
    newLink.setAttribute('tabindex', '10');
    //Insertion de l'element
    document.getElementById('myP').appendChild(newLink);
      //ajout en dernier enfant
      //retourne l'elt affecté
    parent.insetBefore(elt_to_insert, elt_after);
    //Ajouter du texte
    var newLinkText = document.createTextNode("Le Site du Zéro");
    newLink.appendChild(newLinkText);
  //Cloner
  elt1 = elt2.cloneNode(true) //true indicates if I want to copy attributes, but don't copy events in anycase
  //Remplacer
  parent.replaceChild(nexElt, oldElt);
  //Remove
  link.parentNode.removeChild(link); //return remmoved elt to place it at another place
  //Various
  paragraph.hasChildNodes()

//Evenements
  click Cliquer (appuyer puis relâcher) sur l'élément
  dblclick Double-cliquer sur l'élément
  mouseover Faire entrer le curseur sur l'élément
  mouseout Faire sortir le curseur de l'élément
  mousedown Appuyer (sans relâcher) sur le bouton gauche de la souris sur l élément mouseup Relâcher le bouton gauche de la souris sur l élément
  mousemove Faire déplacer le curseur sur l'élément
  keydown Appuyer (sans relâcher) sur une touche de clavier sur l élément
  keyup Relâcher une touche de clavier sur l'élément
  keypress Frapper (appuyer puis relâcher) une touche de clavier sur l élément
  focus « Cibler » l'élément
  blur Annuler le « ciblage » de l'élément
  change Changer la valeur d'un élément spécifique aux formulaires (input,checkbox, etc.)
  input Taper un caractère dans un champ de texte (son support n'est pas complet sur tous les navigateurs)
  select Sélectionner le contenu d'un champ de texte (input,textarea, etc.)
  submit Envoyer le formulaire
  reset Réinitialiser le formulaire
  //usage
    <span onclick="alert('Hello !');">Cliquez-moi !</span>
    this -> pointe sur l'elt qui a subi un evenement
    return false; //bloque l'effet par défaut de l'objet
    evenement sur elt lambda -> utilisation de balise button sans style
  //put event with js
    elt.addEventListener(evt_type, function, phase_bool);
    elt.addEventListener('click', function() {alert("Vous m'avez cliqué !");}, true);
    //phase
      true: capture phase
      false: bubbling phase
      //w3.org/TR/DOM-Level-3-Events/#event-flow
    elt.removeEventListener(evt_type, fct_name)
  //Event object
    declaration of the called function: function(e){};
    e.type //click, mouseover...
    e.target pointer to the triggering element //pour mouseover le target est l'element le plus au dessus même si c'est pas lui qui a l'evt contrairement à
    e.currentTarget elt at the origin of the trigerring
    evt.clientX; evt.clientY; position curseur par rap haut gauche page web
    evt.relatedTarget evt avant pour mouseover/mouseout

//bs4
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
