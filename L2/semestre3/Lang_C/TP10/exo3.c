#define k 3
#include <stdio.h>

int tictactao_gagnant (char tab[k][k], char c){
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

int main (void){
	char tab[k][k] = {{'x','x','x'},{'o','o','o'},{'x','o','x'}};
	int j1 = tictactao_gagnant (tab, 'o');
	int j2 = tictactao_gagnant (tab, 'x');
	printf("%d %d\n",i,j);
	j1>j2 ? printf ("J1 gagne \n") : j2>j1 ? printf ("J2 gagne \n") : printf ("Match Nul");
	printf ("\n");
	return 0;
	}
