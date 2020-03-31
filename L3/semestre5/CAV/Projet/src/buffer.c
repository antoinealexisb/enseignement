/* Fichier buffer.c */
#include "buffer.h"

void moveBuffer(Buffer *tab){
  int i=9;
  while ((tab->tab[i] != NULL) && (i!=0)) i--;
  if (i==0) free(tab->tab[0]);
  while (i!=9){
    tab->tab[i] = tab->tab[i+1];
    i++;
  }
}

void freeBuffer(Buffer *tab){
  int i=0;
    while((i<10)){
      free(tab->tab[i]);
      i++;
    }
  free(tab);
}

void addBuffer(Buffer *tab, char *str){
  moveBuffer(tab);
  tab->tab[9] = malloc(sizeof(char)* strlen(str)+1);
  strcpy(tab->tab[9], str);
}

void printBuffer(Buffer *tab){
  int i=0;
  while (i<10){
    if (tab->tab[i] != NULL)
      printf("%s",tab->tab[i]);
    i++;
  } 
}

