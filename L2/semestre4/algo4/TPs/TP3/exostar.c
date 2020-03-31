#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NB_LIG 10000

int truc_machin (int** tab, int long_tab){
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

int truc_machin_marrejesuis (int** tab, int long_tab){
	int i = 0, j = 1, k = 0, i_star = 1;
	while ( j < long_tab){
		if (tab[j][i]){
			j++;
		}
		else {
			i = j;
			j ++;
		}
	}
	j = 0;
	while (j < i && i_star){
		if (tab[j][i]){
			j ++;
		}
		else {
			i_star = 0;
		}
	}
	j = 0;
	while ( k < long_tab && i_star){
		if (k!=i && tab[i][j]){
			i_star = 0;
		}
		else {
			k++;
		}
	}
	if (i_star){
		return i;
	}
	return -1;
			
}

int** init_mat (void){
	srand(time(NULL));
	int * val = calloc(NB_LIG*NB_LIG, sizeof(int));
	int** ret = malloc(NB_LIG*sizeof(int*));
	int i = 0;
	for (i = 0; i < NB_LIG; i++){
		ret[i]= val + i*NB_LIG;
	}
	for (i = 0; i < NB_LIG; i++){
		ret[i][NB_LIG-1]= 1;
	}
	return ret;
}

int main (void){
	int** mat;
	mat = init_mat();
	clock_t start_t, end_t;
	double total_t;
	start_t = clock();
	printf("%d \n",truc_machin(mat, NB_LIG));
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Temps prit par le processeur: %f \n", total_t);
	start_t = clock();
	printf("%d \n",truc_machin_marrejesuis(mat, NB_LIG));
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Temps prit par le processeur: %f \n", total_t);
	return 0;
}
