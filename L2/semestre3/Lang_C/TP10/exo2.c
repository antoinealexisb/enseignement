#define k 10
#include <stdio.h>

void fusion (int tab[k], int tab2[k], int tab3[k+k]){
	
	int i,x=0,y=0;
	for (i=0; i < (k+k); i++){
		if (x<k && y<k){
			if (tab[x] < tab2[y]){
				tab3[i] = tab[x];
				x++;
				}
			else {
				tab3[i] = tab2[y];
				y++;
				}
			}
		else{
			if (x == k){
				tab3[i] = tab2[y];
				y++;
				}
			else{
				tab3[i] = tab[x];
				x++;
				}
			}
		}
	}

int main (void){
	int i;
	int t[k] = {12,13,27,31,50,55,60,65,70,75};
	int t2[k] = {5,10,15,20,25,30,35,40,45,52};
	int t3[k+k];
	fusion (t,t2,t3);
	for (i=0; i<k+k; i++){
		printf("%d ", t3[i]);
		}
	printf("\n");
	return 0;
	}
