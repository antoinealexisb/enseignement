/* Fichier champions.c */

#include "champions.h"

Champion* initChampion(char* nom, char* type,unsigned char force,unsigned char resistance,int pv,int ce){
    Champion *champion = calloc(1, sizeof(Champion));

    champion->nom        = nom;
    champion->type       = type;
    champion->force      = force;
    champion->resistance = resistance;
    champion->pv_max     = pv;
    champion->pv         = pv;
    champion->CE         = ce;

    return champion;
}


Champion** CreeTabChampionLegume(){
    Champion **tab   = calloc(6, sizeof(Champion*));

    tab[0] = initChampion("Haricobail","legume",10,10,40,5);
    tab[1] = initChampion("Feblouille","legume",5,5,50,5);
    tab[2] = initChampion("Poireauto","legume",20,20,60,15);
    tab[3] = initChampion("Auberginette","legume",5,10,85,15);
    tab[4] = initChampion("Carrotrock","legume",25,25,80,25);
    tab[5] = initChampion("C-800","legume",35,35,60,25);

    return tab;
}

Champion** CreeTabChampionFruit(){
    Champion **tab  = calloc(6, sizeof(Champion*));

    tab[0] = initChampion("Citronaw","fruit ",30,5,25,5);
    tab[1] = initChampion("Fraimler","fruit ",5,5,50,5);
    tab[2] = initChampion("Melonade","fruit ",20,20,60,15);
    tab[3] = initChampion("El Papaya","fruit ",10,10,80,15);
    tab[4] = initChampion("Darth Presk","fruit ",25,25,80,25);
    tab[5] = initChampion("Coco Bongo","fruit ",35,35,60,25);

    return tab;
}

void printfChampion(Champion *champion){
    printf("%s | Nom:%s | Force:%d | Resistance:%d | Pv:%d | Cout:%d \n",champion->type,champion->nom,champion->force,champion->resistance,champion->pv,champion->CE);
}

void printPresentation(Champion **tab, Champion **tab2){
    int i;
    vert();
    printf(" #######################################################################\n");
    printf("# \t\t\t EQUIPE VEGETABLE \t\t\t\t#\n");
    printf("#_______________________________________________________________________#\n");
    printf("#|   NOM       |   TYPE   |   FORCE    |    RES    |    PV    |    CE  |#\n");
        printf("#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#\n");
for(i = 0;i < 6;i++){
        printf("# %12s |",tab[i]->nom);
    printf(" %8s |",tab[i]->type);
    printf(" %9d  |",tab[i]->force);
    printf(" %8d  |",tab[i]->resistance);
    printf(" %7d  |",tab[i]->pv_max);
    printf(" %6d |#\n",tab[i]->CE);
}
     printf("#_______________________________________________________________________#\n");
for(i = 0;i < 6;i++){
    printf("# %12s |",tab2[i]->nom);
    printf(" %8s |",tab2[i]->type);
    printf(" %9d  |",tab2[i]->force);
    printf(" %8d  |",tab2[i]->resistance);
    printf(" %7d  |",tab2[i]->pv_max);
    printf(" %6d |#\n",tab2[i]->CE);
}
    printf(" #######################################################################\n");
    
    printf("\n\n");
    reset();
}


void printTabVegetaux(Champion **tab){
    int i;
    vert();
    printf(" #######################################################################\n");
    printf("# \t\t\t EQUIPE VEGETABLE \t\t\t\t#\n");
    printf("#_______________________________________________________________________#\n");
    printf("#|   NOM       |   TYPE   |   FORCE    |    RES    |    PV    |    CE  |#\n");
        printf("#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#\n");
for(i = 0;i < 6;i++){
        printf("# %12s |",tab[i]->nom);
    printf(" %8s |",tab[i]->type);
    printf(" %9d  |",tab[i]->force);
    printf(" %8d  |",tab[i]->resistance);
    printf(" %7d  |",tab[i]->pv_max);
    printf(" %6d |#\n",tab[i]->CE);
}
    printf(" #######################################################################\n");
    
    printf("\n\n");
    reset();
}

void printTabFruit(Champion **tab2){
 int i;
    rouge();
    printf(" #######################################################################\n");
    printf("# \t\t\t EQUIPE FRUITABLE \t\t\t\t#\n");
    printf("#_______________________________________________________________________#\n");
    printf("#|   NOM       |   TYPE   |   FORCE    |    RES    |    PV    |    CE  |#\n");
        printf("#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#\n");
for(i = 0;i < 6;i++){
        printf("# %12s |",tab2[i]->nom);
    printf(" %8s |",tab2[i]->type);
    printf(" %9d  |",tab2[i]->force);
    printf(" %8d  |",tab2[i]->resistance);
    printf(" %7d  |",tab2[i]->pv_max);
    printf(" %6d |#\n",tab2[i]->CE);
}
    printf(" #######################################################################\n");
    
    printf("\n\n");
    reset();
}

void freeTableauChampion(Champion **tab){
  int i;
  for (i=0; i<6; i++)
    free(tab[i]);
  free(tab);
}


