#include <stdio.h>

void main()
{
	int annee;
	printf("Entrez votre année : ");
	scanf("%d",&annee);
	switch(annee){
		case 1:
		case 2:
		case 3:
			printf("\n D9");
			break;
		case 4:
			printf("\n D309");
			break;
		case 5:
			printf("\n P306");
			break;
		default:
			printf("\n E27");
	}
}
