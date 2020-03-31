/* Fichier soins.c */

#include "soins.h"


Care* initSoin(char *nom, unsigned char CE, unsigned char CA, unsigned char volumes, unsigned char minEffet, unsigned char maxEffet){
  Care *soin = calloc(1, sizeof(Care));

  soin->nom = nom;
  soin->CE = CE;
  soin->CA = CA;
  soin->volumes = volumes;
  soin->minEffet = minEffet;
  soin->maxEffet = maxEffet;

  return soin;
}

Care** CreerTabSoins(){
  Care **tab = calloc(4, sizeof(Care*));

  tab[0] = initSoin("Humus-Neutronique", 1, 5, 4, 2, 4);
  tab[1] = initSoin("Compost-Protonique", 5, 10, 3, 5, 8);
  tab[2] = initSoin("Engrais-Ionique", 7, 15, 2, 8, 12);
  tab[3] = initSoin("Rambo",0,0,0,0,0);
  return tab;
}

void printfCare(Care *soin){
  printf("Nom:%s | CE:%d | CA:%d | Volumes:%d | Effet:%d-%d\n", soin->nom, soin->CE, soin->CA, soin->volumes, soin->minEffet, soin->maxEffet);
}

void printTabSoin(Care **tabSoins){
 
    
    int j;
    vert();
    printf(" #######################################################################\n");
    printf("# \t\t\t EQUIPEMENT SOIN \t\t\t\t#\n");
    printf("#_______________________________________________________________________#\n");
    printf("#|          NOM         |  CA   |  CE  |   VOLUMES   |   MIN  |   MAX  |#\n");
    printf("#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#\n");
    for(j = 0; j < 4 ; j++ ){
        printf("#  %20s ",tabSoins[j]->nom);
        printf("| %5d ",tabSoins[j]->CA);
        printf("|%5d ",tabSoins[j]->CE);
        printf("|%12d ",tabSoins[j]->volumes);
        printf("|%5d ",tabSoins[j]->minEffet);
        printf("|%9d |#\n",tabSoins[j]->maxEffet);
    }
    printf(" #######################################################################\n");
    
    printf("\n\n");
    reset();
}

void freeTableauSoins(Care **tabSoins){
  int i;
  for (i=0; i<4;i++)
    free(tabSoins[i]);
  free(tabSoins);
}


