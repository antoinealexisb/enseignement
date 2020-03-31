/*Fichier Projet.c */
#include "Projet.h"

void printenTete(){
  int i;
  vert_blink();
  printf(" #######################################################################\n");
  for(i=0;i<7;i++){
    if(i == 3){
        printf("#\t\t\t ITS TIME TO KILL EVERYONE \t\t\t#\n");
    }
    else{
        printf("#\t\t\t\t\t\t\t\t\t# \n");
    }
}
printf(" #######################################################################\n");
printf("\n\n");
reset();
}


void jeu(Equipe *equipe, Equipe *equipe2, Weapon **tabArmes, Care **tabSoins, Protection **tabProtections){
    int borne;
    static int CAequipe;
    static int CAequipe2;
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    equipe->pos = 0;
    equipe->posLimite = 0;

    equipe2->pos = w.ws_col-1;
    equipe2->posLimite = w.ws_col-1;
    
    /**borne CE*/
    if (equipe->CE > equipe2->CE)
      equipe->CE = equipe2->CE;
    else if (equipe2->CE > equipe->CE)
      equipe2->CE = equipe->CE;
    borne = equipe->CE;
    equipe->CE -= equipe->champion->CE;
    equipe2->CE -= equipe2->champion->CE;
    /** POSSIBILITÉ //// strat a ajouté // et changer la verif des CE**/
    if (equipe->strat != NULL){
      if (equipe->CE >= equipe->strat->CE){
        stratEquipement(equipe, tabArmes, tabProtections, tabSoins);
      }
      else{
        printf("Pas assez de CE pour utiliser la stratégie pour l'équipe legume\n");
        return;
      }
    }
    else if (equipe->CE >= tabArmes[0]->CE){
      choixEquipement(equipe, tabArmes, tabSoins, tabProtections, borne);
    }
    else{
      printf("Combat impossible pas assez de CE pour acheter ce champion et l'arme la moins chère\n");
        return;
    }
  
    if (equipe2->strat != NULL){
      if (equipe2->CE >= equipe2->strat->CE){
        stratEquipement(equipe2, tabArmes, tabProtections, tabSoins);
      }
      else{
        printf("Pas assez de CE pour utiliser la stratégie pour l'équipe Fruit\n");
        return;
      }
    }
    else if (equipe2->CE >= tabArmes[0]->CE){
      choixEquipement(equipe2, tabArmes, tabSoins, tabProtections, borne);
    }
    else{
      printf("Combat impossible pas assez de CE pour acheter ce champion et l'arme la moins chère \n");
      return;
    }

    equipe->CET -= borne-equipe->CE;
    equipe2->CET -= borne-equipe2->CE;
    /*save CA */
    CAequipe = equipe->CA;
    CAequipe2 = equipe2->CA;
  /*///// COMMENCEMENT JEU ////// */
    while(1){
      /*legume*/
      if (equipe->champion->pv > 0){
        traitement(equipe, equipe2, 1);
        equipe->CA = CAequipe;
      }
      else{
        printGameOver();
        gain(equipe2, equipe, borne);
        return;
      }

      /*fruit*/
      if (equipe2->champion->pv > 0){
        traitement(equipe2, equipe, -1);
        equipe2->CA = CAequipe2;
      }
      else{
        printfWinner();
        gain(equipe, equipe2, borne);
        return;
      }

    }

}


void freeTabs(Champion **tab, Champion **tab2, Weapon **armes, Care **soins, Protection **proc, Equipe *equipe1, Equipe *equipe2, Strategie **tabStrat, int nbFichiersStrat){
  freeTableauChampion(tab);
  freeTableauChampion(tab2);
  freeTableauArmes(armes);
  freeTableauSoins(soins);
  freeTableauProtections(proc);
  freeBuffer(equipe1->commande);
  freeBuffer(equipe2->commande);
  free(equipe1);
  free(equipe2);
  freeTableauStrat(tabStrat, nbFichiersStrat);
}

/**fonction de test de la partie 2 */
void test(char *s, Weapon **tabArmes){
  int i;
  int j;
  char tmp;
  for (i=0; i<5; i++){
    if (strlen(s) == strlen(tabArmes[i]->nom)){
      for (j=0; j<strlen(s); j++){
        tmp = ToUppercase((tabArmes[i]->nom)[j]);
        printf("%c \n", tmp);
        if (s[j]!=tmp){
          if ((s[j]=='_') && ((tmp=='-') || (tmp==' ')))
            continue;
          goto hola;
        }
      }
      hola:;
    }
    
  }
}

