/* Fichier traitement.c */

#include "traitement.h"

void vies(Equipe *attaquant, Equipe *defenseur, char *s, int *vie, int *pvMax){
  if (!strcmp(s,"life")){
    *vie = (attaquant->champion) -> pv;
    *pvMax = (attaquant->champion) -> pv_max;
  }
  else{
    *vie = (defenseur->champion)->pv;
    *pvMax = (defenseur->champion)->pv_max;
  }

}

int enemyInScope(Equipe *attaquant, Equipe *defenseur){
/** return 1 si ennemi à porté sinon 0*/
  int distance = distance((attaquant->pos - defenseur->pos));
  int portee = (attaquant->weapon)->portee;
  return (distance <= portee);
}

void inStdin(char *s){
  int i;
  if (s[strlen(s)-1] == ' ')
    s[strlen(s)-1]='\0';
  ungetc('\n', stdin);
  for (i=strlen(s)-1; i>=0; i--){
    ungetc(s[i], stdin);
  }
}

void lireFichier(Strategie *strat, Equipe *attaquant, Equipe *defenseur){/**mettre les equipes, la simplification ça serait bien ... mais là j'ai pas le courage */
  char buf[50]="";
  char buf2[50]="";
  char retour[50]="";
  int nbIf=0;
  int vie=0;
  int vie2=0;
  int pvMax=0;
  int rien=0; /*cette variable ne sert à rien mais permet de recuperer le retour de fscanf(c'est pour valgrind) */
    while (feof(strat->fichier)==0 && fscanf(strat->fichier, "%s", buf)!=0){
        if (!strcmp(buf, "end")){
          break;
        }
        else if (!strcmp(buf,"use") || !strcmp(buf,"move")){
          if (strlen(retour)==0){/** si retour==0 alors on prepare la commande */
            strcat(retour,buf);
            strcat(retour," ");
          }
          else{
            fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
            inStdin(retour);
            return;
          }

        }
        else if (!strcmp(buf, "endif")){
          if (strlen(retour)==0){
            continue;
          }
          else{
            inStdin(retour);
            return;
          }
        }
        else if (!strcmp(buf, "else")){
          while(strcmp(buf,"endif")){
                  rien=fscanf(strat->fichier, "%s", buf);
          }
          if (strlen(retour)==0){
            continue;
          }
          else{
            inStdin(retour);
            return;
          }
        }
    	else if (!strcmp(buf, "if")){
          nbIf=1;
          rien=fscanf(strat->fichier, "%s", buf);
          if (!strcmp(buf, "life") || !strcmp(buf, "enemyLife")){
            vies(attaquant,defenseur,buf,&vie,&pvMax);
            rien=fscanf(strat->fichier, "%s", buf);
            rien=fscanf(strat->fichier, "%s", buf2);
            vie2= atoi(buf2);
            if (!strcmp(buf, "<")){
              rien=fscanf(strat->fichier, "%s", buf);
              if (!strcmp(buf, "%") || (buf2[strlen(buf2)-1]=='%')){
                vie2=(pvMax*vie2)/100; /*pvmax du champion */
		if (strcmp(buf, "%")) fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
              }
              else{
                fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
                /** on recule pour analyser le futur mot plus tard*/
              }
              if (vie<vie2){
               nbIf--;
               continue;
              }
              else{
                while(nbIf!=0){
                  rien=fscanf(strat->fichier, "%s", buf);
                  if (!strcmp(buf, "if"))
                    nbIf++;
                  else if(!strcmp(buf, "else")){
                    if (nbIf-1==0){
                      continue;
                    }
                  }
                  else if (!strcmp(buf, "endif"))
                    nbIf--;
                }
              }
            }
            else if (!strcmp(buf, "<=")){
              rien=fscanf(strat->fichier, "%s", buf);
              if (!strcmp(buf, "%") || (buf2[strlen(buf2)-1]=='%')){
                vie2=(pvMax*vie2)/100; /*pvmax du champion */
		if (strcmp(buf, "%")) fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
              }
              else{
                fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
                /** on recule pour analyser le futur mot plus tard*/
              }
              if (vie<=vie2){
               nbIf--;
               continue;
              }
              else{
                while(nbIf!=0){
                  rien=fscanf(strat->fichier, "%s", buf);
                  if (!strcmp(buf, "if"))
                    nbIf++;
                  else if(!strcmp(buf, "else")){
                    if (nbIf-1==0){
                      continue;
                    }
                  }
                  else if (!strcmp(buf, "endif"))
                    nbIf--;
                }
              }
            }
            else if (!strcmp(buf, "=")){
              rien=fscanf(strat->fichier, "%s", buf);
              if (!strcmp(buf, "%") || (buf2[strlen(buf2)-1]=='%')){
                vie2=(pvMax*vie2)/100; /*pvmax du champion */
		if (strcmp(buf, "%")) fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
              }
              else{
                fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
                /** on recule pour analyser le futur mot plus tard*/
              }
              if (vie==vie2){
               nbIf--;
               continue;
              }
              else{
                while(nbIf!=0){
                  rien=fscanf(strat->fichier, "%s", buf);
                  if (!strcmp(buf, "if"))
                    nbIf++;
                  else if(!strcmp(buf, "else")){
                    if (nbIf-1==0){
                      continue;
                    }
                  }
                  else if (!strcmp(buf, "endif"))
                    nbIf--;
                }
              }
            }
            else if (!strcmp(buf, "!=")){
              rien=fscanf(strat->fichier, "%s", buf);
              if (!strcmp(buf, "%") || (buf2[strlen(buf2)-1]=='%')){
                vie2=(pvMax*vie2)/100; /*pvmax du champion */
		if (strcmp(buf, "%")) fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
              }
              else{
                fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
                /** on recule pour analyser le futur mot plus tard*/
              }
              if (vie!=vie2){
               nbIf--;
               continue;
              }
              else{
                while(nbIf!=0){
                  rien=fscanf(strat->fichier, "%s", buf);
                  if (!strcmp(buf, "if"))
                    nbIf++;
                  else if(!strcmp(buf, "else")){
                    if (nbIf-1==0){
                      continue;
                    }
                  }
                  else if (!strcmp(buf, "endif"))
                    nbIf--;
                }
              }
            }
            else if (!strcmp(buf, ">=")){
              rien=fscanf(strat->fichier, "%s", buf);
              if (!strcmp(buf, "%") || (buf2[strlen(buf2)-1]=='%')){
                vie2=(pvMax*vie2)/100; /*pvmax du champion */
		if (strcmp(buf, "%")) fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
              }
              else{
                fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
                /** on recule pour analyser le futur mot plus tard*/
              }
              if (vie>=vie2){
               nbIf--;
               continue;
              }
              else{
                while(nbIf!=0){
                  rien=fscanf(strat->fichier, "%s", buf);
                  if (!strcmp(buf, "if"))
                    nbIf++;
                  else if(!strcmp(buf, "else")){
                    if (nbIf-1==0){
                      continue;
                    }
                  }
                  else if (!strcmp(buf, "endif"))
                    nbIf--;
                }
              }
            }
            else{/*>*/
              rien=fscanf(strat->fichier, "%s", buf);
              if (!strcmp(buf, "%") || (buf2[strlen(buf2)-1]=='%')){
                vie2=(pvMax*vie2)/100; /*pvmax du champion */
		if (strcmp(buf, "%")) fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
              }
              else{
                fseek(strat->fichier, ftell(strat->fichier)-strlen(buf), SEEK_SET);
                /** on recule pour analyser le futur mot plus tard*/
              }
              if (vie>vie2){
               nbIf--;
               continue;
              }
              else{
                while(nbIf!=0){
                  rien=fscanf(strat->fichier, "%s", buf);
                  if (!strcmp(buf, "if"))
                    nbIf++;
                  else if(!strcmp(buf, "else")){
                    if (nbIf-1==0){
                      continue;
                    }
                  }
                  else if (!strcmp(buf, "endif"))
                    nbIf--;
                }
              }
            }
            
          }
          else{
            /**enemyInScope*/
            /**détermine si la position actuelle de l’ennemi fait que celui-ci est à 
            portée de l’arme choisie*/
            nbIf=1;
            if (enemyInScope(attaquant, defenseur)){
              continue;
            }
            else{
              while(nbIf!=0){
                rien=fscanf(strat->fichier, "%s", buf);
                if (!strcmp(buf, "if"))
                  nbIf++;
                else if(!strcmp(buf, "else")){
                  if (nbIf-1==0){
                    break;
                  }
                }
                else if (!strcmp(buf, "endif"))
                  nbIf--;
              }
            }
          }
        }
        else{
          strcat(retour,buf);
          strcat(retour," ");          
        }
  }
  inStdin("end");
  rien++; /* ne sert à rien ;) */
}

