----------------------------------------------
--------------- Variable types ---------------
----------------------------------------------
  char //entiers
  bool //#include <stdbool.h>
  #include <stdint.h> //int32_t uint32_t, int8_t...
  int //classiquement 16 ou 32 bits
  Attributs de précision pour ints
    short / long //classiquement 16/32 bits
  Attribut de représentation pour ints
    unsigned -> unsigned short int
  Flottants (precision croissante)
    float
    double
    long double
Constantes
  Types
    Décimales 372
    Octales 010 //commence par 0 et ne contient que des chiffres octaux
    Hexadécimales 0x25A
  Suffixes
    u/U //unsigned
    l/L //long
  Flottants
    2. .3 2.3 2e4 .3e4
Declarations de var avec type
  int i = 42;
  long double i = 0.35, j=.3e35;



----------------------------------------------
----------------- Constants ------------------
----------------------------------------------
// Usage: name always in UPPER CASE
Named constants
  #define PI 3.14159
  remplacera toute utilisation de PI par "3.14159;"
  that a preprocessor command so no ; at the end
Enumeration
  enum {LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE};
  // decalres the 7 constants with values going from 0 to 6
  enum {FRANCE = 10, ESPAGNE = 20, ITALIE = 30};
  // to give particular values
  enum {FRANCE = 10, LUXEMBOURG, BELGIQUE, ESPAGNE = 20, ITALIE = 30};
  // LUXEMBOURG=11, BELGIQUE=12
  usage: int country = FRANCE;




----------------------------------------------
-------------------- Char --------------------
----------------------------------------------
written between quotes:'a'
isalpha(c) //return true for abcwyzABCXYZ
islower(c) //return true for abcxyz
Special chars
  '\0'   null
  '\12'  newline
  '\15'  carriage return
  '\33'  escape
  '\n'   new line
  '\t'   horizontal tabulation
  '\v'   vertical tabulation
  '\b'   back space
  '\r'   carriage return
  '\f'   form feed
  '\a'   audible alert



----------------------------------------------
------------------- String -------------------
----------------------------------------------
  char ch[3] = {’a’, ’b’, ’c’};
  char ch[7] = "chaine"  // Each char in a cell, null at the end
  char ch[10] = "chaine" // Last are NIV
  char ch[] = "chaine" // Take automatically 7 char
  char ch[6] = "chaine" // Won't put the null at the end
  appel fonction avec char p.70
  strlen(mot) -> donne longueur
  strcat(a, b) //concatenation (#include <string.h>)



----------------------------------------------
------------------- Arrays -------------------
----------------------------------------------
  definition
    #define N 100
    int t1[N], t2[N];
    #define N 5
    int t[N] = {1, 2, 3, 4, 5};
    int t[N] = {1, 2}; //Le reste sera initialisé à 0

  access
    int t[10] //t est un pointeur sur le premier élement du tableau, il est constant on ne peut pas lui affecter de valeur
    t[i] && *(t+i) /*referent à la même chose */ i[t] //aussi mais vaut mieux pas s'en servir
    on ne peut pas referer à un tableau en entier, pour t1=t2 il faut le faire élément par élément
    int *p; p=&t[4]; p[2] //réfère au 6eme élément du tableau
  passage en argument
    void imp_tab(int *t, int nb_elem){}
    void imp_tab(int t[], int nb_elem){} //Fait la même chose mais on comprends mieux que c'est un tableau
    -> appel : imp_tab(tab,NB_ELEM);
    si les tableaux vont tous avoir la même taille :
      #define NB_ELEM 10
      void imp_tab(int t[NB_ELEM])
    si la procédure ne modifie pas le tableau
      void imp_tab(const int t[], int nb_elem)
  plusieurs dims
    definition int t[10][20]
    passage en parametre p(int t[][N])//Obligé d'avoir une constante pour le deuxième param
    init int t[4][5] = {
           {0,1,2,3,4},
           {10,11,12,13,14},
           {20,21,22,23,24},
           {30,31,32,33,34},
         };
    lignes taille différentes
      #define NB_ELEM 3
      int taille[NB_ELEM] = {1, 2, 3};
      int ligne1[] = {10};
      int ligne2[] = {20,21};
      int ligne3[] = {30,31,32};
      int *tab[] = {ligne1, ligne2, ligne3};
    parcours
      int i, j, *p;
      for (i = 0; i < NB_ELEM; i++){
        for (j = 0; j < taille[i]; j++)
        printf("%d ", tab[i][j]); /* accès à l’élément courant par tab[i][j] */
        printf("\n");}



