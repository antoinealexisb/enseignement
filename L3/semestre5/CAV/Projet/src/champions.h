/*
 *  champions.h
 *  Fichier contenant toutes les signatures de fonctions permettant d'initialiser, créer et afficher
 *  les champions.
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */

#ifndef _CHAMPIONS_H
#define _CHAMPIONS_H
#include <stdlib.h>
#include "couleurs.h"

/**
 Structure possedant le nom, le type, la force, la resistance, les pv, et les CE du champion.
 **/
typedef struct champion {
    char *nom;
    char *type;
    unsigned char force;
    unsigned char resistance;
    int pv;
    int pv_max;
    unsigned char CE;
} Champion;

/****
 Fonction initChampion qui permet d'initialiser une instance de la structure Champion avec les informations permettant de composer les caracteristiques d'un Champion.
 @nom (char *) chaine de caractere contenant le nom du soin.
 @type (char *) chaine de caractere contenant le type du champion.
 @force (unsigned char) force du champion.
 @resistance (unsigned char) resistance du champion.
 @pv (int) pv du champion
 @ce (unsigned char) cout du champion.
 #champion (Champion *) retourne l'instance créée.
 */
Champion* initChampion(char* nom, char* type,unsigned char force,unsigned char resistance,int pv,int ce);

/****
 Fonction CreeTabChampionLegume qui permet de creer le tableau contenant les champions de type legume.
 #tab (Champion **) tableau contenant les champions de type legume.
 */
Champion** CreeTabChampionLegume();

/****
 Fonction CreeTabChampionFruit qui permet de creer le tableau contenant les champions de type fruit.
 #tab (Champion **) tableau contenant les champions de type fruit.
 */
Champion** CreeTabChampionFruit();

/****
 Fonction printfChampion qui permet d'afficher les caracteristiques du champion mit en parametre.
 @champion (Champion *) un champion.
 */
void printfChampion(Champion *champion);

/****
 Fonction printPresentation qui permet d'afficher les caracteristiques des champions de type legume et fruit.
 @tab (Champion **) tableau de champions de type legume.
 @tab2 (Champion **) tableau de champions de type fruit.
 */
void printPresentation(Champion **tab, Champion **tab2);

/****
 Fonction printTabVegetaux qui permet d'afficher les caracteristiques des champions de type legume.
 @tab (Champion **) tableau de champions de type legume.
 */
void printTabVegetaux(Champion **tab);

/****
 Fonction printTabFruit qui permet d'afficher les caracteristiques des champions de type fruit.
 @tab (Champion **) tableau de champions de type fruit.
 */
void printTabFruit(Champion **tab2);

/****
 Fonction freeTableauChampion qui permet de free completement le tableau de champions.
 @tab (Champion **) tableau contenant les champions.
 */
void freeTableauChampion(Champion **tab);


#endif