void traitement(Equipe *attaquant, Equipe *defenseur, int inverseur){
  char commande[20];
  char volumes = 0;
  unsigned char n;
  int codeRetour=-7;
  char buf[100];

  if (attaquant->strat != NULL){
    fseek((attaquant->strat)->fichier, (attaquant->strat)->script, SEEK_SET);
  }

  while(1){
    printTerrain(attaquant, defenseur);
    printf("\n %s (%d) > ",attaquant->champion->nom, attaquant->CA);
    if (attaquant->strat != NULL){
      lireFichier(attaquant->strat, attaquant, defenseur);

    }
    scanf("%19[^\n]", commande);
    sprintf(buf, "\n %s (%d) > %s\n", attaquant->champion->nom, attaquant->CA, commande);
    /*RISQUE DE DEPPASSEMENT TAMPON CAR PAS C99 si C99 utiliser cela: (reglé ;) )
     *snprintf(buf,100, "\n %s (%d) > %s\n", attaquant->champion->nom, attaquant->CA, commande);*/
    addBuffer(attaquant->commande, buf);
    viderBuffer();
    if (!strcmp(commande, "show")){
      ajouterEquipeBuffer(attaquant);
      codeRetour = 0;
    }
    else if (strstr(commande, "move forward")){
      n = (strlen(commande) == 12) ? 1 : atoi(commande+13);
      codeRetour = forward(attaquant, defenseur, n);
      if (codeRetour > 0){
        sprintf(buf, "Vous avancez de %d pas !\n", codeRetour);
        addBuffer(attaquant->commande, buf);
      }
    }
    else if (strstr(commande, "move backward")){ 
      n = (strlen(commande) == 13) ? 1 : atoi(commande+14);
      codeRetour = backward(attaquant, defenseur, n);
      if (codeRetour > 0){
        sprintf(buf, "Vous avez reculez de %d pas !\n", codeRetour);
        addBuffer(attaquant->commande, buf);
      }
    }
    else if (strstr(commande, "use weapon")){
      n = (strlen(commande) == 10) ? 1 : atoi(commande+11);
      codeRetour = infligeDegats(attaquant, defenseur, n);
      if (codeRetour >= 0){
        sprintf(buf, "Votre adversaire perd %d points de vie. \n", codeRetour);
        addBuffer(attaquant->commande, buf);
      } 
    }
    else if (strstr(commande, "use care")){
      n = (strlen(commande) == 8) ? 1 : atoi(commande+9);
      codeRetour = laCroixRouge(attaquant, &volumes, n);
      if (codeRetour >0){
        sprintf(buf, "Vous avez regagné %d points de vie dans la limite de vos points de vie.\n", codeRetour);
        addBuffer(attaquant->commande, buf);
      }
    }
    else if (!strcmp(commande, "use protection")){
      if((attaquant->activeProtection == 0) && (attaquant->CA >= attaquant->protection->CA ) ){
        attaquant->CA -= attaquant->protection->CA;
        attaquant->activeProtection = 1;
        codeRetour = -8 ;
        (inverseur == 1) ? (printLegumeProtection()) : (printProtectionFruit()) ; 
      }
      else if (attaquant->activeProtection==1)
        codeRetour = -5;
      else if(attaquant->CA >= attaquant->protection->CA)
        codeRetour = -10;
      else
        codeRetour = -6;
    }
    if (!strcmp(commande, "end") || attaquant->CA <= 0 || defenseur->champion->pv <= 0){
      if ((attaquant->strat != NULL)||(attaquant->CA<=0)){
        waitFor(3);
      }
      if (defenseur->activeProtection == 1)
        defenseur->activeProtection =2;
      return;
    }
    else if(codeRetour<0)
      erreur(attaquant,codeRetour);
   printBuffer(attaquant->commande);
   codeRetour=-7;
  }
}

