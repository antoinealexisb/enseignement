/*
 *  graphes.c
 *  Fichier TP5/TP6/TP7
 *
 *  Created by Antoine-Alexis Bourdon
 *  Copyright 2019 . All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXVILLES 1024
#define MAXPERSONNES 1024

typedef struct cel cel;

typedef struct {
	char* nom;
	char* ville;
	struct cel* abonnements;
	struct cel* suivi_par;
} Personne;

struct cel {
	Personne *p;
	struct cel* suiv;
};


//global c'est le mal ;)
char* (personnesTab[MAXVILLES]);
char* (villes[MAXVILLES]); //tableau de villes
int nbVilles = 0; //nb villes 

int distance_villes[MAXVILLES][MAXVILLES];

Personne* tab_personnes[MAXPERSONNES];
int nbPersonnes = 0;

int dist_pers[MAXPERSONNES][MAXPERSONNES];

int tab_composantes[MAXPERSONNES];
int nbComposantes = 0;

int tab_composantes_fc[MAXPERSONNES];
int nbComposantesFc = 0;


int tab_composantes_Tarjan[MAXPERSONNES];
Personne* deja_vus_Tarjan[MAXPERSONNES];
int nbVusTarjan = 0;
int numCompoTarjan = 0;
int rTarjan = 0;
int rang_Tarjan[MAXPERSONNES];
int rang_att_Tarjan[MAXPERSONNES];

Personne* pile_Tarjan[MAXPERSONNES];
int numPileTarjan = 0;


/****
 * Fonction qui ajoute une personne et une ville passé en paraùètre.
 * Cette fonction crée une vouvelle personne 'sans abonnements) et
 * l'ajoute au tab_personnes (tableau global).
 * @nom (char *) : nom de la personne.
 * @ville (char *) : nom de la ville.
 *
 */
void ajoute_personne(char* nom, char* ville) {
	assert(nbPersonnes < MAXPERSONNES);
	Personne *p = (Personne*)malloc(sizeof(Personne));
	p->nom = (char*)malloc(1024 * sizeof(char));
	p->ville = (char*)malloc(1024 * sizeof(char));
	strcpy(p->nom, nom);
	strcpy(p->ville, ville);
	p->abonnements = NULL;
	p->suivi_par = NULL;
	tab_personnes[nbPersonnes++] = p;
}


/****
 * Fonction qui prend un nom en paramètre et retourne un 
 * pointeur vers cette personne en cherchant dans tab_personnes.
 * @nom (char *) : nom de la personne à chercher.
 * # (Personne*) : pointeur vers cette personne ou NULL.
 *
 */
Personne* get_personne(char* nom) {
	Personne *p;
	int ind = 0;
	for (ind = 0; ind < nbPersonnes; ind++) {
		p = tab_personnes[ind];		
		if (strcmp(p->nom, nom) == 0) {
			return p;
		}
	}
	return NULL;
}

/****
 * Fonction qui prend deux personnes p1 et p2  en paramètres
 * et ajoute p2 auxx abonnements de p1.
 * @p1 (Personne *) : personne 1
 * @p2 (Personne *) : personne 2
 */
void ajoute_abo(Personne *p1, Personne *p2) {
	cel *new, *courant;
	new = (cel*)malloc(sizeof(cel));
	new->p = p2;
	new->suiv = NULL;
	courant = p1->abonnements;
	if (courant == NULL) {
		p1->abonnements = new;
	} else {
		while (courant->suiv != NULL) {
			courant = courant->suiv;
		}
		courant->suiv = new;
	}
}


/****
 * Fonction qui prend deux personnes p1 et p2 en paramètres
 * et enlève p2 aux abonnements de p1.
 * @p1 (Personne *) : personne 1.
 * @p2 (Personne *) : personne 2.
 *
 */
void enleve_abo(Personne *p1, Personne *p2) {
	cel *courant, *prec;
	int trouve;
	courant = p1->abonnements;
	prec = NULL;
	trouve = (strcmp(courant->p->nom, p2->nom) == 0);
	while (trouve == 0 && courant != NULL) {
		prec = courant;
		courant = courant->suiv;
		if (courant != NULL) {
			trouve = (strcmp(courant->p->nom, p2->nom) == 0);
		}
	}
	if (trouve == 1) {
		if (prec != NULL) {
			prec->suiv = courant->suiv;
		} else {
			p1->abonnements = courant->suiv;
		}
		free(courant);
	}
}

