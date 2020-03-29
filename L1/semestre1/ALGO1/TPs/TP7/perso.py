#TP 7 personnage
'''
perso.py

Auteur: BOURDON Antoine-Alexis
Date: 14 novembre 2017

Définit l'objet pers comme étant le personne se ballandant de gauche à droite et inversement
'''

from couleur import *
from random import *
import pygame

def init(lim_x, lim_y):
    '''
    prend les limites de l'écran soit ici 600*400
    Argument:
        lim_x -> int
        lim_y -> int
    Retour:
        att -> dict (pos(postion du personnage),pos_lim(position limites), vit(vitesse du personnage),img(la postion du personnage)
    '''
    att={}
    att['pos']=[20,275]#position
    att['pos_lim']=[lim_x, lim_y] #pas de besoin de y
    att['vit']=1
    att['img']=0

    #x=20
    #y=275
    #att['pos'].append([x,y])
    return att

def dessine(perso, surf):
    '''
    '''
    return(0)

def update(pers):
    '''
    dict -> None
    Mise à jour du personnage
    '''
    #pers['pos'][0]+=pers['vit']
    pers['pos'][0] += pers['vit']

    if pers['pos'][0] > pers['pos_lim'][0] or pers['pos'][0]<0:
        pers['vit'] *= -1
        
def dessine_perso(pers, surface):
    '''
    (dict, surface) -> None
    Dessine le personnage en fontion de pers['img']
    '''
    x=pers['pos'][0]
    y=pers['pos'][1]
    #tete, bras , tronc
    pygame.draw.circle(surface, BLANC, (x, y), 8) #tete
    pygame.draw.line(surface , ROUGE , [x , (y+8)] , [x , y+15+8],2) # tronc
    #pygame.draw.line(surface, ROUGE, [x, y+10], [x+8,y+15],2) #Bras droit
    #pygame.draw.line(surface, ROUGE, [x, y+10], [x-8,y+15],2) #Bras gauche

    
    #Jambes position 0
    if pers['img']==0:
        pers['img']+=1
        pygame.draw.line(surface, BLEU, [x, y+15+8],[x+8,y+25+8],3)
        pygame.draw.line(surface, BLEU, [x, y+15+8],[x-8,y+25+8],3)
        pygame.draw.line(surface, ROUGE, [x, y+10], [x+8,y+15],2) #Bras droit
        pygame.draw.line(surface, ROUGE, [x, y+10], [x-8,y+15],2) #Bras gauche


    #Jambes position 1
    elif pers['img']==1:
        pers['img']+=1
        pygame.draw.line(surface, BLEU, [x, y+15+8],[x+4,y+25+8],3)
        pygame.draw.line(surface, BLEU, [x, y+15+8],[x-4,y+25+8],3)
        pygame.draw.line(surface, ROUGE, [x, y+10], [x+6,y+18],2) #Bras droit
        pygame.draw.line(surface, ROUGE, [x, y+10], [x-6,y+18],2) #Bras gauche


    #Jambes position 2
    elif pers['img']==2:
        pers['img']=0
        pygame.draw.line(surface, BLEU, [x, y+15+8],[x,y+25+8],3)
        pygame.draw.line(surface, BLEU, [x, y+15+8],[x,y+25+8],3)
