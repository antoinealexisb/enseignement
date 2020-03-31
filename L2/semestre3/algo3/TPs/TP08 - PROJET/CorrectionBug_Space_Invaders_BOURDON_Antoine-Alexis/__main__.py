# -*- coding: utf:8 -*-
#
# __main__.py
#
# Auteur : Bourdon Antoine-Alexis
# Institution : Université d'Artois
# Date : 02 decembre 2018
#
# Jeu : Space Invaders
#

############################################

#importation des différents modules
from pygame import *
import sys
from os.path import abspath, dirname
from random import randint, choice

############################################

#CONSTANTES
 
##DOSSIERS
RACINE = abspath(dirname(__file__))
DOSSIER_POLICE = RACINE + '/fonts/'
DOSSIER_IMGS = RACINE + '/images/'
DOSSIER_SONS = RACINE + '/sons/'

#COULEURS
NOIR=(0,0,0)
VERT = (78, 255, 87)
BLEU = (80, 255, 239)
VIOLET = (203, 0, 255)
ROUGE = (237, 28, 36)
JAUNE = (241, 255, 0)
BLANC = (255, 255, 255)

surface = display.set_mode((800, 600))
FONT = DOSSIER_POLICE + 'space_invaders.ttf'
NOMS_IMGS = ['vaisseau_joueur', 'vaisseau_mystere', 'ennemi1_1', 'ennemi1_2', 'ennemi2_1', 'ennemi2_2', 'ennemi3_1', 'ennemi3_2', 'explosionbleu', 'explosionvert', 'explosionviolet', 'laser', 'ennemilaser']
IMAGES = {name: image.load(DOSSIER_IMGS + '{}.png'.format(name)).convert_alpha()
		  for name in NOMS_IMGS}

############################################

class Vaisseau(sprite.Sprite):
	'''Classe qui modélise le sprite du joueur sur l'écran
	'''
	def __init__(self,manette):
		'''Vaisseau -> Vaisseau(modif)
		Associe l'image du vaisseau joueur, place le vaisseau à la position (375,540) et donne une vitesse de 5.
		'''
		sprite.Sprite.__init__(self)
		self.image = IMAGES['vaisseau_joueur']
		self.rect = self.image.get_rect(topleft=(375, 540))
		self.vitesse = 5
		self.manette = manette

	def update(self, touches, *args):
		'''Vaisseau(modif) , KEY, *args(groupsennemies) -> None
		Fonction mettant à jour la position du vaisseau joueur au clavier ou manette'''
		if self.manette != None:
			if (touches[K_LEFT] or self.manette.get_hat(0)[0] == -1 or self.manette.get_axis(0) <= -0.5) and self.rect.x > 10:
				self.rect.x -= self.vitesse
			if (touches[K_RIGHT] or self.manette.get_hat(0)[0] == 1 or self.manette.get_axis(0) >= 0.5) and self.rect.x < 740:
				self.rect.x += self.vitesse
		else:
			if touches[K_LEFT] and self.rect.x > 10:
				self.rect.x -= self.vitesse
			if touches[K_RIGHT] and self.rect.x < 740:
				self.rect.x += self.vitesse
		jeu.surface.blit(self.image, self.rect)


class Laser(sprite.Sprite):
	'''Class qui modélise le laser des vaisseaux en fonction de sa direction et 
	des coordonnées du vaisseau émetteur du tire, et si le tir est de centre ou 
	gauche/droite (pour l'amélioration).
	'''
	def __init__(self, xpos, ypos, direction, vitesse, nom_fichier, side):
		'''Initialise le laser avec le nom de l'image à afficher (laser pour le joueur et ennemilaser
		pour les ennemies), la direction du tir (1 pour les ennemies et -1 pour le joueur), vitesse du tir
		(de base pour les ennemies 5 et le joueur 15), 'side' pour savoir si c'est un laser de centre ou gauche/droite.
		Laser, xpos(int), ypos(int), direction(int), vitesse(int), nom_fichier(str), side(str) --> Laser(modif)
		'''
		sprite.Sprite.__init__(self)
		self.image = IMAGES[nom_fichier]
		self.rect = self.image.get_rect(topleft=(xpos, ypos))
		self.vitesse = vitesse
		self.direction = direction
		self.side = side
		self.nom_fichier = nom_fichier

	def update(self, touches, *args):
		'''Mets à jour la modélisation du laser et supprime la classe Laser une fois hors du champ pour pouvoir tirer de nouveau.
		Laser(kill), KEY, *argv(groupennemies) -> None
		'''
		jeu.surface.blit(self.image, self.rect)
		self.rect.y += self.vitesse * self.direction
		if self.rect.y < 15 or self.rect.y > 600:
			self.kill()