/****
 * Fonction qui permet d'afficher une personne : son nom, sa ville, le nom des
 * personnes qu'il suit.
 * @p (Personne) la personne à afficher.
 */
void affiche_personne(Personne p) {
	cel *courant;
	printf(" nom : %s \n ville : %s \n abonnements :", p.nom, p.ville);
	courant = p.abonnements;
	if (courant == NULL) {
		printf(" vide ");
	}
	while (courant != NULL) {
		printf(" %s ", courant->p->nom);
		courant = courant->suiv;
	}
	printf("\n suivi par : ");
	courant = p.suivi_par;
	if (courant == NULL) {
		printf(" vide ");
	}
	while (courant != NULL) {
		printf(" %s ", courant->p->nom);
		courant = courant->suiv;
	}
	printf("\n");
}

/**
 * Fonction qui permet d'afficher la liste complete des personnes avec son som,
 * sa ville, le nom des personnes qu'il suit.
 */
void affiche_personnes() {
	int i;
	for (i = 0; i < nbPersonnes; i++) {
		printf("\n");
		affiche_personne(*(tab_personnes[i]));
	}
}

/**Pourquoi ecrire ParsePersonnesInfos pour remplir personneTab qui n'existe pas car 
 * c'est tab_personnes ?? NOTE A MOI MEME ::: LIRE LA CONSIGNE :::*/

/** Fonction qui prend la liste de personnes et créé puis commence à remplir le
 * tableau personneTab. 
 * @listePersonnes (char *) liste de personnes (ex : [kevin,karim,alice,paul,charlotte,gabriel,dalila],)
 */
void parsePersonnesInfos(char *listePersonnes) {
	char *personneTab, *personneAjout;
	personneTab = strtok(listePersonnes, " ,[]\n");
	while (personneTab != NULL) {
		personneAjout = (char*)malloc(1024 * sizeof(char));
		strcpy(personneAjout, personneTab);
		personnesTab[nbPersonnes++] = personneAjout;
		personneTab = strtok(NULL, " ,[]\n");
	}
}

/****
 * Fonction qui prend la liste de villes et crée puis rempli le tableau villes.
 * @listeVilles (char *) liste de villes (ex: [lille,lens,arras,douai,carvin,seclin],).
 */
void parseVillesInfos(char *listeVilles) {
	char *ville, *villeAjout;
	ville = strtok(listeVilles, " ,[]\n");
	while (ville != NULL) {
		villeAjout = (char*)malloc(1024 * sizeof(char));
		strcpy(villeAjout, ville);
		villes[nbVilles++] = villeAjout;
		ville = strtok(NULL, " ,[]\n");
	}
}

/****
 * Fonction qui une chaine en entrée et qui ajoute les infos de la personne
 * ainsi que ses abonnements.
 * @infosPersonne (char *) chaine de type : kevin:{[gabriel,dalila],lille},.
 */
void parsePersonne(char infosPersonne[]) {
	char* pers;
	char* abo;
	char* ville;
	pers = strtok(infosPersonne, " :{}[]");
	abo = strtok(NULL, " :{}[]");
	ville = strtok(NULL, " :{}[],");
	ajoute_personne(pers, ville);
}

/****
 * Fonction qui retourne l'indice de la ville
 * @s (char *) chaine representant le nom de la ville
 * #ind (int) retourne l'indice de la ville
 */
int indVille(char* nomVille) {
	int i;
	for (i = 0; i < nbVilles && strcmp(villes[i], nomVille) != 0; i++);
	return i;
}

/***
 * Fonction qui prend une chaine en entrée et qui met à jour
 * la matrice distance_villes
 * @s (char *) chaine.
 */
void parseVille(char *s){
	char *ville1;
	char *ville2;
	int dist, indVille1, indVille2;
	ville1 = strtok(s, " ,()");
	dist = atoi(strtok(NULL, " ,()"));
	ville2 = strtok(NULL, " ,()");
	indVille1 = indVille(ville1);
	indVille2 = indVille(ville2);
	distance_villes[indVille1][indVille2] = dist;
	distance_villes[indVille2][indVille1] = dist;
}

