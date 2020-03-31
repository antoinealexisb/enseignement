#include <stdio.h>
int main(void)
{
	int a, b=0, c;
	int f=0;
	printf("Merci de saisir un premier nombre. \n");
	scanf("%d",&b);
	printf("Merci de saisir un deuxième nombre. \n");
	scanf("%d", &c);
	a= (b+c)+1;
	f = (a>1);
	if (f)
		printf("La somme des deux nombres lus est stictement positive.\n");
	return(0);
}
