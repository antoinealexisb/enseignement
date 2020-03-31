#include <stdio.h>
#include <string.h>
#define TAILLES 9

void insertion (int *tab, int *insert, int taille){
  int i, verif, tentative;
  for (i = 0; i < taille; i++){
    verif = 1;
    tentative = 0;
    while(verif){
      cle = i%taille;
      cle = (cle+tentative)%taille;
      if (tab[cle] == NULL){
        tab[cle] = insert[i];
        verif = 0;
      }
      else{
        tentative++;
      }
    }
  }
}

void recherche (int tab*, int cle, int taille){
  int i;
  for (i = 0; i < taille; i++){
    if (tab[i] = cle){
      return i;
    }
  }
  return -1;
}
