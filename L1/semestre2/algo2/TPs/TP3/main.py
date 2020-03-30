__author__ = 'Antoine-Alexis Bourdon <antoine-alexis_bourdon@ens.univ-artois.fr>'
__date__= '26/02/2018'


###Importation des modules.

from PuissanceQuatre import PuissanceQuatre
import random


###Script Principal
def main():
    p4 = PuissanceQuatre()
    joueur = random.randint(0,1)
    while not p4.partie_finie():
        print(p4)
        print("Aux",p4.carac(joueur),"de jouer")
        choix = int(input("Dans quelle colonne voulez-vous jouer ? "))
        res = p4.pose_colonne(choix,joueur)
        if not res :
            print("Non, ce n’est pas possible.")
        else :
            joueur = (joueur+1)%2
    print(p4)
    print("Partie finie. Bravo")

if __name__ == '__main__':
    main()
