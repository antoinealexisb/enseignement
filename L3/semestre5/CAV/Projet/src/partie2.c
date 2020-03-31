/*Fichier partie2.h*/

#include "partie2.h"


/** PARTIE CONCERNANT LA CONFORMITÉ DU FICHIER */
/** Le fichier doit :
	- Avoir un nom (donc après le strategy) si y'a pas erreur.
	- Avoir une arme (obligation) sinon erreur.
	- Stratégie conforme (pour eviter que dans le traitement des erreurs apparaissent).

Le retour des erreurs sera géré par la fonction qui créer tout le tableau. */

int verifGeneral(char *s, Weapon **tabArmes){/**si error = 1 alors le fichier est valide sinon il n'est pas valide. */
  int error=1;
  FILE *perte = fopen(s, "r");
  if (!perte){
    fprintf(stderr,"Erreur: fichier inconnu %s.\n",s);
    free(perte);
    return 0;
  }
  if (!verifNom(perte)){
    fprintf(stderr,"Erreur : Le nom dans le fichier %s n'est pas valide.\n", s);
    error=0;
  }
  if (verifArme(perte, tabArmes)==-1){
    fprintf(stderr,"Le nom de l'arme n'est pas valide pour le fichier %s.\n",s);
    error=0;
  }
  if (verifFile(perte, 0)){
    fprintf(stderr,"La strategie du fichier %s n'est pas valide.\n",s);
    error=0;
  }
  fclose(perte);
  perte=NULL; /*evite de clear mauvais code (memcheck;) )*/
  free(perte);
  return error;

}

int verifNom(FILE* fichier){ /*verifie si le mot strategy existe , si existe alors le nom
                                 de la stratégie est le mot suivant */
  char buf[50];
  fseek(fichier, 0, SEEK_SET);/*curseur remit sur la position 0*/
  while (fscanf(fichier, "%s", buf)!=0 && !feof(fichier)){
    if (!strcmp(buf, "strategy")){ 
      fscanf(fichier, "%s", buf);
      return 1;
    }
  }
  return 0;
}

int verifArme(FILE* fichier, Weapon **tabArmes){ /*Car Arme obligatoire le reste non obligatoire */
  char buf[50];
  fseek(fichier, 0, SEEK_SET);/*curseur remit sur la position 0*/
  while(fscanf(fichier, "%s", buf)!=0 && !feof(fichier)){
    if (!strcmp(buf, "choose")){
      fscanf(fichier, "%s", buf);
      if (!strcmp(buf, "weapon")){
        fscanf(fichier, "%s", buf);
        return indWeapon(buf, tabArmes);
      }
    }
    if (!strcmp(buf, "if"))
      return(-1);
  }
  return(-1);
}

int verifFile(FILE* fichier,int ite){
/** int ite permet de savoir le nombre de boucle 0 == appel ;D
0 fichier valide
autre fichier non valide
*/
   char buf[50];
   char buf2[50];
   int nbIf=0;
   if (ite==0){
     fseek(fichier, 0, SEEK_SET);
     fscanf(fichier,"%s",buf);
       while (strcmp(buf,"if") && feof(fichier)==0){
         fscanf(fichier,"%s",buf);
       }
    fseek(fichier, ftell(fichier)-strlen(buf), SEEK_SET);
   }
    while (fscanf(fichier, "%s", buf)!=0 && !feof(fichier)){
        if (!strcmp(buf, "if")){
          nbIf=1;
          fscanf(fichier, "%s", buf);
          if (!strcmp(buf, "life") || !strcmp(buf, "enemyLife")){
            fscanf(fichier, "%s", buf);
            fscanf(fichier, "%s", buf2);
            if (!strcmp(buf, "<") || !strcmp(buf, "<=") || !strcmp(buf, "=") || !strcmp(buf, "life") || !strcmp(buf, "!=") || !strcmp(buf, ">=") || !strcmp(buf, ">")){
              if (estNum(buf2[0])){
              	while(nbIf!=0 && buf[0]!=EOF && !feof(fichier)){
                  /*fprintf(stderr, "1er etape %d \n", ftell(fichier));*/
                  fscanf(fichier, "%s", buf);
                  /*fprintf(stderr, "2e etape%s %d %d \n", buf, ftell(fichier), feof(fichier));*/
                  if (feof(fichier)){break;}/*obliger de mettre condition ici pour certain cas if if , if life if ... .*/
                  else if (!strcmp(buf, "if")){
                    fseek(fichier, ftell(fichier)-strlen(buf), SEEK_SET);
                    nbIf+=verifFile(fichier,ite+1);
                  }
                  else if (!strcmp(buf, "endif")){
                  /*fprintf(stderr, "coucou %s \n", buf);*/
                    nbIf--;}
                  
                }
                if (nbIf>0){
                  return(100);
                }
                if (ite>0)
                  return(0);
              }
              else{
                return(100);}
            }
            else{
              return(100);
            }
          }
          else if(!strcmp(buf,"enemyInScope")){
            /*fprintf(stderr,"lollool\n");*/
          while(nbIf!=0 && buf[0]!=EOF && !feof(fichier)){
            fscanf(fichier, "%s", buf);
            if (feof(fichier)){break;}/*obliger de mettre condition ici pour certain cas if if , if life if ... .(feof renvoi 1 alors que dans le while c'est 0 [donc boucle inf])*/
            else if (!strcmp(buf, "if")){
              fseek(fichier, ftell(fichier)-strlen(buf), SEEK_SET);
              nbIf+=verifFile(fichier,ite+1);
            }
            else if (!strcmp(buf, "endif")){
              /*fprintf(stderr, "coucou j'en ai moins %s %d\n", buf,nbIf);*/
              nbIf--;
            }
          }
          if (nbIf>0){
                  return(100);
                }
          if (ite>0)
              return(0);
        }
          else{
            return(100);
          }
        }
        else{
          /*fprintf(stderr, "coucou %s \n",buf);*/
          return(100);
        }
     }
     return(0);
}

