#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, int dep, int intermediaire, int dest){
	if (n==1)
		printf("Déplace de %d vers %d\n",dep,dest);
	else{
		hanoi(n-1, dep, dest, intermediaire);
		printf("Déplace de %d vers %d\n",dep,dest);
		hanoi(n-1,intermediaire,dep,dest);	
	}
}


int main(void){
	hanoi(4,0,1,2);
	return(0);
}
