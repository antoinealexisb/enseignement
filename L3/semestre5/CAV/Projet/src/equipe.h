/*
 *  equipe.h
 *  Fichier contenant toutes les signatures de fonctions permettant d'initialiser, créer, choisir 
 *  l'équipements et afficher les equipes (afficher : equipe, gain equipe, etat des crédits ... ).
 *
 *  Created by Antoine-Alexis Bourdon && Anthony Devrainne
 *  Copyright 2019 . All rights reserved.
 *
 */

#ifndef _EQUIPE_H
#define _EQUIPE_H
#include "champions.h"
#include "armes.h"
#include "protection.h"
#include "buffer.h"
#include "soins.h"
#include "lesprints.h"
#define arrondi(a) (floor((a) + 0.5))
#define ABS(a) (a<0) ? (-a) : (a)
#define distance(a) ((ABS(a))-1)

/**
 Structure possedant  le nom, le fichier, l'emplacement du commencement de l'équipement,  l'emplacement du commencement du script,
 un tableau d'indice des différents équipement de la stratégie, et le cout en CE de la stratégie.
 **/
typedef struct Strategie{
  char *nom;
  FILE *fichier;
  int equipement;
  int script;
  /*char **tab; *//*contient les noms de l'arme, protection, soin et CA. Soit 4 elmts*/
  int *tabInd; /*indice des différents elements dans leur tableau d'origine */
  unsigned int CE; /*cout de la stratégie*/
} Strategie;

/**
 Structure possedant  le champion, l'arme, la protection, le soin, le nombre de CE pour le duel (50 
 CE max), le nombre de CE pour la bataille (CET), l'activation de la protection (valable une fois dans
 un duel), la position de l'équipe sur le terrain, sa limite de terrain en arrière, et son historique
 de commande .
 **/
typedef struct equipe{
  Champion* champion;
  Weapon* weapon;
  Protection* protection;
  Care* soin;
  char CE;
  char CA;
  int CET;
  char activeProtection;
  unsigned char pos;
  unsigned char posLimite;
  Buffer *commande;
  Strategie *strat;
} Equipe;

/****
 Fonction initEquipe qui permet d'initialiser une instance de la structure Equipe avec les informations permettant de composer les caracteristiques une equipe au demarrage de la Bataille (CE=50, CA=50, CET=1000, activeProtection=0).
 #equipe (Equipe) retourne l'instance créée.
 */
Equipe* initEquipe();

/****
 Fonction ReinitEquipe qui permet de reinitialiser le champion, l'arme, le soin et la protection à NULL,
 de mettre le bon nombre de CE pour le duel.
 @equipe (Equipe *) une equipe
 */
void ReinitEquipe (Equipe *equipe);

/****
 Fonction afficheEquipe qui permet d'afficher les caracteristiques de l'equipe (champion, arme, protection, soin).
 @equipe (Equipe *) une equipe.
 */
void afficheEquipe(Equipe *equipe);

/****
 Fonction qui permet d'ajouter des CA, en échange des CE du duel.
 @equipe (Equipe *) une equipe.
 */
void achatCA(Equipe *equipe);

/****
 Fonction afficheNbCE qui permet d'afficher les CE des deux equipes (il ne s'agit pas des CE du duel).
 @equipe1 (Equipe *) l'équipe 1.
 @equipe2 (Equipe *) l'équipe 2.
 */
void afficheNbCE(Equipe* equipe1, Equipe* equipe2);

/****
 Fonction afficherEtatAdversaire qui permer d'afficher le nombre de points de vie restant de l'adversaire.
 @defenseur (Equipe *) equipe adversaire.
 */
void afficherEtatAdversaire(Equipe *defenseur);

/****
 Fonction depense qui permet d'afficher le nombre de CE restant et de CE dépensé.
 @equipe (Equipe *) une equipe.
 @borne (int) CE maximum à depenser.
 */
void depense(Equipe *equipe, int borne);

/****
 Fonction gain qui permet d'afficher le nombre de CE gagné par l'equipe vainqueur.
 @gagant (Equipe *) equipe ayant gagné le duel.
 @perdant (Equipe *) equipe ayant perdu son duel.
 @borne (int) CE maximum à depenser.
 */
void gain(Equipe *gagnant, Equipe *perdant, int borne);

/****
 Fonction etatCredits qui permet d'afficher les CE des deux equipes (il ne s'agit pas des CE du duel).
 @equipe1 (Equipe *) l'équipe 1.
 @equipe2 (Equipe *) l'équipe 2.
 */
void etatCredits(Equipe *equipe, Equipe *equipe2);

/****
 Fonction viderBuffer qui permet de supprimer tous les caractères se trouvant dans le Buffer de 
 l'entrée standard
 */
void viderBuffer();

/****
 Fonction copieChampion qui permet de copier un champion du tableau de champions vers l'emplacement
 champion de l'équipe.
 @equipe (Equipe *) une equipe.
 @tab (Champion **) le tableau de champion.
 @choix (int) id du champion choisit.
 */
void copieChampion(Equipe *equipe, Champion **tab, int choix);

/****
 Fonction ChooseYourWeapon qui permet à l'utilisateur de choisir son arme dans le tableau des armes, et
 cette arme sera mise dans l'équipe.
 @equipe (Equipe *) une equipe.
 @tab (Weapon **) le tableau d'armes.
 */
void ChooseYourWeapon(Equipe *equipe,Weapon **tab);


/****
 Fonction ChooseProctetion qui permet à l'utilisateur de choisir sa protection dans le tableau des
 protections, et la protection choisit sera mise dans l'équipe.
 @equipe (Equipe *) une equipe.
 @tab (Protection **) le tableau de protections.
 */
void ChooseProctetion(Equipe *equipe,Protection **tab);

/****
 Fonction ChooseCare qui permet à l'utilisateur de choisir son soin dans le tableau des soins, et
 ce soin sera mis dans l'équipe.
 @equipe (Equipe *) une equipe.
 @tab (Care **) le tableau de soins.
 */
void ChooseCare(Equipe *equipe,Care **tab);

/****
 Fonction choixEquipement qui appelle la fonction des CE restants (depense) et appelle les differentes
 fonctions pour choisir son equipement (ChooseYourWeapon, ChooseProctetion, ChooseCare).
 @equipe (Equipe *) une equipe.
 @tabArmes (Weapon **) tableau d'armes.
 @tabSoins (Care **) tableau de soins.
 @tabProtections (Protection **) tableau de protections.
 @borne (int) CE maximum à depenser.
 */
void choixEquipement(Equipe *equipe, Weapon **tabArmes, Care **tabSoins, Protection **tabProtections, int borne);

/****
 Fonction stratEquipement qui affecte à l'équipe les indices des equipements à avoir.
 @equipe (Equipe *) equipe qui recoit l'equipement.
 @tabWeapons (Weapon **) tableau d'armes.
 @tabPros (Protection **) tableau de protections.
 @tabSoins (Care **) tableau de soins.
 */
void stratEquipement(Equipe *equipe, Weapon **tabWeapons, Protection **tabPros, Care **tabSoins);

#endif

