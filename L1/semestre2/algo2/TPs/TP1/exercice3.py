####TP1 exercice 3

'''Module qui retourne dictionnaire de permuation
Fonction:
 - dictPerm()

'''
__author__ = 'Antoine-Alexis Bourdon <antoine-alexis_bourdon@ens.univ-artois.fr'
__date__= '18/01/2018'

#Importation string et l'exercice2
import string
import exercice2

def dictPerm():
	'''fontion qui fabrique et retourne un dictionnaire de pertumutation (tiré au hasard) pour les lettres majuscules.
	Argument:
		None
	Retour
		retour_dict : --dict(str, str)
	'''
	dict_retour={}
	lettre=string.printable
	lettre_def=[]
	lettre_def2=[]

	for i in lettre:
		lettre_def.append(i)
		lettre_def2.append(i)

	premier=exercice2.permute(lettre_def)
	deuxieme=exercice2.permute(lettre_def2)

	for i in range(len(premier)):
		dict_retour[premier[i]]=deuxieme[i]
	return dict_retour
