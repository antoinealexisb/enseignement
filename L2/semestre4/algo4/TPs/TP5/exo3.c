#include <stdio.h>
#include <stdlib.h>

#define NB_REINE 8

int** init_mat (void){
  int i;
	int** ret = malloc(NB_REINE*sizeof(int*));
  for (i = 0; i < NB_REINE; i++){
    ret[i] = calloc (NB_REINE,sizeof(int));
  }
	return ret;
}

void print_mat (int** tab){
  int i, j;
  for (i = 0; i < NB_REINE; i++){
    for (j = 0; j < NB_REINE; j++){
      printf("%d; ",tab[i][j]);
    }
    printf("\n");
  }
}

int verif_reine(int** tab, int col, int lig){
  if (tab[col][lig] == 0){
    return 1;
  }
  return 0;
}

int verif_reine_v2(int **tab, int col, int lig){
  int i, verif1, verif2;
  //colonnes
  for (i = 0; i < NB_REINE; i++){
    if (!verif_reine(tab, col, i)){
      return 0;
    }
  }
  //lignes
  for (i = 0; i < NB_REINE; i++){
    if (!verif_reine(tab, i, lig)){
      return 0;
    }
  }

  verif1 = col-1;
  verif2 = lig-1;
  while (verif1 >=0 && verif2 >=0){
    if (!verif_reine(tab, verif1, verif2)){
      return 0;
    }
    verif1--;
    verif2--;
  }

  verif1 = col+1;
  verif2 = lig+1;
  while (verif1 < NB_REINE && verif2 < NB_REINE){
   if (!verif_reine(tab, verif1, verif2)){
     return 0;
   }
  verif1++;
  verif2++;
 }

  verif1 = col+1;
    verif2 = lig-1;
      while (verif1 < NB_REINE && verif2 >= 0){
	          if (!verif_reine(tab, verif1, verif2)){
			        return 0;
				    }
		      verif1++;
		          verif2--;
			    }
        verif1 = col-1;
	  verif2 = lig+1;
	    while (verif1 >= 0 && verif2 < NB_REINE){
		        if (!verif_reine(tab, verif1, verif2)){
				      return 0;
				          }
			    verif1--;
			        verif2++;
				  }
	      return 1;

}

int cherche_reine (int** tab, int nb_reines, int col){
  int i;
  if (nb_reines == 0){
    return 1;
  }
  else{
    for(i = 0; i < NB_REINE; i++){
      if (verif_reine_v2(tab, col, i)){
        tab[col][i] = 1;
        cherche_reine(tab, nb_reines, col+1);
      }
    }
    return 0;
  }
}

int main(void){
	int **tab;
	tab = init_mat();
	print_mat(tab);
	int pokemon = cherche_reine(tab, NB_REINE, 0);
	printf("\n");
	print_mat(tab);
	return(0);
}
