###########TP1 exercice5 #######
'''Module qui renverse dictionnaire déjà renverser.
Fonction:
 - invertDict(perm)

'''

__author__ = 'Antoine-Alexis Bourdon <antoine-alexis_bourdon@ens.univ-artois.fr'
__date__= '18/01/2018'

def invertDict(perm):
	'''fonction qui renverse le dictionnaire.
	Argument:
		perm : --dict(str: str)
	Retour:
		dict_retour : --dict(str : str)
	'''
	dict_retour={}
	for i in list(perm.keys()):
		dict_retour[perm[i]]=i
	return dict_retour
