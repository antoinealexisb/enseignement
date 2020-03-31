#include <stdio.h>
void remplir(int n);
void vider(int n);
int main(void);

void remplir(int n)
{
	if (n>0){
	if (n==1){
		printf("Je remplis la case 1 \n");
	}
	else{
		remplir(n-1);
		vider(n-2);
		printf("Je remplis la case %d \n",n);
		remplir(n-2);
	}
	}
}

void vider(int n)
{
	if (n>0){
	if (n==1){
		printf("Je vide la case %d \n", n);
	}
	else{
		vider(n-2);
		printf("Je vide la case %d \n",n);
		remplir(n-2);
		vider(n-1);
	}
	}
}

int main(void)
{
	int i=5;
	printf("\n\n########## REMPLIR ##########\n");
	remplir(i);
	printf("\n\n########### VIDER ###########\n");
	vider(i);
	return(0);
}
