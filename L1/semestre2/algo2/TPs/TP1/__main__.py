#### main.py ###



'''Module principal

Fichiers :
- exercice3.py
- exercice4.py
- exercice5.py
- exercice6.py
- exercice7.py
- __init__.py
- __main__.py

'''

__author__ = 'Antoine-Alexis Bourdon <antoine-alexis_bourdon@ens.univ-artois.fr>'
__date__ = '18 janvier 2018'


#Modules :
import exercice3
import exercice4
import exercice5
import exercice6
import exercice7

#Variable:
dico={}

#Fonction principale:
def main():
	'''Fonction principale.
	Arguments:
		None.
	Retour:
		None.
	'''
	# Tant que l'utilisateur ne choisi pas de quitter:
	quitter = False
	while not quitter:
		option = exercice7.affiche_menu()

		if option == 1:
			exercice7.afficher_les_codes(dico)

		elif option == 2:
			exercice7.ajouter_un_code(dico)

		elif option == 3:
			exercice7.crypter_un_texte(dico)

		elif option == 4:
			exercice7.decrypter_un_texte(dico)

		elif option == 0:
			print('Bye')
			quitter = True

#Appel à la fonction principale.
if __name__ == '__main__':
	main()
