#TP 7 scénario
'''
scenario.py

Auteur: BOURDON Antoine-Alexis
Date: 14 novembre 2017

Definit les arbres, créer le ciel, le soleil et les montagnes
'''

from couleur import *
from random import *
import pygame

def init(nbre_arbres, lim_x1, lim_y1, lim_x2, lim_y2):
    '''
    prend le nombres d'arbes à mettre dans le la fentre avec les limites minimales et maximales
    Arguments:
        lim_x1 -> int
        lim_y1 -> int
        lim_x2 -> int
        lim_y2 -> int
        nbre_arbres -> int
    Retour:
        att -> dict
    '''
    att={}
    att['arbres']=[]
    att['lim']=[lim_x1,lim_y1,lim_x2,lim_y2]

    for i in range(nbre_arbres):
        x=randint(att['lim'][0],att['lim'][2])
        y=randint(att['lim'][1],att['lim'][3])
        att['arbres'].append([x,y])
    return (att)

def dessine(scen, surf):
    '''
    '''
    return(0)

def dessine_ciel(surface):
    '''
    surface -> NOne
    Dessine le ciel
    '''
    surface.fill(AZUR_BLEU)

def dessine_soleil(surface):
    '''
    surface -> None
    Dessine le soleil
    '''
    pygame.draw.circle(surface, JAUNE_CO, (510, 80), 28)
    pygame.draw.circle(surface, JAUNE_CI, (510, 80), 20)

def dessine_montagnes(surface):
    '''
    surface -> None
    Dessine les deux montagnes
    '''
    #Liste des points des 2 montagnes
    points_montagnes=[]
    points_montagnes.append((0,300))
    points_montagnes.append((0,200))
    points_montagnes.append((200,100))
    points_montagnes.append((400,200))
    points_montagnes.append((400,300))
    points_montagnes.append((400,200))
    points_montagnes.append((500,100))
    points_montagnes.append((600,200))
    points_montagnes.append((600,300))


    #Dessine les montagnes
    pygame.draw.polygon(surface, KAKI, points_montagnes)

    #Desinne la neige des montagnes
    points_neige_mont=[]
    points_neige_mont.append((150,125))
    points_neige_mont.append((200,100))
    points_neige_mont.append((250,125))
    points_neige_mont.append((475,125))
    points_neige_mont.append((500,100))
    points_neige_mont.append((525,125))

    pygame.draw.polygon(surface, BLANC, points_neige_mont)

def dessine_sol(surface):
    '''
    surface -> None
    dessine le sol couleur Neige
    '''
    pygame.draw.rect(surface, BLANC, [0, 300, 600,400])

def dessine_sapin(surface,scen):
    '''
    (surface,scen) -> None
    dessine les sapins
    '''
    #x=tuples[0]
    #y=tuples[1]
    #x=randint(0,600)
    #y=randint(220,400)
    for n in scen['arbres']:
        for i in range(4):
            pygame.draw.polygon(surface, VERT, ((n[0]+0, n[1]+30+(i*15)), (n[0]+15, n[1]+0+(i*15)), (n[0]+30, n[1]+30+(i*15))))

def update():
    '''
    None
    None
    '''
    pass
