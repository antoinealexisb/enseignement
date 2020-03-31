#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _liste{
	char c;
	int occ;
	struct _liste *suiv;
};
typedef struct _liste liste;

int in(liste *l, char c){
	while(l != NULL){
		if(l->c == c) return 1;
		l = l->suiv;
	}
	return 0;
}

void ajout_occ(liste *l, char c){
	while(l->c != c){
		l = l->suiv;
	}
	l->occ++;
}

liste* cree(char *s){
	int taille = strlen(s);
	liste *a, *b, *tete;
	tete = malloc(sizeof(liste));
	tete->c = s[0];
	tete->occ = 0;
	b = tete;
	for(int i=0; i<taille;i++){
		if(in(tete,s[i])) ajout_occ(tete,s[i]);
		else{
			a = malloc(sizeof(liste));
			a->c = s[i];
			a->occ = 1;
			b->suiv = a;
			b = a;
		}
	}
	return tete;
}

void imprime(liste *l){
	while(l != NULL){
		printf("%c : %d\n",l->c,l->occ);
		l = l->suiv;
	}
}

int main(){
	char c[] = "monsieur est tres gentil";
	liste *l=cree(c);
	imprime(l);
	return(0);
}