/*****
 * Fonction qui ajoute un suivi par
 * @p1 (Personne *) personne qui reçoit la personne2
 * @p2 (Personne *) une personne qui sera rajouté
 */
void ajoute_suivi_par(Personne *p1, Personne *p2) {
	cel *new, *courant;
	new = (cel*)malloc(sizeof(cel));
	new->p = p2;
	new->suiv = NULL;
	courant = p1->suivi_par;
	if (courant == NULL) {
		p1->suivi_par = new;
	} else {
		while (courant->suiv != NULL) {
			courant = courant->suiv;
		}
		courant->suiv = new;
	}
}

/*****
 * Fonction qui eneleve un suivi par
 * @p1 (Personne *) personne à qui sera enlever la personne2.
 * @p2 (Personne *) une personne à enlever.
 */
void enleve_suivi_par(Personne *p1, Personne *p2) {
	cel *courant, *prec;
	int trouve;
	courant = p1->suivi_par;
	prec = NULL;
	trouve = (strcmp(courant->p->nom, p2->nom) == 0);
	while (trouve == 0 && courant != NULL) {
		prec = courant;
		courant = courant->suiv;
		if (courant != NULL) {
			trouve = (strcmp(courant->p->nom, p2->nom) == 0);
		}
	}
	if (trouve == 1) {
		if (prec != NULL) {
			prec->suiv = courant->suiv;
		} else {
			p1->abonnements = courant->suiv;
		}
		free(courant);
	}
}

/****
 * Fonction qui parse la chaine de caractère pour les abonnements.
 * @infosPersonne (char *)
 */
void parseAbo(char infosPersonne[]) {
	char* pers;
	char* abo;
	char infosAbos[1024];
	Personne *p1, *p2;
	pers = strtok(infosPersonne, " :{}[]");
	abo = strtok(NULL, " :{}[]");
	p1 = get_personne(pers);
	strcpy(infosAbos, abo);
	abo = strtok(infosAbos, ",");
	while (abo != NULL) {
		p2 = get_personne(abo);
		ajoute_abo(p1, p2);
		ajoute_suivi_par(p2, p1);
		abo = strtok(NULL, ",");
	}
}


/****
 * Fonction qui met ajour la matrice distancesVilles
 * infosVille(char *) chaine de caractères.
 */
void parseDistVille(char infosVille[]) {
	char *ville1;
	char *ville2;
	int dist, indVille1, indVille2;
	ville1 = strtok(infosVille, " ,()");
	dist = atoi(strtok(NULL, " ,()"));
	ville2 = strtok(NULL, " ,()");
	indVille1 = indVille(ville1);
	indVille2 = indVille(ville2);
	distance_villes[indVille1][indVille2] = dist;
	distance_villes[indVille2][indVille1] = dist;
}

/****
 * Fonction qui parse le fichier en lui même
 * file (FILE*) le fichier à parser.
 */
void parseInfosFile(FILE* file) {
        int i;
        fseek(file, 0, SEEK_SET);
	char *ligne = (char*)malloc(1024 * sizeof(char));
	char ligneAnalyse[1024];
        for (i=0;i<3;i++) fgets(ligne, 1024, file);
	strcpy(ligneAnalyse, ligne);
	parseVillesInfos(ligneAnalyse);
        for (i=0;i<2;i++) fgets(ligne, 1024, file);
	while (strcmp(ligne, "  ],\n") != 0) {
		strcpy(ligneAnalyse, ligne);
		parsePersonne(ligneAnalyse);
		fgets(ligne, 1024, file);
	}
        for (i=0;i<2;i++) fgets(ligne, 1024, file);
	while (strcmp(ligne, "  ]\n") != 0) {
		strcpy(ligneAnalyse, ligne);
		parseDistVille(ligneAnalyse);
		fgets(ligne, 1024, file);
	}
}

/****
 * FOnction qui parse les Abonnements.
 * @file (FILE *) le fichier.
 */
void parseAbosFile(FILE* file) {
        int i;
        fseek(file, 0, SEEK_SET);
	char *ligne = (char*)malloc(1024 * sizeof(char));
	char ligneAnalyse[1024];
        for (i=0;i<5;i++) fgets(ligne, 1024, file);
	while (strcmp(ligne, "  ],\n") != 0) {
		strcpy(ligneAnalyse, ligne);
		parseAbo(ligneAnalyse);
		fgets(ligne, 1024, file);
	}
}


