#BOURDON Antoine-Alexis

#importation
#global c'est le mal.
from random import *

KM_VOYAGE = 300 # Distance ‡ parcourir pour gagner.
KM_NORM_MIN = 10 # Distance min. ‡ la vitesse normale.
KM_NORM_MAX = 15 # Distance max. ‡ la vitesse normale.
KM_RAP_MIN = 20 # Distance min. ‡ toute vitesse.
KM_RAP_MAX = 25 # Distance max. ‡ toute vitesse.
AVANTAGE_VOYAGEUR = 20 # L'avantage initial du voyageur.
GOURDE_PLEINE = 12 # Le nombre de gorgÈes de la gourde.
MORT_SOIF = 4 # Nombre de tours pour mourir de soif.
MORT_FATIGUE = 4 # Nombre de tours pour mourir de fatigue.
DIF_AIDE = 3 # DifficultÈ pour trouver de l'aide.
AVANCE_NATIFS = 4 # Vitesse des natifs.
SPECIAL=10 #probabilitées pour les evenements aleatoire BONUS
SPECIAL_BLOCK=3 #nombre de jour pour la tempete

print('LE JEU DU CHAMEAU !')
print('\nVous avez volé un chameau pour traverser le grand désert.')
print('Votre objectif est de survivre à la traversée de 300 km sans etre attrapé(e).')

km_voyageur = 0 # Distance totale parcourue.
km_natifs = km_voyageur - AVANTAGE_VOYAGEUR # Distance parcourue par les natifs.
gourde = GOURDE_PLEINE // 2 # Nombre de gorgÈs dans la gourde.
soif = 0 # Niveau de soif du voyageur.
fatigue = 0 # Niveau de fatigue du chameau.
termine = False #Boucle While pour arreter la boucle du jeu en cours
termine_jeu = '1' #Boucle While pour arreter le jeu totalement
alea_block=0 #Reference pour le nombre de jour de la tempete


def boire(gourde_def):
    ''' Vérifie l'état de la gourde quand l'utilisateur boit.
Arguments :
    gourde_def : correspond à la valeur que possède la variable gourde
Retour :
    Affiche un message dissant l'etat de la gourde si vide sinon affiche un message que la gourde possède une gorgée de moins
    retour de la valeur gourde_def pour la variable gourde'''
    if gourde_def==0:
        print('la gourde est vide!')
    else :
        soif=0
        print('Vous avez bu une gorgée.')
        gourde_def = gourde -1
    return gourde_def

def avancement_normal(fatigue_def,km_voyageur_def):
    ''' Fait avancer l'utilisateur normalement et rajoute un fatigue au voyageur.
Arguments :
    fatifue_def : correspond à la valeur que possède la variable fatigue
    km_voyageur_def : correspond à la valeur que possède la variable km_voyageur
Retour :
    Affiche un message dissant combien de kilometre a été parcouru et le parcours total
    retour de la valeur fatigue_def pour la variable fatigue, de me^me pour km_voyageur_def pour km_voyageur'''
    fatigue_def += 1
    alea = randint(KM_NORM_MIN,KM_NORM_MAX)
    km_voyageur_def += alea
    print('Vous avez avancé de ',alea,' km.\n')
    print('Vous avez parcouru un total de',km_voyageur_def,' km jusqu\'ici.')
    return (fatigue_def,km_voyageur_def)

def avancement_rapide(fatigue_def,km_voyageur_def):
    ''' Fait avancer l\'utilisateur rapidement et rajoute un fatigue au voyageur.
Arguments :
    fatifue_def : correspond à la valeur que possède la variable fatigue
    km_voyageur_def : correspond à la valeur que possède la variable km_voyageur
Retour :
    Affiche un message dissant combien de kilometre a été parcouru et le parcours total
    retour de la valeur fatigue_def pour la variable fatigue, de me^me pour km_voyageur_def pour km_voyageur'''
    
    fatigue_def += 2
    alea = randint(KM_RAP_MIN,KM_RAP_MAX)
    km_voyageur_def += alea
    print('Vous avez avancé de ',alea,' km.\n')
    print('Vous avez parcouru un total de',km_voyageur_def,' km jusqu\'ici.')
    return (fatigue_def,km_voyageur_def)

def repos(fatigue_def):
    ''' Repose le chmeau et affiche le message et cela.
Arguments :
    fatifue_def : correspond à la valeur que possède la variable fatigue    
Retour :
    Affiche un message disant que le chameau s\'est bien reposé '''
    
    fatigue_def=0
    print('Votre chameau s\'est bien reposé.')
    return fatigue_def

