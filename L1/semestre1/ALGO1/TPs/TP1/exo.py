#importation
from math import sqrt
from math import sin
__author__ = 'Antoine-Alexis BOURDON <antoine-alexis_bourdon@ens.univ-artois.fr>'
pi = float(3.14)

def celFah():
    '''
    Cette fonction converti des °C en °F.
    '''
    celsius = float(input("\nEntrez la température en Celsius : "))
    fahrenheit = 32+(1.8*celsius)
    print('votre resultat en Fahrenheit :',fahrenheit,'\n\n')

def aireTrap():
    '''
    Cette fonction calcul l'aire d'un trapèze.
    '''
    hauteur = float(input("\nEntrez la hauteur du trapèze en cm : "))
    largeur_inf = float(input("\nEntrez la largeur de la base inférieur du trapèze en cm : "))
    largeur_sup = float(input("\nEntrez la largeur de la base supérieur du trapèze en cm : "))
    aire = (1/2)*(largeur_inf+largeur_sup)*hauteur
    print('L\'aire vaut : ', aire, ' cm\n\n')

def miniCal():
    '''
    Mini calculatrice 
    '''
    choix_calculette = input("Entrez le numéro du programme à exercuter \n 1-Aire du cercle \n 2-Aire de l'ellipse \n 3-Aire du triangle équilatéral \n 4-Volume du cone \n 5-Volume de la sphère \n 6-Aire du traingle arbitraire \n :")
    if choix_calculette == "1":
        rayon = float(input("\nEntrez du rayon du cercle "))**2
        aire = pi*rayon
        print("Aire du cercle vaut :", aire, "cm\n\n")
    if choix_calculette == "2":
        rayon1 = float(input("\nEntrez le premier rayon de l'ellipse "))
        rayon2 = float(input("\nEntrez le deuxième rayon de l'ellipse "))
        aire = pi*rayon1*rayon2
        print("Aire de l'ellipse vaut :", aire, "cm\n\n")
    if choix_calculette == "3":
        hauteur = float(input("\nEntrez la hauteur du triangle equilateral: "))
        aire = ((hauteur**(2)*sqrt(3))/3)
        print("Aire du triangle equilatéral vaut :", aire, "cm\n\n")
    if choix_calculette == "4":
        hauteur = float(input("\nEntrez la hauteur du cone: "))
        rayon = float(input("\nEntrez le rayon du cone:"))
        volume = ((pi*rayon**(2)*hauteur)/3)
        print("Volume du cone vaut :", volume, "cm\n\n")
    if choix_calculette == "5":
        rayon = float(input("\nEntrez le rayon de la sphère:"))
        volume = ((4*pi*rayon**(3))/3)
        print("Volume de la sphère vaut :", volume, "cm\n\n")
    if choix_calculette == "6":
        distanceab = float(input("\nEntrez la distance ab:"))
        sinc = float(input("\n Entrez l'angle C"))
        aire = (1/2)*distanceab*sin(sinc)
        print("L'aire du triangle arbitraire vaut :", aire, "cm\n\n")


boucle=1
print('TP1 - BOURDON ANTOINE-ALEXIS LMI-2\n')
while boucle == 1:
    choix = input("Entrez le numéro du programme à executer : \n 1= Conversion Celsius en Fahrenheit. \n 2= Calcul Aire trapèze \n 3= Mini calculette\n")
    if choix == '1':
        celFah()
    elif choix =='2' :
        aireTrap()
    else :
        miniCal()
    boucle = int(input('Voulez vous continuer ?\n 1 - Oui\n 2 - Non\n\n'))
    
