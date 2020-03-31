#include <stdio.h>

int main(void)
{
	unsigned char cpt=0;
	printf("Merci d'écrire une phrase : ");
	while (getchar() != '\n') cpt++;
	printf("\n Dans la phrase il y a %d caractères", cpt);
	return(0);
}
