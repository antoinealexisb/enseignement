/* Fichier equipe.c */


#include "equipe.h"

Equipe* initEquipe(){
    Equipe *equipe = calloc(1,sizeof(Equipe));
    equipe->CE         = 50;
    equipe->CA         = 50;
    equipe->CET        = 1000;
    equipe->activeProtection = 0;
    equipe->commande   = calloc(1,sizeof(Buffer));
    return equipe;
}

void ReinitEquipe (Equipe *equipe){
    if (equipe->champion != NULL){
        free(equipe->champion);
    }
    equipe->strat      = NULL;
    equipe->champion   = NULL;
    equipe->weapon     = NULL;
    equipe->protection = NULL;
    equipe->soin       = NULL;
    if (equipe->CET >= 50){
      equipe->CE = 50;
    }
    else {
      equipe->CE = equipe->CET;
    }
    equipe->CA         = 50;
    equipe->activeProtection = 0;
    freeBuffer(equipe->commande);
    equipe->commande = calloc(1,sizeof(Buffer));
}

void afficheEquipe(Equipe *equipe){
    printf("\n");
    printfChampion(equipe->champion);
    printfArme(equipe->weapon);
    printfProtection(equipe->protection);
    printfCare(equipe->soin);
    printf("\n");
}

void achatCA(Equipe *equipe){
  char YN;
  int montant;
  do{
    printf("\nVoulez-vous acheter des CA (1CE = 1CA) (Y/N) : ");
    scanf("%c",&YN);
    viderBuffer();
  }while(YN!='Y' && YN!='N');
  if (YN=='Y'){
    do{
      printf("\nSaisissez votre montant de CA à acheter : ");
      scanf("%d", &montant);
      viderBuffer();
    }while(montant>equipe->CE && printf("Montant trop élevé pour vos moyens !\nPour annuler l'achat mettez 0 comme montant, sinon entrez un montant valide\n")); 
    equipe->CA+=montant;
  }
}

void afficheNbCE(Equipe* equipe1, Equipe* equipe2){
  printf("equipe1 : CE : %d , equipe2 : CE : %d\n", equipe1->CET, equipe2->CET);
}

void afficherEtatAdversaire(Equipe *defenseur){
  printf("Votre adversaire %s possède encore %d points de vie.\n", defenseur->champion->nom, defenseur->champion->pv);
}

/**
 * Fonction qui affiche juste les CE restant et les CE dépensés 
 */
void depense(Equipe *equipe, int borne){
  printf("\nCE restant %d et CE depensé %d\n\n",equipe->CE, borne-equipe->CE);
}

void gain(Equipe *gagnant, Equipe *perdant, int borne){
  int max;
  if ((max=((borne-perdant->CE)-(borne-gagnant->CE)))<1)
    max = 1;
  gagnant->CET+=5*max;
  printf("Bilan :\n\t gain du vainqueur : %d CE\n",5*max);
}

void etatCredits(Equipe *equipe, Equipe *equipe2){
  printf("\n Equipe 1 : CE : %d \n Equipe 2 : CE : %d\n",equipe->CET, equipe2->CET);
  free(equipe->champion);
  free(equipe2->champion);
}

void viderBuffer(){
    char c1;
    while(((c1 = getchar()) != '\n')&&(c1 != EOF));
}

void copieChampion(Equipe *equipe, Champion **tab, int choix){
  Champion *tmp = malloc(sizeof(Champion));
  tmp = memcpy(tmp, tab[choix], sizeof(Champion));
  equipe->champion = tmp;
}

void stratEquipement(Equipe *equipe, Weapon **tabWeapons, Protection **tabPros, Care **tabSoins){
  Strategie *strat = equipe->strat;  
  equipe->weapon = tabWeapons[strat->tabInd[0]];
  equipe->protection = tabPros[strat->tabInd[1]];
  equipe->soin = tabSoins[strat->tabInd[2]];
  equipe->CA += strat->tabInd[3];
  equipe->CE -= strat->CE;
}

