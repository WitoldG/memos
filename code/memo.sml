(* Declarations *)
    (* can be used at top level or in a let, not in a function *)
val my_int = 1200
val my_int = 1200: int      (* Can specify the type but not mandatory *)
val my_neg = ~10            (* Unary min is ~ *)
val my_str = "hello"
val my_char = #"a"
val my_bool = true

(* Operators *)
val real_division = 14.0 / 4.0  (* -> 3.5 *)
val int_division  = 14 div 4    (* euclidean -> 3 *)
val int_remainder = 14 mod 4    (* remainder -> 2 *)
val pow = a
val bool_and = b1 andalso b2    (* && *)
val bool_or = b1 orelse b2      (* || *)
val bool_not = not(b1)          (* ! *)

val equality = (i1 = i2)        (* == *)
val difference = (i1 <> i2)     (* != *)


----------------------------------
----------- References -----------
----------------------------------
(* Variables that can be modified *)
val x = ref 42
!x + 1 (* dereference of x to use it *)
val x = ref 43 (* dont modify it *)
x := 5 (* to really modify the reference *)
(* If var def by ref in top level, it handles like a globalbariable (all functions can use and modify the ref) *)

(c := c+1; !c) evalue les expressions à la suite et a pour valeur la valeur de la dernière expressions

(* Allow to declare static args like in java *)
val counter =
let
  val c = ref 0
in
  fn () => (c := !c+1; !c)
