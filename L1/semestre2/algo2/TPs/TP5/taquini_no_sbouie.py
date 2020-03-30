###########TP"5

__author__ = 'Antoine-Alexis BOURDON <antoine-alexis_bourdon@ens.univ-artois.fr>'
__date__ = '22/03/2018'

###Importation de Modules:
from tkinter import *
from string import ascii_lowercase
from random import randint
from taquin import Taquin

#### fonction pour l'initialisation des images.
def initialisationImages():
	""" None -> list().
	fonction met dans une liste le chemin vers les images d'alphabet.
	"""
	liste = list()
	for i in ascii_lowercase:
		source = "alphabet/"+i+".gif"
		liste.append(PhotoImage(file=source))
	return liste
   
   
 ###Classe   
class TaquinMVC:
	''' Classe qui modélise le jeu du taquin selon le schéma Modèle-Vue-Contrôleur.'''
	
	def __init__(self,fenetre,taquin):
		'''TaquinMVC, fontion, fontion -> TaquinMVC
		   Constructeur  avec les valeurs du plateau qui sont placées dans l''ordre, 
		   le vide est dans la dernière cellule
		'''
		self.__taquin=taquin
		self.__taquin.reinit()
		self.__image= initialisationImages()
		self.__f1= Frame(fenetre)
		self.__f2= Frame(fenetre)
		self.__f1.pack()
		self.__f2.pack()
		self.__labels=[]
		for i in range (self.__taquin.dim()):
			self.__labels.append([])
			for j in range (self.__taquin.dim()):
				if self.__taquin.get(i,j)-1 == -2:
					image=PhotoImage(file="./alphabet/rien.gif")
				else:
					image = self.__image[self.__taquin.get(i,j)-1]
				self.__labels[i].append(Button(self.__f1,image=image,command=self.cree_ctrl_choisi_case(i,j)))
				self.__labels[i][j].image=image
				self.__labels[i][j].grid(row=i,column=j)
		self.__b1 = Button(self.__f2,text='Au revoir ',command=fenetre.destroy)
		self.__b1.pack(side='left')
		self.__b2 = Button(self.__f2,text='Recommencer',command=self.restart)
		self.__b2.pack(side='right')


	def update(self):
		''' TaquinMVC(modif) -> None 
		met à jour l'affichage.'''
		for i in range (len(self.__labels)):
			for j in range(len(self.__labels[i])):
				if self.__taquin.get(i,j)-1 == -2:
					image=PhotoImage(file="./alphabet/rien.gif")
				else:
					image = self.__image[self.__taquin.get(i,j)-1]
				
				self.__labels[i][j].configure(image=image)
				self.__labels[i][j].image=image
			   
		
		
	def ctrl_choisie_case(self):
		'''TaquinMVC(modif) -> None.
		gère l'évènement quand l'utilisateur choisie une case, renvoie la lettre associer
		et demande à la vue de se remettre complémentement à jour.'''
		
		coord=(randint(0,self.__taquin.dim()-1),randint(0,self.__taquin.dim()-1))
		self.__taquin.permute_case_vide(coord[0],coord[1])
		self.update()
		
		
		
	def restart(self):
		'''TaquinMVC(modif) -> None
		 Méthode qui demande au modèle de se réinitialiser puis demande à la vue de 
		 se remettre complémentement à jour.
		'''
		
		self.__taquin=Taquin()
		self.__taquin.reinit()
		for i in self.__labels:
			for j in i:
				j["state"]=NORMAL
		self.update()

	def cree_ctrl_choisi_case(self,lig,col):
		'''TaquinMVC , int , int -> TaquinMVC(modif). 
		la fonction retourner demande au modèle de permuter la case(lig, col) avec le vide.'''
		def ctrl_choisie_case():
			truc=self.__taquin.bouge_case(self.__taquin.get(lig,col))
			if truc :
				self.update()
			self.fin()
		return ctrl_choisie_case
	
	def fin(self):
		''' TaquinMVC(modif labels) -> None.
		detecte si la partie est finie et si finie alors les boutons sont inactifs'''
		if self.__taquin.partie_finie():
			for i in self.__labels:
				for j in i:
					j["state"]=DISABLED
####Fin de la classe.					



####MAIN####		
def main():
	'''  None -> None
	Fonction principale.
	'''
	
	fenetre=Tk()
	taquin=Taquin()
	fenetre.title('Le Taquin') 
	TaquinMVC(fenetre,taquin)
	mainloop()

if __name__ == '__main__':
	main()

