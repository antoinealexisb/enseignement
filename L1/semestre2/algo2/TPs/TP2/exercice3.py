### TP2 exercice 3 ###
__author__='Antoine-Alexis Bourdon <antoine-alexis@ens.univ-artois.fr>'
__date__='01/02/2018'

##Module:
from random import *

##Variables:
PointCarte = {"7":0,"8":0,"9":0,"10":10,"Valet":2,"Dame":3,"Roi":4,"As":11}
PointCarteAtout = {"7":0,"8":0,"9":14,"10":4,"Valet":20,"Dame":0,"Roi":2,"As":4}

##Constante:
COULEUR = ["Trèfle","Carreau","Coeur","Piqure"]

###Class Carte:
class Carte:
	'''Classe pour la construction des cartes de belote.'''
	def __init__(self, couleur, hauteur, atout = False):
		'''constructeur pour la classe carte
		Arguments:
			Carte(modif).
			couleur : --str.
			hauteur : --str.
			atout : --boolean.
		Retour :
			None.
		'''
		self.__couleur = couleur
		self.__hauteur = hauteur
		self.__atout = atout

	def affiche(self):
		'''Méthode pour afficher une carte.
		Argument :
			Carte
		Retour :
			None.
		'''
		print(self.str())

	def str(self):
		'''Méthode qui retourne la hauteur et la couleur de la carte.
		Argument :
			Carte
		Retour :
			Carte(hauteur / couleur) : --str
		'''
		return str(self.__hauteur) + " de " + str(self.__couleur)

	def couleur(self):
		'''Méthode qui retourne la couleur de la carte.
		Argument :
			Carte
		Retour :
			Carte(couleur) --str
		'''
		return self.__couleur

	def hauteur(self):
		'''Méthode qui retourne la hauteur de la carte.
		Argument :
			Carte
		Retour :
			Carte(hauteur) --str
		'''
		return self.__hauteur

	def estAtout(self):
		'''Méthode qui indique si la carte est un atout
		Argument :
			Carte
		Retour :
			Carte(atout) --str
		'''
		return self.__atout

	def nbrePoints(self):
		'''Méthode  qui retourne le nombre de point de la carte.
		Argument :
			Carte
		Retour :
			Carte(hauteur) : --int
		'''
		if self.__atout:
			return PointCarteAtout[self.__hauteur]
		return PointCarte[self.__hauteur]

	def est_plus_grand(self, carte):
		'''Méthode qui teste si une carte est plus grand qu'une autre.
		Argument :
			Carte
		Retour :
			boolean
		'''
		return self.nbrePoints() > carte.nbrePoints()


	def est_egal(self, carte):
		'''Méthode qui teste si une carteest égal à une autre.
		Argument :
			Carte
		Retour :
			boolean
		'''
		return self.nbrePoints() == carte.nbrePoints()


def affiche_jeu(liste):
	'''affiche la liste des cartes.
	Argument :
		liste --list
	retour :
		None
	'''
	retour = "["
	for lis in liste:
		retour += lis.str() + ","
	retour += "]"
	print(retour)


def creer_jeu_de_belote():
	'''fonction qui crée un jeu de cartes pour la belote.
	Atout aléa.
	Argument :
		None.
	Retour :
		liste : --list
	'''
	liste = []
	for couleur in COULEUR:
		for hauteur in PointCarte.keys():
			atout = randint(0,1)
			liste.append(Carte(couleur,hauteur, atout == 1))
	return liste


def main():
	'''Fonction principale
	Argument :
		None
	Retour :
		None
	'''
	print('''
	   ############################
	   # Programme Principal TEST #
	   ############################
	''')
	belote = creer_jeu_de_belote()
	print('''
	   #######################
	   #     Affiche Jeu     #
	   #######################
	''')
	affiche_jeu(belote)
	print('''
	    ######################
	    #   belote[7].str()  #
	    ######################
	''')
	print(belote[7].str())
	print('''
            ####################### 
            #   belote[15].str()  #
            #######################  
        ''')

	print(belote[15].str())
	print('''
            ############################# 
            #  [15].est_egal(belote[7]) #
            #############################  
        ''')

	print(belote[15].est_egal(belote[7]))


if __name__ == '__main__':
	main()
