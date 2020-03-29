#TP 7 PYGAME 3.5 DEBUT /////////
'''
Fichiers:
couleur.py
neige.py
perso.py
scenario.py
nuage.py

animation en Python avec Pygame (utilsation des modules et des fonctions graphiques)

Auteur : Antoine-Alexis Bourdon
Date : 14 nov 2017

'''

# 1. Importe la bibliotèque Pygame.
import pygame

# Autres importatiohns.
from couleur import *
import scenario
import nuage
import perso
import neige


def main():
    ''' Fonction principale.
    Arguments:
        None.
    Retour:
        None.
    '''
    # 2. Initialise Pygame.
    pygame.init()

    # 3. Initialise l'horloge.
    horloge = pygame.time.Clock()

    # 4. Ouvre la fenêtre de l'application.
    surface = pygame.display.set_mode((600, 400))
    pygame.display.set_caption('Balade en Montagne ! ')

    #Initialise le scenario, la neige
    ma_neige = neige.init(50, 600, 400)
    scen1 = scenario.init(5, 30, 224, 580, 235) #Sapin arrière plan
    scen2 = scenario.init(10, 30, 240, 580, 350) #Sapin première plan 
    nuag = nuage.init(4, 600, 150) #nuage
    pers = perso.init(600,400) #personnage
    scenario.dessine(scen1, surface) 
    scenario.dessine(scen2, surface)
    nuage.dessine(nuag, surface)
    perso.dessine(pers, surface)
    
    # 5. Tant que le programme n’est pas terminé :
    terminer = False
    while not terminer :

        # 5.1. Traite les evenements.
        # Pour chaque evenement detecté :
        for event in pygame.event.get() :
            # Si l'utilisateur a cliqué sur fermer fenêtre :
            if event.type == pygame.QUIT :
                terminer = True

        # 5.2. Efface l'écran.
        surface.fill((0,0,0))

        # 5.3. Dessine les objets.
        #Update avant l'appel à dessiné
        scenario.update() #pas de mouvement des sapins donc pas d'arguments
        nuage.update(nuag) #mouvement des nuages
        perso.update(pers) #mouvement personnage
        neige.update(ma_neige) #mouvement neige
        
        #Dessins
        
        scenario.dessine_ciel(surface) #dessin du ciel (bleu)
        scenario.dessine_soleil(surface) #soleil
        nuage.dessine_nuages(surface,nuag) #les nuages
        scenario.dessine_montagnes(surface) #montagnes
        scenario.dessine_sol(surface) #sol de neige
        scenario.dessine_sapin(surface,scen1) #sapin arrière
        perso.dessine_perso(pers,surface) #personnage
        scenario.dessine_sapin(surface,scen2) #sapin premier plan
        neige.dessine(ma_neige, surface) #neige

        # 5.4. Mise a jour de l'écran.
        pygame.display.update()

        # 5.5. Ajuste la vitesse de la boucle (10 FPS, car pas besoin de plus et permet de rendre le tout agréable).
        horloge.tick(10)

    # 6. Termine Pygame.
    pygame.quit()

# Appelle la fonction principale.
if __name__ == '__main__':
    main()
