#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define prix_max 100

/*Le jeu du JUSTE PRIX */

int main(void)
{
	printf("#################################\n");
	printf("######    LE JUSTE PRIX     #####\n");
	printf("#################################\n");


	long prix_util;
	unsigned char nbre_coups =0;
	srand(time(NULL));
	long nombre = rand() % prix_max;

	do{
		printf("Ecrire un montant : ");
		scanf("%ld",&prix_util);
		while (getchar() !='\n');
		if (nombre < prix_util)
			printf("Désolé c'est - .\n");
		else if(nombre > prix_util)
			printf("Désolé c'est + .\n");
		nbre_coups++;
	}
	while(prix_util!=nombre);
	printf("\n BRAVO vous avez trouvez le juste prix : %ld, en %d coups", nombre, nbre_coups);
	return(0);

}
