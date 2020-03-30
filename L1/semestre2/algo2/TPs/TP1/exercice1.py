###TP1 exercice 1###

'''On s’intéresse à la gestion d’un grand magasin.
 On dispose de deux structures :
- l’une donne le prix unitaire de chaque article
- l’autre le nombre d’articles en rayon.

Fonctions:
 - information_stocks(stocks, prix)
 - info_depts(depts, prix)
 - index_articles(depts)
'''
__author__ = 'Antoine-Alexis Bourdon <antoine-alexis_bourdon@ens.univ-artois.fr>'
__date__= '18/01/2018'

# Variables :
lesPrix = {'perç̧euse':60,'ampoule':3.5,'clous':1.99,'vis':2.20}
leStock = {'perç̧euse':15,'ampoule':75,'vis':300,'clous':400}
lesDepts = {'quincaillerie':leStock,'outillage':{'perç̧euse':5,'visseuse':8}}

def information_stocks(stocks,prix):
	'''fonction qui retourne, à partir des prix et du nombres d'articles en rayon, trois information :
	- le montant de marchandises en rayon;
	- le nombre total d'articles en rayon;
	- le prix moyen d'un article.
	Arguments:
		stock : -- dict(str:float)
		prix : -- dict(str:int)
	retour:
		montal_total : --float(tuple)
		total_objet : --float(tuple)
		prix_moyen : --float(tuple)
	'''
	total_objet=0
	montant_total=0

	for i in list(stocks.values()):
		total_objet+=i

	for i in list(stocks.keys()):
		if i not in list(prix.keys()):
			prix[i]=1
		montant_total+=(prix[i]*stocks[i])

	prix_moyen=montant_total/total_objet

	return montant_total, total_objet, prix_moyen

def info_depts(depts,prix):
	'''fontion qui retourne les trois informations de la fonction informations_stocks
	Arguments:
		depts : --dict(str : TStocks)
	Retour:
		retour_dict : --dict(str: tuple)
	'''
	retour_dict={}
	for i in list(depts.keys()):
		retour_dict[i]=information_stocks(depts[i],prix)
	return retour_dict

def index_articles(depts):
	''' fonction qui retourne, pour chaque article, les départements dans lesquels ont peut le trouver
	Argument:
		depts : --dict(str : TStocks)
	Retour:
		retour_dict : --dict(str : liste)
	'''
	retour_dict={}
	interieur=[]
	for i in list(depts.keys()):
		for j in list(depts[i].keys()):
			if j in list(retour_dict.keys()):
				interieur=retour_dict[j]
			interieur.append(i)
			retour_dict[j]=interieur
			interieur=[]
	return retour_dict
