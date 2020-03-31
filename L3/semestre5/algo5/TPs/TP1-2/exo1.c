/**
 *BOURDON Antoine-Alexis 
 * Année : L3 - 2019-2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBTRIS 6
#define NBGENLISTES 5
/**
 *  Structure permettant de savoir:
 *  - Le nombre de permutations
 *  - Le nombre de comparaisons
 *  - Le nombre de permutations + comparaisons
 * */
struct _test{
  int **perm;
  int **comp;
  int **totalOp;
};
typedef struct _test test;

int *gen_liste(int taille, int max);
int *genListeTrie(int taille);
int *genListePresTrie(int taille);
int *genListeInverse(int taille);
int *genListeDoublons(int taille);
void aff_liste(int *li, int taille);
int est_trie(int *li, int taille);

void tri_insertion(int *li, int taille, int *comp, int *perm);
void tri_selection(int *li, int taille, int *comp, int *perm);
void tri_bulle(int *li, int taille, int *comp, int *perm);
void fusion(int *tab, int taille, int milieu, int *comp, int *perm);
void tri_fusion(int *tab, int taille, int *comp, int *perm);
void tri_rapide(int *tab, int deb, int fin, int *comp, int *perm);
void tri_tas(int tab[], int size, int *comp, int *perm);
void entasser(int tab[], int ind, int size, int *comp, int *perm);
void swap(int tab[], int ind, int ind2, int *comp, int *perm);
int fd(int tab[], int ind, int size);
int fg(int tab[], int ind, int size);

int **gen_mat(int m);
void gen_test(test *t, int nb_li);
test banc_test(int t_mini, int nbli, int nb_expres, int nbGenList, int valeurMax);
void copyTab(int *tab1, int *tab2, int taille);
void ecriture(test t, int nbTri, int ind, int *perm, int *comp);
void moyenneTris(test t, int nb_expres, int ind);
void affMat(int **mat, int nb_listes, int t_mini, char car);
void saveMat(int **mat, int nb_listes, int t_mini, char car, FILE *fichier);

void afficher(test t, int nb_listes, int t_mini);
void afficherComp(test t, int nb_listes, int t_mini);
void afficherPerm(test t, int nb_listes, int t_mini);
void afficherTotal(test t, int nb_listes, int t_mini);
void generationGnu(char *nom, char *descrip);

/**
 *  Fonction qui génére une matrice pour la structure
 *    - int m : correspond au nombre de listes à faire [variable nb_liste choisit par l'utilisateur]
 * */
int **gen_mat(int m){
  int **res = malloc(sizeof(int*)*NBTRIS);
  for (int i=0; i<NBTRIS; i++){
    res[i] = calloc(m,sizeof(int));
  }
  return res;
}


/**
 * creation matrice pour les permutations, comparaisons, et permutations+comparaisons 
 * */
void gen_test(test *t, int nb_li){
  t->perm = gen_mat(nb_li);
  t->comp = gen_mat(nb_li);
  t->totalOp = gen_mat(nb_li);
}

  

/*void aff_mat(int **mat, int n, int m){
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      printf(" %d",mat[i][j]);
    }
      printf("\n");
  }
}


//Fonction d'affichage pour deboguage.
void aff_test(test t, int n, int m){
  printf("permutations : \n");
  aff_mat(t.perm,n,m);
  printf("---------------\n");
  printf("comparaisons : \n");
  aff_mat(t.comp,n,m);
  printf("---------------\n");
  printf("Toutes les opérations : \n");
  aff_mat(t.totalOp,n,m);
}*/

//AFFICHAGE && ENREGISTREMENT
/**
 *  Fonction qui appels les fonctions d'affichage et d'enregistrement des fichiers .dat et .csv
 * */
void afficher(test t, int nb_listes, int t_mini){
  afficherComp(t, nb_listes, t_mini);
  afficherPerm(t, nb_listes, t_mini);
  afficherTotal(t, nb_listes, t_mini);
}

