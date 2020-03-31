###Recurcivite_1

def suite_ar (n,a,r):
	'''Fonction calculant le dernier terme d'une suite arithmetique.
	
	int, int, int -> int'''

	if n == 0:
		return a

	else:
		return suite_ar(n-1,a,r)+r

def somme_suite (n,a,r):

	'''Fonction qui calcul la somme les premiers termes d'une suite arithmetique.
	
	int, int, int -> int'''

	if n == 0:
		return suite_ar(n,a,r)

	else:
		return somme_suite(n-1,a,r)+ suite_ar(n,a,r)



###Recurcivite_2

def pgcd_euclide (a,b):

	'''Fonction calculant le pgcd de deux entiers naturels
	
	int, int -> int'''

	if a%b == 0:
		return b

	else:
		return pgcd_euclide (b,a%b)


###Recurcivite_3

def inverse_chara (c, cmt):

	
	'''Fonction inversant une chaine de caractere
	
	str, int (longueur de la chaine - 1) -> int'''

	if cmt == 0:
		return c[0]

	else:
		return c[cmt] + inverse_chara(c, cmt-1)
	
###Recurcivite_4

def est_anagramme (m1, m2):

	'''Fonction qui renvoit un bool. si deux mots sont des anagrammes
	
	str, str -> bool'''

	if m1 == "" and m2 == "":
		return True

	elif m1 != "" and m1[0] in m2:
			return est_anagramme (m1.replace(m1[0],"",1),m2.replace(m1[0],"",1))

	else:
		return False


###Recurcivite_5


def puissance(nb,tab=''):
	'''Fonction qui retourne la notation binaire d'un entier naturel.
	int , str -> str
	'''
	if (nb == 0):
		return inverse_chara(tab,len(tab)-1)
	if (nb/2 - int(nb/2))>0 :
		tab+=str(1)
	else:
		tab+=str(0)
	return puissance(int(nb/2),tab)

#### Recurcivite_6

def nota_binaire(nb, var=0):
	'''Fonction qui retourne la notation decimal d'un binaire.
	int, str -> int
	'''
	if var != len(str(nb)):
		return int(str(nb)[var])*2**(len(str(nb))-(var+1)) + nota_binaire(nb, var+1)
	return 0

###Recurcivite_7

def palindrome(c):
	'''Fonction qui regarde si la chaine de caractère est un palindrome
	arg:
		c--str
	Retour:
		bool.
	'''
	if inverse_chara(c,len(c)-1) == c:
		return True
	return False
###Recurcivite_8

def fusion(l1,l2):
	"""Fusionne deux listes triées pour en former une nouvelle elle meme triée
	Arg :
		l1 -- list
		l2 -- list
	Retour :
		list"""
	j=0
	i=0
	l3=[]
	while i != len(l1) and j!=len(l2):
		if l1[i] > l2[j]:
			l3.append(l2[j])
			j+=1
		else:
			l3.append(l1[i]
			i+=1
	if == len(l1):
		for x in range(j,len(l2)):
			l3.append(l2[x]
	else:
		for x in range(i, len(l1)):
			l3.append(l1[x])
	return l3

##complex 1
def cherche_uni(liste):
	"""Retrouve la seule occurence qui est une fois dans la liste
		Arg: l -- list
		Retour : int"""
	i=0
	dico={}
	while( i <= len(liste)-1):
		if liste[i] not in dico:
			dico[liste[i]]=1
		else:
			dico[liste[i]]+=1
		i+=1
	for i in dico:
		if dico[i]==1:
			return print(i)

def intrus(liste):
	""" Methode prof"""
	n=liste[0]
	for i in range(1,len(liste)):
		n=n^liste(i)
	return n


##complex 2

def first(liste):
	"""Trouve la premiere occurence qui se repete dans une liste d entier
	Arg: l -- list
	Retour: int"""
	i=0
	dico={}
	while (i< len(liste)):
		if liste[i] not in dico:
			dico[liste[i]]=1
		else:
			return print(liste[i])
		i+=1


##Complex 3
def entier_intervalle(liste,nb1,nb2):
	'''Prend une liste d'entier et des intervalles pour vérifier si ils sont bien dans la liste
	liste--> Liste
	nb1--> int
	nb2--> int
	return bool'''
	for i in range (nb1,nb2+1):
		if i not in liste:
			return False
	return True


##complex 4

def triplet(liste):
	"""Trouve un 0 <= l[i] < l[j] < l[k] tel que i < j < k
	Arg: l -- list
	Return : i;j;k -- int"""
	n=len(liste)
	indice_max=[0]*n
	indice_min=[0]*n
	min_courant=liste[0]
	indice_min_courant=0
	max_courant=liste[n-1]
	indice_max_courant=n-1
	for i in range(n):
		if liste[i]<min_courant:
			min_courant=liste[i]
		indice_min[i]=indice_min_courant
	for i in range(n-1,-1,-1):
		if liste[i]>max_courant:
			max_courant=liste[i]
			indice_max_courant=i
		indice_max[i] = indice_max_courant

	for i in range(n):
		if indice_min[i]<i<indice_max[i]
			return (indice_min[i],i,indice_max[i])
	return -1
