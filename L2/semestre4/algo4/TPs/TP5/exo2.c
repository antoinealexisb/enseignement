#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tailletab 10000

//EXO 2 - 1 max
int max(int *tab, int taille, int cmp, int maxi){
	if (cmp == taille)
		return maxi;
	if (tab[cmp] > maxi)
		return max(tab, taille, ++cmp, tab[cmp]);
	return max(tab, taille, ++cmp, maxi);
}

int *genererTableau(void){
    int *tab = malloc(tailletab*sizeof(int)),i;
    srand(1664);
    for(i=0;i<tailletab;i++){
        tab[i] = rand();
    }
    return tab;
}

void afficheTab(int tab[]){
        for (int i=0; i<tailletab; i++)
                printf("%d, ",tab[i]);
        printf("\n");
}

//EXO 2 - 2 PALINDROME

int palindrome(char *text, int cmp){
	if (cmp == strlen(text)/2)
		return 1;
	if (text[cmp] != text[strlen(text)-cmp-1])
		return 0;
	return palindrome(text, ++cmp);
}

int main(void){
	int *tab = genererTableau();
	afficheTab(tab);
	int maxb = max(tab, 6, 0, tab[0]);
	printf("Impression du max : %d\n", maxb);
	printf("\n\n");
	char text1[] = "Et la plus jolie des enfants";
	char text2[] = "SOS";
	printf("text 1 : %d \n text2 : %d \n", palindrome(text1, 0), palindrome(text2, 0));
	return(0);
}