void erreur(Equipe *equipe, int codeRetour){
  if (codeRetour == -1)
    addBuffer(equipe->commande, "Erreur : Il n'est pas permis de dépasser son adversaire !\n");
  else if (codeRetour == -2)
    addBuffer(equipe->commande, "Erreur : Limite de terrain !\n");
  else if (codeRetour == -3)
    addBuffer(equipe->commande, "Erreur : Nombre maximal de soins par tour déjà atteint !\n");
  else if (codeRetour == -4)
    addBuffer(equipe->commande, "Erreur : Volume de soin plus élevé que le maximum autorisé !\n");
  else if (codeRetour == -5)
    addBuffer(equipe->commande, "Erreur : Protection déjà revêtue !\n");
  else if (codeRetour == -6)
    addBuffer(equipe->commande, "Erreur : Armure déjà utilisée pendant le duel!\n");
  else if (codeRetour == -7)
    addBuffer(equipe->commande, "Erreur : Commande non reconnue !\n");
  else if (codeRetour == -8)
    addBuffer(equipe->commande,"Armure vêtue\n");
  else if (codeRetour == -10)
    addBuffer(equipe->commande, "Erreur : Pas assez de CA !\n");
}

void printTerrain(Equipe *equipe, Equipe *equipe2){
  int max;
  int i;
  system("clear");
  afficherEtatAdversaire(equipe2);
  max = (equipe->posLimite < equipe2->posLimite) ? (equipe2->posLimite) : (equipe->posLimite);
  for (i=0; i<=max; i++){
    if ((i==equipe->pos) || (i==equipe2->pos))
      printf("%c",(equipe->pos < equipe2->pos) ? ((i==equipe2->pos) ? 'F' : 'L') : ((i==equipe->pos) ? 'F' : 'L'));
    else
      printf(" ");
  }
  printf("\n");
  printf("%0*d", ++max,0);
  printf("\n");
  printf("Distance : %d \n\n",distance((equipe->pos - equipe2->pos)));
  printBuffer(equipe->commande);
}

