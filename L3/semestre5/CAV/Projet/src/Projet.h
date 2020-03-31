/*
 *  Projet.h
 *  Fichier contenant toutes les signatures de fonctions permettant le lancement du jeu, et le fermeture
 *  de celui-ci.
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */
#ifndef _PROJET_H
#define _PROJET_H
#include <sys/ioctl.h>
#include "partie2.h"
void test(char *s, Weapon **tabArmes);

/****
 Fonction printenTete qui permet d'afficher le message "ITS TIME TO KILL EVERYONE"
 */
void printenTete();

/****
 Fonction principale qui permet d'inialiser les différents tableaux (champions, armes, soins,
 protections), les deux equipes, et traitre des commandes utilisateurs (show vegetables, show fruits,
 show vegetable i, show fruit i, show protections, show protection i, show cares, show care i, show
 weapons, show weapon i, exit)
 #exit(0) (int) code sorti de l'application.
*/
int main(int argc, char *argv[]);

/****
 Fonction jeu qui permet le lancement ou non du duel entre l'équipe1 et l'équipe2 et donc alors de
 choisir son equipement avec la fonction (choixEquipement), puis le traitement du duel (traitement)
 @equipe (Equipe *) equipe1.
 @equipe2 (Equipe *) equipe2.
 @tabArmes (Weapon **) tableau des armes.
 @tabSoins (Care **) tableau des soins.
 @tabProtections (Protection) tableau des protections.
 */
void jeu(Equipe *equipe, Equipe *equipe2, Weapon **tabArmes, Care **tabSoins, Protection **tabProtections);

/****
 Fonction qui free tous les tableaux en appelant les fonctions de free adequat pour chaque tableaux.
 @tab (Champion **)tableau des champions de type legume.
 @tab2 (Champion **)tableau des champions de type fruit.
 @armes (Weapon **) tableau des armes.
 @soins (Care **) tableau des soins.
 @proc (Protection) tableau des protections.
 @equipe (Equipe *) equipe1.
 @equipe2 (Equipe *) equipe2.
 @tabStrat (Strategie **) tableau des stratégies.
 @nbFichiersStrat (int) nombre de fichiers Stratégies existant dans le tableau de strategies.
 */
void freeTabs(Champion **tab, Champion **tab2, Weapon **armes, Care **soins, Protection **proc, Equipe *equipe1, Equipe *equipe2, Strategie **tabStrat, int nbFichiersStrat);

#endif

