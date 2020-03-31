#include <stdio.h>
int sommerec(int n,int somme);

int main(void)
{
	int n = 2095;
	printf("La somme des chiffres est : %d\n", sommerec(n,0));
	return 0;
}

int sommerec(int n,int somme)
{
	if (n==0)
		return somme;
	return sommerec(n/10,somme+n%10);
}
