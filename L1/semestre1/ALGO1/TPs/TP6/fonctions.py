from random import *
from constantes import *

def init_plateau():
    ''' Fonction qui créer le plateau de jeu dans un tableau
    Arguments:
        None
    Retour:
        tableau (str)
    '''
    liste=[]
    for i in range(T_PLATEAU):
        liste += [[]]
        for j in range(T_PLATEAU):
            liste[i] += [VIDE]
    return liste

def print_plateau(plateau_recu):
    ''' affiche la grille de jeu en fonction du tableau
    Arguments :
        plateau_recu --tableau (str)
    Retour :
        None '''
    for i in range(len(plateau_recu)):
        for j in range(len(plateau_recu)):
            print(plateau_recu[i][j], end ="")
            if j < (len(plateau_recu))-1:
                print('|',end="")
        print()
        if i < (len(plateau_recu)-1):
            print(T_PLATEAU*'--')

def input_humain(plateau_liste):
    ''' Demande à l'utilisateur d'entrer des coordonnées pour la tableau
    Arguments :
        plateau_liste -> str (tableau)
    Retour:
        choix : str (tableau)
    '''
    mot=False
    while not mot:
        choix = (input('Votre coup ("q" pour abandonner) [sous la forme ligne espace colonne]: '))
        choix = choix.split( )
        if int(choix[0]) <= T_PLATEAU and int(choix[1]) <= T_PLATEAU and choix[0] >'0' and choix[1]>'0' and plateau_liste[int(choix[0])-1][int(choix[1])-1] == VIDE:
            mot = True
            return choix
        else :
            print('Le coup n\'est pas valide ou vous vous êtes tromper de touche.\nLe coup dois être sous la forme numéro_ligne (espace) numéro_colone, exemple 1 1 pour la case en haut à gauche.')
            
def coords_vides(liste):
    ''' Met les emplacements libres dans une liste de liste
    Argument
        liste : str (tableau de la grille)
    Retour:
        liste_vide :str liste de liste
    '''
    liste_vide=[]
    for i in range(T_PLATEAU):
        for j in range(T_PLATEAU):
            if liste[i][j] == VIDE:
                liste_vide.append([i,j])
    if liste_vide==[]:
        liste_vide='rien'
    return liste_vide

def input_ordi(liste_vide):
    ''' Choix aléatoire de l'ordinateur pour l'emplacement de son coup dans le tableau
    Argument:
        liste_vide : str
    Retour:
        liste_vide : str (avec les coordonnées dans le tableau)
    '''
    liste_vide=liste_vide[randint(0,len(liste_vide)-1)]
    return liste_vide

def placement_humain(choix,plateau):
    ''' Place le choix de l'utilisateur dans le tableau
    Argument :
        choix : str (coordonnées du point choisi)
        plateau : str (tableau)
    Retour :
        plateau : str (tableau mit a jour)
    '''
    plateau[int(choix[0])-1][int(choix[1])-1]='X'
    return plateau

def placement_ordi(choix_ordi,plateau):
    ''' Place le choix de l'ordinateur dans le tableau
    Argument :
        choix : str (coordonnées du point choisi)
        plateau : str (tableau)
    Retour :
        plateau : str (tableau mit a jour)
    '''
    plateau[int(choix_ordi[0])][int(choix_ordi[1])]='O'
    print('Coup de l\'ordinateur :',choix_ordi[0]+1, choix_ordi[1]+1)
    return plateau
    
def est_victoire(plateau):
    ''' Vérifie si l'utilisateur ou l'ordinateur à gagné
    Argument :
        plateau : str (tableau)
    Retour:
        False : si gagnant
        True : si pas de gagnant
    '''
    diao=[]
    diao2=[]
    ordi_bon=""
    humain_bon=""
    for i in range(T_PLATEAU):
        colone=[]
        for j in range(T_PLATEAU):
            colone.append(plateau[j][i])
        diao.append(plateau[i][i])
        diao2.append(plateau[(T_PLATEAU-1)-i][(T_PLATEAU-1)-i])

        if plateau[i] == T_PLATEAU*['X'] or colone == T_PLATEAU*['X']:
            humain_bon="o"
            
    
        if plateau[i] == T_PLATEAU*['O'] or colone == T_PLATEAU*['O']:
            ordi_bon="o"
            
            
        if i == T_PLATEAU-1:
            if diao == T_PLATEAU*['X'] or diao2==T_PLATEAU*['X']:
                humain_bon="o"
            elif diao==T_PLATEAU*['O'] or diao2 == T_PLATEAU*['O']:
                ordi_bon="o"
                
        if humain_bon == "o":
            print('Félicitations. Vous avez gagné.')
            return False
        if ordi_bon =="o":
            print('Vous avez perdu.')
            return False
    return True

def joue_partie():
    ''' Fonction qui initialise le jeu
    Argument:
        None
    Retour:
        None
    '''
    partie = True
    plateau = init_plateau()
    print_plateau(plateau)
    while partie:
        choix = input_humain(plateau)
        plateau = placement_humain(choix,plateau)
        print_plateau(plateau)
        partie = est_victoire(plateau) #retour à mettre en place
        if partie == False:
            break
        liste_vide = coords_vides(plateau)
        if liste_vide == 'rien':
            print('Match Nul !!')
            break
        liste_vide = input_ordi(liste_vide)
        plateau = placement_ordi(liste_vide,plateau)
        print_plateau(plateau)
        partie = est_victoire(plateau) #retour à mettre en place
        if partie == False:
            break
    input_rejouer()


def input_rejouer():
    ''' Fonction qui demande à l'utilisateur s'il veut jouer une nouvelle partie.
    Argument:
        None
    Retour:
        None
    '''
    rejouer = True
    while rejouer:
        reponse = input('Voulez-vous rejouer ?\n1 - Oui\n2 - Non : ')
        if reponse not in '12':
            print('reponse non valide\n')
        elif reponse == '1':
            print('\n\n')
            rejouer = False
            joue_partie()
        else:
            print('Bye, Bye !!\n')
            rejouer = False
    
