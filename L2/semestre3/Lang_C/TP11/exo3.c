#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 256
#define nbl 26
void frequence (const char *s, unsigned int tab[]);
void caractere_en_chaine (char c, char* s);
void imprimer_un_element (const char *s, unsigned int a);
void imprimer_frequence (char *s);


void frequence (const char *s, unsigned int tab[]){
	int i = 0;
	while (s[i] != '\0'){
		tab[s[i]-'A'] ++;
		i++;
		}
	}

void caractere_en_chaine (char c, char* s){
	s[0] = c;
	s[1] = '\0';
	}

void imprimer_un_element (const char *s, unsigned int a){
	printf ("%s %d \n", s,a);
	}


void imprimer_frequence (char *s){
	int i;
	unsigned int* tab = calloc(sizeof(unsigned int), nbl);
	frequence (s,tab);
	for (i = 0; i < nbl; i++){
		caractere_en_chaine('A'+i, s);
		imprimer_un_element(s, tab[i]);
		}
	}
int main (void){
	char s[taille] = "ECRIREUNEFONCTIONQUIACOMMEENTETEINTMAJUSCULECETTEFONCTION";
	imprimer_frequence (s);
	return 0;
	}
