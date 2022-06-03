/* ========================================================== */
/* ======================= VARIABLES ======================== */
/* ========================================================== */
int myNum = 5; // 4 bytes
float myFloatNum = 1.99, sci = 35e3; // 4 bytes
double myDoubleNum = 5.99, sci = 12E4; // 8 bytes
char myLetter = 'D'; // 1 byte
    like C, can be seen as ASCII: char a = 65;
uchar byte = 'a'; // 1 byte
string myText = "Hello";
    #include <string>
bool myBoolean = true; // 1 byte
    when printed gives 1 and 0
const int a = 1; // constant variable
constexpr int a = 1; // variable or function to be evaluated at compile time
auto //makes type inference

/* ========================================================== */
/* ======================= OPERATIONS ======================= */
/* ========================================================== */
Like C
&&, ||, ! // boolean opeartors
&, | //bitwise operators
max(x, y); min(x, y); // basic functions
sqrt(), round(), log(), abs(), cos(), pow(), sin(), log()/*ln*/, log10() // #include <cmath>
ceilf(fl) == fl // tests if float fl is an integer

/* ========================================================== */
/* ========================= STRING ========================= */
/* ========================================================== */
c++ string type different than char*
// char* to string
    string string_value(char_value);
// string to char*
    char char_value[string_value.length()+1];
    strcpy(char_value, string_value.c_str()); 
// string to int
    string str = stoi(integer)
stra + strb                         // concatenation
stra.append(strb)                   // concatenation
stra.length(); stra.size();         // length
str[a];                             // for access or modification
std::count(s.begin(), s.end(), '_');// count occurences of _ (include <algorithm>)
std::cout << std::string(100, '*')  // print char n times

/* ========================================================== */
/* ======================= CONDITIONS ======================= */
/* ========================================================== */
if, switch like C
condition? espression: expression;
switch(variable)
{
    case value1:
        /* do smth without declaration */
        break;
    case value2: /* FALLTHROUGH */
    case value3:
    {
        /* do smth with declarations */
    }
        break;
    default: break;
}

/* ========================================================== */
/* ========================= LOOPS ========================== */
/* ========================================================== */
for, while like C
for into vector
	int v[] = {0,1,2,3,4,5,6,7,8,9};
	for (auto x : v)

/* ========================================================== */
/* ========================= ARRAY ========================== */
/* ========================================================== */
/* Classical C arrays */
int array[5] = {0, 1, 2, 3, 4}
int array[5] = {4, 5}// can omit elements
for (auto elem: array){ /* Go through array */}

list<int> my_list = {0, 1, 2}; /* Double linked list */
my_list.size();
my_list.frony(); my_list.back(); /* Fisrt and last elements */
my_list.push_front(); my_list.push_back(); /* Push new elt at the beginning or the end */
my_list.pop_front(); my_list.pop_back(); /* Pop elt at the beginning or the end */


/* ========================================================== */
/* ========================= VECTOR ========================= */
/* ========================================================== */
#include <vector>
using namespace std;                // elements contiguous in memory
vector<int> int_vector = {1, 2, 3}; // Creates a vector containing integers
vector<int> uniform_vector(5, 10);  // Creates a vector of 5 elements set to 10
std::vector<int> dest(src, src + n);// vector from array (n size)
int_vector.push_back(4);            // Append at the end
for(const auto& value: v) {         // Iterate with classic for
    std::cout << value << "\n";
}
for(auto it = std::begin(v); it != std::end(v); ++it) {     // Iterate with iterator
    std::cout << *it << "\n";
}
/* Useful functions */
/* In <iterator> */
std::inserter(v)                    // Generates an insert iterator, when assigning object into the iterator, they are added
std::back_inserter(v)               // Generates a back_insert_iterator, same but reversed
/* In <algorithm> */
std::fill_n(v.begin(), 3, -1)       // Fills the n 1st elements with the given value
std::generate_n(v.begin(), 3, f)    // (f returns value with v elem type) Generates a new value with f for the n 1st elems
std::transform(s1.begin(), s1.end(), s2.begin(), f) // applies f to elems of s1 and put result in s2
std::max_element(std::begin(a), std::end(a)); // ??
std::accumulate(vector.begin(), vector.end(), 0); //??
std::find(v.begin(), v.end(), val)  // Retunrs iterator to elem if found else iterator to last
std::find_if(v.begin(), v.end(), f) // Same but for elem that respects f
std::sort(s.begin(), s.end(), f)    // Sort the lis with the comparing function f
std::count(s.begin(), s.end(), val) // count nb of values equal to val
std::count_if(s.begin(), s.end(), f)// count nb of values that respects f
/* In <functional> */
auto f1 = std::bind(f, std::placeholders::_2, 42, std::placeholders::_1) // f1(n, m) == f(m, 42, n)


