#include <stdio.h>

int main(void)
{
	unsigned int nombre=0;
	printf("Entrez un nombre, pour afficher le 3e bits, de poids le plus faible :");
	scanf("%d", &nombre);
	printf("\nLe bit est : %d", (nombre>>2)%2);
}