class Ennemi(sprite.Sprite):
	'''Classe qui modélise et initialise les élèments d'un ennemi.
	Représenté par son image, sa position en ligne et colonne, la
	direction de celui ci à droite et à gauche, le nombre de mouvements
	à effectuer avant collision et le temps entre chaque mouvement'''
	def __init__(self, ligne, colonne):
		'''Initialise l'ennemi.
		Ennemi, ligne(int), colonne(int) -> Ennemi
		'''
		sprite.Sprite.__init__(self)
		self.ligne = ligne
		self.colonne = colonne
		self.images = []
		self.charger_imgs()
		self.indice = 0
		self.image = self.images[self.indice]
		self.rect = self.image.get_rect()
		self.direction = 1
		self.mouv_droite = 30
		self.mouv_gauche = 30
		self.nbre_mouv = 15
		self.tmp_mouv = 600
		self.timer = time.get_ticks()

	def update(self, touches, tmp_save, ennemies):
		'''Mets à jour l'emplacement des ennemies
		ennemi(modif), tmp_save(int), ennemies(groupEnnemies) -> None
		'''
		if tmp_save - self.timer > self.tmp_mouv:
			if self.direction == 1:
				mouv_max = self.mouv_droite + ennemies.add_mouv_drt
			else:
				mouv_max = self.mouv_gauche + ennemies.add_mouv_ghe

			if self.nbre_mouv >= mouv_max:
				if self.direction == 1:
					self.mouv_gauche = 30 + ennemies.add_mouv_drt
				elif self.direction == -1:
					self.mouv_droite = 30 + ennemies.add_mouv_ghe
				self.direction *= -1
				self.nbre_mouv = 0
				self.rect.y += 35
			elif self.direction == 1:
				self.rect.x += 10
				self.nbre_mouv += 1
			elif self.direction == -1:
				self.rect.x -= 10
				self.nbre_mouv += 1

			self.indice += 1
			if self.indice >= len(self.images):
				self.indice = 0
			self.image = self.images[self.indice]

			self.timer += self.tmp_mouv

		jeu.surface.blit(self.image, self.rect)

	def charger_imgs(self):
		'''Charge l'image de l'ennemi (un ennemi à deux images pour le mouvement)
		ennemi(modif) -> None
		'''
		images = {0: ['1_2', '1_1'],1: ['2_2', '2_1'],2: ['2_2', '2_1'],3: ['3_1', '3_2'],4: ['3_1', '3_2']}
		img1, img2 = (IMAGES['ennemi{}'.format(img_num)] for img_num in images[self.ligne])
		self.images.append(transform.scale(img1, (40, 35)))
		self.images.append(transform.scale(img2, (40, 35)))


class GroupEnnemies(sprite.Group):
	'''Modelise le groupe de tous les ennemies 
	'''
	def __init__(self, colonnes, lignes):
		'''Initialise le groupe en liste [[0, 0, 0, 0, 0],[ 0, 0, 0, 0, 0]...]
		GroupEnnemies, colonnes (int), lignes(int) -> GroupEnnemies
		'''
		sprite.Group.__init__(self)
		self.ennemies = [[0] * colonnes for _ in range(lignes)]
		self.colonnes = colonnes
		self.lignes = lignes
		self.add_mouv_ghe = 0
		self.add_mouv_drt = 0
		self._colonnes_vivantes = list(range(colonnes))
		self._colonnes_ghe_vivantes = 0
		self._colonnes_drt_vivantes = colonnes - 1
		self._colonnes_ghe_tuees = 0
		self._colonnes_drt_tuees = 0 ##correction

	def add(self, *sprites):
		'''Ajoute un sprite ennemi dans le GroupEnnemies.
		GroupEnnemies(modif), sprites(groups) -> None 
		'''
		super(sprite.Group, self).add(*sprites)

		for s in sprites:
			self.ennemies[s.ligne][s.colonne] = s

	def est_colonne_morte(self, colonne):
		'''fonction qui dit si une colonne est morte ou non.
		GroupEnnemies -> Bool
		'''
		for ligne in range(self.lignes):
			if self.ennemies[ligne][colonne]:
				return False
		return True

	def ennemies_choisit(self):
		'''fonction qui choisit un ennemi pour tirer avec son laser.
		GroupEnnemies -> ennemi sprite
		'''
		random_indice = randint(0, len(self._colonnes_vivantes) - 1)
		col = self._colonnes_vivantes[random_indice]
		for ligne in range(self.lignes, 0, -1):
			ennemi = self.ennemies[ligne - 1][col]
			if ennemi:
				return ennemi
		return None

	def kill(self, ennemi):
		'''fonction qui vérifie si un ennemi est mort.
		GroupEnnemies(modif) -> None'''
		# sur les appels à double coup pour le même ennemi, alors vérifiez avant
		if not self.ennemies[ennemi.ligne][ennemi.colonne]:
			return  None

		self.ennemies[ennemi.ligne][ennemi.colonne] = None
		estColonneMorte = self.est_colonne_morte(ennemi.colonne)
		if estColonneMorte:
			self._colonnes_vivantes.remove(ennemi.colonne)

		if ennemi.colonne == self._colonnes_drt_vivantes:
			while self._colonnes_drt_vivantes > 0 and estColonneMorte:
				self._colonnes_drt_vivantes -= 1
				self._colonnes_drt_tuees += 1##correction
				self.add_mouv_drt = self._colonnes_drt_tuees * 5##correction
				estColonneMorte = self.est_colonne_morte(self._colonnes_drt_vivantes)

		elif ennemi.colonne == self._colonnes_ghe_vivantes:
			while self._colonnes_ghe_vivantes < self.colonnes and estColonneMorte:
				self._colonnes_ghe_vivantes += 1#correction
				self._colonnes_ghe_tuees += 1
				self.add_mouv_ghe = self._colonnes_ghe_tuees * 5
				estColonneMorte = self.est_colonne_morte(self._colonnes_ghe_vivantes)