/* ========================================================== */
/* ========================= TUPLE ========================== */
/* ========================================================== */
tuple<double, char, std::string> my_tuple;              // Creation
my_tuple = std::make_tuple(3.8, 'A', "Lisa Simpson");   // Set
double val = std::get<0>(my_tuple)


/* ========================================================== */
/* ======================== OPTION ========================== */
/* ========================================================== */
/!\ C++17
#include <optional>
using namespace std;
optional<int> fn(bool a){
    if (a) {return 2;}                  // 1st way to return
    else {return nullopt; return{};}
    return b? 2: nullopt;               // 2nd way to return
}
int main(){
    if (int a = fn(true)){
        cout << a;
    }
}

//boost
#include <boost/optional.hpp>
boost::optional<int> optionnal_int = 1;
boost::optional<int> optionnal_int = boost::none;
if (boost::optional<int> oi = getOptionnalInt())
    cout << "There is an int: " << oi;
  else
    cout << "There is no int";
/* ========================================================== */
/* ======================== REFERENCE ======================= */
/* ========================================================== */
int& r = x; //binds r to x
unary & in declaration. Similar to pointer but doesnt need * to access the value
Useful in function arguments -> use it instead of pointers because easier 
	void sort(vector<double>& v); //we assure that this is not a copy of the vec that is sorted
Always initialized, no null handling -> doesnt permit to go through arrays like pointer


/* ========================================================== */
/* ======================== POINTERS ======================== */
/* ========================================================== */
Null pointer: nullptr
	tests: if (p==nullptr)

/* ========================================================== */
/* ========================= PRINT ========================== */
/* ========================================================== */
cout << "Hello World!\n";
cout << endl // break line
cout << "I am " << myAge << " years old."; // concatenation
#include <iostream>
using namespace std;

/* ========================================================== */
/* ========================= INPUT ========================== */
/* ========================================================== */
int x;
cin >> x;

/* ========================================================== */
/* ======================== FUNCTIONS ======================= */
/* ========================================================== */
void function(string country="Sweden"){} // default parameters
inline functions
inline int fn(int a) {/* function code */}
instruction to the compiler not to place the instructions at another address in the memory,
so the execution wont need to follow 2 address redirections, avoiding time consuming operations
compared to the execution time of small funcions body
compiler may not perform inlining if loop, static variables, recursive, return statement, switch, goto 

/* ========================================================== */
/* ======================== NAMESPACE ======================= */
/* ========================================================== */
space to define variables and functions that belong together
    namespace my_namespace {int a = 5}
	int b = my_namespace::a


/* ========================================================== */
/* ========================== MAIN ========================== */
/* ========================================================== */
int main(int argc, char *argv[]){}
Must have exactly one main