/**
 *  Fonction qui affiche les comparaisons et enregistre les fichiers .dat et csv
 */
void afficherComp(test t, int nb_listes, int t_mini){
  //sortie standard :
  printf("Comparaisons :\n");
  printf("Taille\tInsert.\tSelect.\tBulle\tFusion\tRapide\tTas\n");
  affMat(t.comp, nb_listes, t_mini, '\t');

  //sortie cvs
  FILE *fichier = fopen("comp.csv","w+"); //lecture et ecriture. Supprime l'ancien contenu.
  fprintf(fichier,"Taille,Insertion,Selection,Bulle,Fusion,Rapide,Tas\n");
  saveMat(t.comp, nb_listes, t_mini, ',', fichier);
  fclose(fichier);

  //sortie plot
  fichier = fopen("comp.dat","w+");
  fprintf(fichier,"# Taille de la liste - Nombre de comparaison pour chaque tri\n");
  saveMat(t.comp, nb_listes, t_mini, '\t', fichier);
  fclose(fichier);
  generationGnu("comp","Comparaisons"); 
  
}

/**
 *  Fonction qui affiche les permutations et enregistre les fichiers .dat et .csv
 */
void afficherPerm(test t, int nb_listes, int t_mini){
  //sortie standard :
  printf("Permutations :\n");
  printf("Taille\tInsert.\tSelect.\tBulle\tFusion\tRapide\tTas\n");
  affMat(t.perm, nb_listes, t_mini, '\t');

  //sortie cvs
  FILE *fichier = fopen("perm.csv","w+"); //lecture et ecriture. Supprime l'ancien contenu.
  fprintf(fichier,"Taille,Insertion,Selection,Bulle,Fusion,Rapide,Tas\n");
  saveMat(t.perm, nb_listes, t_mini, ',', fichier);
  fclose(fichier);

  //sortie plot
  fichier = fopen("perm.dat","w+");
  fprintf(fichier,"# Taille de la liste - Nombre de permutations pour chaque tri\n");
  saveMat(t.perm, nb_listes, t_mini, '\t', fichier);
  fclose(fichier);
  generationGnu("perm","Permutations"); 
}

/**
 *  Fonction qui affiche le nombre d'opérations et enregistre les fichiers .dat et .csv
 */
void afficherTotal(test t, int nb_listes, int t_mini){
  //sortie standard :
  printf("Nombre d'opérations :\n");
  printf("Taille\tInsert.\tSelect.\tBulle\tFusion\tRapide\tTas\n");
  affMat(t.totalOp, nb_listes, t_mini, '\t');

  //sortie cvs
  FILE *fichier = fopen("total.csv","w+"); //lecture et ecriture. Supprime l'ancien contenu.
  fprintf(fichier,"Taille,Insertion,Selection,Bulle,Fusion,Rapide,Tas\n");
  saveMat(t.totalOp, nb_listes, t_mini, ',', fichier);
  fclose(fichier);

  //sortie plot
  fichier = fopen("total.dat","w+");
  fprintf(fichier,"# Taille de la liste - Nombre d'opérations pour chaque tri\n");
  saveMat(t.totalOp, nb_listes, t_mini, '\t', fichier);
  fclose(fichier);
  generationGnu("total","Opérations");
}  


/**
 *  Fonction qui genere les fichiers en .gnu
 */