/** Si validation du fichier les fonctions si serviront ;) */

int* chooseNoms(FILE* fichier,int curseur, int limite, Weapon **tabArmes, Protection **tabPro, Care **tabSoins){
  /*char **tab = calloc(4,sizeof(char));*//* 0:weapon; 1:protection; 2:care; 3:CA*/
  int *tab = calloc(4,sizeof(int));
  char buf[50];/*, weapon[50], protection[50], care[50], CA[2];*/
  tab[1]=4;
  tab[2]=3;
  fseek(fichier, curseur, SEEK_SET);
  while(ftell(fichier)<limite){
    fscanf(fichier, "%s", buf);
    if (!strcmp(buf, "choose")){
      fscanf(fichier, "%s", buf);
      if (!strcmp(buf, "weapon")){
        fscanf(fichier, "%s", buf);
        tab[0]=indWeapon(buf, tabArmes);
      }
      if(!strcmp(buf, "protection")){
        fscanf(fichier, "%s", buf);
        tab[1]=indProtection(buf, tabPro);
      }
      if(!strcmp(buf, "care")){
        fscanf(fichier, "%s", buf);
        tab[2]=indSoin(buf, tabSoins);
      }
    }
    if (!strcmp(buf, "add")){
      fscanf(fichier, "%s", buf);
      fscanf(fichier, "%s", buf);
      tab[3]=atoi(buf);
    }
  }
  return tab;
}



void printfDescription(Strategie *strat, Weapon **tabArmes, Protection **tabPro, Care **tabSoins){
  printf("#########################\n");
  printf("## Stratégie : %s ##\n",strat->nom);
  printf("## Arme : %s ##\n", tabArmes[strat->tabInd[0]]->nom);
  printf("## Protection : %s ##\n", tabPro[strat->tabInd[1]]->nom);
  printf("## Soin : %s ##\n", tabSoins[strat->tabInd[2]]->nom);
  printf("## CA supplémentaires : %d ##\n", strat->tabInd[3]);
  printf("## cout de la stratégie en CE : %d \n", strat->CE);
  printf("\n\n");

}


int indWeapon(char *s, Weapon **tabArmes){
  int i;
  int j;
  char tmp;
  for (i=0; i<5; i++){
    if (strlen(s) == strlen(tabArmes[i]->nom)){
      for (j=0; j<strlen(s); j++){
        tmp = ToUppercase((tabArmes[i]->nom)[j]);
        if (s[j]!=tmp){
          if ((s[j]=='_') && ((tmp=='-') || (tmp==' ')))
            continue;
          goto hola;
        }
      }
      return i;
      hola:;
    } 
  }
  return -1; /*si arme inconnu renvoyé une erreur ensuite ;) */
}

int indProtection(char *s, Protection **tabPro){
  int i;
  int j;
  char tmp;
  for (i=0; i<5; i++){
    if (strlen(s) == strlen(tabPro[i]->nom)){
      for (j=0; j<strlen(s); j++){
        tmp = ToUppercase((tabPro[i]->nom)[j]);
        if (s[j]!=tmp){
          if ((s[j]=='_') && ((tmp=='-') || (tmp==' ')))
            continue;
          goto hello;
        }
      }
      return i;
      hello:;
    } 
  }
  return 4; /*remplacer -1 par l'equipement null */
}

