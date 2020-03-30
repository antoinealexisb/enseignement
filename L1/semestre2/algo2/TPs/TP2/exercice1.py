###########TP"2 exercice1

__author__ = 'Antoine-Alexis BOURDON <antoine-alexis_bourdon@ens.univ-artois.fr>'
__date__ = '01/08/2018'

###Class
class CompteBancaire :
	'''Classe qui permet d'instancier des objets tels que compte1, compte2, etc.
	'''
	def __init__(self,name, solde=1000):
		'''Constructeur pour compte
		Arguments :
			CompteBancaire(modif)
			name : --str
			sole : --int
		Retour :
			None.
		'''
		self.__nom = name
		self.__solde = solde

	def depot(self,somme):
		'''permet d'ajouter une certaine somme au solde.
		Argument :
			CompteBancaire(modif)
			somme : --int
		Retour :
			None
		'''
		if somme > 0 :
			self.__solde += somme

	def retrait(self,somme):
		'''permet de retirer une certaine somme du solde.
		Argument :
			CompteBancaire(modif)
			somme : --int
		Retour :
			None
		'''
		if somme > 0:
			if somme<=self.__solde:
				self.__solde -= somme

	def affiche(self):
		print("Le solde du compte bancaire de", self.__nom," est de", self.__solde," euros.")



def main():
	'''Fonction principale.
	Argument :
		None.
	Retour :
		None.
	'''
	###########TEST##########
	compte1 = CompteBancaire('Michu', 800)
	compte1.depot(350)
	compte1.affiche()
	compte1.retrait(25)
	compte1.affiche()


if __name__ == "__main__" :
	main()
########## programme principal à venir
