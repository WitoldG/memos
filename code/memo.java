// -------------------
// ------------ Arrays
// -------------------
int[] tab; //declaration
tab = new int[5]; //allocation
tab[0] = 2; //access
//objects array
Pangolin[] pangolins = new Pangolin[n];
for (int i = 0; i < pangolins.length; i++) { //classic parcours
    pangolins[i] = new Pangolin(...); //allocation 1 by 1
for (Pangolin p : pangolins) { //foreach parcours
    System.out.println(p.toString());
//2D array
int[][] tab2D;
tab2D = new int[5][]; // array of 5 null references
for (int i = 0; i < tab2D.length; i++) {
    tab2D[i] = new int[i + 1];} //case by case allocation
tab2D[1][0] = 45;

// -----------------------------
// ------------ Class definition
// -----------------------------
file name: MyClass.java
class MyClass {
    //encapsulation -> screen
    //abstract -> if at least ine method is abstract (absolutely needs sub-class)

    //attributes definition
    private String name;
    private int id;
    //default values
    private String name = new String ("name");
    private int id = 5;
        //if no specified values, int->0, float->0.0; bool->false, ref->null
        //constructor executed after these definitions


    //method definition
    int methodOfMyClass(int a, String b){
        // attributes accessing
        this.id = 5;
    // abstract
    abstract public int coutNourriture();
        //method redefined in sub-classes
        //here just definition as in .h

    //special methods
    public String toString{
        return "Description de " + this.name;
    }

    //class attributes
    private static int nbClass = 0;
    //accession in constructor
    nbClass++;
    //class methods
    public static int getNbClass(){
        return nbClass;
    //access to this method
    objectOfMyClass.getNbClass();
    MyClass.getNbClass();
    }
}
// -------------------------
// ------------ Class object
// -------------------------

// definition and allocation
MyClass objectOfMyClass = new MyClass();
//attributes setting
MyClass objectOfMyClass = new MyClass("name", 5);
objectOfMyClass.name = "name";
//object destruction -> unreferencing then garbagecollector
objectOfMyClass = null; //dereferencing

// ------------------------------
// ------------- Test programming
// ------------------------------
public class TestMysClass{
    public static void main(String[] args) {
        //test code
    }
}

// ----------------------
// ------------- Heritage
// ----------------------
class PangolinALongueQueue extends Pangolin {
    //same properties, attributes and methods
    //if not specified extends automatically from Object class
    private int longueurQueue;

    public PangolinALongueQueue(String nom, int nbEcailles, int longueurQueue) {
        super(nom, nbEcailles);
      	this.longueurQueue = longueurQueue;
    }

    public int getLongueurQueue() {
        return longueurQueue;
    }

    @Override //(redefinition), if not specified automatically if same args, else overload
    // must be as much or less protected than overrided method
    public String crier(){
        return "gwak";
    }
    public final void crier() {} //forbid the override
}

// ---------------------------
// ------------- Polymorphisme
// ---------------------------
//Allow to write methods that can apply on objects of different class if they herit from the same class
Pangolin p = new Pangolin(...);
Animal p_animal = p; //car Pangolin hérite de Animal
//dynamic type: in memory, don't change and defined with new
    object.getClass().getName(); //get dynamic type
    (object isinstance Animal); //true if object is Animal or subclasses
//static type: change regarding the reference used

//transtypage
//upcast -> to most general class
Animal a = p;
Animal a = (Animal)p;
//downcast -> to sub-class
Canard c = (Canard) uneBebete; //must cast in this case

// ---------------------------
// ------------- Composition / Agrégation
// ---------------------------

Agrégation(losange vide --<>) : on file les références de l objet qui peut vivre en dehors
Compositon(losange plein) : on les crée à l'intérieur

// -------------------------
// ------------- Collections
// -------------------------
Dans java.util
Une collection est une interface
Si on a une collection on sait qu on a à dispo les méthodes de collections
Selon les collections les performances ne seront pas les mêmes pour les différentes opérations

Type generic : au lieu d'écrire un code pour chaque type d'objet sans savoir ce que c'est
ex:
class Couple<Truc>{
    private truc truc1, truc2;
    public Couple(Truc a, Truc b){
        truc1 = a; truc2 = b;
    }
    public String toString(){
        return truc1.toString()+truc2.toString();
    }
}

Relations d ordre sur E
E implémente l'interface Comparable<E>méthode int compareTo(E e)
–renvoie 0 si this = e
–renvoie un entier strictement positif si this > e
–renvoie un entier strictement négatif si this < e

Parcourir :
Collection<E> coll = ...
for (E e : coll){...}
avec iterateur
Iterator<E> it = al.iterator();
while (it.hasNext()){
    it.next();
    traitement...
}

exo : Ecrire une classe comparateur générique qui compare 2 éléments Bidule en fonction de leur représentation via toString. Son constructeur prendra en argument un booléen indiquant si la relation d’ordre est dans l’ordre alphabétique(true) ou alphabétique inverse(false)
class Bidule implements Comparable<Bidule>{
    public boolean ordre = true;
    public int.compareTo(Bidule b){
        if (ordre) return this.toString().compareTo(b.toString());
        else return b.toString().compareTo(this.toString());
    }
    public bool compareTo(){
        return b1.toString.compareTo(b2.toString());
    }
}
















// object creation
PangolinALongueQueue rantanplan = new PangolinALongueQueue("Rantanplan", 1966, 28); //put args of class and sub-class

//exception
throw new IllegalArgumentException("Argument incorrect : x = " + x)
try {
    y = meth2(x);
} catch (ArithmeticException e) {
    System.out.println("Exception rattrapée");
}
return y;







//Ajouter un régime pour les animaux
On définit le constructeur dans le régime
Régime doit être static  mais au niveau de chaque animal
On ajoute aussi l attribut final

B il n y a pas de constructeur par défaut
A pas possible en java, utilise interface à la place
D si a=b; a.getY(); ça marche toujours pas
    A a=b; a est statiquement de classe A mais dynamiquement de classe B, les méthodes sont choisies dynamiquement donc prend méthode de B
E appelle la méthode de D car a est dynamiquement de type D
6 D
7 D appelle la fct sanss arguments car ce n est pas la même, le dernier ne l a pas redéfinie mais surchargée
8 C l1 palmipede est une abstraction d'un canard donc pas de souc
    l2 l'objet réel n'est pas un canard donc on peut pas cast
    l3 besoin de cast explicite (type de canardo plus specialise que celui de donald)
9 A
10 A
11 true false true false. quand on appelle la methode de l objet on prend pas la surchargée, on prend celle qui compare les refs.

1 C add: ça dépend de la collection
2 BC, A non quand on crée objet de type generic il faut l'alloc avec le même nom


// Correction tp
// class ExpressionEvaluable implements Evaluable {
//     private ExpAbstraite expr;
//     private Env env;
//
//     public ExpressionEvaluable(ExpAbstraite)
// }
