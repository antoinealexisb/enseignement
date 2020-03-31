/*
 *  traitement.h
 *  Fichier contenant toutes les signatures de fonctions permettant le traitement des commandes en duel,  
 *  avec ou sans stratégies, et fonctions associer à ces commandes. 
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */
#ifndef _TRAITEMENT_H
#define _TRAITEMENT_H
#include "equipe.h"

/****
 Fonction traitement qui permet d'afficher le nom du champion avec son nombre de CA disponible et attend de recevoir une commande de l'utilisateur pour lancer une autre action (fonction, ou message d'erreur).
 @attaquant (Equipe *) equipe qui envoie les attaques.
 @defenseur (Equipe *) equipe qui reçoit les attaques.
 @inverseur (int) permet de savoir si c'est le tour du fruit, ou du legume.
 */
void traitement(Equipe *attaquant, Equipe *defenseur, int inverseur);

/****
 Fonction erreur qui affiche à l'utilisateur les différentes erreurs suite à sa commande.
 @equipe (Equipe *) l'équipe dont le retour erreur sera afficher.
 @codeRetour (int) numéro du code erreur.
 */
void erreur(Equipe *equipe, int codeRetour);

/****
 Fonction printTerrain qui affiche le terrain avec les deux équipes représentées par les lettres L et F.
 @equipe (Equipe *) la première equipe.
 @equipe2 (Equipe *) la deuxième equipe.
 */
void printTerrain(Equipe *equipe, Equipe *equipe2);

/****
 Fonction ajouterEquipeBuffer qui ajoute dans le buffer de l'équipe le retour de la commande show
 @equipe (Equipe *)
 */
void ajouterEquipeBuffer(Equipe *equipe);

/****
 Fonction infligeDegats qui inflige à l'adversaire les dégats de l'arme en fonction de la force, la
 résistance, la distance et la protection des équipes.
 @attaquant (Equipe *) equipe qui attaque.
 @defenseur (Equipe *) equipe qui se defend.
 #degatTotal (int) nombre de dégat si >=0, sinon code d'erreur.
 */
int infligeDegats(Equipe *attaquant, Equipe *defenseur, unsigned char n);

/****
 Fonction forward qui permet de faire avancer le champion sur le terrain dans la limite du terrain et 
 de l'emplacement de l'adversaire.
 @attaquant (Equipe *) equipe qui attaque.
 @defenseur (Equipe *) equipe qui defend.
 @n (int) nombre de pas à effectuer.
 #n (int) nombre de pas si >0, sinon code d'erreur.
 */
int forward(Equipe *attaquant, Equipe *defenseur, unsigned char n);

/****
 Fonction backward qui permet de faire reculer le champion sur le terrain dans la limite du terrain et 
 de l'emplacement de l'adversaire.
 @attaquant (Equipe *) equipe qui attaque.
 @defenseur (Equipe *) equipe qui defend.
 @n (int) nombre de pas à effectuer.
 #n (int) nombre de pas si >0, sinon code d'erreur.
 */
int backward(Equipe *attaquant, Equipe *defenseur, unsigned char n);

/****
 Fonction laCroixRouge qui permet de soigner le champion de l'équipe dans la limite de ses points de vie
 et du nombre de fois que le sort peut être utilisé par tour (volumes).
 @patient (Equipe *) equipe qui a besoin de soigner son champion.
 @volumes (char *) nombre de fois que le soin fût utilisé.
 @n (unsigned char) nombre de fois que l'utilisateur veut utiliser le sort de soin.
 #soinTotal (int) nombre de pv recuperer si soinTotal>0, sinon code d'erreur.
 */
int laCroixRouge(Equipe *patient, char *volumes, unsigned char n);

/**PARTIE 2*/

/**
 Fonction vies permettant de recuperer la valeur des pv et des pv_max du champion concerné lors de la
 lecture du fichier de stratégie en combat
 @attaquant (Equipe *) equipe qui utilise la stratégie.
 @defenseur (Equipe *) adversaire de l'équipe attaquant.
 @s (char *) contient l'expression life ou enemyLife.
 @vie (int *) variable qui contiendra la vie du champion concerné par la lecture de la stratégie.
 @pvMax (int *) variable qui contiendra la vie Maximale du champion concerné par la lecture de la stratégie.
 */
void vies(Equipe *attaquant, Equipe *defenseur, char *s, int *vie, int *pvMax);

/**
 Fonction qui permet d'écrire dans l'entrée standard (entrée clavier), une chaine de caractère correspondant à une commande.
 @s (*char) chaine de caractère à écrire dans l'entrée standard.
 */
void inStdin(char *s);

/**
 Fonction permettant de lire un fichier de stratégie, et d'appliquer les instructions ecrites dedans.
 @strat (Strategie *) Strategie à appliquer pour l'attaquant.
 @attaquant (Equipe *) equipe qui utilise la stratégie.
 @defenseur (Equipe *) adversaire de l'équipe attaquant.
 */
void lireFichier(Strategie *strat, Equipe *attaquant, Equipe *defenseur);

/**
 Fonction permettant de savoir si l'ennemi est à distance de tir de l'attaquant.
 @attaquant (Equipe *) equipe qui utilise la stratégie.
 @defenseur (Equipe *) adversaire de l'équipe attaquant.
 #(distance<=arme->portee) (int) 1 si l'ennemi est à distance sinon 0.
 */
int enemyInScope(Equipe *attaquant, Equipe *defenseur);
#endif

