__author__ = 'Antoine-Alexis Bourdon <antoine-alexis_bourdon@ens.univ-artois.fr>'
__date__= '18/01/2018'


##Classe du Puissance Quatre
class PuissanceQuatre:
	'''Classe qui modélise le jeu du puissance 4.
	Par défaut, le puissance 4 est construit en dimension 6lignes x 7colonnes.
	'''
	def __init__(self, ligne = 6, colonne = 7):
		'''PuissanceQUatre, int, int -> PuissanceQuatre
		construit le puissance Quatre de lignes x colonnes.
		Initialise une partie
		'''
		assert ligne and colonne > 1
		self.__ligne = ligne
		self.__colonne = colonne
		self.__plateau = []

		for i in range(ligne):
			self.__plateau.append([])
			for j in range(colonne):
				self.__plateau[i].append(-1)

		self.__carac = ["0","X"]
		self.__dernier_coup = (-1,-1)

	def carac(self, joueur):
		'''PuissanceQuatre, int -> str
		liste qui renvoie la marque sur le pion du joueur  (un O ou un X)
		Cette liste ne sert juste pour un affichage agréable
		'''
		return self.__carac[joueur]

	def __str__(self):
		'''PuissanceQuatre -> str
		retourne le plateau du jeu.
		'''
		r = ""
		for i in range(self.__ligne):
			r += self.affiche_ligne1()
			r += self.affiche_ligne2(i)
		r += self.affiche_ligne1()
		return r


	def affiche_ligne1(self):
		''' PuissanceQuatre -> str
		retourne ligne du plateau
		exemple : +-+-+-+-+ 
		'''
		r = "+"
		for i in range(self.__colonne):
			r += "-+" 
		return r + "\n"

	def affiche_ligne2(self,lig):
		'''PuissanceQuatre -> str
		retourne colonne du plateau sans caratère ou avec, depend si la case est occupée ou non.
		exemple : | | | |
		'''
		r = "|"
		for i in self.__plateau[lig]:
			if i == -1:
				r += " "
			else:
				r += self.carac(i)
			r += "|"
		return r + "\n"

	def colonne_valide(self,col):
		'''PuissanceQuatre, int ->  Bool.
		regarde si la colonne est valide.
		'''
		return col >= 0 and col < self.__colonne and self.EmptyCaseInCol(col)

	def EmptyCaseInCol(self,col):
		'''PuissanceQuatre, int -> Bool.
		Regarde si la case de la colonne est vide.
		'''
		for i in range(self.__ligne):
			if self.__plateau[i][col] == -1:
				return True
		return False

	def pose_colonne(self, choix, joueur):
		'''PuissanceQuatre, int ,str -> Puissance
		Pose la coup du joueur dans la colonne choisit par celui-ci.
		'''
		if self.colonne_valide(choix):
			for i in range(self.__ligne):
				if (i+1) > self.__ligne-1:
					self.__plateau[i][choix] = joueur
					self.__dernier_coup = (i,choix)
					return True
				elif self.__plateau[i+1][choix] != -1:
					self.__plateau[i][choix] = joueur
					self.__dernier_coup = (i,choix)
					return True
		return False

	def partie_finie(self):
		''' PuissanceQuatre -> bool 
		detecte si la partie est finie.
		'''
		for i in [-1,0,1]:
			for j in [-1,0,1]:
				if (i,j) != (0,0):
					if self.compte_valeur(self.__dernier_coup[0],self.__dernier_coup[1],self.__plateau[self.__dernier_coup[0]][self.__dernier_coup[1]],i,j) >= 3:
						return True
		return False

	def coords_valide(self,x,y):
		'''PuissanceQuatre, int, int -> Bool.
		vérifie que le numéro de ligne et de colonne donnés en paramètres sont des coordonnées sont valides.
		'''
		return x >= 0 and x < self.__colonne and y >= 0 and y < self.__ligne


	def compte_valeur(self,lig,col,val,inc_lig,inc_col):
		'''PuissanceQuatre, int, int, int, int, int -> int
		retourne le nombre de cases de valeur val à partir de (lig, col)
		dans la direction (inc_lig, inc_col)
		'''
		i = 0
		while self.coords_valide(col+i*inc_col,lig+i*inc_lig) and self.__plateau[lig+i*inc_lig][col+i*inc_col] == val:
			i += 1
		return i-1