/****
 Fonction qui affiche tout
*/
void affiche_tout() {
	int i;
	for (i = 0; i < nbPersonnes; i++) {
		printf("\n");
		affiche_personne(*(tab_personnes[i]));
	}
}

/****
 Fonction qui affiche les villes
*/
void affiche_villes() {
	int i;
	for (i = 0; i < nbVilles; i++) {
		printf("%s\n", villes[i]);
	}
}

/****
 fonction qui indique si la personne est dan tabPers.
 * trouve (int) 1 si trouvé sinon 0.
 */
int persDansTab(Personne *p, Personne *tabPers[MAXPERSONNES], int indTabPers) {
	int trouve = 0, i;
	for (i = 0; i < indTabPers && !trouve; i++) {
		trouve = (p == tabPers[i]);
	}
	return trouve;
}


/****
 * Fonction qui prend deux personnes p1 et p2 en paramètres et calcule la distance de p1 à p2.
 * @p (Personne*) personne
 * @p (Personne*) personne.
 * @ind (int) retourne la distance.
 */ 
int distance_personnes(Personne *p1, Personne *p2) {
	int trouve = 0, ind = 0, indTabCourant = 1, indTabFutur = 0, indTraites = 1;
	int i, ajout = 0;
	Personne *dejaTraites[MAXPERSONNES] = {p1};
	Personne *courant[MAXPERSONNES] = {p1}, *futur[MAXPERSONNES];
	cel *celCourante;
	if (p1 == p2) {
		return 0;
	}
	while (!trouve) {
		indTabFutur = 0;
		ajout = 0;
		for (i = 0; i < indTabCourant; i++) {
			celCourante = courant[i]->abonnements;
			while (celCourante != NULL) {
				if (!persDansTab(celCourante->p, dejaTraites, indTraites)) {
					ajout = 1;
					futur[indTabFutur] = celCourante->p;
					indTabFutur++;
					dejaTraites[indTraites] = celCourante->p;
					indTraites++;
				}
				celCourante = celCourante->suiv;
			}
		}
		if (ajout == 0) {
			return -1;
		}
		for (indTabCourant = 0; indTabCourant < indTabFutur; indTabCourant++) {
			courant[indTabCourant] = futur[indTabCourant];
		}
		ind++;
		for (i = 0; i < indTabCourant; i++) {
			if (courant[i] == p2) {
				trouve = 1;
			}
		}
	}
	return ind;
}


/****
 * FOnction qui calcule la distance moyenne entre deux personnes dans un réseau (on ne prendra pas en compte dans le calcul les personnes qui ne sont pas en lien).
*/
float distance_moyenne() {
	int i, j;
	int somme = 0, nbRelations = 0;
	int dist;
	for (i = 0; i < nbPersonnes; i++) {
		for (j = 0; j < nbPersonnes; j++) {
			dist = distance_personnes(tab_personnes[i], tab_personnes[j]);
			if (dist > 0) {
				somme += dist;
				nbRelations++;
				dist_pers[i][j] = dist;
			}
		}
	}
	return ((float)somme / nbRelations);
}

/** Pas besoin de faire la fontions sysmetriser qui met a jour le champ suivi_par
 * car champ_suivi est deja mit a jour automatiquement. */

/****
 *Fonction qui retourne l'indice de la personne dans le tab_personnes
 * p (Personne *) personne
 à #ind (int)
*/
int ind_personne(Personne *p) {
	int i;
	for (i = 0; (i < nbPersonnes) && (p != tab_personnes[i]); i++);
	return i;
}

/****
 * Fonction qui calcule une composante connexe sur les noueds qui ne sont
 * pas déja.
 * @num_compo (int) numero de composante.
 */
