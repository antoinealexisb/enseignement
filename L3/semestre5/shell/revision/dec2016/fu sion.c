#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void fusion(int *tab, int taille, int milieu);
void tri_fusion(int *tab, int taille);

void tri_fusion(int *tab, int taille){
  //printf("coucou \n");
  //printf("yolo : %d\n", tab[0]);
  //int taille = sizeof(tab)/sizeof(*tab);
  if (taille<=1){
    printf("%d\n",tab[0]);
    return;}
  int milieu = taille/2;
  tri_fusion(tab, milieu);
  tri_fusion(&tab[milieu],taille-milieu);
  fusion(tab, taille, milieu);
  /*void gauche = tri_fusion(tab, milieu);
  void droite = tri_fusion(tab, milieu)


  return(tab);*/
}

void fusion(int *tab, int taille, int milieu){
  int *tab2 = malloc(taille*sizeof(*tab));
  int Do, Re, Mi;//vive le C89 :-)
  for (Do=0, Re=milieu, Mi=0; Mi<taille; Mi++){
    if (Re == taille){
      tab2[Mi] = tab[Do];
      Do++;
    }
    else if(Do==milieu){
      tab2[Mi] = tab[Re];
      Re++;
    }
    else if(tab[Re]<tab[Do]){
      tab2[Mi] = tab[Re];
      Re++;
    }
    else{
      tab2[Mi] = tab[Do];
      Do++;
    }
  }
  for (Do = 0; Do<taille; Do++)
    tab[Do] = tab2[Do];
  free(tab2);

}

/*void tri_rapide(int *tab, int taille){
  int mur, courant, pivot, tmp;
  //printf("taille : %d\n",taille);
  if (taille<=1)
    return;
  pivot = tab[0], mur = 0, courant = 0;
  while(courant<taille){
    if(tab[courant]<= pivot){
      if(mur != courant){
        tmp = tab[courant];
        tab[courant] = tab[mur];
        tab[mur] = tmp;
      }
      mur++;
    }
    courant++;
  }
  //printf("mur : %d, taille : %d, mur-1: %d\n", mur, taille, mur-1);
  tri_rapide(tab, mur-1);
  //printf("%d\n",mur);
  printf("mur : %d, taille : %d, mur-1: %d, taille-mur+1: %d\n", mur, taille, mur-1,taille-mur+1);
  tri_rapide(tab+mur-1, taille-(mur+1));
  printf("coucou3\n");
}*/

void tri_rapide(int *tab, int deb, int fin){
  int pivot = tab[deb];
  int pos=deb;
  int i;
  if (deb>=fin)
    return;
  for (i=deb; i<fin; i++){
    if (tab[i]<pivot){
      tab[pos]=tab[i];
      pos++;
      tab[i]=tab[pos];
      tab[pos]=pivot;
    }
  }
  tri_rapide(tab,deb,pos);
  tri_rapide(tab,pos+1,fin);
}

int main(void){
  int tab[]={12,1,99,52,10,2,6,123,5,3};
  int tab2[]={3,6,9,10,11,12,15,17,18,20,1,2,4,5,7,8,13,14,16,19};
  int taille = sizeof(tab2)/sizeof(*tab2);
  //printf("%d\n",taille);
  //tri_fusion(tab,taille);
  //tri_fusion(tab2, taille);
  tri_rapide(tab2,0, taille);
  for (int i=0; i<taille; i++)
    printf("%d, ",tab2[i]);
  printf("\n");
  return(0);
}