class Bouclier(sprite.Sprite):
	'''classe qui modélise un bouclier représenter par un rectangle.
	'''
	def __init__(self, taille, couleur, ligne, colonne):
		'''Constructeur avec les valeurs de la taille du bouclier, son emplacement et sa couleur.
		Bouclier, taille(int), couleur(tuple(int,int,int)), ligne(int), colonne(int) -> Bouclier
		'''
		sprite.Sprite.__init__(self)
		self.hauteur = taille
		self.largeur = taille
		self.couleur = couleur
		self.image = Surface((self.largeur, self.hauteur))
		self.image.fill(self.couleur)
		self.rect = self.image.get_rect()
		self.ligne = ligne
		self.colonne = colonne

	def update(self, touches):
		'''fonction qui dessine les boucliers sur surface.
		Bouclier, touches (pygame surface ) -> None
		'''
		jeu.surface.blit(self.image, self.rect)


class vaisseau_mys(sprite.Sprite):
	'''classe qui modélise le vaisseau mystère.
	'''
	def __init__(self):
		'''Constructeur qui initialise le vaisseau mystère en lui donnant l'image associée, sa direction, sa ligne, tous les combien de temps il apparaît, son son ....
		vaisseau_mys -> vaisseau_mys
		'''
		sprite.Sprite.__init__(self)
		self.image = IMAGES['vaisseau_mystere']
		self.image = transform.scale(self.image, (75, 35))
		self.rect = self.image.get_rect(topleft=(-80, 45))
		self.ligne = 5
		self.tmp_mouv = 25000
		self.direction = 1
		self.timer = time.get_ticks()
		self.vaisseau_mystere = mixer.Sound(DOSSIER_SONS + 'vaisseau_mystere.wav')
		self.vaisseau_mystere.set_volume(0.3)
		self.jouerSon = True

	def update(self, touches, tmp_save, *args):
		'''Mets à jour la position du vaisseau mystère.
		vaisseau_mys(modif), touches(list(liste des touches appuyées)), tmp_save(int), *args(groupennemies) -> None
		'''
		timerReinit = False
		tmp_passe = tmp_save - self.timer
		if tmp_passe > self.tmp_mouv:
			if (self.rect.x < 0 or self.rect.x > 800) and self.jouerSon:
				self.vaisseau_mystere.play()
				self.jouerSon = False
			if self.rect.x < 840 and self.direction == 1:
				self.vaisseau_mystere.fadeout(4000)
				self.rect.x += 2
				jeu.surface.blit(self.image, self.rect)
			if self.rect.x > -100 and self.direction == -1:
				self.vaisseau_mystere.fadeout(4000)
				self.rect.x -= 2
				jeu.surface.blit(self.image, self.rect)

		if self.rect.x > 830:
			self.jouerSon = True
			self.direction = -1
			timerReinit = True
		if self.rect.x < -90:
			self.jouerSon = True
			self.direction = 1
			timerReinit = True
		if tmp_passe > self.tmp_mouv and timerReinit:
			self.timer = tmp_save


