#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//QUESTION 1 et 2
//FONCTION MAX
int max(int *tab, int n){
	int i, max = tab[0];
	int cpt=0;
	for(i=1;i<n;i++){
		if(max < tab[i]){
			max = tab[i];
		}
		cpt++;
	}
	printf("\nQuestion 1,2 : %d comparaisons max#1\n",cpt);
	return max;
}

//FONCTION MIN
int min(int tab[], int n){
	int i, min = tab[0], cpt=0;;
	for(i=1;i<n;i++){
		if(min > tab[i]){
			min = tab[i];
		}
		cpt++;
	}
	printf("\nQuestion 1,2 :%d comparaisons min#1\n",cpt);
	return min;
}


//QUESTION 3
//FONCTION MIN_MAX retourne un soit disant couple(min,max) LOL
int *min_max2(int *tab, int n){
	int i, min = tab[0], max = tab[0],cpt=0;
	for(i=1;i<n;i++){
		if(min > tab[i]){
			min = tab[i];
		}
		if(max < tab[i]){
			max = tab[i];
		}
		cpt+=2;
	}
	int *tab2 = malloc(sizeof(int)*2);
	tab2[0] = min;
	tab2[1] = max;
	printf("\nQuestion 3 : %d comparaisons minmax#2\n",cpt);
	return tab2;
}

//QUESTION 4
//COMPARAISONS DEUX PAR DEUX
int *min_max3(int *tab, int n){
	
	int i, min, max, cpt=0;
	if(tab[0]>tab[1]){
		min=tab[1];
		max=tab[0];
	} else {
		min=tab[0];
		max=tab[1];
	}
	cpt+=2;
	for(i=2;i<n;i+=2){
		if(tab[i]>tab[i+1]){
			if(tab[i]>max) max = tab[i];
			if(tab[i+1]<min) min = tab[i+1];
		} else {
			if(tab[i+1]>max) max = tab[i+1];
			if(tab[i]<min) min = tab[i];
		}
		cpt+=3;
	}
	
	int *tab2 = malloc(sizeof(int)*2);
	tab2[0] = min;
	tab2[1] = max;
	printf("\nQuestion 4 :%d comparaisons minmax#3\n",cpt);
	return tab2;
}

//JE SUIS QUELQU'UN QUI N'AIME PAS AVOIR MAL AU POIGNE donc tableau ainsi :D
int *genererTab(int N, int valMax){
	int *tab = malloc(sizeof(int)*N);
	srand(time(NULL));
	int i;
	for(i=0;i<N;i++){
		tab[i] = rand()%valMax;
	}
	return tab;
}

int main(){
	int taille = 100000;
	int *tab = genererTab(taille,99999);
	int *tab2 = malloc(sizeof(int)*2);
	int *tab3 = malloc(sizeof(int)*2);
	
	double start_t, end_t, total_t;
	start_t = clock();
	
	/*Fonctions*/

	printf("Max=%d\n %f\n",max(tab,taille),clock()-start_t);
	start_t = clock();
	printf("Min=%d\n %f\n",min(tab,taille),clock()-start_t);
	
	start_t=clock();
	tab2 = min_max2(tab,taille);
	printf("Min=%d Max=%d %f\n",tab2[0],tab2[1],clock()-start_t);
	
	start_t = clock();
	tab3 = min_max3(tab,taille);
	printf("Min=%d Max=%d\n",tab3[0],tab3[1]);
	
	end_t = clock();
	total_t = (end_t - start_t) / CLOCKS_PER_SEC;
	printf(" %f\n", total_t);
	return(0);
}