def aide(gourde_def):
    ''' Aide le voyageur en lui remplicant sa gourde.
Arguments :
    gourde_def : correspond à la valeur que possède la variable gourde    
Retour :
    Affiche un message disant l\'état de la gourde  '''
    alea = randint(0,DIF_AIDE)
    if alea == 0:
        print('Vous avez trouvé de l\'aide.\n')
        if gourde_def >= GOURDE_PLEINE:
            print('La gourde est déjà pleine!')
        else:
            print('Quelques gorgées ont été ajoutées à votre gourde.')
            if gourde_def+3 > GOURDE_PLEINE:
                gourde_def = GOURDE_PLEINE
            else:
                gourde_def +=3
    else:
        print('Vous n\'avez pas trouvé de l\'aide.\n')
    return gourde_def

def gagne(km_voyageur_def,termine_def):
    ''' Dit si le voyageur à gagner.
Arguments :
    km_voyageur_def : correspond à la valeur que possède la variable km_voyageur
    termine_def : correspond à la valeur que possède la variable termine
Retour :
    Affiche un message disant que le joueur à gagné  '''
    if km_voyageur_def >=KM_VOYAGE:
        print('Le joueur a gagné!!')
        termine_def = True
    return termine_def

def avancement_natifs(km_natifs_def,km_voyageur_def):
    ''' Calcul l'avancement des natifs et leur position par rapport au voyageur.
Arguments :
    km_voyageur_def : correspond à la valeur que possède la variable km_voyageur
    km_natifs_def : correspond à la valeur que possède la variable km_natifs_def
Retour :
    Affiche de la distance et aussi si l'utilsateur a perdu '''
    termine_def=False
    alea=randint(0,AVANCE_NATIFS)
    if alea==0:
        km_natifs_def += randint(KM_RAP_MIN,KM_RAP_MAX)
        print('Les natifs sont à ',km_voyageur_def-km_natifs_def,' km derrière vous.')
        if km_natifs_def>=km_voyageur_def :
            print('Vous avez été attrapé par les natifs !\nLe joueur a perdu !!')
            termine_def = True
    else:
        km_natifs_def += randint(KM_NORM_MIN,KM_NORM_MAX)
        if km_natifs_def>=km_voyageur_def :
            print('Vous avez été attrapé par les natifs !\nLe joueur a perdu !!')
            termine_def = True
        print('Les natifs sont à ',km_voyageur_def-km_natifs_def,' km derrière vous.')
    return(km_natifs_def,termine_def)

def soif_prog(soif_def,termine_def,MORT_SOIF):
    ''' Dit l'état de soif du voyageur.
Arguments :
    soif_def : correspond à la valeur que possède la variable soif
    termine_def : correspond à la valeur que possède la variable termine
    MORT_SOIF: correspond à la valeur MORT_SOIF
Retour :
    Affiche un message disant l'état
    retourne la soif et le termine '''
    if soif_def ==0:
        print('Vous n\'avez pas soif.')
    elif soif_def ==1:
        print('Vous avez un peu soif.')
    elif soif_def ==2:
        print('Vous avez beaucoup soif!')
    elif soif_def ==3:
        print('Vous allez mourir de soif!!')
    elif soif_def >= MORT_SOIF:
        print('Le joueur a perdu !!')
        termine_def = True
    soif_def += 1
    return (soif_def,termine_def)

def fatigue_prog(fatigue_def,termine_def):
    ''' Dit si le chameau est fatigué.
Arguments :
    fatigue_def : correspond à la valeur que possède la variable fatigue
    termine_def : correspond à la valeur que possède la variable termine
Retour :
    Affiche un message disant la fatigue du chameau
    retourne la fatigue et le termine'''
    if fatigue_def ==0:
        print('Le chameau est en bonne forme.')
    elif fatigue_def ==1:
        print('Le chameau est un peu fatigué.')
    elif fatigue_def ==2:
        print('Le chameau est très fatigué !')
    elif fatigue_def ==3:
        print('Le chameau va mourir de fatigue !!')
    elif fatigue_def >= MORT_FATIGUE:
        print('Le joueur a perdu !!')
        termine_def = True
    return termine_def

def gorge_rest(gourde):
    ''' donne les nombre de gorgées restante dans la gourde.

Arguments:
    gourde correspond à la veleur de gourde
Retour : Affiche de message de gorgées restante
Aucune retour

'''
    print('Votre gourde contient ',gourde,' gorgées d\'eau.')

