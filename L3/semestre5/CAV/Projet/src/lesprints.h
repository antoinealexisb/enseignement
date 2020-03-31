/*
 *  lesprints.h
 *  Fichier contenant toutes les signatures de fonctions d'animation des ASCII ARTS.
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */

#ifndef _LESPRINTS_H
#define _LESPRINTS_H
#include "couleurs.h"
#define ToUppercase(a)   ((a >= 'a' && a <= 'z' ) ? (a  + 'A' -'a') : (a))

/****
 Fonctions contenant différentes distance entre la carotte et la pomme en ASCII ART.
 - printFightDistance() : La plus grande distance.
 - printFightMidle() : Moyenne Distance.
 - printFightCac() : Corps à Corps.
*/
void printFightDistance();
void printFightMidle();
void printFightCac();

/****
 Fonction printGameOver() qui permet d'afficher la phrase "GAME OVER" en ASCII ART, quand le légume
 perd le duel.
 */
void printGameOver();

/****
 Fonction printWinner() qui permet d'afficher la phrase "YOU WIN" en ASCII ART, quand le légume
 gagne le duel.
 */
void printfWinner();


/****
 Fonctions qui affiche le fruit (la pomme) entrain de tirer en ASCII ART.
 (Tire qui touche le legume).
 */
void printTireFruit0();
void printTireFruit1();
void printTireFruit2();
void printTireFruit3();
void printTireFruit4();
void printTireFruit5();

/****
 Fonctions qui affiche le legume (la carotte) entrain de tirer en ASCII ART.
 (Tire qui touche le fruit).
 */
void printTireLegume0();
void printTireLegume1();
void printTireLegume2();
void printTireLegume3();

/****
 Fonctions qui affiche le fruit (la pomme) entrain de tirer en ASCII ART.
 (Tire qui ne touche pas le légume suite à une distance de portée trop petite par rapport à la  distance entre les deux champions)
 */
void printTireFruit10();
void printTireFruit11();
void printTireFruit12();
void printTireFruit13();
void printTireFruit14();

/****
 Fonctions qui affiche le légume (la carotte) entrain de tirer en ASCII ART.
 (Tire qui ne touche pas le fruit suite à une distance de portée trop petite par rapport à la  distance entre les deux champions)
 */
void printTireLegume10();
void printTireLegume11();
void printTireLegume12();


/****
 Fonctions qui affiche le fruit (la pomme) entrain de tirer sur la protection du légume en ASCII ART.
 */
void printTireProtectionFruit0();
void printTireProtectionFruit1();
void printTireProtectionFruit2();
void printTireProtectionFruit3();
void printTireProtectionFruit4();
void printTireProtectionFruit5();
void printTireProtectionFruit14();
void printTireProtectionFruit15();

/****
 Fonctions qui affiche le légume (la carotte) entrain de tirer sur la protection du fruit en ASCII ART.
 */
void printTireProtectionLegume0();
void printTireProtectionLegume1();
void printTireProtectionLegume2();
void printTireProtectionLegume3();
void printTireProtectionLegume4();
void printTireProtectionLegume13();
void printTireProtectionLegume14();

/****
 Fonctions qui affiche le fruit (la pomme) entrain d'avancer en ASCII ART.
 */
void printFruitAvancement0();
void printFruitAvancement1();
void printFruitAvancement2();

/****
 Fonctions qui affiche le legume entrain d'avancer en ASCII ART.
 */
void printLegumeAvancement0();
void printLegumeAvancement1();
void printLegumeAvancement2();


/****
 Fonction affichant l'animation du Tire du fruit touchant le legume (sans protection).
 */
void printTireFruitOK();

/****
 Fonction affichant l'animation du Tire du legume touchant le fruit (sans protection).
 */
void printTireLegumeOK();

/****
 Fonction affichant l'animation du Tire du fruit ne touchant pas le legume.
 */
void printTireFruitDistance();

/****
 Fonction affichant l'animation du Tire du legume ne touchant pas le fruit.
 */
void printTireLegumeDistance();

/****
 Fonction affichant l'animation du Tire du fruit touchant la protection du legume.
 */
void printTireFruitProtection();

/****
 Fonction affichant l'animation du Tire du legume touchant la protection du fruit.
 */
void printTireLegumeProtection();

/****
 Fonction affichant l'animation de soin du fruit.
 */
void printFruitSoin();

/****
 Fonction affichant l'animation de soin du legume.
 */
void printLegumeSoin();

/****
 Fonction affichant l'animation de protection du fruit.
 */
void printProtectionFruit();

/****
 Fonction affichant l'animation de protection du legume.
 */
void printLegumeProtection();

/****
 Fonction affichant l'animation du Tire du fruit passant la protection du legume.
 */
void printTireFruitProtectionPass();

/****
 Fonction affichant l'animation du Tire du legume passant la protection du fruit.
 */
void printTireLegumeProtectionPass();

/****
 Fonction affichant l'animation d'avancement du fruit.
 */
void printFruitAvance();

/****
 Fonction affichant l'animation d'avancement du legume.
 */
void printLegumeAvance();

/****
 Fonction affichant l'animation de reculement du fruit.
 */
void printFruitRecule();

/****
 Fonction affichant l'animation de reculement du legume.
 */
void printLegumeRecule();

/****
 Fonction affichant le message "VAINQUEUR".
 */
void printVainqueur();

/****
 Fonction affichant le message "FRUITS" pour indiquer le camp vainqueur de la guerre.
 */
void printFruits();

/****
 Fonction affichant le message "LEGUMES" pour indiquer le camp vainqueur de la guerre.
 */
void printLegumes();

/****
 Fonction affichant le message "EX-AEQUO" pour indiquer qu'aucun camp n'est vainqueur de la guerre.
 */
void printExaequo();
#endif
