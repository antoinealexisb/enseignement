/*
 *  armes.h
 *  Fichier contenant toutes les signatures de fonctions permettant d'initialiser, créer et afficher
 *  les Armes.
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */

#ifndef _ARMES_H
#define _ARMES_H
#include <stdlib.h>
#include "couleurs.h"

/**
 Structure possedant le nom, les CE, les CA, les Degats et la portée de l'arme
 **/
typedef struct weapon{
    char *nom;
    unsigned char CE;
    unsigned char CA;
    unsigned char minDegat;
    unsigned char maxDegat;
    unsigned char portee;
} Weapon;

/****
 Fonction initWeapon qui permet d'initialiser une instance de la structure Weapon avec les informations permettant de composer les caracteristiques d'une arme.
 @nom (char *) chaine de caractere contenant le nom de l'arme.
 @CE (unsigned char) nombre de Crédit d'équipement de l'arme.
 @CA (unsigned char) nombre de Crédit d'Action de l'arme.
 @minDegat (unsigned char) degat minimal de l'arme.
 @maxDegat (unsigned char) degat maximal de l'arme.
 @portee (unsigned char) portee maximale de l'arme.
 #weapon (Weapon) retourne l'instance créée.
 */
Weapon* initWeapon(char *nom, unsigned char CE, unsigned char CA, unsigned char minDegat, unsigned char maxDegat, unsigned char portee);

/****
 Fonction CreerTabArmes qui permet de creer le tableau contenant les Armes.
 #tab (Weapon **) tableau contenant les Armes.
 */
Weapon** CreerTabArmes();

/****
 Fonction printfArme qui permet d'afficher les caracteristiques de l'arme mit en parametre.
 @weapon (Weapon *) une arme.
 */
void printfArme(Weapon *weapon);

/****
 Fonction printTabArme qui permet d'afficher les caracteristiques de toutes les armes du tabArmes.
 @tabArmes (Weapon **) tableau contenant les Armes.
 */
void printTabArme(Weapon **tabArmes);

/****
 Fonction freeTableauArmes qui permet de free completement le tableau d'armes.
 @tabArmes (Weapon **) tableau contenant les Armes.
 */
void freeTableauArmes(Weapon **tabArmes);
#endif

