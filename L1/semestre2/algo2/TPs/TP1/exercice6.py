###########TP1 exercice6 #####
'''Module qui décrypte texte.
Fonction : 
 - decrypt(txt, perm)

'''


__author__ = 'Antoine-Alexis Bourdon <antoine-alexis_bourdon@ens.univ-artois.fr'
__date__= '18/01/2018'

#Importation modules exercie5, exercice6
import exercice5
import exercice4



def decrypt(txt, perm):
	'''fonction qui décrypte le txt qui a été crypter à l'aide dictionnaire de permutation perm
	Arguments:
		txt : --str
		perm : --dict(str : str )
	retour:
		retour : --str
	'''
	perm = exercice5.invertDict(perm)
	retour = exercice4.crypte(txt, perm)
	return retour
