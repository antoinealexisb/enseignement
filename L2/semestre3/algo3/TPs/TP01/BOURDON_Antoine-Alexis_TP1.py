'''
TP1.py

Auteur: Antoine-Alexis Bourdon
Année : L2 - 2018/2019

'''

#importation des différents modules
import random
import time
from math import *

#Listes Simples
def deuxieme_plus_grand(liste):
	'''Fonction qui retourne le deuxieme plus grand éléments d'une liste
	Arguments:
		liste: list-- liste qui se fait parcourir
	Retour:
		int
	'''
	nombre1 =0
	nombre2 =0
	for i in range(len(liste)):
		if nombre1  < liste[i] :
			nombre2 = nombre1
			nombre1 = liste[i]
	return nombre2


def occurence(liste):
	'''Fonction qui retourne le premier element qui se repete
	Arguments:
		liste: list-- liste qui se fait parcourir
	Retour:
		int
	'''
	for i in range(len(liste)):
		for j in range(i+1,len(liste)):
			if liste[i] == liste[j]:
				return liste[i]


def negAvantPos(liste):
	'''Fonction qui tri les négatifs et positifs
	Arguments :
		liste(modif) : list-- liste qui se fait parcourir
	Retour :
		None.
	'''
	i=0;
	j=len(liste)-1
	while i<j:
		if liste[i] <0:
			i+=1
		elif liste[j]>0:
			j-=1
		else:
			liste[i],liste[j]=liste[j],liste[i]

def bidimensionnelle(matrice):
	'''Fonction imprimant les diagonales d'une matrice
	Arguments:
		matrice: list (list)-- la liste a parcourir
	Retour:
		None.
	'''
	i = 0
	for j in range (i,len(matrice)):
		ch =""
		tmp = i
		while j > i-1:
			ch += str(matrice[j][tmp])
			j -= 1
			tmp +=1
		print (ch)

	j = len(matrice)-1
	for i in range (1,len(matrice[0])):
		ch =""
		tmp = j
		while j > i-1:
			ch += str(matrice[tmp][i])
			i += 1
			tmp -=1 
		print (ch)





#Algo de tri
def triSelection(liste):
	'''Fonction cours
	'''
	for i in range(0, len(liste)-1):
		for j in range(i+1, len(liste)):
			if liste[i]>liste[j]:
				liste[i],liste[j] = liste[j],liste[i]


def triInsertion(liste):
	for i in range(1, len(liste)):
		m=liste[i]
		j=i-1
		while j>=0 and liste[j]>m:
			liste[j+1]=liste[j]
			j-=1
		liste[j+1]=m

def triBulles(liste):
	permute = True
	while permute:
		permute=False
		for i in range(len(liste)-1):
			if liste[i+1] < liste[i]:
				tmp = liste[i]
				liste[i],liste[i+1] = liste[i+1], liste[i]
				permute = True

def comparaison():
	'''
	fonction qui compare les 3 tris vu en cours, affiche leur temps.
	Meilleur tri : Insertion puis Bulles pour finir par Bulles.
	Arguments :
		-None
	Retour:
		-None
	'''
	#Le tri Selection est un tri non stable, les deux autres peuvent être stable
	tableau1 = random.sample(range(1,1000), 100) #nombre de 1-1000 , 100 nombres
	tableau2 = random.sample(range(1,10000), 1000) #1000 nombres
	tableau3 = random.sample(range(1,1000000), 100000) #100000 nombres

	#Tableau 1
	temps1_selec = time.time()
	triSelection(tableau1.copy())
	print("Pour le tableau 1 (100nombres) en tri Insertion nous sommes à ",time.time()-temps1_selec," secondes")

	temps1_inser = time.time()
	triInsertion(tableau1.copy())
	print("Pour le tableau 1 (100nombres) en tri Selection nous sommes à ",time.time()-temps1_inser," secondes")

	temps1_bulles = time.time()
	triBulles(tableau1.copy())
	print("Pour le tableau 1 (100nombres) en tri Bulles nous sommes à ", time.time()-temps1_bulles, " secondes\n")

	#Tableau 2
	temps1_selec = time.time()
	triSelection(tableau2.copy())
	print("Pour le tableau 2 (1000nombres) en tri Insertion nous sommes à ",time.time()-temps1_selec," secondes")

	temps1_inser = time.time()
	triInsertion(tableau2.copy())
	print("Pour le tableau 2 (1000nombres) en tri Selection nous sommes à ",time.time()-temps1_inser," secondes")

	temps1_bulles = time.time()
	triBulles(tableau2.copy())
	print("Pour le tableau 2 (1000nombres) en tri Bulles nous sommes à ", time.time()-temps1_bulles, " secondes\n")

	#Tableau 1
	temps1_selec = time.time()
	triSelection(tableau3.copy())
	print("Pour le tableau 3 (100000nombres) en tri Insertion nous sommes à ",time.time()-temps1_selec," secondes")

	temps1_inser = time.time()
	triInsertion(tableau3.copy())
	print("Pour le tableau 3 (100000nombres) en tri Selection nous sommes à ",time.time()-temps1_inser," secondes")

	temps1_bulles = time.time()
	triBulles(tableau3.copy())
	print("Pour le tableau 3 (100000nombres) en tri Bulles nous sommes à ", time.time()-temps1_bulles, " secondes\n")


class Point:
	'''
	Classe qui definit un point
	'''

	def __init__(self,abs, ord):
	
		self.__abs = abs
		self.__ord = ord

		
	def retour_abs(self):
	
		return self.__abs
		
	def retour_ord(self):
	
		return self.__ord
		
	def dist_origine(self):
			return sqrt((self.__abs**2)+(self.__obs**2))
		
def triBullepoint (liste):
	'''fonction qui tri les points :D '''
	permute = True
	while permute:
		permute = False
		for i in range(len(liste)-1):
			if liste[i+1].dist_origine() < liste [i].dist_origine():
				tmp = liste[i]
				liste[i],liste[i+1] = liste[i+1],liste[i]
				permute = True
				
def triSelectionpoint(liste):
	'''fonction qui tri les points :D '''
	for i in range(0, len(liste)-1):
		for j in range(i+1, len(liste)):
			if liste[i].dist_origine()> liste[j].dist_origine():
				liste[i],liste[j] = liste[j],liste[i]