void calcule_une_composante_connexe(int num_compo) {
	int indTabCourant = 0, indTabFutur = 0, indTraites = 0;
	int i, fin = 0, indPers;
	Personne *dejaTraites[MAXPERSONNES];
	Personne *courant[MAXPERSONNES], *futur[MAXPERSONNES];
	cel *celCourante;
	for (i = 0; (i < nbPersonnes) && (indTabCourant == 0); i++) {
		if (tab_composantes[i] == -1) {
			courant[indTabCourant] = tab_personnes[i];
			indTabCourant++;
			dejaTraites[indTraites] = tab_personnes[i];
			indTraites++;
		}
	}
	i--;
	tab_composantes[i] = num_compo;
	while (!fin) {
		indTabFutur = 0;
		for (i = 0; i < indTabCourant; i++) {
			celCourante = courant[i]->abonnements;
			while (celCourante != NULL) {
				if (!persDansTab(celCourante->p, dejaTraites, indTraites)) {
					futur[indTabFutur] = celCourante->p;
					indTabFutur++;
					dejaTraites[indTraites] = celCourante->p;
					indTraites++;
				}
				celCourante = celCourante->suiv;
			}
			celCourante = courant[i]->suivi_par;
			while (celCourante != NULL) {
				if (!persDansTab(celCourante->p, dejaTraites, indTraites)) {
					futur[indTabFutur] = celCourante->p;
					indTabFutur++;
					dejaTraites[indTraites] = celCourante->p;
					indTraites++;
				}
				celCourante = celCourante->suiv;
			}
		}
		fin = (indTabFutur == 0);
		for (indTabCourant = 0; indTabCourant < indTabFutur; indTabCourant++) {
			courant[indTabCourant] = futur[indTabCourant];
		}
		for (i = 0; i < indTabCourant; i++) {
			indPers = ind_personne(courant[i]);
			tab_composantes[indPers] = num_compo;
		}
	}
}

/****
 Fonction qui caclule les composantes connexes
*/
void calcule_les_composantes_connexes() {
	int i;
	for (i = 0; i < nbPersonnes; i++) {
		tab_composantes[i] = -1;
	}
	for (i = 0; i < nbPersonnes; i++) {
		if (tab_composantes[i] == -1) {
			nbComposantes++;
			calcule_une_composante_connexe(nbComposantes);
		}
	}
}

/****
 Fonction qui affiche UNE composante connexe.
*/
void affiche_une_composante(int num_compo) {
	int i;
	for (i = 0; i < nbPersonnes; i++) {
		if (tab_composantes[i] == num_compo) {
			affiche_personne(*(tab_personnes[i]));
			printf("\n");
		}
	}
}

/****
 Fonction qui affiche les composantes connexes.
*/
void affiche_les_composantes() {
	int i;
	for (i = 1; i <= nbComposantes; i++) {
		printf("Composante %d : \n\n", i);
		affiche_une_composante(i); 
	}
}


/****
 * Fonction qui calcule une composante fortement connexe sur les noeuds
 * qui ne sont pas déjà rattachés.
 * @num_compo (int) numéro de composante
 */
void calcule_une_composante_fortement_connexe(int num_compo) {
	int indTabCourant = 0, indTabFutur = 0, indTraites = 0;
	int i, fin = 0, indPers;
	Personne *dejaTraites[MAXPERSONNES];
	Personne *courant[MAXPERSONNES], *futur[MAXPERSONNES];
	cel *celCourante;
	for (i = 0; (i < nbPersonnes) && (indTabCourant == 0); i++) {
		if (tab_composantes_fc[i] == -1) {
			courant[indTabCourant] = tab_personnes[i];
			indTabCourant++;
			dejaTraites[indTraites] = tab_personnes[i];
			indTraites++;
		}
	}
	i--;
	tab_composantes_fc[i] = num_compo;
	while (!fin) {
		indTabFutur = 0;
		for (i = 0; i < indTabCourant; i++) {
			celCourante = courant[i]->abonnements;
			while (celCourante != NULL) {
				if (!persDansTab(celCourante->p, dejaTraites, indTraites)) {
					futur[indTabFutur] = celCourante->p;
					indTabFutur++;
					dejaTraites[indTraites] = celCourante->p;
					indTraites++;
				} else {
					indPers = ind_personne(celCourante->p);
					if (tab_composantes_fc[indPers] == -1) {
						tab_composantes_fc[indPers] = num_compo;
					}
					indPers= ind_personne(courant[i]);
					if (tab_composantes_fc[indPers] == -1) {
						tab_composantes_fc[indPers] = num_compo;
					}
				}
				celCourante = celCourante->suiv;
			}
		}
		fin = (indTabFutur == 0);
		for (indTabCourant = 0; indTabCourant < indTabFutur; indTabCourant++) {
			courant[indTabCourant] = futur[indTabCourant];
		}
	}
}