end
(* when counter is called, it returns the next int
It's a closure: a funciton with its specific environnment *)
fun counter () =
let
  val c = ref 0
in
  fn () => (c := !c+1; !c)
end
(* counter() returns a function being itself a counter, so we can create multiple counters *)
fun counter () =
let
  val c = ref 0
in
  (fn() => c := 0, fn() => (c := !c+1; !c))
end
(* returns a couple (reset, incr) of functions *)

----------------------------------
-------- Structure/Module --------
----------------------------------
(* definition *)
structure M =
  struct
    type t = int
    val x = 42
  end

(* acces *)
val y : M.t = 52

(* signature *)
(* type of a structure *)
signature S =
sig
  type t = int
  val x: T
end

structure N: S = (* N:S to say that a structure respects a signature *)
struct           (* In this case S replaces the structural type *)
  type t = int   (* It works the same as the types *)
  val x = 42
end
(* if N defines an argument not in S it will be considered as private when the others are public *)

(* Abstract types *)
(* when :> used, if the type is not defined in the sig it will be abstract, so not known at the exterior *)
structure Image :>
  sig
    type t
    val get: int -> t
  end
= struct
type t = ...
end

structure Image_grey :> Image_sig where type pixel = int
(* concretise le type *)
(* pas forcement concretisation mais peut juste donner l'info que 2 types sont egaux *)
foncteur: fonction sur les modules


----------------------------------
------------- Functor ------------
----------------------------------
functor Strings_Array (structure S: String_Lattice
                       structure I: Abstract_Lattice) : Strings_Array_Lattice =
struct
end

----------------------------------
-------------- List --------------
----------------------------------
datatype 'a list = (* List definition in sml *)
    Nil
  | Cons of 'a * 'a list
val li = Cons (1, Cons (2, Cons (3, Nil)))  (* possible declaration of a array *)
val numbers = [1, 3, 3, 7, 229, 230, 248]   (* Actual array creation *)
val elem = List.nth (numbers, 2) (* numbers[2] *)
val names = [ "Fred", "Jane", "Alice" ]     
val groups = [ [ "Alice", "Bob" ],          (* list of lists *)
               [ "Huey", "Dewey", "Zoe" ],
               [ "Bonnie", "Clyde" ] ]
1 :: 2 :: []; -> [1, 2]                     (* append *)
val guest_list = [ "Mom", "Dad" ] @ [ "Aunt", "Uncle" ]     (* append an entire list *)
val number_char_count = String.size numbers (* length *)
(* Tuples -> cantype contain a fixed number of different things *)
val person1 = ("Simon", 28, 3.14159)

fun map f list = 
  case list of
    Nil => Nil
  | Cons (x, xs) => Cons (f x, map f xs)
fun map f list =
  case list of  
    [] => []
  | x :: xs => f x :: map f xs  
fun fold f neutral list =
  case list of
  Nil => neutral
  | Cons (x, xs) => f x (fold f neutral xs)

----------------------------------
------------- Arrays -------------
----------------------------------
SML lists are chained lists
SML arrays are nomral lists

val a = Array.fromList[1,2,3]    declaration
Array.sub(a, 1)   == a[1]
Array.update(a, 2, 42)    == a[2] = 42    
acces en temps constant mais O(n) pour ajouter elem. List -> ajout en temps constant mais acces en O(n)



https://smlfamily.github.io/Basis/array.html

----------------------------------
------------- Tuples -------------
----------------------------------
(* Fixed length ,types can differ *)
val i =(1 * true * "yes")
#1 i -> 1

----------------------------------
------------- Record -------------
----------------------------------
(* Definition *)
type person = {name : string, age : int}
(* Instanciation *)
val x = {age=42, name="John"} (* gives an object of type {name : string, age : int} because it's a structural type *)
val x = {age=42, name="John"}: person (* if we want the label person on the type it must be explicitely precised *)

(* Function *)
fun bonjour (person: person) =
    case person of
        {age = x, name = n} => "Bonjour " ^ n ^ " qui a " ^ Int.toString x ^ " ans"
fun age (person : person) =
  case person of
    {age = x, ...} => x (* must not precise the full record *)

(* type definit un alias sur le nom du type, si on a 2 types de la même structure ils vont fonctionner pareil *)
(* les record peuvent être utilisés directement dans la signature d'une fonction pour créer une mini doc *)

----------------------------------
------------- String -------------
----------------------------------
val concatenation = "Hello " ^ "there, " ^ "fellow!\n"
val _ = print foo (* Not interested in the result *)

-----------------------------------
------------ Functions ------------
-----------------------------------
fun f x y = x+y     (* int -> int -> int *)
val carre = fn x => x * x
val f2 = f 5 (* Donne la fonction f2 y = y+5 *)
fun empty () = AllChar (* function with no arg -> give unit *)
(* anonyms functions *)
fn x => x * x
fn x => fn y => x * y (* with >=2 args *)
(* local declaration *)
fun fun_with_local_dec =
    let
        fun local_fun x = x+5
        val local_val
    in
        local_fun (local_val + 3)
    end

(* examples *)
fun fold_right f neutral list =
  case list of
  [] => neutral
  | x :: xs => f x (fold_right f neutral xs)
fun fold_left f neutral list = (* peut être terminal *)
  case list of
  [] => neutral
  | x :: xs => fold_left f (f neutral x) xs
fun append list1 list2 =
    case list1 of
      [] => list2
    | x :: xs => x :: (append xs list2)
fun rev_term list acc =
    case list of
    [] => acc
    | x :: xs => rev_term xs (x :: acc)

(* fonction recursive terminale *)
(* we do the operation in an acc var to make the call recursive terminal and not having to pile on the stack *)
fun length_acc list acc = 
  case list of
    [] => acc
  | _ :: xs => length_acc xs (acc + 1)
(* Retourne le résultat d'une opération non commutative notamment pour les constructions de listes 

*)



------------------------------------
------------ Conditions ------------
------------------------------------
if cdt
then instructions
else if cdt
then instructions
else
then instructions

------------------------------------
------------ Loop ------------
------------------------------------
while !x >= 0 (x := x-1)


-----------------------------------
-------------- Types --------------
-----------------------------------
datatype color = (* type sum *)
    Heart
  | Spade
  | Club
  | Diamond
datatype value = (* defines a new type, giving it constructors *)
    King
  | Queen
  | Jack
  | Number of int
type card = value*color (* use type when alias and not new type with new constructors *)
val king_of_heart = (K, Heart)
val nine_of_diamond = (N 9, Diamond)
fun is_red color = (* matching types *)
    case color of
        Heart => true
      | Diamond => true
      | _ => false
fun is_ace value =
    case value of
        N x => x = 1
      | _ => false
(* on 2 elems *)
case (color1, color2) of
    (Heart, Heart) => true
  | (Heart, _) => false
  | (_, Spade) => false
  | (_, _) => true
(* Option *)
datatype 'a option = (* declaration of option of unknown type *)
    NONE
  | SOME of 'a
fun map function opt = (* function applying a given function to an option if it's some *)
  case opt of
    SOME x => SOME (function x)
    | NONE => NONE


(* case *)
varaible/function -> zorro_le_grand_zorro (* snake case *)
    (* can begin by a maj, not like camel, but not recommended *)

-----------------------------------
-------------- Error --------------
-----------------------------------
raise Fail "error description" (* Most simple way *)
(* declare its own exception *)
exception GlbBottom of int (* can use of smth if needed *)
(* catch it *)
val x = f arg1 handle GlbBottom 1 => Top
                    | GlbBottom 2 => Bottom 
                    | GlbBottom _ => Top 


https://codeinterview.io/FWKDEVAWYI

include -> pour inclure une signature dans une autres
open -> exporte un module dans le code. permet d'inclure une structure (ses attributs et fonctions) dans une autre. peut être fait au milieu d'un let pour que les fonctions soient utilisables dans le in. à eviter au max après on sait plus d'où viennent les fonctions

(* declaration *)
exception Foo
(* levee *)
raise Foo
(* rattrapage *)
val f = (raise Foo; 51) handle Foo => 42