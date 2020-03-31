/* fichier armes.c*/
#include "armes.h"

Weapon* initWeapon(char *nom, unsigned char CE, unsigned char CA, unsigned char minDegat, unsigned char maxDegat, unsigned char portee){
  Weapon *weapon = calloc(1, sizeof(Weapon));  

  weapon->nom = nom;
  weapon->CE = CE;
  weapon->CA = CA;
  weapon->minDegat = minDegat;
  weapon->maxDegat = maxDegat;
  weapon->portee = portee;

  return weapon;
}

Weapon** CreerTabArmes(){
  Weapon **tab = calloc(5,sizeof(Weapon*));

  tab[0] = initWeapon("Epluche Moitroa", 2, 1, 1, 2, 2);
  tab[1] = initWeapon("Mandoline Sonique", 5, 3, 1, 3, 3);
  tab[2] = initWeapon("Couperet Laser", 10, 5, 2, 6, 5);
  tab[3] = initWeapon("Hachoir Neuronique", 20, 7, 4, 9, 7);
  tab[4] = initWeapon("Mixeur Blaster", 30, 10, 7, 12, 11);

  return tab;
}

void printfArme(Weapon *weapon){
  printf("Nom:%s | CE:%d | CA:%d | Dégats:%d-%d | Portée:%d\n", weapon->nom, weapon->CE, weapon->CA, weapon->minDegat, weapon->maxDegat, weapon->portee);
}

void printTabArme(Weapon **tabArmes){
     int j;
    orange();
    printf(" #######################################################################\n");
    printf("# \t\t\t EQUIPEMENT ARMES \t\t\t\t#\n");
    printf("#_______________________________________________________________________#\n");
    printf("#|         NOM          | CA | CE |  DEGAT MIN   |  DEGAT MAX  | PORTEE|#\n");
    printf("#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx#\n");
    for(j = 0; j < 5 ; j++ ){
        printf("#  %20s ",tabArmes[j]->nom);
        printf("| %2d ",tabArmes[j]->CA);
        printf("|%3d ",tabArmes[j]->CE);
        printf("|%13d ",tabArmes[j]->minDegat);
        printf("|%12d ",tabArmes[j]->maxDegat);
        printf("|%6d |#\n",tabArmes[j]->portee);
    }
    printf(" #######################################################################\n");
    
    printf("\n\n");
    reset();
}

void freeTableauArmes(Weapon **tabArmes){
  int i;
  for (i=0; i<5; i++)
    free(tabArmes[i]);
  free(tabArmes);
}


