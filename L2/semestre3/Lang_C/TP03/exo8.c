#include <stdio.h>
/* Les conséquences d'une représentation */
/* approchée des nombres réels */
int main(void)
{
	float f;
	f=.1;
	while (f!=1.){
		printf("La valeur de f est %.13f \n", f);
		f+=.1;
		//getchar();
	}
	return(0);
}

