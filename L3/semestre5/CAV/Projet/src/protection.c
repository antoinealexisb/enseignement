/* Fichier protection.c */
#include "protection.h"


Protection* initProtection(char *nom, unsigned char CE, unsigned char CA, unsigned char proba){
  Protection *protection = calloc(1, sizeof(Protection));

  protection->nom = nom;
  protection->CE = CE;
  protection->CA = CA;
  protection->proba = proba;

  return protection;
}

Protection** CreerTabProtections(){
  Protection **tab = calloc(5, sizeof(Protection*));

  tab[0] = initProtection("Casque en papier", 1, 2, 25);
  tab[1] = initProtection("Casque-Entonnoir", 3, 4, 40);
  tab[2] = initProtection("Woklier", 5, 6, 60);
  tab[3] = initProtection("Tablier-Armure", 10, 8, 80);
  tab[4] = initProtection("Vanilla",0,0,0);
  return tab;
}

void printfProtection(Protection *protection){
  printf("Nom:%s | CE:%d | CA:%d | Probalité:%d%%\n", protection->nom, protection->CE, protection->CA, protection->proba);
}

void printTabProtection(Protection **tabProtections){
 
    
    int j ;
    jaune(); 
    printf(" #######################################################################\n");
    printf("# \t\t\t EQUIPEMENT PROTECTION \t\t\t\t#\n");
    printf("#_______________________________________________________________________#\n");
    printf("#|         NOM          |     CA     |     CE    |   CHANCE DE BLOQUER |#\n");
    printf("#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#\n");
    for(j = 0; j < 5 ; j++ ){
        printf("#  %20s ",tabProtections[j]->nom);
        printf("| %10d ",tabProtections[j]->CA);
        printf("|%11d ",tabProtections[j]->CE);
        printf("|%19d |#\n",tabProtections[j]->proba);
    }
    printf(" #######################################################################\n");
    
    printf("\n\n");
    reset();
}

void freeTableauProtections(Protection **tabProtections){
  int i;
  for (i=0; i<5; i++)
    free(tabProtections[i]);
  free(tabProtections);
}