class Explosion(sprite.Sprite):
	'''Classe qui modélise les Explosions que subissent les vaisseaux.
	'''
	def __init__(self, xpos, ypos, ligne, vaisseau, vaisseau_Mystere, score):
		'''
		À chaque tir qui touche le constructeur ce mets en place.
		Explosion, xpos(int), ypos(int), ligne(int), vaisseau (bool(pour savoir si notre vaisseau toucher ou non)), vaisseau_Mystere (bool), score(int) -> Explosion
		'''
		sprite.Sprite.__init__(self)
		self.estvaisseau_Mystere = vaisseau_Mystere
		self.estvaisseau = vaisseau
		if vaisseau_Mystere:
			self.text = Text(FONT, 20, str(score), BLANC, xpos + 20, ypos + 6)
		elif vaisseau:
			self.image = IMAGES['vaisseau_joueur']
			self.rect = self.image.get_rect(topleft=(xpos, ypos))
		else:
			self.ligne = ligne
			self.charger_image()
			self.image = transform.scale(self.image, (40, 35))
			self.rect = self.image.get_rect(topleft=(xpos, ypos))
			jeu.surface.blit(self.image, self.rect)

		self.timer = time.get_ticks()

	def update(self, touches, tmp_save):
		'''Explosion, touches(list), tmp_save(int) -> None
		affiche l'animation d'explosion.
		'''
		tmp_passe = tmp_save - self.timer
		if self.estvaisseau_Mystere:
			if tmp_passe <= 200:
				self.text.draw(jeu.surface)
			elif 400 < tmp_passe <= 600:
				self.text.draw(jeu.surface)
			elif tmp_passe > 600:
				self.kill()
		elif self.estvaisseau:
			self.kill()
		else:
			if tmp_passe <= 100:
				jeu.surface.blit(self.image, self.rect)
			elif 100 < tmp_passe <= 200:
				self.image = transform.scale(self.image, (50, 45))
				jeu.surface.blit(self.image,(self.rect.x - 6, self.rect.y - 6))
			elif tmp_passe > 400:
				self.kill()

	def charger_image(self):
		'''Explosion(modif)-> None
		fonction qui charge les images d'explosion en fonction de leur représentation sur le terrain.
		'''
		imgCouleurs = ['violet', 'bleu', 'bleu', 'vert','vert']
		self.image = IMAGES['explosion{}'.format(imgCouleurs[self.ligne])]


class Vie(sprite.Sprite):
	'''Classe qui modélise la vie du joueur sous forme d'image.
	'''
	def __init__(self, xpos, ypos):
		'''Constructeur avec les valeurs x et y de l'emplacement des images de la vie.
		Vie, xpos(int), ypos(int) -> Vie
		'''
		sprite.Sprite.__init__(self)
		self.image = IMAGES['vaisseau_joueur']
		self.image = transform.scale(self.image, (23, 23))
		self.rect = self.image.get_rect(topleft=(xpos, ypos))

	def update(self, touches, *args):
		'''Fonction dessinant le nombre de vies.
		Vie, touches(list(liste des touches appuyées)), *args(groupennemies) -> None
		'''
		jeu.surface.blit(self.image, self.rect)


class Text(object):
	'''Classe modélisant le texte à afficher.
	'''
	def __init__(self, textFont, taille, message, couleur, xpos, ypos):
		'''Constructeur avec les valeurs x et y pour le texte, la couleur du texte et sa taille
		Text, textFont(str(emplacement de la police)), taille(int), message(str), couleur(tuple(int,int,int)), xpos(int), ypos(int) -> Text
		'''
		self.font = font.Font(textFont, taille)
		self.surface = self.font.render(message, True, couleur)
		self.rect = self.surface.get_rect(topleft=(xpos, ypos))

	def draw(self, surface):
		'''Fonction qui affiche le texte.
		Text -> None
		'''
		surface.blit(self.surface, self.rect)