void ajouterEquipeBuffer(Equipe *equipe){
    char tmp[100];
    Champion *champion = equipe->champion;
    Weapon *weapon = equipe->weapon;
    Protection *protection = equipe->protection;
    Care *soin = equipe->soin; 
    sprintf(tmp, "%s | Nom:%s | Force:%d | Resistance:%d | Pv:%d/%d | Cout:%d \n",equipe->champion->type,champion->nom,champion->force,champion->resistance,champion->pv,champion->pv_max,champion->CE);
    addBuffer(equipe->commande, tmp);
    sprintf(tmp, "Nom:%s | CE:%d | CA:%d | Dégats:%d-%d | Portée:%d\n", weapon->nom, weapon->CE, weapon->CA, weapon->minDegat, weapon->maxDegat, weapon->portee);
    addBuffer(equipe->commande, tmp);
    sprintf(tmp, "Nom:%s | CE:%d | CA:%d | Probalité:%d%%\n", protection->nom, protection->CE, protection->CA, protection->proba);
    addBuffer(equipe->commande, tmp);
    sprintf(tmp, "Nom:%s | CE:%d | CA:%d | Volumes:%d | Effet:%d-%d\n", soin->nom, soin->CE, soin->CA, soin->volumes, soin->minEffet, soin->maxEffet);
    addBuffer(equipe->commande, tmp);
}

