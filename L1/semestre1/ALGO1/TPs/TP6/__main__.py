'''
TIC-TAC-TOE !!!

Auteur: Antoine-Alexis BOURDON
Année : L1 - 2017/2018
Date: 9 novembre 2017

Jeu du tic-tac-toe, en version brute, sans interface graphique (pygame)
'''
#Importation des différents fichiers 
from constantes import *
from fonctions import *
from random import *

def main():
    '''Fontion principale
    Arguments:
        None.
    Retour:
        None.
    '''
    #Titre du Jeu:
    print('''
             ########################
             ## JEU DU TIC-TAC-TOE ##
             ########################
             ''')
    #lance la fonction joue_partie qui actionne le jeu
    joue_partie()


#Appel à la fonction principale.
if __name__ == '__main__':
    main()
