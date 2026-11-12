OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        VARIABLES
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
// toutes les variables sont constantes par défaut, sinon utiliser mut
let i = 0; //constante
let mut i = 0; //mutable

types
let i: i32 = 0;
let i = 0i32;
"i8, i16, i32, i6, i128"; //entier signé de n bits
"u8, u16, u32, u6, u128"; //entier non-signé de n bits
"isize, usize"; //size = 32 sur syst 32 bits et 64 sur 64 bits
"f32, f64"; //flottant de n bits
"String, slice";

let _i = 0; //ne produit pas de warning si inutilisée

// option
let number: Option<i32> = Some(7); //an optionnal value, can be Some(n) or None;

// concatenation
format!("Hello {} from {}", var1, var2); // method 1
let mut owned_string: String = "hello ".to_owned(); // method 2
let another_owned_string: String = "world".to_owned();
owned_string.push_str(&another_owned_string);

//global
Outside of a code block, static keyword, type and value given;
static glob: i32 = 30;

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        VECTORS / ARRAYS
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
creation
let v1 = vec![1, 2, 3]; //[1, 2, 3]
let v2 = vec![1; 3]; //[1, 1, 1]
let v3 = &[0, 1, 2];
let mut v4: Vec<u8> = Vec::new();
v4.push(0); v4.push(1); v4.push(2);
let v5: Vec<_> = (1..21).collect();

display
println!("v = {:?}", v);

access
v[0]
v.last() // -> Option(dernier_elem)

go through
for x in &vec {
    *x //to get value
}

