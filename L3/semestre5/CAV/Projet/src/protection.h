/*
 *  protection.h
 *  Fichier contenant toutes les signatures de fonctions permettant d'initialiser, créer et afficher
 *  les protections.
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */

#ifndef _PROTECTION_H
#define _PROTECTION_H
#include <stdlib.h>
#include "couleurs.h"

/**
 Structure possedant le nom, les CE, les CA et la probabilite de la protection.
 **/
typedef struct protection{
    char *nom;
    unsigned char CE;
    unsigned char CA;
    unsigned char proba;
} Protection;

/****
 Fonction initProtection qui permet d'initialiser une instance de la structure Protection avec les  informations permettant de composer les caracteristiques d'une protection.
 @nom (char *) chaine de caractere contenant le nom du soin.
 @CE (unsigned char) nombre de Crédit d'équipement de l'arme.
 @CA (unsigned char) nombre de Crédit d'Action de l'arme.
 @proba (unsigned char) probalite que la protection reussisse.
 #protection (Protection) retourne l'instance créée.
 */
Protection* initProtection(char *nom, unsigned char CE, unsigned char CA, unsigned char proba);

/****
 Fonction CreerTabProtections qui permet de creer le tableau contenant les Protections.
 #tab (Protection **) tableau contenant les Protections.
 */
Protection** CreerTabProtections();

/****
 Fonction printfProtection qui permet d'afficher les caracteristiques de la protection mit en parametre.
 @protection (Protection *) une protection.
 */
void printfProtection(Protection *protection);

/****
 Fonction printTabProtection qui permet d'afficher les caracteristiques de toutes les Protections du tabProtections.
 @tabProtections (Protection **) tableau contenant les Protections.
 */
void printTabProtection(Protection **tabProtections);

/****
 Fonction freeTableauProtections qui permet de free completement le tableau de Protections.
 @tabProtections (Protection **) tableau contenant les Protections.
 */
void freeTableauProtections(Protection **tabProtections);
#endif
