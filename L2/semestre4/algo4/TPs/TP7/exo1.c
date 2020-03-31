#include <stdio.h>
#include <string.h>
#define TAILLES 9

struct _chaine{
	int val;
	struct _chaine *suivant;
	};

typedef struct _chaine chaine;

chaine *creer_chaine (int val){
	chaine *creation = malloc(sizeof(chaine));
	creation -> val = val;
	creation -> suivant = NULL;
	return creation;
}

void set_suivant (chaine *c, chaine add){
	c -> suivant = add;
}

chaine[] creation_table(void){
	chaine *table = malloc(sizeof(passager)*TAILLES);
	return table;
}

void methode_div (chaine* remplir, int* remplissage, int taille){
	int i, cle, j;
	for (i = 0; i < taille; i++){
		cle = i%taille;
		chaine *tmp = creer_chaine(remplissage[i]);
		if (remplir[cle] == NULL){
			remplir[cle] = tmp;
		}
		else{
			chaine *cmp = remplir[cle];
			while (cmp -> suivant != NULL){
				cmp = cmp -> suivant;
			}
			set_suivant(cmp, tmp);
		}
	}
}

void methode_mult(float a, chaine* remplir, int* remplissage, int taille){
	int i, cle, j;
	for (i=0; i< taille; i++){
		
	}
}
