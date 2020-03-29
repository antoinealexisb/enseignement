#BOURDON Antoine-Alexis


from random import *
from string import ascii_letters
from figures_pendu import *

#Déclaration des constantes
ACCENTS = 'àáâäèéêëìíîïòóôöùúûüç'
ALPHABET = ascii_letters + ACCENTS + ACCENTS.upper()

##############INTRO##########
def intro():
    """ presentation du jeu au joueur
argument:
none
return:
none"""
    print("#################\n#               #\n#               #\n#LE JEU DU PENDU#\n#               #\n#               #\n################# ")

def dictionnaire() :
    '''Accède au fichier texte dico.txt, et retourne la liste des lignes de texte du fichier.
    Arguments :
    nom_fich : str -- le nom du fichier à lire.
    Retour :
    list(str) -- la liste des lignes du texte contenu dans dico.txt.
    '''
    liste_dico = []# Crée la liste qui contiendra le résultat.
    fich = open('dico.txt', 'r')# Ouvre le fichier, pour le lire (r = read).
    ligne = fich.readline()# Lit une ligne de texte du fichier.
    while (ligne != '') :# Lorsque la ligne sera égale à ’’, on sera arrivé au bout du fichier.
        liste_dico.append(ligne.rstrip()) # Enlève les espaces, les fins de ligne, etc à la fin de ligne
        # et l’ajoute dans la liste.
        ligne = fich.readline()   # Lit la ligne suivante.
    fich.close()# Ferme le fichier.
    return liste_dico# Retourne la liste


############## 1 #############

def choisis_mot():
    """La fonction choisis_mot reçoit une liste de chaînes de caractères en argument retourne une chaîne aléatoirement choisie dans le fichier dico.txt.
    Argument:
    liste --> str
    return:
    chaine[x] --> str """
    chaine=dictionnaire()
    
    x=randint(0,len(chaine)-1)
    
    return chaine[x]

############ 2 #############

def input_lettre(lettre_entrees):
    """La fonction input_lettre qui reçoit une chaîne de caractères lettres_entrees
en argument et qui retourne une lettre (chaîne de caractères).
 argument:
 lettre_entrees --> str
 return
 lettre --> str"""
    
       
    while True:
        lettre=input('Entrez une lettre : ')
        
        if lettre in lettre_entrees:
            print("Cette lettre a deja été choisi.")        
        elif len(lettre)!=1:
            print("Une seule lettre dois être rentrée.")
        elif lettre not in ALPHABET:
            print("Ceci n'est pas une lettre.")
                    
        else:
            break
        
    lettre_entrees+= lettre
    #print('test :',lettre,'  ',lettre_entrees)
    return lettre
	
################# 3 #############

def dessine_pendu(erreur):
    """La fonction dessine_pendu recoit un entier n et affiche l'image correspondant à l'entier
argument;
entier --> int"""
    print(FIGURES_PENDU[erreur])

################ 3.2 ###########

def affiche_erreurs(erreurs):
    print('Erreurs :')
    for i in range(len(erreurs)):
        print(erreurs[i], end=" ")


############# 3.3 ############

def affiches_correctes(correctes,mot_secret):
    #test=len(mot_secret)*['_']
    for i in range(len(mot_secret)):
        if mot_secret[i] in correctes:
            print(mot_secret[i], end =" ")
        else :
            print("_", end=" ")
    print()


    

########## 4 ############
def verification(lettre_entrees,mot_secrets):
    """permet de savoir si le mot_secrets est dans les lettre_entrees
        argument:
            lettre_entrees--> str
            mot_secret --> str
        return:
            retourne soit False si mot_secret n'est pas dans lettre_entrees et True inversement"""
    for i in range (len(mot_secrets)):
        if not(mot_secrets[i] in lettre_entrees):
            return False
    return True

def rejouer():
    """permet de recommencer si le joueur desir
argument:
--> none
return:
--> main"""
    choix=input("Voulez vous rejouez ?(Y/N) :").lower() #mettre la chaine en miniscule
    decision=True
    
    while decision:
        if choix == "y":
            main()
        elif choix == "n":
            print("partie terminer")
            end=False
            break
        else:
            choix=input("Voulez vous rejouez ?(Y/N) :").lower() #mettre la chaine en miniscule
            
def main():
    """Fonction partie excutan la partie
argument:
--> none
return:
--> True si gagner et False si perdu"""
    intro()
    erreur = 0
    mot_secrets=choisis_mot()
    lettre_entrees =[]
    end=True
    partie=False
    while end :
        letter_proposer=""
        for i in range(len(lettre_entrees)):
           letter_proposer+=lettre_entrees[i]+" "
        dessine_pendu(erreur)
        print("Lettres déjà proposées :", letter_proposer)
        affiches_correctes(lettre_entrees,mot_secrets)
        print("Lettre fausse :")
        lettre = input_lettre(lettre_entrees)
        
        if lettre in mot_secrets:
                        
                     
            if verification(lettre_entrees,mot_secrets):
                print('tu as gagné')
                end = False
                partie = True
                
        else:
            erreur = erreur + 1
            if erreur >= 6:
                dessine_pendu(erreur)
                print("vous êtes pendu, le mot était :", mot_secrets)
                end=False
                
    rejouer()
        
if __name__ == "__main__":
    main()

