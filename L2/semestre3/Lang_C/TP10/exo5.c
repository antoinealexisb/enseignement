#define k 3
#include <stdio.h>

void init_plateau(char tab[k][k]);
void print_tab(char tab[k][k]);
void coup (char tab[k][k], char c);
int gagnant (char tab[k][k], char c);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void init_plateau(char tab[k][k]){
	int i,j;
	
	for (i = 0; i <k; i++){
		for (j = 0; j <k; j++){
			tab[i][j] = ' ';
			}
		}
	}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void print_tab(char tab[k][k]){

	int i, j;
	char a;
	for (i = 0; i <k; i++){
		for (j = 0; j <k; j++){
			a = tab[i][j];
			printf ("%c", a);

			if (j!= k-1){
				printf("|");
				}
			else{
				printf("\n");
				}
			}
		if (i != k-1){
			printf("----------- \n");
			}
		}
	}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int gagnant (char tab[k][k], char c){
	int i, j, verif=0, verif2=0;
	for (i=0; i<k; i++){
		verif = 0;
		verif2 = 0;
		for (j=0; j<k; j++){
			if (tab[i][j] == c){
				verif++;
				}
			if (tab[j][i] == c){
				verif2++;
				}
		if (verif == 3 || verif2 == 3){
			return 1;
			}
		}
	}

	verif = 0;
	verif2 = 0;
	for(i = 0; i<k; i++){
		if (tab[i][i] == c){
			verif++;
			}
		if (tab[i][k-i-1] == c){
			verif++;
			}
		}
		
	return (verif == 3 && verif2 == 3);
	}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void coup (char tab[k][k], char c){
	int verif = 1, i, j;
	printf("Au joueur %c \n", c);

	while (verif){
		printf("Entrez votre coup \n");
		scanf("%d %d", &i, &j);
		if (i>=0 && i<k && j>=0 && j<k){
			if (tab[i][j] == ' '){
				tab[i][j] = c;
				verif = 0;
				}
			}
		}
	}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int main (void){
	char tab[k][k];
	char c = 'o';
	init_plateau(tab);
	int verif = 0;
	while (!verif){
		print_tab(tab);
		coup(tab, c);
		verif = gagnant(tab, c);
		if (c == 'o'){
			c = 'x';
			}
		else{
			c = 'o';
			}
		}
	return 0;
	}