class SpaceInvaders(object):
	'''Classe Principale du jeu.
	'''
	def __init__(self):
		'''Constructeur qui initialise les éléments principaux du jeu.
		SpaceInvaders -> SpaceInvaders
		'''
		mixer.pre_init(44100, -16, 1, 4096)
		init()
		self.nom_fenetre = display.set_caption('Space Invaders Arcade')
		self.surface = surface
		self.background = image.load(DOSSIER_IMGS + 'background.jpg').convert()
		self.startjeu = False
		self.surface_ecran = 0
		self.gameOver = False
		# valeur initiale pour un nouveau jeu
		self.positionEnnemiDefaut = 65
		# Compteur pour la position de départ de l'ennemi (augmenté chaque nouveau tour)
		self.compteurPositionActive = self.positionEnnemiDefaut
		# Position de départ actuelle de l'ennemi
		self.positionEnnemi = self.compteurPositionActive
		self.hi_score = int(open("hi_score","r").read())
		self.coins = 0
		self.space = 0
		self.nb_manettes = joystick.get_count()
		if self.nb_manettes == 0:
			self.manette = None
			print("Attention : Aucune manette de jeu connecté.")
		else:
			#utilisation de la manette 0.
			self.manette = joystick.Joystick(0)
			#Initialisation de la manette de jeu.
			self.manette.init()
			print("Manette de jeu connecté.")

	def reset(self, score, vies, nouveauJeu=False):
		'''Fonction qui remet tout à zéro, sauf les boucliers, le score et les vies si le jeu a été gagné.
		SpaceInvaders(modif), score (int), vies(int), nouveauJeu(bool) -> None
		'''
		self.joueur = Vaisseau(self.manette)
		self.joueurGroup = sprite.Group(self.joueur)
		self.explosionsGroup = sprite.Group()
		self.lasers = sprite.Group()
		self.vaisseau_Mystere= vaisseau_mys()
		self.mysteryGroup = sprite.Group(self.vaisseau_Mystere)
		self.lasersEnnemi = sprite.Group()
		self.reset_vies(vies)
		self.positionEnnemi = self.compteurPositionActive
		self.creation_ennemies()
		self.hi_score = int(open("hi_score","r").read())
		# Créer uniquement des bloqueurs sur un nouveau jeu, pas un nouveau tour
		if nouveauJeu:
			self.ensembleBoucliers = sprite.Group(self.creation_boucliers(0), self.creation_boucliers(1), self.creation_boucliers(2), self.creation_boucliers(3))
		self.touches = key.get_pressed()
		self.clock = time.Clock()
		self.timer = time.get_ticks()
		self.noteTimer = time.get_ticks()
		self.vaisseauTimer = time.get_ticks()
		self.score = score
		self.vies = vies
		self.stockage_sons()
		self.stockage_text()
		self.creerNouveauVaisseau = False
		self.VaisseauVie = True

	def creation_boucliers(self, number):
		'''Fonction qui crée le groupe de bouclier.
		SpaceInvaders -> Group (36 sprites ici)
		'''
		bouclierGroup = sprite.Group()
		for ligne in range(4):
			for colonne in range(9):
				bouclier = Bouclier(10, VERT, ligne, colonne)
				bouclier.rect.x = 50 + (200 * number) + (colonne * bouclier.largeur)
				bouclier.rect.y = 450 + (ligne * bouclier.hauteur)
				bouclierGroup.add(bouclier)
		return bouclierGroup

	def reset_vies_sprites(self):
		'''Fonction qui crée les Vies du joueur (sprite) avec leur position sur la surface et définit combien de sprites dans le ViesGroup.
		SpaceInvaders(modif) -> None
		'''
		self.vie1 = Vie(715, 3)
		self.vie2 = Vie(742, 3)
		self.vie3 = Vie(769, 3)

		if self.vies == 3:
			self.viesGroup = sprite.Group(self.vie1, self.vie2, self.vie3)
		elif self.vies == 2:
			self.viesGroup = sprite.Group(self.vie1, self.vie2)
		elif self.vies == 1:
			self.viesGroup = sprite.Group(self.vie1)

	def reset_vies(self, vies):
		'''Fonction qui remet à zéro le nombre de vies du joueur dans le self.vies.
		SpaceInvaders(modif) -> None
		'''
		self.vies = vies
		self.reset_vies_sprites()

	def stockage_sons(self):
		'''Fonction qui stocke les fichiers sons et leur attribut du pygame.mixer dans le self.sons.
		SpaceInvaders(modif) -> None
		'''
		self.sons = {}
		for nom_son in ['tire', 'tire2', 'ennemimort', 'mystmort','vaisseau_joueur_explosion']:#,'MIT_Concert_Choir_-_01_-_O_Fortuna']:
			self.sons[nom_son] = mixer.Sound(DOSSIER_SONS + '{}.wav'.format(nom_son))
			self.sons[nom_son].set_volume(0.2)

		self.musicNotes = [mixer.Sound(DOSSIER_SONS + '{}.wav'.format(i)) for i in range(4)]
		for son in self.musicNotes:
			son.set_volume(0.5)

		self.noteindice = 0

	def lire_musique_ennemies(self, tmp_save):
		'''Fonction qui démarre le son des ennemies (soit 4 sons à faire en 4 mouvements des ennemies)
		SpaceInvaders(modif) -> None
		'''
		tmp_mouv = self.ennemies.sprites()[0].tmp_mouv
		if tmp_save - self.noteTimer > tmp_mouv:
			self.note = self.musicNotes[self.noteindice]
			if self.noteindice < 3:
				self.noteindice += 1
			else:
				self.noteindice = 0

			self.note.play()
			self.noteTimer += tmp_mouv

	def stockage_text(self):
		'''Fonction qui stocke les différents textes à afficher avec leurs caractéristiques(taille, text, couleur, xpos, ypos).
		SpaceInvaders(modif) -> None
		'''
		self.titleCoinText = Text(FONT, 50,'INSERT COIN', BLANC,201,225)
		self.titleCoin2Text = Text(FONT, 20,'Credits ', BLANC,640,580)
		self.titleCoin3Text = Text(FONT, 50,'PLAYS ', BLANC,300,225)
		self.titleText = Text(FONT, 50, 'Space Invaders', BLANC, 164, 155)
		self.gameOverText = Text(FONT, 50, 'GAME OVER', BLANC, 250, 270)
		self.ennemi1Text = Text(FONT, 25, '   =   10 pts', VERT, 368, 270)
		self.ennemi2Text = Text(FONT, 25, '   =  20 pts', BLEU, 368, 320)
		self.ennemi3Text = Text(FONT, 25, '   =  30 pts', VIOLET, 368, 370)
		self.ennemi4Text = Text(FONT, 25, '   =  ?????', ROUGE, 368, 420)
		self.scoreText = Text(FONT, 20, 'Score', BLANC, 5, 5)
		self.highscoreText = Text(FONT,20,'high score', BLANC, 250, 5)
		self.highscoreText2 = Text(FONT,20,str(self.hi_score), VERT, 450, 5)
		self.viesText = Text(FONT, 20, 'vies ', BLANC, 640, 5)

	def sortie(self,evt):
		'''Fonction vérifiant si l'utilisateur a demandé de partir.
		SpaceInvaders, evt(list(liste des touches appuyées)) -> bool
		'''
		return evt.type == QUIT or (evt.type == KEYUP and evt.key == K_ESCAPE)

	def touche_appuyee(self):
		'''Fonction qui sauvegarde les touches appuyer et actionne l'action du laser si la touche espace est enfoncée.
		SpaceInvaders(modif) -> None
		'''
		self.touches = key.get_pressed()
		for e in event.get():
			if self.sortie(e):
				sys.exit()
			#print(e)
			if e.type == KEYDOWN:
				if e.key == K_SPACE :
					self.space = 1
			elif e.type == JOYBUTTONDOWN:
				if e.button == 0:
					self.space = 1
			if self.space == 1:
				if len(self.lasers) == 0 and self.VaisseauVie:
					if self.score < 1000:
						laser = Laser(self.joueur.rect.x + 23, self.joueur.rect.y + 5, -1, 15, 'laser', 'center')
						self.lasers.add(laser)
						self.allSprites.add(self.lasers)
						self.sons['tire'].play()
					else: #BONUS SCORE
						lasergauche = Laser(self.joueur.rect.x + 8,self.joueur.rect.y + 5, -1, 15, 'laser', 'gauche')
						laserdroite = Laser(self.joueur.rect.x + 38,self.joueur.rect.y + 5, -1, 15, 'laser', 'droite')
						self.lasers.add(lasergauche)
						self.lasers.add(laserdroite)
						self.allSprites.add(self.lasers)
						self.sons['tire2'].play()
				self.space = 0
			

	def creation_ennemies(self):
		'''Fonction qui crée le groupe des ennemies.
		SpaceInvaders -> Group (50 sprites ici)
		'''
		ennemies = GroupEnnemies(10, 5)
		for ligne in range(5):
			for colonne in range(10):
				ennemi = Ennemi(ligne, colonne)
				ennemi.rect.x = 157 + (colonne * 50)
				ennemi.rect.y = self.positionEnnemi + (ligne * 45)
				ennemies.add(ennemi)

		self.ennemies = ennemies
		self.allSprites = sprite.Group(self.joueur, self.ennemies,self.viesGroup, self.vaisseau_Mystere)

	def creation_ennemies_tire(self):
		'''Fonction qui fait tirer un ennemi à un intervalle de 0.7 secondes.
		SpaceInvaders(modif) -> None
		'''
		if (time.get_ticks() - self.timer) > 700:
			ennemi = self.ennemies.ennemies_choisit()
			if ennemi:
				self.lasersEnnemi.add(Laser(ennemi.rect.x + 14, ennemi.rect.y + 20, 1, 5,'ennemilaser', 'center'))
				self.allSprites.add(self.lasersEnnemi)
				self.timer = time.get_ticks()

	def calcul_score(self, ligne):
		'''Fonction qui calcule le score en fonction de la ligne touchée.
		SpaceInvaders(modif) -> None
		'''
		scores = {0: 30, 1: 20,2: 20, 3: 10, 4: 10, 5: choice([50, 100, 150, 300])}
		score = scores[ligne]
		self.score += score
		return score

	def creation_menu_regle(self):
		'''Fonction qui crée le menu 2 donc celui des règles avec le nombre de points par ennemies.
		SpaceInvaders -> None
		'''
		self.ennemi1 = IMAGES['ennemi3_1']
		self.ennemi1 = transform.scale(self.ennemi1, (40, 40))
		self.ennemi2 = IMAGES['ennemi2_2']
		self.ennemi2 = transform.scale(self.ennemi2, (40, 40))
		self.ennemi3 = IMAGES['ennemi1_2']
		self.ennemi3 = transform.scale(self.ennemi3, (40, 40))
		self.ennemi4 = IMAGES['vaisseau_mystere']
		self.ennemi4 = transform.scale(self.ennemi4, (80, 40))
		self.surface.blit(self.ennemi1, (318, 270))
		self.surface.blit(self.ennemi2, (318, 320))
		self.surface.blit(self.ennemi3, (318, 370))
		self.surface.blit(self.ennemi4, (299, 420))

		for e in event.get():
			if self.sortie(e):
				sys.exit()
			if e.type == KEYUP or e.type == JOYBUTTONDOWN:
				self.surface_ecran = 3
				self.startjeu = True

	def update_ennemies_vitesse(self):
		'''fonction qui change la vitesse des ennemies en fonction du nombre d'ennemies restant sur la surface.
		SpaceInvaders(modif) -> None
		'''
		if 10 < len(self.ennemies) <= 20:
			for ennemi in self.ennemies:
				ennemi.tmp_mouv = 400
		if len(self.ennemies) <= 10:
			for ennemi in self.ennemies:
				ennemi.tmp_mouv = 250
		if len(self.ennemies) == 1:
			for ennemi in self.ennemies:
				ennemi.tmp_mouv = 100

	def verifier_collisions(self):
		'''Fonction qui vérifie la collision des lasers joueurs et ennemis [laser_joueur,laser_ennemi;;laser_joueur,ennemi;;laser_joueur,vaisseau_mystere;;laser_ennemi,joueur].
		SpaceInvaders(modif) -> None
		'''
		collidedict = sprite.groupcollide(self.lasers, self.lasersEnnemi,True, False)
		if collidedict:
			for value in collidedict.values():
				for spriteCourant in value:
					self.lasersEnnemi.remove(spriteCourant)
					self.allSprites.remove(spriteCourant)

		ennemiesdict = sprite.groupcollide(self.lasers, self.ennemies,True, False)
		if ennemiesdict:
			for value in ennemiesdict.values():
				for spriteCourant in value:
					self.ennemies.kill(spriteCourant)
					self.sons['ennemimort'].play()
					score = self.calcul_score(spriteCourant.ligne)
					explosion = Explosion(spriteCourant.rect.x, spriteCourant.rect.y, spriteCourant.ligne, False, False,score)
					self.explosionsGroup.add(explosion)
					self.allSprites.remove(spriteCourant)
					self.ennemies.remove(spriteCourant)
					self.jeuTimer = time.get_ticks()
					break

		mysterydict = sprite.groupcollide(self.lasers, self.mysteryGroup,True, True)
		if mysterydict:
			for value in mysterydict.values():
				for spriteCourant in value:
					spriteCourant.vaisseau_mystere.stop()
					self.sons['mystmort'].play()
					score = self.calcul_score(spriteCourant.ligne)
					explosion = Explosion(spriteCourant.rect.x,spriteCourant.rect.y,spriteCourant.ligne, False, True,score)
					self.explosionsGroup.add(explosion)
					self.allSprites.remove(spriteCourant)
					self.mysteryGroup.remove(spriteCourant)
					newVaisseau = vaisseau_mys()
					self.allSprites.add(newVaisseau)
					self.mysteryGroup.add(newVaisseau)
					break

		lasersdict = sprite.groupcollide(self.lasersEnnemi, self.joueurGroup,True, False)
		if lasersdict:
			for value in lasersdict.values():
				for joueurVaisseau in value:
					if self.vies == 3:
						self.vies -= 1
						self.viesGroup.remove(self.vie3)
						self.allSprites.remove(self.vie3)
					elif self.vies == 2:
						self.vies -= 1
						self.viesGroup.remove(self.vie2)
						self.allSprites.remove(self.vie2)
					elif self.vies == 1:
						self.vies -= 1
						self.viesGroup.remove(self.vie1)
						self.allSprites.remove(self.vie1)
					elif self.vies == 0:
						self.gameOver = True
						self.startjeu = False
					self.sons['vaisseau_joueur_explosion'].play()
					explosion = Explosion(joueurVaisseau.rect.x, joueurVaisseau.rect.y,0, True, False, 0)
					self.explosionsGroup.add(explosion)
					self.allSprites.remove(joueurVaisseau)
					self.joueurGroup.remove(joueurVaisseau)
					self.creerNouveauVaisseau = True
					self.VaisseauTimer = time.get_ticks()
					self.VaisseauVie = False

		if sprite.groupcollide(self.ennemies, self.joueurGroup, True, True):
			self.gameOver = True
			self.startjeu = False

		sprite.groupcollide(self.lasers, self.ensembleBoucliers, True, True)
		sprite.groupcollide(self.lasersEnnemi, self.ensembleBoucliers, True, True)
		sprite.groupcollide(self.ennemies, self.ensembleBoucliers, False, True)

	def creer_nouveau_vaisseau(self, creerVaisseau):
		'''Fonction qui crée un vaisseau pour le joueur en cas de perte de vie.
		SpaceInvaders (modif) -> None
		'''
		if creerVaisseau:
			self.joueur = Vaisseau(self.manette)
			self.allSprites.add(self.joueur)
			self.joueurGroup.add(self.joueur)
			self.creerNouveauVaisseau = False
			self.VaisseauVie = True

	def menu_jeu_perdu(self, tmp_save):
		'''Fonction qui dessine le menu quand le joueur perd la partie.
		SpaceInvaders (modif) -> None.
		'''
		self.surface.blit(self.background, (0, 0))
		tmp_passe = tmp_save - self.timer
		if tmp_passe < 750:
			self.gameOverText.draw(self.surface)
		elif 750 < tmp_passe < 1500:
			self.surface.blit(self.background, (0, 0))
		elif 1500 < tmp_passe < 2250:
			self.gameOverText.draw(self.surface)
		elif 2250 < tmp_passe < 2750:
			self.surface.blit(self.background, (0, 0))
		elif tmp_passe > 3000:
			self.surface_ecran = 0

		for e in event.get():
			if self.sortie(e):
				sys.exit()

	def main(self):
		'''
		Fonction principale.
		SpaceInvaders (modif) -> None
		'''
		#Musique de fond
		mixer.Channel(0).play(mixer.Sound('sons/MIT_Concert_Choir_-_01_-_O_Fortuna.wav'), loops = -1)
		while True:
			
			#Menu 1 (INSERT COIN ["espace" pour mettre des crédits, "entrer" pour commencer si crédit present])
			if self.surface_ecran == 0:
				self.reset(0, 3, True)
				self.surface.blit(self.background, (0, 0))
				Text(FONT, 20,str(self.coins), BLANC,750,580).draw(self.surface)
				self.titleCoin2Text.draw(self.surface)
				if (self.timer % 3000)<1500 and self.coins < 1:
					self.titleCoinText.draw(self.surface)
				if (self.timer % 3000)<1500  and (self.coins > 0):
					self.titleCoin3Text.draw(self.surface)
				for e in event.get():
					if self.sortie(e):
						sys.exit()
					if e.type == KEYUP:
						if e.key == K_SPACE:
							self.coins += 1
						if e.key == K_RETURN and self.coins > 0:
							self.coins -=1
							self.surface_ecran += 1
					elif e.type == JOYBUTTONDOWN:
						if e.button == 6:
							self.coins += 1
						if e.button == 7 and self.coins > 0:
							self.coins -=1
							self.surface_ecran += 1
				
			#Menu 2	(Regles du Jeu score)
			elif self.surface_ecran == 1:
				self.reset(0, 3, True)
				self.surface.blit(self.background, (0, 0))
				self.titleText.draw(self.surface)
				self.ennemi1Text.draw(self.surface)
				self.ennemi2Text.draw(self.surface)
				self.ennemi3Text.draw(self.surface)
				self.ennemi4Text.draw(self.surface)
				self.creation_menu_regle()

			#Menu 3 Jeu
			elif self.startjeu:
				if len(self.ennemies) == 0:
					self.surface.blit(self.background, (0, 0))
					self.scoreText2 = Text(FONT, 20, str(self.score),VERT, 85, 5)
					self.scoreText.draw(self.surface)
					self.scoreText2.draw(self.surface)
					self.viesText.draw(self.surface)
					self.viesGroup.update(self.touches)
					self.touche_appuyee()
					self.compteurPositionActive += 35
					self.reset(self.score, self.vies)
					self.jeuTimer += 3000
				else:
					tmp_save = time.get_ticks()
					self.lire_musique_ennemies(tmp_save)
					self.surface.blit(self.background, (0, 0))
					self.ensembleBoucliers.update(self.surface)
					self.scoreText2 = Text(FONT, 20, str(self.score), VERT,85, 5)
					self.scoreText.draw(self.surface)
					self.scoreText2.draw(self.surface)
					self.viesText.draw(self.surface)
					self.touche_appuyee()
					self.allSprites.update(self.touches, tmp_save,self.ennemies)
					self.explosionsGroup.update(self.touches, tmp_save)
					self.verifier_collisions()
					self.creer_nouveau_vaisseau(self.creerNouveauVaisseau)
					self.update_ennemies_vitesse()

					if len(self.ennemies) > 0:
						self.creation_ennemies_tire()
			
			#Menu 4 : Perdu
			elif self.gameOver:
				tmp_save = time.get_ticks() #'''Ennemi position de départ'''
				self.compteurPositionActive = self.positionEnnemiDefaut
				self.menu_jeu_perdu(tmp_save)
			
			#Vérification du score 
			if self.score > self.hi_score:
				open("hi_score","w").write(str(self.score))
				self.highscoreText2 = Text(FONT,20,str(self.score), VERT, 450, 5)
			self.highscoreText.draw(self.surface)
			self.highscoreText2.draw(self.surface)
			
			display.update()
			self.clock.tick(60)


#Appel à la classe principale.
if __name__ == '__main__':
	jeu = SpaceInvaders()
	jeu.main()
