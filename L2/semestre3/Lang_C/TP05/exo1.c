#include <stdio.h>
int absolu(int a);

int absolu(int a)
{
	printf("la valeur de a est %d\n",a);
	printf("L'adresse de a est %p \n", &a);
	return (a<0) ? -a : a;
}

int main(void)
{
	int i=-20;
	printf("L'adresse de i est %p \n",&i);
	printf("La valeur absolue de i est : %d.\n", absolu(i));
	return(0);
}
