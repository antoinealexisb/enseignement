###########TP"2 exercice1

__author__ = 'Antoine-Alexis BOURDON <antoine-alexis_bourdon@ens.univ-artois.fr>'
__date__ = '08/03/2018'

###Importation de Modules:
from tkinter import *
from string import *
from random import *

###classe 1
class VueMessage(object):
	"""classe qui créé une fenêtre graphique avec un message de bienvenue et un bouton
	pour quitter l'application.
	"""
		
		
	def __init__(self, fenetre):
		'''VueMessage, fontion -> VueMessage.
		construit l'interface graphique et la lance.
		'''
		self.__l1 = Label(fenetre,text="Bonjour à tous")
		self.__l1.pack()
		self.__b1 = Button(fenetre,text="Au revoir",command=fenetre.destroy)
		self.__b1.pack()

		
###classe2		
####EXERCICE 2 ####
class VueMessage2(object):
	"""Construit une fenetre qui dit bonjours à la personne qui aura donné son nom.."""
	
	
	def __init__(self, fenetre):
		"""VueMessage2, fonction -> VueMessage2.
		construit l'interface graphique avec les différents elèments qui sont : une 
		étiquette, une zone de saisie, deux boutons.
		"""
		self.__v1 = StringVar()
		self.__l1 = Label(fenetre,textvariable=self.__v1)
		self.__v1.set("Bonjour ")
		self.__l1.pack()
		self.__e1 = Entry(fenetre)
		self.__e1.pack()
		self.__f1 = Frame(fenetre)
		self.__f1.pack()
		self.__b1 = Button(self.__f1,text="Valider",command=self.valider)
		self.__b1.pack(side="left")
		self.__b2 = Button(self.__f1,text="Au revoir",command=fenetre.destroy)
		self.__b2.pack(side="right")

	def valider(self):
		"""
		VueMessage2(modif) -> None
		change le message de bienvenue en fonction du nom saisi.
		"""
		self.__v1.set("Bonjour " + self.__e1.get())

		
###EXERCICE 3 ####
def initialisationImages():
	""" None -> list().
	fonction met dans une liste le chemin vers les images d'alphabet.
	"""
	liste = list()
	for i in ascii_lowercase:
		source = "alphabet/"+i+".gif"
		liste.append(PhotoImage(file=source))
	return liste

	
###EXERCICE 4 5 6 ###
class VueAlphabet(object):
	"""Classe qui construit une fenetre avec les images placé de facon aléatoires de 
	dimension 5 x 5
	"""
	
	def __init__(self, fenetre):
		"""VueAlphabet, fonction -> VueAlphabet.
		construit l'interface graphique avec les différents elèments qui sont : des 
		étiquettes, deux boutons.
		"""
		fenetre.title("exercice 6")
		self.__images = initialisationImages()
		self.__f1 = Frame(fenetre)
		self.__f2 = Frame(fenetre)
		self.__f1.pack()
		self.__f2.pack()
		self.__labels = []

		for i in range(5):
			self.__labels.append([])
			for j in range(5):
				photo = self.__images[randint(0,len(self.__images)-1)]
				self.__labels[i].append(Label(self.__f1,image=photo))
				self.__labels[i][j].image = photo
				self.__labels[i][j].grid(row=i, column=j)

		self.__b1 = Button(self.__f2,text="Recommencer",command=self.rejouer)
		self.__b2 = Button(self.__f2,text="Au revoir",command=fenetre.destroy)
		self.__b1.pack(side="left")
		self.__b2.pack(side="right")

	def rejouer(self):
		"""VueAlphabet(modif) -> None
		fonction qui ré-affiche aléatoirement les images.
		"""
		for i in self.__labels:
			for j in i:
				photo = self.__images[randint(0,len(self.__images)-1)]
				j.configure(image=photo)
				j.image = photo


def main():
	"""None -> None
	FOnction principale.
	"""
	fenetre = Tk() #fenetre de tkinter qui sera créée
	# VueMessage(fenetre) #Appel exercice 1
	# VueMessage2(fenetre) #Appel exercice 2
	VueAlphabet(fenetre) #Appel exercie 3-4-5-6
	mainloop()

if __name__ == '__main__':
	main()
