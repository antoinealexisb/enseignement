/*
 *  partie2.h
 *  Fichier contenant toutes les signatures de fonctions permettant 
 *  la gestion de fichiers en .strat .
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */
#ifndef _PARTIE2_H
#define _PARTIE2_H
#include "traitement.h"
#define estNum(a)   ((a >= '0' && a <= '9') ? (1) : (0))


/****
 Fonction qui utilise les fonctions de vérification du fichier pour afficher les erreurs.
 @s (char *) nom du fichier.
 @tabArmes (Weapon **) tableau d'armes.
 # (int) si le fichier de stratégie est correct alors 1 sinon 0.
 */
int verifGeneral(char *s, Weapon **tabArmes);

/****
 Fonction qui vérifie si le nom dans la stratégie est present.
 @fichier (FILE *) pointeur vers le fichier ouvert.
 # (int) retourne 1 si valide , 0 sinon.
 */
int verifNom(FILE* fichier);

/****
 Fonction qui vérifie si l'arme est choisit et valide.
 @fichier (FILE *) pointeur vers le fichier ouvert.
 @Weapon (tabArmes **) tableau d'armes.
 # ind (int) retoune l'indice de l'arme si arme correcte sinon retourne -1;
 */
int verifArme(FILE* fichier, Weapon **tabArmes);

/****
 Fonction qui vérifie si le script de la stratégie est valide.
 @fichier (FILE *) pointeur vers le fichier ouvert.
 @ite (int) indicateur de boucle.
 # (int) si fichier valide renvoit 0.
 */
int verifFile(FILE* fichier,int ite);

char* nomFichier(FILE* fichier);

/****
 Fonction creerTabStrategie qui permet de creer le tableau contenant les différentes stratégie.
 @tabArmes (Weapon **) tableau d'armes.
 @tabPro (Protection **) tableau de protections.
 @tabSoins (Care **) tableau de soins.
 @nbArg (int) nombre d'argument dans argc(du main).
 @tabArg (char **) tableau des arguments.
 @nbFichiersStrat (int *) nombre de fichiers stratégies possibles (de base 4 + ensuite nbArg).
 #tab (Strategie **) tableau contenant les différentes stratégie.
 */
Strategie** creerTabStrategie(Weapon **tabArmes, Protection **tabPro, Care **tabSoins, int nbArg, char *tabArg[], int *nbFichiersStrat);

/****
 Fonction chooseNoms qui renvoi dans un tableau les indices des différents equipement
 @fichier (FILE *) pointeur vers le fichier ouvert.
 @cuseur (int) emplacement d'où le curseur doit commencer.
 @limite (int) limite de lecture du fichier.
 @tabArmes (Weapon **) tableau d'armes.
 @tabPro (Protection **) tableau de protections.
 @tabSoins (Care **) tableau de soins.

 */
int* chooseNoms(FILE* fichier,int curseur, int limite, Weapon **tabArmes, Protection **tabPro, Care **tabSoins);

/****
 Fonction printfDescription qui imprime une description de la stratégie (nom, arme, protection, soin).
 @strat (Strategie *) strategie.
 @tabArmes (Weapon **) tableau d'armes.
 @tabPro (Protection **) tableau de protections.
 @tabSoins (Care **) tableau de soins.
 */
void printfDescription(Strategie *strat, Weapon **tabArmes, Protection **tabPro, Care **tabSoins);

/****
 Fonction initStrategie qui permet d'initialiser une instance de la structure Strategie.
 @fichier (FILE *) pointeur vers le fichier ouvert.
 @tabArmes (Weapon **) tableau des armes.
 @tabPro (Protection **) tableau des protections.
 @tabSoins (Care **) tableau des soins.
 #Strategie (Strategie *) retourne l'instance créée.
 */
Strategie* initStrategie(FILE *fichier, Weapon **tabArmes, Protection **tabPro, Care **tabSoins);

/****
 Fonction detectionScript qui renvoi l'emplacement dans le fichier où commence les scripts.
 @fichier (FILE *) pointeur vers le fichier ouvert.
 */
int detectionScript(FILE *fichier);

/****
 Fonction afficheSuite qui affiche la suite du fichier (Fonction de deboguage).
 @strat (Strategie *) Strategie.
 */
void afficheSuite(Strategie *strat);

/****
 Fonction printfStrategies qui affiche les différentes stratégies disponible.
 @tab (Strategie **) tableau des strategies.
 @nbFichiersStrat (int) nombre de stratégies disponible.
 */
void printfStrategies(Strategie **tab, int nbFichiersStrat);

/****
 Fonction indWeapon renvoyant l'indice de l'arme correspondant au fichier de Stratégie.
 @s (char *) chaine de caractère pouvant correspondre au nom de l'arme.
 #ind (int) retourne l'indice de l'arme si existe, sinon retourne -1
 */
int indWeapon(char *s, Weapon **tabArmes);

/****
 Fonction indProtection renvoyant l'indice de la protection correspondant au fichier de Stratégie.
 @s (char *) chaine de caractère pouvant correspondre au nom de la protection.
 #ind (int) retourne l'indice de la protection si existe, sinon retourne l'indice de la protection Vanilla.
 */
int indProtection(char *s, Protection **tabPro);

/****
 Fonction indSoin renvoyant l'indice du soin correspondant au fichier de Stratégie.
 @s (char *) chaine de caractère pouvant correspondre au nom du soin.
 #ind (int) retourne l'indice du soin si existe, sinon retourne l'indice du soin Rambo.
 */
int indSoin(char *s, Care **tabSoins);

/****
 Fonction freeStrat qui supprime l'instance Stratégie.
 @Strat (Strategie *) Strategie.
 */
void freeStrat(Strategie *strat);

/****
 Fonction freeTableauStrat qui permet de free completement le tableau de strategies.
 @tab (Strategie **) tableau contenant les stratégies.
 @nbElemt (int) nombre de stratégies.
 */
void freeTableauStrat(Strategie **tab, int nbElemt);

#endif