int indSoin(char *s, Care **tabSoins){
  int i;
  int j;
  char tmp;
  for (i=0; i<5; i++){
    if (strlen(s) == strlen(tabSoins[i]->nom)){
      for (j=0; j<strlen(s); j++){
        tmp = ToUppercase((tabSoins[i]->nom)[j]);
        if (s[j]!=tmp){
          if ((s[j]=='_') && ((tmp=='-') || (tmp==' ')))
            continue;
          goto bonjour;
        }
      }
      return i;
      bonjour:;
    } 
  }
  return 3; /*remplacer -1 par l'equipement null */
}

Strategie* initStrategie(FILE *fichier, Weapon **tabArmes, Protection **tabPro, Care **tabSoins){
Strategie *strategie = calloc(1, sizeof(Strategie));
int detectionScript(FILE *fichier);

  strategie->nom = nomFichier(fichier);
  strategie->fichier = fichier;
  strategie->equipement = ftell(fichier);
  strategie->script = detectionScript(fichier);
  strategie->tabInd = chooseNoms(fichier, strategie->equipement, strategie->script, tabArmes, tabPro, tabSoins);
  strategie->CE=(tabArmes[(int)strategie->tabInd[0]]->CE + tabPro[(int)strategie->tabInd[1]]->CE + tabSoins[(int)strategie->tabInd[2]]->CE + strategie->tabInd[3]);
  return strategie;
}

char* nomFichier(FILE* fichier){
  char *buf = malloc(sizeof(char)*50);
  fseek(fichier, 0, SEEK_SET);/*curseur remit sur la position 0*/
  while (fscanf(fichier, "%s", buf)!=0){/* && !feof(fichier)){*/
    if (!strcmp(buf, "strategy")){ 
      fscanf(fichier, "%s", buf);
      return buf;
    }
  }
  return "";
}

int detectionScript(FILE *fichier){
  char buf[50];
  while (fscanf(fichier, "%s", buf)!=0){
    if (!strcmp(buf, "if")){
      return ftell(fichier)-2;
    }
  }
  return 0;
}

void afficheSuite(Strategie *strat){
  char buf[50];
  printf("%d \n", SEEK_SET);
  if (fseek(strat->fichier, strat->equipement, SEEK_SET))
    printf("erreur \n");
  while (feof(strat->fichier)==0 && fscanf(strat->fichier, "%s", buf)!=0){
    printf("%s \n", buf);
  }
}

int ceStrategie(char **tabStrat, Weapon **tabArmes, Protection **tabPro, Care **tabSoins){

  return(0);
}



void printfStrategies(Strategie **tab, int nbFichiersStrat){
  int i;
  printf("#######################\n");
  for (i=0; i<nbFichiersStrat; i++){
    printf("# %d | nom: %s #\n", i+1, tab[i]->nom);
  }
  printf("\n");
}

Strategie** creerTabStrategie(Weapon **tabArmes, Protection **tabPro, Care **tabSoins, int nbArg, char *tabArg[], int *nbFichiersStrat){
  Strategie** tab = calloc(*nbFichiersStrat+(nbArg-1), sizeof(Strategie*));
  int j=0, i;
/**Stratégie déjà incluses. */
  tab[j++] = initStrategie(fopen("./strat/exemple.strat","r"), tabArmes, tabPro, tabSoins);
  tab[j++] = initStrategie(fopen("./strat/bouftou.strat","r"), tabArmes, tabPro, tabSoins);
  tab[j++] = initStrategie(fopen("./strat/agreV2.strat","r"), tabArmes, tabPro, tabSoins);
  tab[j++] = initStrategie(fopen("./strat/dash2en1.strat","r"), tabArmes, tabPro, tabSoins);

/** Stratégie de l'arguments *argv[] */

  if (nbArg > 1){
  int verif = 0;
  for (i=1; i<=nbArg-1; i++){
     verif = verifGeneral(tabArg[i], tabArmes);
     if (verif){
         tab[j] = initStrategie(fopen(tabArg[i],"r"), tabArmes, tabPro, tabSoins);
         if (tab[j]->CE > 50){
             fprintf(stderr,"Trop de CE pour la stratégie %s ", tab[j]->nom);
             freeStrat(tab[j]);
         }
         else{
             j++;
         }
     }
  }
  waitFor(5);
  }
  *nbFichiersStrat = j;

  return tab;
  
}

void freeStrat(Strategie *strat){
  free(strat->nom);
  free(strat->tabInd);
  fclose(strat->fichier);
  strat->fichier = NULL;
  free(strat->fichier);
  free(strat);
}

void freeTableauStrat(Strategie **tab, int nbElemt){
  int i;
  for (i=0; i<nbElemt;i++){
    freeStrat(tab[i]);
  }
  free(tab);
}

