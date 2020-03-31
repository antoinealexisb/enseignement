/****
Les sept erreurs de compilation
****/
#include <stdio.h>
int main(int argc, char* argv[])
{
	int nombre, somme, i;
	somme=0;
	printf("Merci d\'introduire un nombre entier positif : ");
	scanf("%d", &nombre);
	for (i=0; nombre!=0; i++)
	{
		somme = somme + (nombre %10);
		nombre = nombre /10;
	}
	printf("La somme des chiffres de ce nombre est : %d\n", somme);
	return(0);
}