/* ========================================================== */
/* ========================= STRUCT ========================= */
/* ========================================================== */
a struct is a class with members public by default
struct Parameter { //declaration
    string id;
    string type;
};
struct Parameter param {"language", "fr"} //initialization
string id = Parameter.id;
union -> struct which can have only one parameter initialized (so it has the sized of the
bigger element)
variant -> safer to use than an union
    variant<Node*, int> v;
    if (holds_alternative<int>(v) {cout << get<int>(v); }
    try {
      std::get<float>(w); // w contains int, not float: will throw
    }
    catch (const std::bad_variant_access& ex) {
        std::cout << ex.what() << '\n';
    }
/* For the members to be continuous in memory
 * Useful to save memory or when data must be in specific place (protocols) */
#pragma pack(push, 1) // for other compilers
typedef struct __attribute__((packed)) // for gcc
{
    int32_t a;
    int8_t b;
    int16_t c;
    int8_t d;
} date_time_t;
#pragma pop

/* ========================================================== */
/* ========================== CLASS ========================= */
/* ========================================================== */
//classic example
class complex {
    double re, im; // representation: two doubles
    public:
        complex(double r, double i) :re{r}, im{i} {}    // construct complex from two scalars
        complex(double r) :re{r}, im{0} {}              // construct complex from one scalar
        complex() :re{0}, im{0} {}                      // default complex: {0,0}
                                                        // call it without ()
            
        double real() const { return re; }
        void real(double d) { re=d; }
        double imag() const { return im; }
        void imag(double d) { im=d; }

        complex& operator+=(complex z){ //operators overloading
            re+=z.re;         // add to re and im
            im+=z.im;
            return *this;     // and return the result
        }
        complex& operator−=(complex z){
            re−=z.re;
            im−=z.im;
            return *this;
        }}
        complex& operator*=(complex);    // defined out-of-class somewhere
        complex& operator/=(complex);    // defined out-of-class somewhere
};
complex a {2.3};       // construct {2.3, 0.0}
complex b {1/a};       // construct {1/2.3, 0.0}

//slightly more difficult example
class Vector {
    public:
        Vector(int s): elem{new double[s]}, sz{s}{     // constructor: acquire resources
            for (int i=0; i!=s; ++i)                   // initialize elements
                    elem[i]=0;
        }
        Vector(std::initializer_list<double> lst)      // initialize with a list
            :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
        {
            copy(lst.begin(),lst.end(),elem);
        }        // e.g. Vector v1 = {1,2,3,4,5}; 
        void push_back(double);                        // add element at end, increasing the size by one
        Vector read(istream& is){
            Vector v;
            for (double d; is>>d;)        // read floating-point values into d
                v.push_back(d);           // add d to v
            return v;
        }
        ~Vector() { delete[] elem; }                   // destructor: release resources

        double& operator[](int i);
        int size() const;
    private:
        double* elem;     // elem points to an array of sz doubles
        int sz;
};
Vector v(3);

//abstract class an instanciation example
class Container {
public:
     virtual double& operator[](int) = 0;     // pure virtual function
     virtual int size() const = 0;            // const member function (§4.2.1)
     virtual ~Container() {}                  // destructor (§4.2.2)
};
class Vector_container : public Container {   // Vector_container implements Container
public:
     Vector_container(int s) : v(s) { }   // Vector of s elements
     ~Vector_container() {}

     double& operator[](int i) override { return v[i]; }
     int size() const override { return v.size(); }
private:
     Vector v;
};
user-defined type to represent a concept in a program
constructor
    complex(double r, double i) :re{r}, im{i} {/* body of the constructor */} 
    // fields must be initialized before the body of the constructor
    a constructor with no arguments is the default constructor -> assure there won t be
    uninitialized instances of the class
methods
    inlined by default
    virtual fn(){}                  // like abstract in Java
    virtual int size() const = 0;   // =0 indicates pure virtual function, so must be redefined
        a class with only virtual methods is a pure interface
        a class with at least a pure virtual function is an abstract class

// test if a class isfrom a particular subtype
Shape* ps {read_shape(cin)};
if (Smiley* p = dynamic_cast<Smiley*>(ps)) {/* ... a Smiley; use it */}
else {/* not a Smiley, try something else */}
dynamic_cast returns null_ptr if it cant perform the cast

// special operations
class X {
public:
     X(Sometype);            // 'ordinary constructor': create an object
     X();                    // default constructor
     X(const X&);            // copy constructor
     X(X&&);                 // move constructor
     X& operator=(const X&); // copy assignment: clean up target and copy
     X& operator=(X&&);      // move assignment: clean up target and move
     ~X();                   // destructor: clean up
     // ...
};

// copy
initializes an object using another object of the same class
ClassName (const ClassName &old_obj); 
    Point(int x1, int y1) { x = x1; y = y1; }       // normal
    Point(const Point &p1) {x = p1.x; y = p1.y; }   // copy
    Point p1(10, 15);                               // Call of normal
    Point p2 = p1;                                  // Call of copy