----------------------------------------------
----------------- Operations -----------------
----------------------------------------------
  Incrementation
    b = ++a // b get the value of a AFTER incrementation
    b = a++ // b get the value of a BEFORE incrementation
  decrémentation
    b = --a // b get the value of a AFTER incrementation
    b = a-- // b get the value of a BEFORE incrementation
  affectation
    i = 3
    i = j + 1
    i = (j = k) +1
    // To the left there is a lvalue, to the right an expression
    // expression type is converted to lvalue type if needed
    // Makes a bord effect affecting expression to lvalue and returns affected value
  addition, soustraction, multiplication //trivial
  division
    a/b // if one of them is a float
  euclidian division
    a/b // if they are two ints
  modulo
    a%b // type of result generally the same than the dividende, but depends of the implementation
  comparaisons
    a>b, a<b, a>=b, a<=b, a==b, a!=b // returns int: 1 or 0
    return 1/0
    pr string
      #include <string.h>
      strncmp(str1, str2) //retrun <0 if str1<str2... =0, >0
  logique
    bool and: &&    binary and: &)
      si int, 0=false, autre=true
      évalue déjà la première expression puis la 2eme, si 1ere fausse regarde pas la deuxieme
    bool or: || (binary or : |)
      premiere opérande évaluée puis seconde si premier vraie
    bool negation: !    binary negation: ~ 



----------------------------------------------
---------------- Instructions ----------------
----------------------------------------------
  instruction expression
    j = i + 1;
  instruction composée
    {
      liste_declarations //Ne seront accessibles qu'a l'int
      liste_instructions
    }
  if ( expression ) instruction
  else if ( expression ) instruction
  else instruction
  affectation concurrente
    a = condition ? val_vrai : val_faux
  switch(num){
    case 1: //Execute tout jusqu'au prochain break même si pas le même case
      printf("Y en a un");
      break;
    case 2:
      printf("Y en a deux");
      break;
    default:
      print("Y en a plus que deux");
  }

  for (initialisation_var; cdt_arret; incrementation) {instructions}
  for (i = 0; i < N; i++) t[i] = 0;

  while (expression) {instuctions}
  do {instructions} while (expression) //La condition n'est testée qu'à la 2eme itération

  break Coupe la boucle dans la quelle on est actuellement
  continue arrête l itération courante et va au début de la suivante

#include "nom-de-fichier" inclut fichier utilisateur
#include <nom-de-fichier> inclut fichier système



-----------------------------------------------
------------------ Functions ------------------
-----------------------------------------------
  precision type_du_return nom (declaration de parametre){
    liste decla / instructions
  }
  precision : extern //Devant appel si definition de fct dans un autre fichier    cf base/portee
              static //Rend utilisable fonction que dans son propre fichier
              automatic
  int sum_square(int i,int j){}
  double pi(void){} //Pas de parametres
  void print(a){} //Ne retourne rien
  int main(int argc, char *argv[]/*ou **argv*/){//Prends param donnés avec le nom de fichier
    argc /*nb arg*/ argv[1] /*1er arg*/ argv2[2] /*2eme arg*/
  }

printf("texte")
  %d int
  %ld long
  %f float %lf double
  %c char
  %s string
  %p pointeur
  %hd short
  %x int hex
  liste exhaustive p.91
  #include <stdio.h> //besoin pour que ça marche



----------------------------------------------
------------------ Pointers ------------------
----------------------------------------------
  Déclaration
    int *pi; Déclaration pointeur vers un int
    void *i; Capable de pointer vers tout
  Adressage
    pi = &i; pi pointe sur i
    *pi = 2; initialisation valeur pointée par pi
  Op additifs
    si p pointe sur une case m de tableau, p+N pointe su la case N+m
  Parcourir string
    for (p = &mess[0]; *p != ’\0’; p++) {ici p repère l’élément courant de mess}
  Parcourir tableau
    int *pdeb,*pfin,*p;
    pdeb = &t[0]; pfin = &t[N-1];
    for (p = pdeb; p <= pfin; p++){}
  Difference pointers
    Can be used only for two pointers on the same array
    Return smth of type ptrdiff_t coming from <stddef.h>
  Null -> for chained lists
   NULL Defined in stddef.h


---------------- Input utilisateur
  scanf ( format , liste-d’expressions ) ;
    scanf("%d %x",&i,&j);
    put an int in i and an hexadecimal in j
    retourne EOF si tout s est bien déroulé sinon le nombre de variables qu elle a pu affecter
  char c; c = getc(stdin);
  char tampon[11];
  fgets(tampon, 11, stdi%n);
  uint32_t n = atoi(tampon);

---------------- Ecriture dans un fichier
  static void log_message(FILE *stream, const char *message){fputs(message, stream);}
  log_message(stdout, "Sortie standard\n");
  log_message(stderr, "Sortie erreur\n");
  fprintf(stderr, "Aussi sur sortie erreur") //Affiche immédiatement, pas de mise en buffer
  FILE *f = fopen("nom_fichier.txt", "w");
  log_message(f, "Dans un fichier")

  ./prgm > file.txt //Rediriger la sortie standard
  ./prgm 2> file.txt //Rediriger la sortie erreur