void generationGnu(char *nom, char *descrip){
  char *temp = (char *)(malloc(strlen(nom)));
  strcpy(temp, nom);
  strcat(temp, ".gnu");
  FILE *fichier = fopen(temp,"w+");
  fprintf(fichier,"set title ' %s.dat des algorithmes de tris'\n",descrip);
  fprintf(fichier,"set xlabel 'Taille de la liste'\n");
  fprintf(fichier,"set ylabel 'Nombre de comparaisons'\n");
  fprintf(fichier,"plot '%s.dat' using 1:2 title 'Tri par insertion' with linespoints\n",nom);
  fprintf(fichier,"replot '%s.dat' using 1:3 title 'Tri par sélection du minimum' with linespoints\n",nom);
  fprintf(fichier,"replot '%s.dat' using 1:4 title 'Tri à bulles' with linespoints\n",nom);
  fprintf(fichier,"replot '%s.dat' using 1:5 title 'Tri fusion' with linespoints\n",nom);
  fprintf(fichier,"replot '%s.dat' using 1:6 title 'Tri rapide' with linespoints\n",nom);
  fprintf(fichier,"replot '%s.dat' using 1:7 title 'Tri par tas' with linespoints\n",nom);
  fprintf(fichier,"pause -1\n");
  fclose(fichier);

}

/*void afficherCompCSV(test t, int nb_listes, int t_mini){
  printf("Taille,Insertion,Selection,Bulle,Fusion,Rapide\n");
  affMat(t.comp, nb_listes, t_mini, ',');
  FILE *fichier = fopen("comp.csv","w+"); //lecture et ecriture. Supprime l'ancien contenu.
  fprintf(fichier,"Taille,Insertion,Selection,Bulle,Fusion,Rapide\n");
  saveMat(t.comp, nb_listes, t_mini, ',', fichier);
  fclose(fichier);
}

void afficherPermCSV(test t, int nb_listes, int t_mini){
  printf("Taille,Insertion,Selection,Bulle,Fusion,Rapide\n");
  FILE *fichier = fopen("perm.csv","w+");
  fprintf(fichier,"Taille,Insertion,Selection,Bulle,Fusion,Rapide\n");
  saveMat(t.perm, nb_listes, t_mini, ',', fichier);
  fclose(fichier);
  affMat(t.perm, nb_listes, t_mini, ',');
}


void afficherTotalCSV(test t, int nb_listes, int t_mini){
  printf("Taille,Insertion,Selection,Bulle,Fusion,Rapide\n");
  FILE *fichier = fopen("total.csv","w+");
  fprintf(fichier,"Taille,Insertion,Selection,Bulle,Fusion,Rapide\n");
  saveMat(t.totalOp, nb_listes, t_mini, ',', fichier);
  fclose(fichier);
  affMat(t.totalOp, nb_listes, t_mini, ',');
}

void afficherCompPlot(test t, int nb_listes, int t_mini){
  printf("# Taille de la liste - Nombre de comparaisons pour chaque tri\n");
  FILE *fichier = fopen("comp.dat","w+");
  fprintf(fichier,"# Taille de la liste - Nombre de comparaison pour chaque tri\n");
  saveMat(t.comp, nb_listes, t_mini, ',', fichier);
  fclose(fichier);
  affMat(t.comp, nb_listes, t_mini, '\t');
}

void afficherPermPlot(test t, int nb_listes, int t_mini){
  printf("# Taille de la liste - Nombre de permutations pour chaque tri\n");
  FILE *fichier = fopen("perm.dat","w+");
  fprintf(fichier,"# Taille de la liste - Nombre de permuations pour chaque tri\n");
  saveMat(t.perm, nb_listes, t_mini, '\t', fichier);
  fclose(fichier);
  affMat(t.perm, nb_listes, t_mini, '\t');
}


void afficherTotalPlot(test t, int nb_listes, int t_mini){
  printf("# Taille de la liste - Nombre de d'opérations pour chaque tri\n");
  FILE *fichier = fopen("total.dat","w+");
  fprintf(fichier,"# Taille de la liste - Nombre d'opération pour chaque tri\n");
  saveMat(t.totalOp, nb_listes, t_mini, ',', fichier);
  fclose(fichier);
  affMat(t.totalOp, nb_listes, t_mini, '\t');
}*/

/**
 *  Fonction qui affiche la matrice envoyé.
 *    - char car : caractère de séparation.
 */