if we dont define one, its defined by the compiler, the default copy-constructor only shallowcopy
    Vector::Vector(const Vector& a)                 // suitable copy constructor for a vector
        :elem{new double[a.sz]},
        sz{a.sz}
    {
         for (int i=0; i!=sz; ++i)
           elem[i] = a.elem[i];
    }
    Vector& Vector::operator=(const Vector& a)      // need to have a copy assignement
    {                                               // with the constructor
        double* p = new double[a.sz];
        for (int i=0; i!=a.sz; ++i)
            p[i] = a.elem[i];
        delete[] elem;         // delete old elements
        elem = p;
        sz = a.sz;
        return *this;
    }

// move
creates a new pointer pointing to the object passed in argument
used when a large object risk to be copied a lot, to allow it to be moved
ClassName(ClassName&& obj): data{ obj.data } {}
    Object(int d){
        data = new int;
        *data = d;
    }
    Object(Object&& source): data{ source.data } {}


class Y {
public:
     Y(Sometype);
     Y(const Y&) = default;   // I really do want the default copy constructor
     Y(Y&&) = default;        // and the default move constructor
     Y(const Y&) = delete;    // I really don't want a copy constructor
     Y(Y&&) = delete;         // I really don't want a move constructor
}

// conversions
when making a constructor taking an only argument, it kind of perform a conversion from the argument
type to the user-defined type.
This conversion is implicit, when we dont want to we use 
    explicit Vector(int s)
    Vector v1(7);           // OK: v1 has 7 elements
    Vector v2 = 7;          // error: no implicit conversion from int to Vector


/* ========================================================== */
/* ======================== THREADS ========================= */
/* ========================================================== */
Make main thread wait for worker thread to finish an operation
    mutex m;
    bool ready = false;
    condition_variable cv;
    void worker_thread(){
        std::unique_lock<std::mutex> lk(m);
        // makes work for which main is waiting
        ready = true;
        lk.unlock();
        cv.notify_one();
    }
    int main(){
        thread worker(worker_thread);
        {
            unique_lock<mutex> lk(m);
            cv.wait(lk, []{return ready;});
            ready = false;
        }
        // at this point we're assured the work is done in the other thread
    }
Make thread sleep
#include <thread>
this_thread.sleep_for(chrono::seconds(1))


/* ========================================================== */
/* ====================== DATE & HOUR ======================= */
/* ========================================================== */
Unix
- date                                  // get the current system date&hour
- ntpdate <ip_server>                   // auto update date&hour with ntp server
- sudo setcap CAP_SYS_TIME+ep <file>    // allow binary to change date&hour
- sudo date +%T -s "11:14:00"           // change hour
- date +%Y%m%d -s "20211220"            // change date
C++
struct tm tm{}; //store date and time info in c++
    //https://www.cplusplus.com/reference/ctime/tm/
// parses a date with given format and stores its info in tm
// stores in ret what's left after parsing, or nullptr if an error occurs
char* ret = strptime(const char* date_to_parse, const char* format, struct tm* tm)
// takes date info from tm and stores them into date_parsed according to format
// returns the number of bytes written, or 0 if maxsize is reached before creating the entire string
size_t written = strftime(char* date_parsed, size_t maxsize, const char* format, struct tm* tm)


/* ========================================================== */
/* ========================== CAST ========================== */
/* ========================================================== */
static_cast<int>(other_value);
to_string(i); //int to string
to_string(f); //float to string
stoi(s) //string to int


/* ========================================================== */
/* ========================= REGEX ========================== */
/* ========================================================== */
#include <regex>
regex my_regex("FRQ([0-9]{5}\\.[0-9]{3})");
string analysed_str = "FRQ12000.000";
smatch value_captured;
if (regex_match(analysed_str, value_captured, my_regex)){
    value_captured.size();      // nb of elems that have been captured +1 (first elem is whole str)
    value_captured[1].str();    // 12000.000
}

/* ========================================================== */
/* ================== INSCTRUCTIONS COMPILO ================= */
/* ========================================================== */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
    fonctions avec params non utilisés
#pragma GCC diagnostic pop



