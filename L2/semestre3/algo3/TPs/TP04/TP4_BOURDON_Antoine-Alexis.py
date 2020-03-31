'''
BOURDON ANTOINE-ALEXIS
TP3 ALGO3
L2 2018-2019
'''

from random import *

class Point:
	'''Classe qui définit un point'''
	def __init__(self,li,col):
		self.__li=li
		self.__col=col

	def somme(self):
		''' retourne la somme de li+col
		Point -> int
		>>> p = Point(1,2)
		>>> p.somme()
		3'''
		return self.__li+self.__col

	def __str__(self):
		''' Point -> str
		>>> p = Point(1,2)
		>>> print(p)
		(1,2)'''
		return "("+str(self.__li)+","+str(self.__col)+")"

	def lig(self):
		''' Retourne la valeur de li
		Point -> int
		>>> p = Point(1,2)
		>>> p.li()
		1'''
		return self.__li

	def col(self):
		''' Retourne la valeur de col
		Point -> int
		>>> p = Point(1,2)
		>>> p.col()
		2'''
		return self.__col

	def coord(self):
		''' Retourne les coordonnées du Point
		Point -> int
		>>> p = Point(1,2)
		>>> p.coord()
		2'''
		return (self.__li,self.__col)



class Cluster:
	''' Classe qui définit un Cluster '''
	def __init__(self,k):
		self.__k=k
		self.__li=list()

	def __str__(self):
		''' Cluster -> str
		'''
		lp=''
		for i in self.__li:
			lp+=str(i.coord())
		return ' PointK:' + str(self.__k.coord()) + '\n Points:' + str(lp)
	
	def li(self):
		''' Retourne la valeur de li
		Cluster -> int
		>>> l = Cluster(1)
		>>> l.li()
		[]
		>>> l.ajouter(5)
		>>> l.li()
		[5] '''
		return self.__li

	def kpoint(self):
		''' retourne la valeur de k de cluster
		Cluster -> int
		>>> l = Cluster(1)
		>>> l.kpoint()
		1'''
		return self.__k

	def newk(self,k):
		''' Change le k du cluster
		Cluster(modif) -> None
		>>> l = Cluster(1)
		>>> l.kpoint()
		1
		>>> l.newk(5)
		>>> l.kpoint()
		5'''
		self.__k = k


	def ajouter(self,pts):
		''' Ajoute un point
		Cluster(modif) -> None
		>>> l = Cluster()
		>>> l.li()
		[]
		>>> l.ajouter(5)
		>>> l.li()
		[5]'''
		self.__li.append(pts)

	def cleanLi(self):
		''' Efface la liste de li
		Cluster(modif) -> None
		>>> l = Cluster(1)
		>>> l.li()
		[]
		>>> l.ajouter(5)
		>>> l.li()
	5
	>>> l.cleanLi()
		>>> l.li()
		[]'''
		self.__li = list()


def lKP():
	nbK=4
	liK=list()
	
	for i in range(0,nbK):
		liK.append(Point(randint(0,10),randint(0,10)))
		
	return liK



def lP():
	nbP=20
	liP=list()
	for i in range(0,nbP):
		liP.append(Point(randint(0,10),randint(0,10)))
	return liP



def creatCluster(LKP,LP):
	LCluster=list()
	for i in LKP:
		LCluster.append(Cluster(i))
	for i in range(len(LP)):
		a = LP[i].somme()
		dif = 10000
		for y in range(len(LCluster)):
			b = LKP[y].somme()
			if a > b :
				if ((a - b) <= dif) :
					dif = (a - b)
					c = y
			if b > a :
				if ((b - a) <= dif) :
					dif = (b - a)
					c = y
			if a == b:
				dif = (b - a)
				c = y
		LCluster[c].ajouter(LP[i])
		

	return LCluster


def newCentre(lC,lP):
	kp=list()
	newkp=list()
	for i in lC:
		x = 0
		y = 0
		kp.append(i.kpoint())
		for j in i.li():
			x += j.lig()
			y += j.col()
		if len(i.li()) == 0:
			newkp.append(i.kpoint())
		else:
			newkp.append(Point(x//len(i.li()),y//len(i.li())))
	liste = [kp,newkp]
	return (liste)


	
		
def main():
	'''Fonction principale
	'''
	terminer=False
	listeKPoint=lKP()	   
	listePoint=lP()
	listeCluster=creatCluster(listeKPoint,listePoint)
	while not terminer:
		li = newCentre(listeCluster,listePoint)	 
		for i in range(len(li[0])):
			if li[0][i].coord()!= li[1][i].coord():
				terminer = True
		listeCluster = []
		listeCluster = creatCluster(li[1],listePoint)
		for z in range(len(listeCluster)):
			print ('\n Cluster '+ str(z))
			print(listeCluster[z])
			
if __name__ == '__main__':
	main()