int infligeDegats(Equipe *attaquant, Equipe *defenseur, unsigned char n){
  int animation = 1;
  int nbDegatArme;
  int nbDegats;
  int nbAlea;
  int degatTotal =0;
  int estFruit = !strcmp(attaquant->champion->type, "fruit ");
  int distance = distance((defenseur->pos - attaquant->pos));

  if (attaquant->CA >= attaquant->weapon->CA*n)
  {
    attaquant->CA -= attaquant->weapon->CA*n;
    while(n>0){
      nbDegatArme = rand()%((attaquant->weapon->maxDegat)+1-(attaquant->weapon->minDegat)) + attaquant->weapon->minDegat;
      nbDegats = ((float)nbDegatArme*((100+(float)attaquant->champion->force)/100)) * ((100-(float)defenseur->champion->resistance)/100)+0.5;			  
      if (attaquant->weapon->portee >= distance){
        if (defenseur->activeProtection == 1){
	  nbAlea = (rand()%100)+1;
	  if (nbAlea > defenseur->protection->proba){
	    defenseur->champion->pv -= nbDegats;
	    degatTotal += nbDegats;
            if ((estFruit) && (animation))
              printTireFruitProtectionPass();
            else if(animation)
              printTireLegumeProtectionPass();
	  }
          else{
            if ((estFruit) && (animation))
              printTireFruitProtection();
            else if(animation)
              printTireLegumeProtection();

            animation = 0;
          }
	}
	else{
	  defenseur->champion->pv -= nbDegats;
	  degatTotal += nbDegats;
          if ((estFruit)&&(animation)){
            printTireFruitOK();
          }
          else if(animation)
            printTireLegumeOK();
          animation=0;
	}
      }
      else{
        if ((estFruit)&&(animation))
          printTireFruitDistance();
        else if(animation)
          printTireLegumeDistance();
        animation = 0;
      }
      n--;
    }
    return degatTotal;
  }
  return -10;	
}

int forward(Equipe *attaquant, Equipe *defenseur, unsigned char n){
  int distance = distance((attaquant->pos - defenseur->pos));
  if (n <= attaquant->CA){
    distance -= n;
    if (distance < 0)
      return -1;
    attaquant->CA -= n;
    (defenseur->pos > attaquant->pos) ? ((attaquant->pos += n),printLegumeAvance()) : ((attaquant->pos -= n), (printFruitAvance()));
    return n;
  }
  return -10;
}

int backward(Equipe *attaquant, Equipe *defenseur, unsigned char n){
  if (n*2 <= attaquant->CA){
    if (defenseur->pos > attaquant->pos){
      if (attaquant->pos-n < attaquant->posLimite){
        return -2;
      }
      printLegumeRecule();
      attaquant->pos-=n;
    }
    else{
      if (attaquant->pos+n > attaquant->posLimite)
        return -2;
      printFruitRecule();
      attaquant->pos+=n;
    }
    attaquant->CA -= 2*n;
    return n;
  }
  return -10;
}

int laCroixRouge(Equipe *patient, char *volumes, unsigned char n){
  if((patient->CA >= patient->soin->CA*n) && (patient->soin->volumes > *volumes) && (n<=patient->soin->volumes)){
    int soinTotal = 0;
    int nbSoin;
    while ((patient->soin->volumes > *volumes) && n>0 ){
      nbSoin = rand()%((patient->soin->maxEffet)+1-(patient->soin->minEffet)) + patient->soin->minEffet;
      patient->champion->pv += nbSoin;
      soinTotal+=nbSoin;
      patient->CA-=patient->soin->CA;
      if (patient->champion->pv > patient->champion->pv_max)
          patient->champion->pv = patient->champion->pv_max;
      n--;
      *volumes+=1;
    }
    !strcmp(patient->champion->type, "fruit ") ? printFruitSoin(): printLegumeSoin(); 
    return soinTotal;
  }
  return (patient->CA < patient->soin->CA*n) ? (-10) : (n > patient->soin->volumes) ? (-4) : (-3);
}