void ChooseYourWeapon(Equipe *equipe,Weapon **tab){
    int choix;
    char YN;
    Weapon *tmp;
    do{
    printTabArme(tab);
    printf("Prends l'arme qui te convient (1 à 5): \n");
    do{
        scanf("%d",&choix);
        viderBuffer();
    }
    while( choix < 1 || choix  > 5 );
      tmp = tab[choix-1];
    }while(equipe->CE < tmp->CE && printf("Impossible d'équiper l'équipement \n\n"));
        do{
          printf("\nÊtes-vous sûr de vouloir prendre %s ? (Y/N) : ",tmp->nom);
          scanf("%c",&YN);
          viderBuffer();
        }while(YN!='Y' && YN!='N');
        if (YN=='Y'){
        equipe->weapon = tmp;
        equipe->CE -= tmp->CE;
        }
        else{
          ChooseYourWeapon(equipe, tab);
        }
}

/**/
void ChooseProctetion(Equipe *equipe,Protection **tab){
    int choix;
    char YN;
    Protection *tmp;
    printf("Choisi une protection, celle-ci n'est pas obligatoire \n");
    printTabProtection(tab);
    do{
        scanf("%d",&choix);
        viderBuffer();
    }
    while(choix < 1 || choix > 5 );
    tmp = tab[choix-1];
    if(equipe->CE >= tmp->CE){
        do{
          printf("\nÊtes-vous sûr de vouloir prendre %s ? (Y/N) : ",tmp->nom);
          scanf("%c",&YN);
          viderBuffer();
        }while(YN!='Y' && YN!='N');
        if (YN=='Y'){
        equipe->protection = tmp;
        equipe->CE -= tmp->CE;
        }
        else{
          ChooseProctetion(equipe, tab);
        }
    }
    else{
      printf("Impossible d'équiper l'équipement !\n");
      do{
        printf("\nVoulez-vous choisir autre chose (Y/N) : ");
        scanf("%c",&YN);
        viderBuffer();
      }while(YN!='Y' && YN!='N');
      if (YN=='Y'){
        ChooseProctetion(equipe, tab);
      }
      else{
        printf("Protection Vanilla activée\n");
        equipe->protection = tab[4];
        waitFor(2);
      }
    }
}

/**/
void ChooseCare(Equipe *equipe,Care **tab){
    int choix;
    char YN;
    Care *tmp;
    printf("Choisi un objet de soins celui-ci n'est pas obligatoire \n");
    printTabSoin(tab);
    do{
        scanf("%d",&choix);
        viderBuffer();
    }
    while(choix < 1 || choix > 4 );
    tmp = tab[choix-1];
    if(equipe->CE >= tmp->CE){
        do{
          printf("\nÊtes-vous sûr de vouloir prendre le soin %s ? (Y/N) : ",tmp->nom);
          scanf("%c",&YN);
          viderBuffer();
        }while(YN!='Y' && YN!='N');
        if (YN=='Y'){
        equipe->soin = tmp;
        equipe->CE -= tmp->CE;
        }
        else
          ChooseCare(equipe, tab);
    }
    else{
      printf("Impossible d'équiper le soin !\n");
      do{
        printf("\nVoulez-vous choisir un autre soin (Y/N) : ");
        scanf("%c",&YN);
        viderBuffer();
      }while(YN!='Y' && YN!='N');
      if (YN=='Y')
        ChooseCare(equipe, tab);
      else{
        printf("Soin Rambo activé\n");
        equipe->soin = tab[3];
        waitFor(3);
      }
    }
}

void choixEquipement(Equipe *equipe, Weapon **tabArmes, Care **tabSoins, Protection **tabProtections, int borne){
      system("clear");
      depense(equipe, borne);
      ChooseYourWeapon(equipe,tabArmes);

      system("clear");
      depense(equipe, borne);
      ChooseProctetion(equipe,tabProtections);

      system("clear");
      depense(equipe, borne);
      ChooseCare(equipe,tabSoins);

      system("clear");
      depense(equipe, borne);
      achatCA(equipe);
      afficheEquipe(equipe);
      waitFor(5);
}



