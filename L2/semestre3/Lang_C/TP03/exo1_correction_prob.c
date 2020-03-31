#include <stdio.h>

int main(void)
{
	int n,i,somme=0;
	do {
		printf("\nMerci d'introduire un nombre strictement positif : ");
		scanf("%d",&n);
	} while (n<=0);
	for (i=2; i<=n; i=i+2) {
		somme+=i;
	}
	printf("\n La somme des nombres pairs inférieurs à %d est : %d. \n", n, somme);
	return(0);
}

/*

Pour un nombre positif pair nous sommes à n+2 en sortie,
Pour un nombre positif impair nous sommes à n+1 en sortie,
Car l'instruction : for (i=2; i<=n; i+=2) ; {... = for (i=2; i<=n; i+=2){;}
donc exemple avec 2:
	donc i=2; 2<=2; i=2+2 comme il y a ; la somme ne se fait pas donc:
	i=4; 4<=2 .. on rentre pas dans la boucle donc somme=4
*/
