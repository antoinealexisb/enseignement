#include <stdio.h>

int main(){
	unsigned char n_base;
	long int n=0;
	do{
		printf("Entrez un nombre entre 0 et 8 inclus : ");
		n_base = getchar()-'0';
		//scanf("%hhd",&n_base);
	} while (n_base=>8 || n_base<0);
	for (int i=0; i<n_base; i++)
	{
		while(getchar() != '\n');
		printf("\nEntrez votre nombre n°%d : ",i+1);
		n=(n*10)+(getchar()-'0');//+tmp;
	}
	printf("%ld\n",n);
	for (int i=0; i<n_base; i++)
	{
		printf(" %ld ",n%10);
		n/=10;
	}
	//printf("\nLe nombre est %ld", n);
	return(0);
}

