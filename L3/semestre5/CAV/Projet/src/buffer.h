/*
 *  buffer.h
 *  Fichier contenant toutes les signatures de fonctions permettant de garder pour chaque camp
 *  son historique de commandes et donc ne pas voir les commandes de l'autre quand c'est son tour.
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */

#ifndef _BUFFER_H
#define _BUFFER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 Structure pour retenir les commandes et leur retour.
*/
typedef struct buffer{
  char *tab[10];
} Buffer;

/****
 Fonction moveBuffer qui permet de décaler le tableau de 1 à chaque nouvelle entrée.
 Si le tableau est plein, la première commande entrée est free.
 @tab (Buffer *) le buffer de la structure Buffer.
 */
void moveBuffer(Buffer *tab);

/****
 Fonction freeBuffer permettant de free toutes cellules du *tab de la structure Buffer et de free tab.
 @tab (Buffer *) le buffer de la structure Buffer.
 */
void freeBuffer(Buffer *tab);

/****
 Fonction addBuffer qui permet de rajouter un element dans le *tab de la structure Buffer.
 @tab (Buffer *) le buffer de la structure Buffer.
 @str (char *) chaine de caractère à ajouter.
 */
void addBuffer(Buffer *tab, char *str);

/****
 Fonction printBuffer qui permet d'afficher le contenu du *tab de la structure Buffer.
 @tab (Buffer *) le buffer de la structure Buffer.
 */
void printBuffer(Buffer *tab);


#endif

