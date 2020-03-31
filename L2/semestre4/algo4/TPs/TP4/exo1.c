#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 10000

int *genererTableau(void){
    int *tab = malloc(taille*sizeof(int)),i;
    srand(1664);
    for(i=0;i<taille;i++){
        tab[i] = rand();
    }
    return tab;
}

void afficheTab(int tab[]){
	for (int i=0; i<taille; i++)
		printf("%d, ",tab[i]);
	printf("\n");
}

void triSelection(int *tab){
	for (int i=0; i<taille-1; i++){
		for (int j=i+1; j<taille; j++){
			if (tab[i]>tab[j]){
				int tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

void triInsertion(int *tab){
	for (int i=1; i<taille;i++){
		int en_cours = tab[i];
		int j = i;
		while ((j>0)&&(en_cours<tab[j-1])){
			tab[j]=tab[j-1];
			j--;
		}
		tab[j]=en_cours;
	}

}


void triBulle(int* tableau) {
	char permutation=1;
	int en_cours=0, sens=1, debut=0, fin=taille-1;
	do {
		permutation=0;
		while (((sens==1) && (en_cours<fin)) || ((sens==-1) && (en_cours>debut))) {
			en_cours += sens;
			if (tableau[en_cours]<tableau[en_cours-1]) {
				int temp = tableau[en_cours];
				tableau[en_cours]=tableau[en_cours-1];
				tableau[en_cours-1]=temp;
				permutation=1;
			}
		}
		if (sens==1) fin--; else debut++;
		sens = -sens;
	} while (permutation);
}

int main(void){
	int *tab = genererTableau();
	char a;
	printf("\t##########################################\n");
	printf("\t############# TP 5 - Les Tris ############\n");
	printf("\t##########################################\n\n\n");

	printf("---Tris de tableau---\n");
	printf("\tMenu selection :\n");
	printf("1. Tri Sélection \n");
	printf("2. Tri Insertion \n");
	printf("3. Tri à Bulle \n");
	printf("Choisissez un algorithme de tris : ");
	scanf("%c",&a);

	printf("\n\n\n\tGénération tableau de %d élèments :\n", taille);
	sleep(0.5);
	printf("###                               : 10%%\n");
	sleep(1);
        printf("########                          : 27%%\n");
	sleep(0.5);
        printf("#############                     : 42%%\n");
	sleep(1);
        printf("#######################           : 68%%\n");
	sleep(1);
        printf("###############################   : 96%%\n");
	sleep(0.5);
        printf("################################# : 100%%\nSuccé !!!!\n\n");

	clock_t start, stop ;

	switch(a){
		case '1':
			printf("Tri Sélection choisit, traitement en cours\n");
			start = clock();
			triSelection(tab);
			stop = clock();
			//afficheTab(tab);
			break;
		case '2':
			printf("Tri Insertion choisit, traitement en cours\n");
			start=clock();
                        triInsertion(tab);
			stop = clock();
                        //afficheTab(tab);
			break;
		case '3':
			printf("Tri Insertion choisit, traitement en cours\n");
			start=clock();
                        triBulle(tab);
			stop = clock();
                        //afficheTab(tab);
                        break;
		default:
			printf("ERREUR MAUVAIS CHOIX BYE BYE\n");
			exit(0);
			break;
	}
	printf("Temps d'execution : %f secondes \n", (double)(stop-start)/CLOCKS_PER_SEC);
	//afficheTab(tab);
	//triSelection(tab);
	//triInsertion(tab);
	//triBulle(tab);
	//afficheTab(tab);
	//afficheTab(tab);
	return(0);
}
