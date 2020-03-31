#define k 3
#include <stdio.h>

int calcul_lig (int tab[k][k]);
int est_carre_magique (int tab[k][k]);

int calcul_lig (int tab[k][k]){
	int i, res=0;
	for (i=0; i<k; i++){
		res+=tab[0][i];
		}
	return res;
	}

int est_carre_magique (int tab[k][k]){
	int i, j, somme, verif, verif2;
	somme = calcul_lig(tab);
	for (i=0; i<k; i++){
		verif = 0;
		verif2 = 0;
		for (j=0; j<k; j++){
			verif += tab[i][j];
			verif2 += tab[j][i];
			}
		if (verif != somme || verif2 != somme){
			return 0;
			}
		}

	verif = 0;
	verif2 = 0;
	for(i = 0; i<k; i++){
		verif += tab[i][i];
		verif2 += tab[i][k-i-1];
		}
		
	return (verif == somme && verif2 == somme);
	}

int main (void){
	int tab[k][k] = {{8,1,6},{3,5,7},{4,9,2}};
	int i = est_carre_magique (tab);
	printf ("%d \n", i);
	return 0;
	}


