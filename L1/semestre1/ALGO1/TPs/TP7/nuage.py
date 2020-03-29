#TP 7 nuage
'''
nuage.py

Auteur: BOURDON Antoine-Alexis
Date: 17 novembre 2017

Definit les nuages.
'''

from couleur import *
from random import *
import pygame

def init(nbre_nuag, lim_x, lim_y):
    '''
    Initialise nbre_nuage niages dans les coordonnées limites passées en argulent.
    Argument:
        nbre_nuage -> int
        lim_x -> int
        lim_y -> int
    Retour:
        att(int, int ,int) -> dict
    '''
    att={}
    att['nuage']=[]
    att['lim']=[lim_x, lim_y]
    att['vit']=0.5

    for i in range(nbre_nuag):
        x = randint(0, att['lim'][0])
        y = randint(0, att['lim'][1])
        att['nuage'].append([x,y])
    return (att)

def dessine(nuag, surf):
    '''
    '''
    return(0)

def update(nuag):
    '''
    dict -> None
    Mise à jour de la position des nuages
    '''
    for i in range(len(nuag['nuage'])):
        nuag['nuage'][i][0] += nuag['vit']
        #print(nuag['lim'][0])
        if nuag['nuage'][i][0]>nuag['lim'][0]:
            y = randint(0, nuag['lim'][1])
            nuag['nuage'][i] = [-110, y]
    

def dessine_nuages(surface,nuag):
    '''
    (surface, dict) -> None
    Dessine les nuages
    '''
    #x=tuples[0]
    #y=tuples[1]
    for n in nuag['nuage']:
        pygame.draw.ellipse(surface, BLANC, [n[0], n[1], 100, 30])
        pygame.draw.ellipse(surface, BLANC, [n[0]+22, n[1]-8, 50, 50])
    

        
