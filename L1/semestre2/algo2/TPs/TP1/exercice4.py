#########TP1 exercice 4
'''Module qui crypte
Fonction:
 - crypte(txt, perm)

'''
__author__ = 'Antoine-Alexis Bourdon <antoine-alexis_bourdon@ens.univ-artois.fr'
__date__= '18/01/2018'

def crypte(txt, perm):
	'''fonction qui crypte le texte txt à l'aide du dictionnaire de permutation creer dans l'exercice3 (ici perm).
	Arguments:
		txt :-- str
		perm : --dict(str : str)
	Retour:
		txt_retour : --str
	'''
	txt_retour=''
	#txt_def2=[]
	#j=0
	for i in txt:
		txt_retour+=perm[i]
	#for i in txt_def:
	#	txt_def2.append(perm[i])
	return txt_retour

