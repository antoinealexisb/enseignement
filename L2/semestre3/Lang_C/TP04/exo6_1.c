#include <stdio.h>

int main()
{
	unsigned int entier=0;
	int somme = 0;
	do{
		printf("Entrez un nombre positif : ");
		scanf("%u", &entier);
	}while (entier <0);
	for(;entier>0;)
	{
		somme+= entier%10;
		entier/=10;
	}
	printf("La sommes est %d", somme);
	return(0);
}
