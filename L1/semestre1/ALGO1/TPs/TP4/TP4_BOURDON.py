__author__ = 'BOURDON Antoine-Alexis'
__date__ = 'BONNE QUESTION'


print('##########################################')
print('# TP4 : Cryptage et décryptage de textes #')
print('##########################################')




from string import ascii_letters, digits

#Déclaration des constantes
ACCENTS = 'àáâäèéêëìíîïòóôöùúûüç'
ALPHABET = ascii_letters + ACCENTS + ACCENTS.upper() + digits
LONG_ALPHA = len(ALPHABET)

def belongs(car, chaine):
    '''Vérifie si car appartient à un des caractères de chaine.
    Arguments:
        car : String -- caractère à comparé
        chaine : String -- base de comparaison
    Retour:
        Boolean -- True si oui, False sinon.'''

    for i in chaine:
        if car == i:
            return True

    return False

def input_mode():
    '''Demande à l'utilisateur d'entrer c ou bien d.
    Arguments : None
    Retour : String -- l'entrée de l'utilisateur (c ou bien d)'''

    entree = input("Voulez-vous chiffrer ou déchiffrer un message (c/d) ? : ")
    entree = entree.lower()
    
    if not belongs(entree, 'cd'):
        print("Option invalide !")
        entree = input_mode()

    return entree

def is_entier_nat(chaine):
    '''Vérifie si chaine est un entier naturel.
    Argument:
        chaine : String -- chaine à vérifier
    Retour:
        Boolean -- Vrai si un entier, sinon Faux.'''

    for i in chaine:
        if not belongs(i, digits):
            return False

    return True
            
def input_cle():
    '''Demande à l'utilisateur d'entrer une clé de chiffrement entre
    1 et la longueur de ALPHABET.
    Arguments : None
    Retour : Integer -- cle de chiffrage'''

    cle_valide = False
    while cle_valide == False:

        entree = input("Entrez la clé de chiffrement (1-" + str(LONG_ALPHA) + ") : ")

        if is_entier_nat(entree):
            cle = int(entree)

            if not (cle >= 1 and cle < LONG_ALPHA):
                print("Entrée invalide !")
            else:
                cle_valide = True

        else:
            print("Entrée invalide !")

    return cle

def pos(c):
    '''Retourne l'indice de la lettre dans ALPHABET.
    Arguments :
        c : String -- chaîne de caractères à trouver dans ALPHABET
    Retour:
        i si c'est dans ALPHABET
        -1 sinon'''

    if belongs(c, ALPHABET):

        for i in range(LONG_ALPHA):
            if ALPHABET[i] == c:
                return i
    else:
        return -1

def car(n):
    '''Retour le caractère correspondant à la position n dans ALPHABET.
    Arguments :
        n : Integer -- Index dans ALPHABET
    Retour:
        String -- caractère de ALPHABET d'index n
        '''
                        
    return ALPHABET[n] # -_-

def chiffre_car(c,n):
    '''Retourne le chiffrement du caractère c par la clé n.
    Arguments :
        c : String -- caractère à chiffer
        n : Integer -- clé de chiffrage
    Retour :
        String -- caractère chiffré si contenu dans ALPHABET, sinon c
    '''

    if belongs(c, ALPHABET):
        return car((pos(c) + n) % LONG_ALPHA)

    return c


def cesar(message, mode, cle):
    '''Chiffre ou déchiffre un message avec la méthode Cesar.
    Arguments :
        message: String -- chaine de caractère à traiter
        mode: String -- c pour chiffrer, d pour déchiffrer
        cle: Integer -- cle de dechiffrage
    Retour:
        chiffre_mess: String -- message chiffré'''

    if mode == "d":
        cle = -cle

    chiffre_mess = ""
    for i in message:
        chiffre_mess += chiffre_car(i, cle)

    return chiffre_mess

def input_methode():
    '''Demande à l'utilisateur de choisir entre deux chiffrements :
    César (’c’) ou Vigenère (’v’).
    Argument: None
    Retour: String -- "c" ou "d"'''

    entree = input("Quelle méthode voulez-vous utiliser : Cesar (c) ou Vigenere (v) ? : ")
    entree = entree.lower()

    if not belongs(entree, 'cv'):
        print("Option invalide !")
        entree = input_methode()

    return entree

def vigenere(message, mode, mot_cle):
    '''Chiffre ou déchiffre un message avec la méthode Vigenère.
    Arguments:
        message: String -- chaine de caractère à traiter
        mode: String -- c ou v pour le mode de chiffrage
        mot_cle: String -- mot servant de clé de chiffrage
    Retour: String -- message chiffré'''

    chiffre_mess = ""

    for i in range(len(message)):
        cle = pos(mot_cle[i % len(mot_cle)])
        
        if mode == 'c':
            chiffre_mess += chiffre_car(message[i], cle)
        else:
            chiffre_mess += chiffre_car(message[i], -cle)
        
    return chiffre_mess

def main():
    '''Fonction principale du programme
    Argument : None
    Retour : None'''

    message = input("Entre votre message :\n")
    mode = input_mode()
    methode = input_methode()

    if methode == 'c':
        cle = input_cle()
        print("Résultat :\n" + cesar(message, mode, cle))
    else:
        cle = input("Entre le mot_clé : ")
        print("Résultat :\n" + vigenere(message, mode, cle))

main()
