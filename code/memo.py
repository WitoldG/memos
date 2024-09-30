###############################
############# INT #############
###############################
sys.maxint 

####################################
############# STRINGS ##############
####################################

string.lower() # lower-case string
string.upper() # upper-case string
string.capitalize() # first letter in upper case
string.strip() # take off spaces at the beginning and end of the string
stirng.replace('a', 'b') # replaces substring in string
title = "introduction"
title.upper().center(20) '    INTRODUCTION    '

for num_indice,element in enumerate (l):
for elt in enumerate l #Renvoie des tuples avec indice et contenu

ma_string = "Bonjour à tous"
ma_string.split(" ")
['Bonjour', 'à', 'tous']

ma_liste = ['Bonjour', 'à', 'tous']
" ".join(ma_liste)
'Bonjour à tous'

prenom = "Paul"
nom = "Dupont"
age = 21
print("Je m'appelle {0} {1} et j'ai {2} ans.".format(prenom, nom, age))
Je m'appelle Paul Dupont et j'ai 21 ans.

r"test" # means that the string is to be treated as a raw string, which means all escape codes will be ignored
raw_string = "%r"%normal_string # transformation during execution

####################################
############## LISTES ##############
####################################

presentation[:2] # Du début jusqu'à la troisième lettre non comprise
'sa'
presentation[2:] # De la troisième lettre (comprise) à la fin
'lut'

ma_liste = ['a', 'b', 'd', 'e']
ma_liste.insert(2, 'c') # On insère 'c' à l'indice 2

ma_liste.index(2) #Donne la position de 2

ma_liste1 = [3, 4, 5]
ma_liste2 = [8, 9, 10]
ma_liste1.extend(ma_liste2) # On insère ma_liste2 à la fin de ma_liste1
print(ma_liste1)
[3, 4, 5, 8, 9, 10]
ma_liste1 = [3, 4, 5]
ma_liste1 + ma_liste2
[3, 4, 5, 8, 9, 10]

[a, b, c, d, e, f, g, h]
       |_______2:______|
|__:2__|
|_______:-2______|
                 |__-2:_|

l=[1,2,3,4]
del(l[0])
l=[2,3,4]
l.remove(3)
l=[2,4]

def fonction_inconnue(nom, prenom, *commentaires): #Filer nb indéfini d'arguments

l = [1, 4, 9, 16, 25, 36]
print(*l)
1 4 9 16 25 36

###############################################
###############  DICTIONNARIES  ###############
###############################################

# Creation
my_dict = dict()
my_dict = {}
my_dict = eval("{'a': 1, 'b': 2, 'c': 3}") # from a string

# Add values
monDictionnaire["pseudo"] = "Wain5542"
monDictionnaire[0] = "a"
monDictionnaire["a", 1] = "tour blanche"
placard = {"chemise":3, "pantalon":6, "tee-shirt":7}


# Deletion
del placard["chemise"]
placard.pop("chemise") # Delete the value and retrun it

# Go through a dictionnary
fruits = {"pommes":21, "melons":3, "poires":31}
for a in fruits: # Loops through keys
for a in fruit.keys(): # Loops through keys
for a in fruits.values: # Loops through values

keys = list(dict.keys()) # Get keys as list
key in dictionnary # Test existence of a key in the dict

####################################
############ CONDITIONS ############
####################################
locical operators
&: and, |: or, !: not;

####################################
############## CLASS ###############
####################################
class MyClass:
    # attributes
    i=12
    # methods
    def f(self, other)
    # instanciation
    a = MyClass(intiation, parameters)
    a.f(other)

    # special methods
    def __init__(self): ; # constructor
    def __add__(self, other): ; # +
    def __sub__(self, other): ; # -
    def __mul__(self, other): ; # *
    def __floordiv__(self, other): ; # //
    def __div__(self, other): ; # /
    def __mod__(self, other): ; # %
    def __pow__(self, other[, modulo]): ; # **
    def __lshift__(self, other): ; # <<
    def __rshift__(self, other): ; # >>
    def __and__(self, other): ; # and
    def __xor__(self, other): ; # xor
    def __or__(self, other): ; # or
    def __iadd__(self, other): ; # +=, add i to all the other to make += version
    def __neg__(self): ; # -
    def __pos__(self): ; # +
    def __abs__(self): ; # abs()
    def __invert__(self): ; # ~
    def __complex__(self): ; # complex()
    def __int__(self): ; # int()
    def __long__(self): ; # long()
    def __float__(self): ; # float()
    def __oct__(self): ; # oct()
    def __hex__(self): ; # hex()
    def __lt__(self, other): ; # <
    def __le__(self, other): ; # <=
    def __eq__(self, other): ; # ==
    def __ne__(self, other): ; # !=
    def __ge__(self, other): ; # >=
    def __gt__(self, other): ; # >

####################################
############ EXECUTION #############
####################################
def main():
    print("Hello World!")

if __name__== "__main__":
    main()

#arguments
p a.py arg1 arg2 arg3
-> in the list sys.argv

####################################
########## FILE HANDLING ###########
####################################
file = open(path, mode)
file.close()

# Reading: only with 'r' mode
file.read() # returns the whole file
file.readline() # returns a line
file.read(n) # returns the n first char
for line in file:
    print (line) # go through lines

# Writing: 'a' put the pointer at the end, 'w' erase file content
file.write('something to write') # returns where is the cursor after writing

# Create a new file
'x': will create a file, returns an error if it exists
'r', 'a': creates the file if it doesnt exists

# Other
os.path.getsize(filepath) # Give number of characters
file.tell() # Say where is the cursor
fh.seek(-7, 1)


####################################
############## IMPORT ##############
####################################
from other_file import MyClass # from file in the same dir

# from another folder, with project being in 2-depth sub-folder
project_root = "/".join(os.path.abspath(__file__).split("/")[:-2])+"/"
data_treatment_folder = project_root + "/data_treatment/"
sys.path.append(project_root)
sys.path.append(data_treatment_folder)


####################################
############### JSON ###############
####################################

import json
# Parse json string into a dictionnary
person_dict = json.loads('{"name": "Bob", "languages": ["English", "Fench"]}')
    # Quotes should always be double
# Convert dictionary inton JSON string
person_json = json.dumps({'name': 'Bob', 'age': 12, 'children': None})
# Read json (returns dictionary)
f = open('path/file.json', 'r')
data = json.load(f)
# Write in json
f = open('path/file.json', 'w')
json.dump(dict, f)
# Pretty print
print(json.dumps(person_dict, indent = 4, sort_keys=True))

####################################
############## OTHER ###############
####################################

folder_content = os.system("ls") # Execute system commands
