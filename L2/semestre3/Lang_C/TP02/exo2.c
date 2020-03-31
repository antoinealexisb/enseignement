/**** Le Programme afiiche les caractères ASCII de 0 à 255 à l'infini
 (representation en caractère et le numéro associé) ***/

#include <stdio.h>
int main(void)
{
	unsigned char i;
	unsigned short int j=256;
	for (i=0; i!=j; i++)
	{
		printf("Le caractère numéro %d est : %c \n", i, i);
	}
	return(0);
}