void affMat(int **mat, int nb_listes, int t_mini, char car){
  for (int i=0; i<nb_listes; i++){
    printf("%d",t_mini*(i+1));
    for (int j=0; j<NBTRIS; j++){
      printf("%c%d",car,mat[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

/**
 * Fonction qui enregistre la matrice dans un fichier.
 */
void saveMat(int **mat, int nb_listes, int t_mini, char car, FILE *fichier){
  for (int i=0; i<nb_listes; i++){
    fprintf(fichier,"%d",t_mini*(i+1));
    for (int j=0; j<NBTRIS; j++){
      fprintf(fichier,"%c%d",car,mat[j][i]);
    }
    fprintf(fichier,"\n");
  }
}


//BANC D'ESSAIS
/**
 *  Fonction de banc d'essais
 */
test banc_test(int t_mini, int nbli, int nb_expres, int nbGenList, int valeurMax){
  int* (*tab[NBGENLISTES])(int taille, int max) = {gen_liste,genListePresTrie,genListeTrie,genListeInverse,genListeDoublons};

  test res;
  gen_test(&res, nbli);
  int *comp = malloc(sizeof(int));
  int *perm = malloc(sizeof(int));
  *comp = 0, *perm = 0;
  for (int i=1; i<=nbli; i++){
    for (int j=0; j<nb_expres; j++){
      int *li = tab[nbGenList](t_mini*i, valeurMax);//gen_liste(t_mini*i,100);
      int *copy = malloc(t_mini*i*sizeof(int));
      copyTab(li, copy, t_mini*i);

      tri_insertion(copy, t_mini*i, comp, perm);
      ecriture(res, 0, i-1, perm, comp);
      copyTab(li,copy, t_mini*i);

      tri_selection(copy, t_mini*i, comp, perm);
      ecriture(res, 1, i-1, perm, comp);
      copyTab(li, copy, t_mini*i);
    
      tri_bulle(copy, t_mini*i, comp, perm);
      ecriture(res, 2, i-1, perm, comp);
      copyTab(li, copy, t_mini*i);

      tri_fusion(copy, t_mini*i, comp, perm);
      ecriture(res, 3, i-1, perm, comp);
      copyTab(li, copy, t_mini*i);

      tri_rapide(copy, 0, t_mini*i, comp, perm);
      ecriture(res, 4, i-1, perm, comp);
      copyTab(li, copy, t_mini*i);

      tri_tas(copy, t_mini*i, comp, perm);
      ecriture(res, 5, i-1, perm, comp);
      copyTab(li, copy, t_mini*i);

    free(li);
    free(copy);
    }
    moyenneTris(res, nb_expres, i-1);
  }
  free(perm),free(comp);
  return res;
}


/**
 *  Fonction qui copie la liste courante.
 */
void copyTab(int *tab1, int *tab2, int taille){
  for (int i=0; i<taille; i++)
    tab2[i] = tab1[i];
}

/**
 *  Fonction qui additionne les permutations et comparaison dans la matrice.
 */
void ecriture(test t, int nbTri, int ind, int *perm, int *comp){
  t.perm[nbTri][ind] += *perm;
  t.comp[nbTri][ind] += *comp;
  *perm = 0;
  *comp = 0;
}

/**
 *  Fonction qui calcul la moyenne des comparaisons, permutations de la matrice et ecrit le total des opérations.
 */
void moyenneTris(test t, int nb_expres, int ind){
  int i = 0;
  for (;i<NBTRIS;i++){
    t.perm[i][ind] /= nb_expres;
    t.comp[i][ind] /= nb_expres;
    t.totalOp[i][ind] = t.perm[i][ind]+t.comp[i][ind];
  }

}

//DIFFERENTES GENERATIONS DE LISTE

int *gen_liste(int taille, int max){
  int * res = malloc(sizeof(int)*taille);
  int nbr;
  int i;
  srand(time(NULL));
  for (i=0; i<taille; i++){
    nbr = rand()%max;
    res[i] = nbr;
  }
  return res;
}

int *genListeTrie(int taille){
  int *res = malloc(sizeof(int)*taille);
  int i;
  for (i=0; i<taille; i++){
    res[i] = i;
  }
  return res;
}

int *genListePresTrie(int taille){
  int *res = genListeTrie(taille);
  int i;
  srand(time(NULL));
  for (i=0; i<(rand()%((taille-1)%3))+1; i++)
    res[i] = rand()%taille;
  return res;
}

int *genListeInverse(int taille){
  int *res = malloc(sizeof(int)*taille);
  int i;
  for (i=0; i<taille ; i++){
    res[i] = taille-i;}
  return res;
}

int *genListeDoublons(int taille){
  return gen_liste(taille, 5);
}


//AFFICHAGE LISTE
//
void aff_liste(int *li,int taille){
	int i;
	printf("[ ");
	for (i=0; i<taille-1; i++){
		printf("%d, ", li[i]);
	}
        printf("%d ]\n", li[taille-1]);
}

//TRIES

int est_trie(int *li, int taille){
	int i;
	for (i=0; i<taille-1; i++){
		if (li[i] > li[i+1]){
			return 0;
		}
	}
	return 1;
}

//
void tri_selection(int *li,int taille, int *comp, int *perm){
  int cours, petit, j ,tmp;
  for (cours=0; cours<taille-1; cours++){
    petit = cours;
    for (j=cours+1; j<taille; j++ ){
      *comp+=1;
      if (li[j]<li[petit]){
        petit=j;
      }
    }
    *perm+=1;
    tmp = li[cours];
    li[cours] = li[petit];
    li[petit] = tmp;
    
  }
}

//
void tri_insertion(int *li, int taille, int *comp, int *perm){
  int i, j, cours;
  for (i=0; i<taille ;i++){
    cours = li[i];
    for (j=i; *comp+=1,(j>0) && (li[j-1]>cours); j--){
      li[j] = li[j-1];
      *perm+=1;
    }
    li[j] = cours;
    *perm+=1;
  }
}

//
void tri_bulle(int *li, int taille, int *comp, int *perm){
  int passage = 0;
  int permutation = 1;
  int cours;
  while (permutation == 1){
    permutation = 0;
    passage ++;
    for(cours=0; cours<taille-passage; cours++){
      *comp+=1;
      if (li[cours]>li[cours+1]){
        *perm+=1;
        permutation = 1;
        int tmp = li[cours];
        li[cours] = li[cours+1];
        li[cours+1] = tmp;
      }
    }
  }
}

//
void tri_fusion(int *tab, int taille, int *comp, int *perm){
  if (taille<=1)
    return;
  int milieu = taille/2;
  tri_fusion(tab, milieu, comp, perm);
  tri_fusion(&tab[milieu],taille-milieu, comp, perm);
  fusion(tab, taille, milieu, comp, perm);

}

//
void fusion(int *tab, int taille, int milieu, int *comp, int *perm){
  int *tab2 = malloc(taille*sizeof(*tab));
  int Do, Re, Mi;//vive le C89 :-)
  for (Do=0, Re=milieu, Mi=0; Mi<taille; Mi++){
    if (Re == taille){
      *comp+=1;
      tab2[Mi] = tab[Do];
      Do++;
    }
    else if(Do==milieu){
      *comp+=2;
      tab2[Mi] = tab[Re];
      Re++;
    }
    else if(tab[Re]<tab[Do]){
      *comp+=3;
      tab2[Mi] = tab[Re];
      Re++;
    }
    else{
      *comp+=3;
      tab2[Mi] = tab[Do];
      Do++;
    }
  }
  //pas de permuation car création d'une nouvelle liste, il y a juste un remplacement dans la liste principale ensuite.
  for (Do = 0; Do<taille; Do++)
    tab[Do] = tab2[Do];
  free(tab2);
}

//
void tri_rapide(int *tab, int deb, int fin, int *comp, int *perm){
  int pivot = tab[deb];
  int pos=deb;
  int i;
  if (deb>=fin)
    return;
  for (i=deb; i<fin; i++){
    *comp+=1;
    if (tab[i]<pivot){
      *perm+=3;
      tab[pos]=tab[i];
      pos++;
      tab[i]=tab[pos];
      tab[pos]=pivot;
    }
  }
  tri_rapide(tab,deb,pos,comp,perm);
  tri_rapide(tab,pos+1,fin,comp,perm);
}

//
int fg(int tab[], int ind, int size){
  int emp=ind*2+1;
  if (emp>size)
    return -1;
  return emp;
}

int fd(int tab[], int ind, int size){
  int emp=ind*2+2;
  if (emp>size)
    return -1;
  return emp;
}

void swap(int tab[], int ind, int ind2, int *comp, int *perm){
  int tmp = tab[ind];
  tab[ind] = tab[ind2];
  tab[ind2] = tmp;
  *perm+=1;
}


void entasser(int tab[], int ind, int size, int *comp, int *perm){
  if (ind==-1) return ;
  int iMax = ind;
  int ifg = fg(tab,ind,size);
  int ifd = fd(tab,ind,size);
  if (ifg>-1 && ifg<size && tab[ifg]>tab[iMax])
    iMax=ifg;
  if (ifd>0 && ifd<size && tab[ifd]>tab[iMax])
    iMax=ifd;
  *comp+=2;
  if (iMax > ind){
    swap(tab, ind, iMax,comp,perm);
    entasser(tab, iMax,size,comp,perm);
  }
  entasser(tab,ind-1,size,comp,perm);
}

void tri_tas(int tab[], int size, int *comp, int *perm){
  while (size>0){
    entasser(tab,0,(size/2)+1,comp,perm);
    swap(tab, 0, --size,comp,perm);
  }
}


////////////

void viderBuffer(void){
  char c1;
  while (((c1 = getchar()) != '\n') && (c1 != EOF));
  printf("\n");
}


int main(void){
  int tmin, nblist, nb_expres, valeurMax, nbGenlist, continuer;
  nb_expres = 1000;
  tmin=100;
  nblist=10;
  valeurMax=100;
  nbGenlist=0;
  continuer=1;
  while (continuer == 1){
    printf("Veuillez choisir une valeur pour nb_expres : ");
    scanf("%d", &nb_expres);
    viderBuffer();

    printf("Veuillez choisir une valeur pour taille_mini : ");
    scanf("%d", &tmin);
    viderBuffer();

    printf("Veuillez choisir une valeur pour nb_listes : ");
    scanf("%d", &nblist);
    viderBuffer();

    do{
      printf("Veuillez choisir votre type de generation de liste à tester : \n");
      printf("0 - Liste d'entiers choisis aléatoirement.\n");
      printf("1 - Liste d'entiers déjà presque triée.\n");
      printf("2 - Liste d'entiers déjà triée.\n");
      printf("3 - Liste d'entiers triée dans l'ordre inverse.\n");
      printf("4 - Liste d'entiers contenant beaucoup de doublons.\n");
      printf("\t Votre choix : ");
      scanf("%d", &nbGenlist);
      viderBuffer();
    }while((nbGenlist > 4) || (nbGenlist < 0));

    if (nbGenlist == 0){
      printf("\t + Veullez choisir une valeur maximale pour votre liste : ");
      scanf("%d", &valeurMax);
      viderBuffer();
    }

    test t = banc_test(tmin,nblist,nb_expres,nbGenlist,valeurMax);
    afficher(t, nblist, tmin);
    continuer = 2;

    do{
    printf("Voulez-vous continuer : \n 0 - Non\n 1 - Oui\n\t : ");
    scanf("%d",&continuer);
    viderBuffer();
    }while(continuer!=0 && continuer!=1);

  }
  return(0);
}