while not termine_jeu=='2':       
    while not termine==True:
        if alea_block <1: #empeche la variable aléatoire de donné un evenement aléatoire tant que le nombre de jours de t'empete n'est pas egale à  0
            alea = randint(0,SPECIAL) #Variable aléatoire pour les evénements aléatoires
        print('OPTIONS :\n1. Boire \n2. Avancer normalement \n3. Avancer à toute vitesse \n4. Repos \n5. Espérer de l\'aide \nT. Terminer la partie\n\nQu\'allez-vous faire ?', end=' ')
        choix = input()
        if termine == True:
            print('test')
        if choix =='1': #BOIRE
            if alea<=1:
                if alea==0:
                    gourde=GOURDE_PLEINE
                    print('Le joueur a trouvé une oasis.\nVotre gourde est pleine')
                else:
                    alea_block = randint(1,SPECIAL_BLOCK)
                    print('Le joueur subit une tempête.\n Le joueur ne peut même pas boire, ni avancer, ni tenter de trouver de l\'aide')
                    print('la tempête risque de durée : ',alea_block,'jours\n')
                    km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
                    termine=fatigue_prog(fatigue,termine)
                    alea_block-=1
            gourde=boire(gourde)
            gorge_rest(gourde)
            km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
            termine=fatigue_prog(fatigue,termine)
        elif choix =='2': #Avancer normalement
            if alea<=1:
                if alea==0:
                    gourde=GOURDE_PLEINE
                    print('Le joueur a trouvé une oasis.\nVotre gourde est pleine')
                else:
                    alea_block = randint(1,SPECIAL_BLOCK)
                    print('Le joueur subit une tempête.\n Le joueur ne peut même pas boire, ni avancer, ni tenter de trouver de l\'aide')
                    print('la tempête risque de durée : ',alea_block,'jours\n')
                    km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
                    termine=fatigue_prog(fatigue,termine)
                    alea_block-=1
            fatigue,km_voyageur=avancement_normal(fatigue,km_voyageur)
            km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
            soif,termine=soif_prog(soif,termine,MORT_SOIF)
            gorge_rest(gourde)
            termine=fatigue_prog(fatigue,termine)
            termine=gagne(km_voyageur,termine)
        elif choix =='3': #Avancer à toute vitesse
            if alea<=1:
                if alea==0:
                    gourde=GOURDE_PLEINE
                    print('Le joueur a trouvé une oasis.\nVotre gourde est pleine')
                else:
                    alea_block = randint(1,SPECIAL_BLOCK)
                    print('Le joueur subit une tempête.\n Le joueur ne peut même pas boire, ni avancer, ni tenter de trouver de l\'aide')
                    print('la tempête risque de durée : ',alea_block,'jours\n')
                    km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
                    termine=fatigue_prog(fatigue,termine)
                    alea_block-=1
            fatigue,km_voyageur=avancement_rapide(fatigue,km_voyageur)
            km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
            soif,termine=soif_prog(soif,termine,MORT_SOIF)
            gorge_rest(gourde)
            termine=fatigue_prog(fatigue,termine)
            termine=gagne(km_voyageur,termine)
        elif choix =='4': #repos
            if alea<=1:
                if alea==0:
                    gourde=GOURDE_PLEINE
                    print('Le joueur a trouvé une oasis.\nVotre gourde est pleine')
                else:
                    alea_block = randint(1,SPECIAL_BLOCK)
                    print('Le joueur subit une tempête.\n Le joueur ne peut même pas boire, ni avancer, ni tenter de trouver de l\'aide')
                    print('la tempête risque de durée : ',alea_block,'jours\n')
                    km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
                    termine=fatigue_prog(fatigue,termine)
                    alea_block-=1
            fatigue=repos(fatigue)
            km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
            soif,termine=soif_prog(soif,termine,MORT_SOIF)
            gorge_rest(gourde)
            termine=fatigue_prog(fatigue,termine)
        elif choix =='5': #Aide
            if alea<=1:
                if alea==0:
                    gourde=GOURDE_PLEINE
                    print('Le joueur a trouvé une oasis.\nVotre gourde est pleine')
                else:
                    alea_block = randint(1,SPECIAL_BLOCK)
                    print('Le joueur subit une tempête.\n Le joueur ne peut même pas boire, ni avancer, ni tenter de trouver de l\'aide')
                    print('la tempête risque de durée : ',alea_block,'jours\n')
                    km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
                    termine=fatigue_prog(fatigue,termine)
                    alea_block-=1
            gourde=aide(gourde) #Quitter
            km_natifs,termine=avancement_natifs(km_natifs,km_voyageur)
            soif,termine=soif_prog(soif,termine,MORT_SOIF)
            gorge_rest(gourde)
            termine=fatigue_prog(fatigue,termine)
        elif choix =='42': #Mini Bonus
            print('Bravo tu as finis le jeu.\n Regarde "H2G2 le guide du voyageur galactique"\n')
            termine = True
        elif choix=='T':
            termine = True
        else:
            print('Option invalide!\n')
    termine_jeu=input('Voulez-vous jouez une nouvelle partie ?\n 1 - Oui\n 2 - Non\n')
    if termine_jeu != '2':
        km_voyageur = 0 # Distance totale parcourue.
        km_natifs = km_voyageur - AVANTAGE_VOYAGEUR # Distance parcourue par les natifs.
        gourde = GOURDE_PLEINE // 2 # Nombre de gorgÈs dans la gourde.
        soif = 0 # Niveau de soif du voyageur.
        fatigue = 0 # Niveau de fatigue du chameau.
        termine = False
        print('\n\n')
    else:
        print('Bye !!')
