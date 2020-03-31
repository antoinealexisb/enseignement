#include <stdio.h>

int main(void)
{
	char a='A';
	int b =-4, c=2;
	unsigned int d=2;
	double x = 1.75;
	printf("la valeur de (a+2) %d ,et la taille est : %ld \n", (a+2), sizeof((a+2)));
        printf("la valeur de (a) %d ,et la taille est : %ld \n", (a), sizeof((a)));
        printf("la valeur de (c+31) %d ,et la taille est : %ld \n", (c+31), sizeof((c+31)));

        printf("la valeur de (c+013) %d ,et la taille est : %ld \n", (c+013), sizeof((a+013)));
        printf("la valeur de (c+0x1F) %d ,et la taille est : %ld \n", (c+0x1F), sizeof((c+0x1F)));
        printf("la valeur de (c+x) %f ,et la taille est : %ld \n", (c+x), sizeof((a+2)));
        printf("la valeur de (b>c) %d ,et la taille est : %ld \n", (b>c), sizeof((b>c)));
        printf("la valeur de (b>d) %d ,et la taille est : %ld \n", (b>d), sizeof((b>d)));


	return(0);
}
