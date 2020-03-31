#include <stdio.h>
int main(void){
	char i;
	i=1;
	while (i>0) i++;
	printf("Après la boucle, la valeur de i est : %d.\n",i);
	return(0);
}

/*
Nous constatons que la valeur afficher est -128 car le type char est compris antre [-128, 127].
Donc si =127 + 1 = -128 et l'on quite la boucle.
*/