---------------- Utilisation fichier ext
  File descriptor: low-level integer used to identify an opened file
  FILE pointer: C standard library-level construct, wraping the file descriptor, and adding buffering and other features to make I/O easier.
  #include <stdio.h>
  FILE *f = fopen("nom_fichier", mode) // return type pointeur vers FILE def dans <stdio.h>, return NULL en cas d'erreur
  "r" lecture
    le fichier doit exister
    fgetc("nom_fichier") //renvoie le prochian caractère, sinon EOF
    fseek(f, 9, SEEK_SET); //se place au 9eme char depuis le debut
      SEEK_CUR /* depuis le current */ SEEK_END /* Depuis la fin */
    fgets(ĉ, taille, "nom_fichier") //ĉ pointe vers tableau char, taille en octets du tableau de caractere
    cf p.89
  "w" ecriture
    crée fichier si existe pas sinon overwrite
    fputc(carac, "nom_fichier") //carac de type int, rend carac si ok sinon EOF
  "a" ecriture à la fin
    crée fichier si existe pas sinon ajoute à la fin
  fclose("nom_fichier") //rend 0 si ok sinon EOF
  fprintf("nom_fichier", "%d: y en a %d", param1, param2)
  voi p.100
  traitement automatisé
    int fscanf(FILE *stream, const char *format, ...)
    fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);

--------------------------------------------
---------------- Structures ----------------
--------------------------------------------
  Déclaration
    struct personne{ //Déclare la structure
      char prenom[20];
      char nom[20];
      int no_employe;
    }; // } p1, p2; Pour créer var en plus
    struct personne p1, p2; //déclare deux variables de type struct personne
    struct personne p={"Jean", "Dupont", 7483}
  Accès
    p.nom -> "Dupont"
    p.nom[0] -> "D"
    p1 = p3 //p1 reçoit infos p3
  Tableaux
    struct personne t[100];
    t[i].nom
  Pointeurs
    struct personne *p;
    struct personne pers;
    p = &pers;
    p->nom //= (*p).nom, Pour avoir el nom de p (priotité . > *)
  Structure chaînée
    struct personne{
      /*   les différents membres   */
      struct personne *suivant;
    };
  Allocation memoire
    struct cellule *liste = malloc(sizeof(struct cellule)); // #include <stdlib.h>
  Champ de bits
    struct sr {
      unsigned int trace : 2;
      unsigned int priv : 2;
      unsigned int : 1;
      unsigned int masque : 3;
    };
    On ne peut déclarer que des signed int, unsigned int, int. Vaut mieux préciser pour savoir ce qui se passe



---------------------------------------------
------------------- Union -------------------
---------------------------------------------
  Comme les structures sauf que un seul champ peut être renseigné à la fois
    union nombre{
      int i;
      float f;
    }
  Affectation valeur
    nombre.i = 10;
    nombre.f = 3.14159


----------------------------------------------
------------------- Random -------------------
----------------------------------------------
#include <time.h>
srand(time(NULL));	// init du générateur de nombres aléatoires
rand() //Donne nb entre 0 et 10^9



----------------------------------------------
---------------- Multi-thread ----------------
----------------------------------------------
fork()
  Creates a new process which is the duplicate of the caller
  Returns the current pid as a pid_t
    -1 -> error
    0 -> son process
    other -> parent process
pipe()
  connection between two processes, such that the standard output from one process becomes the standard input of the other process
  must be used on int fd[2];
  write in fd[1], read in fd[0]
  son uses fd[1] to send info to parent with fd[0]
close()
  close one side of the pipe
  classically, son closes fd[0] and parent fd[1]
dup2() // unistd.h
  duplicates a file descriptor
  dup2(fd[1], 1) -> make fd[1] become the standard output
  dup2(1, 2) -> redirects stderr to stdout
special file descriptors:
  0: stdin
  1: stdout
  2: stderr
  
execvp()
  executes another program
  execvp(const char* program_name, const char** args)



---------------- Indentation automatique
  indent -linux mystere.c


-----------------------------------------------
------------------ Compiling ------------------
-----------------------------------------------
  Plusieurs fichiers
    clang -c file.c //A faire sur tous fichiers -> genere file.o
    clang file_1.o file_2.o -o final_file //Compile ensemble
  Inclure library
    clang -Wall -Wextra -std=c99 compile-toi.c -o compile-toi -lm//Nom librairie en question
  Options de compilation
    -D option1 //dans la ligne de compilation
    #ifdef V1 \n act1 \n #elif defined(V2) \n act2 \n #else \n act3 \n #endif
    -D BIEN_COMPRIS=43
    #if BIEN_COMPRIS >= 42 \n act1

---------------- Makefile

  MAKE
    CC=clang
    CFLAGS=-Wall -Wextra -std=c99 -g
    LDFLAGS=-lm

    all: compile-toi

    compile-toi: compile-toi.c
     $(CC) $(CFLAGS) compile-toi.c -o compile-toi $(LDFLAGS)

    .PHONY: clean
    clean:
     rm -rf compile-toi *.o *~

---------------- Include list
#include <stdio.h> // printf
#include <math.h> // mathematic functinos
typedef uint8_t grey_scale_t;
perror("texte explicatif");









typedef V
daddy-cool V
idef V
bingo V
divfloat
profiler
debogage-exo2
stdtruc
speed
sdl
morse
makemorse
concatenation
debogage-trace
jedi
debogage-exo6
contact
quicksort
debogage-exo8
bigbucks
void
slab
debogage-exo4
