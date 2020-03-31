/*
 *  soins.h
 *  Fichier contenant toutes les signatures de fonctions permettant d'initialiser, créer et afficher
 *  les soins.
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */

#ifndef _SOINS_H
#define _SOINS_H
#include <stdlib.h>
#include "couleurs.h"

/**
 Structure possedant le nom, les CE, les CA, les volumes et les effet du soin.
 **/
typedef struct care{
  char *nom;
  unsigned char CE;
  unsigned char CA;
  unsigned char volumes;
  unsigned char minEffet;
  unsigned char maxEffet;
} Care;

/****
 Fonction initSoin qui permet d'initialiser une instance de la structure Care avec les
 informations permettant de composer les caracteristiques d'un soin.
 @nom (char *) chaine de caractere contenant le nom du soin.
 @CE (unsigned char) nombre de Crédit d'équipement de l'arme.
 @CA (unsigned char) nombre de Crédit d'Action de l'arme.
 @volumes (unsigned char) nombre de fois que le soin peut être activé par tour.
 @minEffet (unsigned char) pv minimal que l'on peut gagner.
 @maxEffet (unsigned char) pv maximal que l'on peut gagner.
 #soin (Care) retourne l'instance créée.
 */
Care* initSoin(char *nom, unsigned char CE, unsigned char CA, unsigned char volumes, unsigned char minEffet, unsigned char maxEffet);

/****
 Fonction CreerTabSoins qui permet de creer le tableau contenant les Soins.
 #tab (Care **) tableau contenant les Soins.
 */
Care** CreerTabSoins();

/****
 Fonction printfCare qui permet d'afficher les caracteristiques du soin mit en parametre.
 @soin (Care *) un soin.
 */
void printfCare(Care *soin);

/****
 Fonction printTabSoin qui permet d'afficher les caracteristiques de touts les Soins du tabSoins.
 @tabSoins (Care **) tableau contenant les Soins.
 */
void printTabSoin(Care **tabSoins);

/****
 Fonction freeTableauSoins qui permet de free completement le tableau de Soins.
 @tabSoins (Care **) tableau contenant les Soins.
 */
void freeTableauSoins(Care **tabSoins);

#endif
