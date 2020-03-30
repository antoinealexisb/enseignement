####TP1 exo 2
'''Module qui échange sucessivement chaque élèment de la liste.
Fonctions:
 - permute(liste)

'''
__author__ = 'Antoine-Alexis Bourdon <antoine-alexis_bourdon@ens.univ-artois.fr'
__date__= '18/01/2018'

#Importation du module random
from random import *


def permute(liste):
	'''fonction qui échange successivement chaque élément de la liste avec un autre élèment de la liste choisi au hasard.
	Argument:
		liste(modif) :-- list
	Retour:
		liste :--list
	'''
	for i in range(len(liste)):
		nombre=randint(0,len(liste)-1)
		sauvegarde=liste[nombre]
		liste[nombre]=liste[i]
		liste[i]=sauvegarde
	return liste
