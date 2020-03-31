#include <stdio.h>
#include <stdlib.h>

void rendre_monnaie (int* tab_piece, int t, int rendu){
  if (rendu > 0 && t-1 >= 0){
    int nb_piece = rendu/tab_piece[t-1];
    printf("%d pièces de %d cents rendues \n", nb_piece, tab_piece[t-1]);
    rendre_monnaie(tab_piece, t-1, rendu-(nb_piece*tab_piece[t-1]));
  }
}

int main(void){
  int piece[] = {1,2,5,10,20,50,100,200};
  rendre_monnaie(piece, 8, 263);
  return 0;
}
