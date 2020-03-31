#include <stdio.h>

void main()
{
	int i=1;
	int *p;
	printf("La variable i comme valeur %d et se trouve à l'adresse : %p \n", i, &i);
	p=&i;
	printf("L'adresse de la variable pointeur p est : %p \n", p);
	*p+=3;
	printf("La variable i à la nouvelle valeur suivante : %d \n", i);
}