/****
 * Fonction qui calcule toutes les composantes fortement connexess du graphe.
 */
void calcule_les_composantes_fortement_connexes() {
	int i;
	for (i = 0; i < nbPersonnes; i++) {
		tab_composantes_fc[i] = -1;
	}
	for (i = 0; i < nbPersonnes; i++) {
		if (tab_composantes_fc[i] == -1) {
			nbComposantesFc++;
			calcule_une_composante_fortement_connexe(nbComposantesFc);
		}
	}
}

void affiche_une_cfc(int num_compo){
  	int i;
	for (i = 0; i < nbPersonnes; i++) {
		if (tab_composantes_fc[i] == num_compo) {
			affiche_personne(*(tab_personnes[i]));
			printf("\n");
		}
	}
}

void affiche_les_cfc(){
        int i;
        for (i = 1; i<=nbComposantesFc; i++){
		printf("Composante fortement connexe %d : \n\n", i);
		affiche_une_cfc(i); 
        }

}

/****
 * Fonction du parcours descendants.
 * @p (Personne *) une personne
 * @ind (int) indice
*/
void parcours_descendants(Personne *p, int ind) {
	int indPers;
	Personne *pers;
	cel *celCourante;
	pile_Tarjan[numPileTarjan] = p;
	numPileTarjan++;
	deja_vus_Tarjan[nbVusTarjan] = p;
	nbVusTarjan++;
	rTarjan++;
	rang_Tarjan[ind] = rTarjan;
	rang_att_Tarjan[ind] = rTarjan;
	celCourante = p->abonnements;
	while (celCourante != NULL) {
		indPers = ind_personne(celCourante->p);
		if (!persDansTab(celCourante->p, deja_vus_Tarjan, nbVusTarjan)) {
			parcours_descendants(celCourante->p, indPers);
			if (rang_att_Tarjan[ind] > rang_att_Tarjan[indPers]) {
				rang_att_Tarjan[ind] = rang_att_Tarjan[indPers];
			}
		}
		else if (persDansTab(celCourante->p, pile_Tarjan, numPileTarjan)) {
			if (rang_att_Tarjan[ind] > rang_Tarjan[indPers]) {
				rang_att_Tarjan[ind] = rang_Tarjan[indPers];
			}
		}
		celCourante = celCourante->suiv;
	}
	if (rang_att_Tarjan[ind] == rang_Tarjan[ind]) {
		numCompoTarjan++;
		do {
			numPileTarjan--;
			pers = pile_Tarjan[numPileTarjan];
			indPers = ind_personne(pers);
			tab_composantes_Tarjan[indPers] = numCompoTarjan;
		} while (ind != indPers);
	}
}


void calcule_les_cfc_Tarjan() {
	int ind = 0;
	Personne *p = tab_personnes[ind];
	while (nbVusTarjan < nbPersonnes) {
		while (ind < nbPersonnes && persDansTab(p, deja_vus_Tarjan, nbVusTarjan)) {
			ind++;
			p = tab_personnes[ind];
		}
		parcours_descendants(p, ind);
	}
}


void affiche_une_cfc_Tarjan(int num_compo) {
	int i;
	for (i = 0; i < nbPersonnes; i++) {
		if (tab_composantes_Tarjan[i] == num_compo) {
			affiche_personne(*(tab_personnes[i]));
			printf("\n");
		}
	}
}


void affiche_les_cfc_Tarjan() {
	int i;
	for (i = 1; i <= numCompoTarjan; i++) {
		printf("Composante fortement connexe Tarjan %d : \n\n", i);
		affiche_une_cfc_Tarjan(i); 
	}
}

/**Foction principale */
int main(void){
  	FILE* file = fopen("reseau1.txt", "r");
	parseInfosFile(file);
        parseAbosFile(file);
	fclose(file);
        printf("%f\n", distance_moyenne());
        //ajoute_personne("bidule", "machin");
        printf("affiche_tout\n");
        affiche_tout();

	calcule_les_composantes_connexes();
	affiche_les_composantes();

	calcule_les_composantes_fortement_connexes();
	affiche_les_cfc();

	calcule_les_cfc_Tarjan();
	affiche_les_cfc_Tarjan();

        return 0;
}
