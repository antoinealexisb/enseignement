#include <stdio.h>
int main(void)
{
	int nombre;
	printf("Entrez un nombre : ");
	scanf("%d",&nombre);
	printf("\nLe dernier nombre est : %d", nombre%10);
	nombre =nombre/10;
	printf("\nL'avant dernier nombre est : %d", nombre%10);
	return(0);
}
