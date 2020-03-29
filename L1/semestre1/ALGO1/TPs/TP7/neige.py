# -*- coding: utf-8 -*-
'''
neige.py

Auteur : T. de Lima
Institution : Université d'Artois
Date : 27 sep 2015

Définit l'objet neige comme un groupe de flocons.
'''
import pygame
from random import randrange
from couleur import BLANC

def init(nb_flocons, lim_x, lim_y):
    '''
    (int, int, int) -> dict

    Initialise nb_flocons flocons de neige dans les coordonées limites passées en
    argument.
    '''
    dict = {}
    dict['flocons'] = []
    dict['taille'] = 2
    dict['pos_lim'] = [lim_x, lim_y]
    #dict["hnei"] = 10 sert à monter le niveau de neige (ne sert à rien ici)    
    dict["vnei"] = 0.1
    
    for i in range(nb_flocons) :
        x = randrange(0, dict['pos_lim'][0])
        y = randrange(0, dict['pos_lim'][1])
        dict['flocons'].append([x, y])

    return dict


def update(neige):
    '''
    dict -> None

    Met à jours les flocons de neige.
    '''
    #neige["pos_lim"][1] -= neige["vnei"] ne sert pas ici
    #neige["hnei"] += neige["vnei"] ne sert à rien ici
    # Pour chaque flocon de neige
    for i in range(len(neige['flocons'])):

        # Déplace le flocon de neige d'un pixel vers le bas.
        neige['flocons'][i][1] += 1

        # Si le flocon de neige est arrivé en bas de l'écran.
        if neige['flocons'][i][1] > neige['pos_lim'][1] :

            # Le recrée juste au dessus de l'écran.
            x = randrange(0, neige['pos_lim'][0])
            neige['flocons'][i] = [x, 0]


def dessine(neige, surface):
    '''
    (dict, Surface) -> None

    Dessine la neige.
    '''
    for n in neige['flocons']:
        pygame.draw.circle(surface, BLANC, n, neige['taille'])


