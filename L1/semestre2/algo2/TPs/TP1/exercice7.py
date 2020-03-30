#####TP 1 exercice7
##BOURDON Antoine-Alexis L1MI
'''Module Menu Principal
Fonctions:
 - affiche_menu()
 - afficher_les_codes(dict_codes)
 - ajouter_un_code(dict_codes)
 - crypter_un_texte(dict_codes)
 - decrypter_un_texte(dict_codes)
'''
__author__ = 'Antoine-Alexis BOURDON <antoine-alexis_bourdon@ens.univ-artois.fr>'
__date__ = '24 janvier 2018'

#Modules:
import exercice3
import exercice4
import exercice5
import exercice6

def affiche_menu():
	'''affiche toutes les options du menu principal et
	retourne le choix de l’utilisateur.
	Argument:
		None
	Retour:
		- choix : int 
	'''
	choix="12"
	while choix not in ('0,1,2,3,4'):
		print('''
		1 : Liste des codes disponibles.
		2 : Creer un nouveau code.
		3 : Crypter un texte.
		4 : Decrypter un texte.
		0 : Quitter l’application.

		Votre choix : ''',end="")
		choix = str(input())
	return int(choix)


def afficher_les_codes(dict_codes):
	'''à partir d’un dictionnaire qui, à un
	nom, associe un code, affiche tous les codes disponibles.
	Argument:
		Dict
	Retour:
		None
	'''
	for nom in dict_codes.keys():
		print(nom, ':', dict_codes[nom])

def ajouter_un_code(dict_codes):
	'''qui prend en paramètre le dictionnaire de
	tous les codes et en créé un nouveau
	'''
	nom = input('Donnez le nom de votre nouveau code : ')
	while nom in dict_codes:
		nom = input('Donnez le nom de votre nouveau code : ')
	dict_codes[nom]=exercice3.dictPerm()


def crypter_un_texte(dict_codes):
	'''Fonction qui crypte le texte de l'utilisateur à l'aide du dictionnaire de permutation choisi.
        Argument:
                dict_codes : --dict(str : (str : str)).
        Retour:
                None.
	'''
	afficher_les_codes(dict_codes)
	dico_choix = input('Nom du code choisi : ')
	while dico_choix  not in dict_codes.keys():
		dico_choix = input('Nom du code choisi : ')
	texte_origine = input('Texte à crypter : ')
	print('Le texte crypté est : \n',exercice4.crypte(texte_origine, dict_codes[dico_choix]))

def decrypter_un_texte(dict_codes):
	'''Fonction qui décrypte le texte de l'utilisateur à l'aide du dictionnaire de permuattion choisi.
	Argument:
		dict_codes : --dict(str : (str : str)).
	Retour:
		None.
	'''
	afficher_les_codes(dict_codes)
	dico_choix = input('Nom du code choisi : ')
	while dico_choix not in dict_codes.keys():
		dico_choix = input('Nom du code choisi : ')
	texte_crypt = input('Texte à décrypter : ')
	print('Le texte décrypté est : \n',exercice6.decrypt(texte_crypt,dict_codes[dico_choix]))