int main(int argc, char *argv[]){
    int nbFichiersStrat = 4;
    Strategie **tabStrat;    
    Champion** tab;
    Champion** tab2;
    Weapon **tabArmes;
    Protection **tabProtections;
    Care **tabSoins;
    Equipe *equipe;
    Equipe *equipe2;
    char *strToken;
    unsigned char id; /*juste pour économiser de la mémoire :D */
    char i;
    char commande[20];
    unsigned char sumEndFruit;
    unsigned char sumEndVegetable;
    srand(time(NULL));

    system("resize -s 87 32"); /* mettre la console en 87x32 merci ;) )*/

    equipe = initEquipe();
    equipe2 = initEquipe();

    tab = CreeTabChampionLegume();
    tab2 = CreeTabChampionFruit();
    tabArmes = CreerTabArmes();
    tabProtections = CreerTabProtections();
    tabSoins = CreerTabSoins();
    tabStrat = creerTabStrategie(tabArmes, tabProtections, tabSoins, argc, argv, &nbFichiersStrat);

    sumEndFruit = (tab2[0]->CE + tabArmes[0]->CE);
    sumEndVegetable = (tab[0]->CE + tabArmes[0]->CE);

    system("clear");
    printenTete();
    waitFor(7);
    system("clear");
    etatCredits(equipe, equipe2);
    printTabFruit(tab);;
    printTabVegetaux(tab2);

  while(1){
    printf(" > ");
    scanf("%[^\n]", commande);
    if (!strcmp(commande, "show vegetables"))
      printTabVegetaux(tab);
/*ICI partie 2 ninja :D */
    else if(!strcmp(commande, "show strategies"))
      printfStrategies(tabStrat,nbFichiersStrat);
    else if(strstr(commande, "show strategy ")){
      ((id = atoi(commande+14)-1)<nbFichiersStrat) ? printfDescription(tabStrat[id],tabArmes,tabProtections,tabSoins) : (void)printf("Stratégie inconnue\n");
    }
      
/*FIN partie 2 ninja :D */
    else if(!strcmp(commande, "show fruits"))
      printTabFruit(tab2);
    else if(!strcmp(commande, "show weapons"))
      printTabArme(tabArmes);
    else if(!strcmp(commande, "show protections"))
      printTabProtection(tabProtections);
    else if(!strcmp(commande, "show cares"))
      printTabSoin(tabSoins);
    else if (strstr(commande, "show vegetable "))
      ((id= atoi(commande+15)-1)<=5) ? printfChampion(tab[id]) : (void)printf("Champion inconnu\n");
    else if (strstr(commande, "show fruit "))
      ((id = atoi(commande+11)-1)<=5) ? printfChampion(tab2[id]) : (void)printf("Champion inconnu\n");
    else if (strstr(commande, "show weapon "))
      ((id = atoi(commande+12)-1)<=4) ? printfArme(tabArmes[id]) : (void)printf("Arme inconnue\n");
    else if (strstr(commande, "show protection "))
      ((id = atoi(commande+16)-1)<=4) ? printfProtection(tabProtections[id]) : (void)printf("Protection inconnue\n");
    else if (strstr(commande, "show care "))
      ((id = atoi(commande+10)-1)<=3) ? printfCare(tabSoins[id]) : (void)printf("Soin inconnu\n");
    else if (strstr(commande, "fight ") && strstr(commande, " versus ")){
      ReinitEquipe(equipe);
      ReinitEquipe(equipe2);
      strToken = strtok(commande, " ");
      i=0;
      while (strToken != NULL) { 
        if (!strcmp(strToken, "fight")){
          i=1;
          strToken = strtok(NULL, " ");
          ((id = atoi(strToken)-1) <=5) ? copieChampion(equipe, tab, id) : (void)printf("Legume inconnu\n");
          goto analyse;
        }
        if (!strcmp(strToken, "versus")){ 
          i=2;
          strToken = strtok(NULL, " ");
          ((id = atoi(strToken)-1) <=5) ? copieChampion(equipe2, tab2, id) : (void)printf("Fruit inconnu\n");
          goto analyse;
        }
        if (strcmp(strToken, "versus") && strcmp(strToken, "fight")){ 
          id = atoi(strToken)-1;
          if (i==1){
            if (id <nbFichiersStrat){
               equipe->strat = tabStrat[id];
            }
            else{
              printf("Equipe 1 : ");
              i=0;
            }
          }
          else if (i==2){
            if (id <nbFichiersStrat){
               equipe2->strat = tabStrat[id];
            }
            else{
              printf("Equipe 2 : ");
              i=0;
            }
          }
          if (i==0){
            ReinitEquipe(equipe);
            ReinitEquipe(equipe2);
            printf("Erreur strat ...\n");
          }
          i=0;
        }
analyse: strToken=strtok(NULL, " ");
      }

      if ((equipe->champion != NULL) && (equipe2->champion !=NULL)){
        system("clear");
        jeu(equipe, equipe2, tabArmes, tabSoins, tabProtections);
        etatCredits(equipe, equipe2);
      }

      /*((id = atoi(commande+6)-1) <=5) ? copieChampion(equipe, tab, id) : (void)printf("Legume inconnu\n");
      ((id = atoi(strstr(commande, " versus ")+8)-1) <=5) ? copieChampion(equipe2, tab2, id) : (void)printf("Fruit inconnu\n");
      if ((equipe->champion != NULL) && (equipe2->champion !=NULL)){
        system("clear");
        jeu(equipe, equipe2, tabArmes, tabSoins, tabProtections);
        etatCredits(equipe, equipe2);
      }*/
    }
    else if (!strcmp(commande, "exit") || (sumEndFruit>equipe2->CET) || (sumEndVegetable>equipe->CET) ){
      printf("Au revoir.\n");
      freeTabs(tab,tab2,tabArmes,tabSoins,tabProtections,equipe,equipe2,tabStrat,nbFichiersStrat);
      exit(0);
    }
    else
      printf("Commande non reconnue.\n\n");

    if ((sumEndFruit>equipe2->CET) || (sumEndVegetable>equipe->CET)){  
      if (equipe2->CET == equipe->CET){
        printVainqueur();
        printExaequo();
      }
      else if(sumEndFruit > equipe2->CET){
        printVainqueur();
        printLegumes();
      }
      else if(sumEndVegetable > equipe->CET){
        printVainqueur();
        printFruits();
      }
      else{
        printf("Au revoir.\n");
      }
      freeTabs(tab,tab2,tabArmes,tabSoins,tabProtections,equipe,equipe2,tabStrat,nbFichiersStrat);
      exit(0);
    }
    viderBuffer();
    memset(commande, 0, 20); /*enlève le contenu de la variable commande.*/
    
  }

    return 0;
}
