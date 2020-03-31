'''
BOURDON ANTOINE-ALEXIS
TP3 ALGO3
L2 2018-2019
'''

import time
import random

def fibonacci(n):
	'''Fonction calculant une suite de fibonacci de maniere recursive.
	
	int -> int'''
	if n<=1:
		return 1
	return fibonacci(n-1)+fibonacci(n-2)

def fibonacci_iteratif(n):
	'''Fonction calculant une suite de fibonacci de maniere interative.
	
	int -> int'''
	i=0
	# attention sur les sldes f(0) = 1 donc p =1
	p, q=1,1
	while i<n:
		p,q=q,p+q
		i=i+1
	return p

#attenion sur les slides f(0) = 1 donc p=1
def fibonacci_terminale(n,p=1,q=1):
	'''Fonction calculant une suite de fibonacci de maniere recursive terminale.
	
	int -> int'''
	if n==0:
		return p
	else :
		return fibonacci_terminale(n-1,q,p+q)

def comparaison_fibo(n):
	temp1 = time.time()
	fibonacci(n)
	print("Pour ",n," , la suite fibonacci recursive fait un temps de ",time.time()-temp1," secondes")

	temp1 = time.time()
	fibonacci_iteratif(n)
	print("Pour ",n," , la suite fibonacci itérative fait un temps de ",time.time()-temp1," secondes")

	temp1 = time.time()
	fibonacci_terminale(n)
	print("Pour ",n," , la suite fibonacci terminale fait ",time.time()-temp1," secondes")

##2

def fac_iterative(n):
	'''Fonction calculant le factoriel de n de maniere iterative.
	
	int -> int'''
	res=1
	for i in range(2, n+1):
		res=res*i
	return res

def fac_recursive(n):
	'''Fonction calculant le factoriel de n de maniere recursive.
	
	int -> int'''
	if n == 0:
		return 1
	else :
		return fact_recursive(n-1)*n
##3

def liste_recur(l,i=0,j=1):
	'''Fonction renvoyant la somme de l[i]l[j].
	
	int -> int'''
	if (i==len(l)-2) and (j==len(l)-1):
		return l[i]*l[j]
	elif (j==len(l)-1):
		return l[i]*l[j]+ liste_recur(l,i+1,i+2)
	else:
		return l[i]*l[j]+ liste_recur(l,i,j+1)

##4
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

##5


def fusion(l1,l2):
	'''Fonction la fusion de deux listes
	
	list, list -> list'''
	if l1==[]:
		return l2
	elif l2==[]:
		return l1
	elif l1[0]<l2[0]:
		return [l1[0]]+fusion(l1[1:],l2)
	else:
		return [l2[0]]+fusion(l1,l2[1:])

def fusion2(l1,l2,l3):
	'''Fonction fusionnant 3 listes triee
	list, list, list -> list'''
	if l1 == []:
		return fusion(l2,l3)
	elif l2 == []:
		return fusion(l1,l3)
	elif l3 == []:
		return fusion(l2,l1)
	elif l1[0]<l2[0] and l1[0]<l3[0]:
		return [l1[0]]+fusion2(l1[1:],l2,l3)
	elif l2[0]<l1[0] and l2[0]<l3[0]:
		return [l2[0]]+fusion2(l2[1:],l1,l3)
	else:
		return [l3[0]]+fusion2(l3[1:],l1,l2)


##6
def tri_insertion(tableau):
	for i in range(1,len(tableau)):
		en_cours = tableau[i]
		j = i
		#décalage des éléments du tableau }
		while j>0 and tableau[j-1]>en_cours:
			tableau[j]=tableau[j-1]
			j = j-1
			#on insère l'élément à sa place
		tableau[j]=en_cours
		
	

def fusion(gauche,droite):
	resultat = []
	index_gauche, index_droite = 0, 0
	while index_gauche < len(gauche) and index_droite < len(droite):		
		if gauche[index_gauche] <= droite[index_droite]:
			resultat.append(gauche[index_gauche])
			index_gauche += 1
		else:
			resultat.append(droite[index_droite])
			index_droite += 1
	if gauche:
		resultat.extend(gauche[index_gauche:])
	if droite:
		resultat.extend(droite[index_droite:])
	return resultat
	 
def tri_fusion(m):
	if len(m) <= 1:
		return m
	milieu = len(m) // 2
	gauche = m[:milieu]
	droite = m[milieu:]
	gauche = tri_fusion(gauche)
	droite = tri_fusion(droite)
	return list(fusion(gauche, droite))



def tri_rapide(tableau):
	if not tableau:
		return []
	else:
		pivot = tableau[-1]
		plus_petit = [x for x in tableau	 if x <  pivot]
		plus_grand = [x for x in tableau[:-1] if x >= pivot]
		return tri_rapide(plus_petit) + [pivot] + tri_rapide(plus_grand)

def generer_exo6(n,i,j):
	'''Fonction generant une liste de n valeur entre i et j
	int, int, int -> list'''
	return random.sample(range(i,j), n)

def comparaison_exo6(l):
	'''
	fonction qui compare les 3 tris vu en cours, affiche leur temps.
	Meilleur tri : 1e-rapide puis 2e-fusion pour finir par 3e-insection.
	Arguments :
		-None
	Retour:
		-None
	'''

	temps1_inser = time.time()
	tri_insertion(l.copy())
	print("Pour le tableau 1 en tri Insertion nous sommes à ",time.time()-temps1_inser," secondes")

	temps1_fusion = time.time()
	tri_fusion(l.copy())
	print("Pour le tableau 1 en tri fusion nous sommes à ",time.time()-temps1_fusion," secondes")

	temps1_rapide = time.time()
	tri_rapide(l.copy())
	print("Pour le tableau 1 en tri rapide nous sommes à ", time.time()-temps1_rapide, " secondes\n")