/* ========================================================== */
/* ===================== ABSTRACT TYPES ===================== */
/* ========================================================== */
Concrete types: their attributes are part of the def
Abstract types: you dont know the attributes and you dont need to know
about the implementation details, you only use the exposed methods 



/* ========================================================== */
/* ======================== KEYWORDS ======================== */
/* ========================================================== */
static
outside of a class: tells the compiler the variable should be only considered for this file,
and must not be imported when include


/* ========================================================== */
/* ====================== COMPILATION ======================= */
/* ========================================================== */
g++ program.cpp -o program


/* ========================================================== */
/* ======================== INCLUDE ========================= */
/* ========================================================== */
#include "file_to_include.h"


/* ========================================================== */
/* ======================= EXCEPTIONS ======================= */
/* ========================================================== */
#include <stdexcept>
throw std::invalid_argument("received inexistant hour mode");
list: https://en.cppreference.com/w/cpp/error/exception







Des questions si il sait pas bah ça se trouve en 2 sec
2: Bien
3: C'est la 1
4: pointeurs pas con
5: patron de conception ???

7: très classique
8: question avec ensemble de tests pas la plus simple à debug
9: copi de structy
13: deja posée
16: vachement longue (stocks)
17: un peu moins longue mais short par rapport au temps dispo

Plus de temps, moins de code à faire, surtout en C où un petit code peut vite demander beaucoup de dvp (langage avec peu d outils)
Pas fan en général, parce qu on est là pour bien coder, pas pour le faire le plus vite possible
Bien sûr en parmer à la fin pour voir ce qu iel en a pensé

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

const int NB_PODIUM = 3;

char** get_top_stocks(int nbstocks, char stocks[nbstocks][257], int nbdays, float prices[nbdays][nbstocks], int* top_count)
{
    // Write your code here
    // To debug: fprintf(stderr, "Debug messages...\n");'
    float total_prices[nbstocks];
    for (int i = 0; i<nbstocks; i++)
    {
        float total_price = 0;
        for (int j = 0; j < nbdays; j++)
        {
            total_price += prices[j][i];
        }
        total_prices[i] = total_price;
    }

    float best_prices[NB_PODIUM];
    int best_ids[NB_PODIUM];
    for (int i = 0; i<NB_PODIUM; i++){
        best_prices[i] = total_prices[0]*1000;
        best_ids[i] = 0;
    }

    for (int i = 0; i<nbstocks; i++)
    {
        float cur_price = total_prices[i];
        if (cur_price< best_prices[0]){
            best_prices[2] = best_prices[1];
            best_prices[1] = best_prices[0];
            best_prices[0] = cur_price;
            best_ids[2] = best_ids[1];
            best_ids[1] = best_ids[0];
            best_ids[0] = i;
        } else if (cur_price< best_prices[1]){
            best_prices[2] = best_prices[1];
            best_prices[1] = cur_price;
            best_ids[2] = best_ids[1];
            best_ids[1] = i;
        } else if (cur_price< best_prices[2]){
            best_prices[2] = cur_price;
            best_ids[2] = i;
        }
    }

    char best_stocks[NB_PODIUM][257];
    for (int i = 0; i<NB_PODIUM; i++)
    {
        strcpy(best_stocks[i], stocks[best_ids[i]]);
    }
    return ((char**)best_stocks);
}

/* Ignore and do not change the code below */
#pragma region
int main()
{
    int nbstocks;
    scanf("%d", &nbstocks);
    int nbdays;
    scanf("%d", &nbdays); fgetc(stdin);
    char stocks[nbstocks][257];
    for (int i = 0; i < nbstocks; i++)
    {
        scanf("%[^\n]", stocks[i]); fgetc(stdin);
    }
    float prices[nbdays][nbstocks];
    for (int i = 0; i < nbdays; i++)
    {
        for (int j = 0; j < nbstocks; j++)
        {
            scanf("%f", &prices[i][j]);
        }
    }
    int top_count;
    int std_out_fd = dup(1);
    dup2(2, 1);
    char** top = get_top_stocks(nbstocks, stocks, nbdays, prices, &top_count);
    dup2(std_out_fd, 1);
    for (int i = 0; i < top_count; i++)
    {
        printf("%s\n", top[i]);
    }

    return 0;
}
#pragma endregion
