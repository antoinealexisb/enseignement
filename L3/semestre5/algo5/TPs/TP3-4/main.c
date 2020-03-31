#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h> 


#define Islowercase(a)   ((a >= 'a' && a <= 'z') ? (1) : (0))
#define IsUppercase(a)   ((a >= 'A' && a <= 'Z') ? (1) : (0))
#define IsChar(a) (((Islowercase(a)) || (IsUppercase(a))) ? (1) : (0))
#define Tolowercase(a)   ((a >= 'A' && a <= 'Z' ) ? (a  - 'A' + 'a') : (a))
#define ToUppercase(a)   ((a >= 'a' && a <= 'z' ) ? (a  + 'A' -'a') : (a))
#define TAILLEHASH 25
#define TAILLECORPUS 3

typedef struct documents {
    int nbmot;
    char nom[250];
}Document;

typedef struct chaine Chaine;
struct chaine{
  int nbOcc;
  char mot[25];
  Chaine *suivant;
};

typedef struct{
  Chaine *tete;
} listeChainee;

typedef struct tabHash{
  listeChainee *tablehash[TAILLEHASH];
  Document *tab_doc[250];
}TabHash;


Chaine *CreeMotChaine(char *s){
  Chaine *tmp;
  tmp = malloc(sizeof(Chaine));
  strcpy(tmp->mot, s);
  tmp->nbOcc = 1;
  return tmp;
}

void ajoutOcc(Chaine *maillon){
  maillon->nbOcc +=1;
}

void ajoutListeChainee(listeChainee *liste, char *s, int doc){
  if (liste->tete == NULL){
    liste->tete = CreeMotChaine(s);
  }
  else{
    Chaine *tete = liste->tete;
    Chaine *prec = NULL;
    while (tete!=NULL){
      if (!strcmp(s,tete->mot)){
        ajoutOcc(tete);
        return;
      }
      else if(strcmp(s,tete->mot)<=-1){
        Chaine *tmp = CreeMotChaine(s);
        tmp->suivant = tete;
        if (prec == NULL){
          liste->tete = tmp;
        }
        else{
          prec->suivant = tmp;
        }
        return;
      }
      prec = tete;
      tete = tete->suivant;
    }
    prec->suivant = CreeMotChaine(s);
  }
}

void printListeChainee(listeChainee *liste){
  if (liste != NULL){
    Chaine *tete = liste->tete;
    while(tete!=NULL){
      printf("Mot : %s , NbOcc %d \n", tete->mot, tete->nbOcc);
      tete = tete->suivant;
    }
    
  }
  else{
    printf("Ya rien !!!!\n");
  }
}


int hashSomme(char *mot){
    int somme=0;
    while(*mot !='\0'){
        somme+= (*mot);
        mot++;
    }
    return somme;
}

int hash(char *mot){
    return hashSomme(mot)%TAILLEHASH;
}

void ajoutHashMot(TabHash *h,char *mot, int doc){
    int clef = hash(mot);
    if (h->tablehash[clef] == NULL){
        h->tablehash[clef] = calloc(1,sizeof(listeChainee));
    }
    ajoutListeChainee(h->tablehash[clef],mot, doc);
}


void printDocument(Document *d){
    if (d != NULL){
        printf("Nom :%s | Nombre de mot : %d", d->nom , d->nbmot);
    }
}


FILE *ouvrirFichier(char *s){
  FILE *fichier;
  fichier = fopen(s, "r");
  return fichier;
}

void printFichier(FILE *f){
  char c=fgetc(f);
  if (c==EOF)
    return;
  else if(IsChar(c))
    printf("%c",c);
  else
    printf("\n");
  printFichier(f);
}


void testListeChaineeFichier(FILE *f, listeChainee *liste){
  char mot[25];
  int i=0;
  char c = fgetc(f);
  while (c !=EOF){
    if (IsChar(c))
      mot[i++] = ToUppercase(c);
    else{
      mot[i] = '\0';
      ajoutListeChainee(liste, mot,0);
      i=0;
    }
    c = fgetc(f);
  }
}

void testHashFile(FILE *f, TabHash *h, int doc){
  char mot[25];
  int i =0;
  char c = fgetc(f);
  while (c != EOF){
    if (IsChar(c))
      mot[i++] = ToUppercase(c);
    else{
      //nope pour le comptage
      (h->tab_doc[doc]->nbmot)++;
      mot[i]='\0';
      ajoutHashMot(h, mot, doc);
      i=0;
    }
    c=fgetc(f);
  }
}

void hashCorpus(TabHash * th){
  FILE * f;
  struct dirent *lecture;
  DIR *rep;
  rep = opendir("./dossierCorpus" );
  char * dirname ="./dossierCorpus/";
  char nomfichier[250]="";
  int i =0;  
  printf("-----------------------Ajout des different fichier dans la table de hash-----------------------\n");
  while ((lecture = readdir(rep))) {
    if (strcmp(lecture->d_name,".")!=0 && strcmp(lecture->d_name,"..")!=0 ){
      strcpy(nomfichier,dirname);
      strcat(nomfichier,lecture->d_name);
      printf("Ajout de %s dans la table de Hash\n",nomfichier);
      f = ouvrirFichier(nomfichier);
      th->tab_doc[i]=calloc(1,sizeof(Document));
      //th->tab_doc[i]->nbmot=0;
      //th->tab_doc[i]->nom = (char *)malloc(sizeof(char)*250);
      //printf("Erreur ?\n");
      strcpy(th->tab_doc[i]->nom ,lecture->d_name);
      testHashFile(f,th,i);
      i++;
      fclose(f);
    }
  }
    closedir(rep);
    printf("-----------------------------------------------------------------------------------------------\n");
}

void affichage_stats_document_hash(TabHash * th){    
    printf("-----------------------------------------------------------------------------------------------\n");
        
    printf("MetaDonnee du Corpus de document\n");
    for (int i =0; i < TAILLECORPUS ; i ++){
        printDocument(th->tab_doc[i]);
        printf("\n");

    }
    printf("-----------------------------------------------------------------------------------------------\n");

}

int main(void){
  //listeChainee *liste = malloc(sizeof(listeChainee));
  //FILE *truc = ouvrirFichier("texte1.txt");
  //printFichier(truc);
  //testListeChaineeFichier(truc, liste);
  //printListeChainee(liste);
  TabHash *th = calloc(1,sizeof(TabHash));
  hashCorpus(th);
  affichage_stats_document_hash(th);
  return(0);
}

