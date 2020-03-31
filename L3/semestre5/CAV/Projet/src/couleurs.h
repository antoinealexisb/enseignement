/*
 *  couleur.h
 *  Fichier contenant toutes les signatures de fonctions concernant la couleur de l'affichage.
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */

#ifndef _COULEURS_H
#define _COULEURS_H
#include <stdio.h>
#include <time.h>
/* Fonction pour effacé l'ecran (=clear)*/
#define clear() printf("\033[H\033[J")

/****
 Fonction rouge qui permet d'afficher les futurs caractères en couleurs rouges.
 Utilise les caractères d'échappement prévu sur Linux.
 */
void rouge();

/****
 Fonction jaune qui permet d'afficher les futurs caractères en couleurs jaunes.
 Utilise les caractères d'échappement prévu sur Linux.
 */
void jaune();

/****
 Fonction vert qui permet d'afficher les futurs caractères en couleurs vertes.
 Utilise les caractères d'échappement prévu sur Linux.
 */
void vert();

/****
 Fonction vert_blinck qui permet d'afficher les futurs caractères en couleurs vertes et clignotant.
 Utilise les caractères d'échappement prévu sur Linux.
 */
void vert_blink();

/****
 Fonction magenta qui permet d'afficher les futurs caractères en couleurs magenta.
 Utilise les caractères d'échappement prévu sur Linux.
 */
void magenta();

/****
 Fonction orange qui permet d'afficher les futurs caractères en couleurs jaune(et non orange :D ).
 Utilise les caractères d'échappement prévu sur Linux.
 */
void orange();

/****
 Fonction reset qui permet d'afficher les futurs caractères avec les paramètres par défaut.
 Utilise les caractères d'échappement prévu sur Linux.
 */
void reset();

/****
 Fonction waitFor qui permet d'attendre un certain nombre de secondes avant la reprise de la fonction  qui l'appel.
 @secs (unsigned int) le nombre de secondes
 */
void waitFor(unsigned int secs);

#endif
