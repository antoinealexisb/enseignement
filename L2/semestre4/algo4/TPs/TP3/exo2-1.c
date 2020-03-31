#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NB_LIG 10000

/* question 1:
 * Seulement une star au maximum.
*/


int** init_mat(void){
	srand(time(NULL));
	int *val = calloc(NB_LIG*NB_LIG, sizeof(int));
	int **ret = malloc(NB_LIG*sizeof(int*));
	int i = 0;
	for (i = 0; i < NB_LIG; i++){
		ret[i]= val + i*NB_LIG;
	}
	for (i = 0; i < NB_LIG; i++){
		ret[i][NB_LIG-1]= 1;
	}
	ret[15][9999] = 0; //test ERRRRRREEEEEEUUUUURRR car star connait personne
	return ret;
}

int connait_la_star(int** tab, int long_tab){
	int i, j, verif;
	for (i = 0; i < long_tab; i++){
		verif = 1;
		for (j=0; j <long_tab; j++){
			if (j!=i && tab[i][j] && !tab[j][i]){
				verif = 0;
			}
		}
		if (verif){
			return i;
		}
	}
	return -1;		
}

int main(void){
	int **mat;
	mat = init_mat();
	printf("%d \n", connait_la_star(mat, NB_LIG));
	return(0);
}

