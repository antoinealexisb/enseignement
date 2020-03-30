#####TP2 exercice1

__author__ = 'Antoine-Alexis BOURDON <antoine-alexis_bourdon@ens.univ-artois.fr'
__date__ = '01/08/2018'


###classe Voiture
class Voiture :
	'''Voiture
	'''
	def __init__(self, color, name):
		'''Constructeur pour création voiture avec la couleurn nom et vitesse
		Arguments:
			Voiture(modif)
			color : --str
			name : --str
		Retour:
			None
		'''
		self.__couleur = color
		self.__nom = name
		self.__vitesse = 0

	def accelere(self,inc):
		'''augmente la vitesse de la voiture limité à 130 km/h
		Argument :
			Voiture(modif)
			inc : --int
		Retour:
			None
		'''
		if inc <= 10 :
			self.__vitesse += inc
			if self.__vitesse > 130:
				self.__vitesse = 130

	def freine(self, dec):
		'''diminue la vitesse de la voiture 
		Argument :
			Voiture(modif)
			dec : --int
		Retour:
			None
		'''
	        self.__vitesse -= dec
	        if self.__vitesse < 0:
        		self.__vitesse = 0

	def str(self):
		'''retourne une chaine de caractère
		Argument:
			Voiture
		Retour
			: --str
		'''
		return "Nom : " + self.__nom + "\nCouleur : " + self.__couleur + "\nVitesse : " + self.__vitesse

	def affiche(self):
		'''affiche sur la console toutes les indications utiles sur la voiture.
		Argument :
			Voiture
		Retour :
			None
		'''
		print(self.str())


########## test unitaire dans console ..., script principal console ...