v.iter() //creates iterator on vector
v.len() //get length -> returns usize

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        SLICES
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
represent a part of an array
let tab = &[0, 1, 2];
let slice = &tab[1..]; //slice pointe sur [1, 2]
let slice = &v;
let slice = &v[1..];
fn remise_a_zero(tranche: &mut [i32]) { //donner en param
slice.chunk(3); //creates an iterator over slices that re this slices cuted each 3 elements

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        ITERATORS
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
v.iter() //creates iterator on vector
c.chars() //creates iterator on a chain
v.par_iter() // same with parallel iterator
v.iter_mut() //to be able to modify v
z = v1.iter().zip(v2.iter()); //zip 2 iterators together
for (x,y) in z{};
same = repeat_with(|| 1); //endless iterator applying closure each time
iterator::Item; //get type of objects on the iterator

// map
i.map() //transform an iterator
i.map(|x| x+1)
    //|x| -> how should be interpreted the elements
    //x+1 -> expression to apply to each element
let mut c = 0;
i = ['a', 'b', 'c']
i.map(|letter| { c += 1; (letter, c) })
i = [('a', 1), ('b', 2), ('c', 3)]
i.map(f) //compute f on each elem

// fold
i.fold(initial_value, closure)
// for every value in iterator apply closure on this value and an accumulated value
let a = [1, 2, 3];
let sum = a.iter().fold(0, |acc, x| acc + x);
// 0+1 then 1+2 then 3+3
// first parameter is accumulated value, 2nd is given by iterator
// function intrinsically sequential

// reduce
i.reduce(closure)
// like fold but without initial value
// can work in parallel
// use reduce::Reduce

other
i.all(|x| *x == 21) //return boolean saying wether it's respected for all the elements
i.take(10) //creates a new iterator with the 10 first values of i
i.rev() //reverse order of iterator
i.filter(|&e| e % 2 == 0) //creates new iterator with elts that respects closure
i = once(value); //iterator that yields value once
i.enumerate() //creates iterator that yields on tuples (index, value)

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        CONDITIONS
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO;
match my_string {
    "bonjour" => {println!("français");}
    "ciao" => {println!("italien");}
    "hello" => {println!("anglais");}
    "hola" => {println!("espagnol");}
    _ => {println!("je ne connais pas cette langue...");}
}
// can be used on any type of variable
match age {
    17 => {println!("mineur !");}
    18 => {println!("majeur !");}
    x => {println!("ni 17, ni 18 mais {} !", x);}
}
match age {
    tmp if tmp > 60 => {println!("plus tout jeune...");}
    tmp if tmp > 17 => {println!("majeur !");}
    _ => {println!("mineur !");}
}
let s = match i {
    x @ 10..=100 => "{} est entre 9 et 101",
    x => "{} n'est pas entre 9 et 101",
};
//used on options
let x = match thing_with_option {
    Some(x) => x,
    None => error_handling(),
}

let number: Option<i32> = Some(7);
if let Some(s) = number{ //si number est un some et pas un none
    println!("Matched: {}", s);
}
let mut v = vec!(1, 2, 3);

while let Some(x) = v.pop() {
    println!("{}", x);
}

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        LOOPS
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
// like in C, no need for () around the cdt but {} mandatory for instructions
// instruction loop <=> while true

// for fonctionne avec des objets implementant le trait IntoIterator
for i in 0..10 {} //0 inclus 10 exclus
let v = vec!(1, 4, 5, 10, 6);
for value in v {println!("{}", value);}
for (i, j) in (12..17).enumerate() {} //i count, j valeurs

'global: for _ in 0..10 {
    'outer: for x in 0..10 {
        'inner: for y in 0..10 {
            if x > 3 { break 'global; } // on arrête la boucle qui s'appelle global
            if x % 2 == 0 { continue 'outer; } // on continue la boucle sur x
            if y % 2 == 0 { continue 'inner; } // on continue la boucle sur y
            println!("x: {}, y: {}", x, y);
        }
    }
}

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        FUNCTIONS
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
// closure
// |x, y, z| x+y*z
// like lambda in python, used in map, fold...

fn addition(nb1: i32, nb2: i32) -> i32{
    nb1 + nb2 //evalué comme une expression, équivaut à un return
}

//precise args traits
fn reduce<T, ID, OP>(entree: &[T], identity: ID, op: OP) -> T
where
    T: Copy + Send + Sync,
    ID: Fn() -> T + Sync,
    OP: Fn(T, T) -> T + Sync,
{
	reduce_rec(entree, &identity, &op)
}
fonction!(); // c'est une macro
fonction(); // c'est une fonction

// uselful macros
println!();
panic!("Erreur critique"); //Fait quitter le prog immediatement

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        ENUM
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
enum IPKind {
    IPV4(u8, u8, u8, u8),
    IPV6(u32, u32, u32, u32),
}
IPKind::IPV4(0,0,0,0);

enum Color {
    Red,
    Green,
    Blue,
}
Color::Blue;

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        STRUCT
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
// declaration
struct Point {
    x: f64, //attribut privé
    pub y: f64, //attribut public
    color: Option<Couleur>,
}
// instanciation
let p1 = Point {
    x: 0.0,
    y: 0.0,
    color: Some(Couleur::Rouge),
};
// methods
impl Point{
    pub fn new_with_pos(cur_x, cur_y) -> Point {
        Point{
            x: cur_x,
            y: cur_y,
            color: None,
        }
    }
    pub fn get_x(&self){self.x} //methode non-statique pusique self en premier argument
    fn distance_a(&self, autre: &Self) -> f64 {}

}
destructuration
match origin {
    Point { x, y } => println!("({},{})", x, y),
}

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        TRAITS
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
// creation
trait Animal {
    fn get_espece(&self) -> &str;
}

// example
struct Chien {
    nom: String,
}
impl Animal for Chien {
    fn get_espece(&self) -> &str {
        "Chien"
    }
    fn get_nom(&self) -> &str {
        &self.nom
    }

// make printable
impl std::fmt::Display for Movement{}

// Fn: function
// FnMut: function borrowing mutable object
// FnOnce: function that can be called only once
// Send: authorize the variable to change thread
// Sync: authorize passing by reference between threads
// Copy: when do x = y, x is copied into y and you can still use x;
// IndexedParallelIterator:
// ParallelIterator: don't know number of each element

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        SPECIFIC METHODS
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

println!("{1} {0} {2}", "à", "Bonjour", "tous !"); //peut donner l'ordre des args
println!("{:.3}", nombre_decimal); //affiche 3 chiffres après la virguke
println!("{:b}", nombre); // affiche le nombre en binaire
println!("{:o}", nombre); // affiche le nombre en octal (base 8)
println!("{:x}", nombre); // affiche le nombre en "petit" hexadecimal (base 16)
println!("{:X}", nombre); // affiche le nombre en "grand" hexadecimal (base 16)
println!("{:08}", nombre);  // affiche le nombre avec 6 chiffres (complète par des 0)

format!("{}", entier); //fonctionne comme print mais renvoie la string

//cast
1.to_string(); //string to int
"1".parse::<i32>().unwrap(); //int to string
u64::from(nb), //u16 to u64
true as i32; //bool to int

random
extern crate rand;
use rand::Rng
use rand::random
let mut rng = rand::thread_rng();
let n1: u8 = rng.gen();
let n2 = rng.gen::<u8>;
let n3 = random::<u8>(); //3 ways to randomly generate an u8
rand::random::<u32>()%(big-little+1)+little;

math
nb.powi(2);
nb.sqrt();

unsafe{code;}
    Dereference a raw pointer
    Call an unsafe function or method
    Access or modify a mutable static variable
    Implement an unsafe trait
    Access fields of unions

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        ERRORS
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
use std::fs::File;
let mut fichier = match File::open("fichier.txt") {
    Ok(f) => {f} // ouverture du fichier s'est bien déroulée, on renvoie l'objet
    Err(e) => {println!("{}", e);return;}
};

// Throwing errors
panic!("Error explication") //unrecoverable error

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        FILE
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
match File::open("fichier.txt") {
    Ok(fichier) => {
        // le fichier existe et on a les droits d'accès, on peut s'en servir !
    }
    Err(e) => {
        // le fichier n'existe pas ou on n'a pas les droits d'accès, on ne peut rien faire...
        println!("Erreur en tentant d'ouvrir le fichier : {:?}", e);
    }
}

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        INCLUDE / IMPORT
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
to use a struct stored in file.rs
-> lib.rs (same dir as main)
	pub mod file;
-> main.rs
	use file::struct;

use a function from another file
//if file.rs in the same dir as main
pub mod file;
use file::function;
//if file.rs is in dir/
create mod.rs in dir/
    mod file;
in main.rs
    pub mod dir;
    use dir::file::function;

OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        CARGO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
project creation: cargo new nom_projet
compile: cargo build > ./target/build/nom_projet
    cargo build --release //pas en mode debug
compile + run: cargo run
    with arguments: cargo run arg; cargo run --bin name_bin arg
only run: ./target/debug/nom_projet
    with arguments: ./target/debug/nom_projet arg

dépendances
si dispo sur crates.io
    [dependencies]
    gtk = "0.3.0" //plein de pattern disponibles pour choisir les versions
sinon
    [dependencies.gtk]
    git = "https://github.com/gtk-rs/gtk" //sur git
    path = "chemin/vers/gtk"//dl en local

utilisation dans le programme
    dans le fichier principal : extern crate time;
    utiliser la fonction : time::now();
    imports time::Tm;


OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
        MAIN
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
fn main(){}
get command-line arguments:
    use std::env::args;
    let args = match args() => Vec<Option<String>>
    let arg_1 = match args().nth(1){
        Some(x) => x,
        None => "nothing",
    };








difference expression / assignation "https://blog.guillaume-gomez.fr/Rust/1/9"
let str : String = "lol".to_owned(); //transform string litteral into String
print à paramètre
println!("Premier param : {}, deuxième param : {}", a, b);
selection dans un tableau
tabl[:?] donne tout



&mut [u32]: tranche mutable
