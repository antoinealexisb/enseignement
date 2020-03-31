#include <stdio.h>
int main(void)
{
	int i;
	unsigned int j;
	i = -10;
	j = 10;
	if (i>j)
		printf("A priori c'est étrange d'avoir cet affichage ... Mais en réalité c'est normal à cause des conversions implicites. \n");
	else
		printf("ca va mieux avec les conversions explicites \"cast\"\n");
	return(0);
}

/*Le programme affiche "A priori c'est étrange d'avoir cet affichage ... 
Mais en réalité c'est normal à cause des conversions implicites

ici la comparaison i>j affichage cela car ont converti de int vers un unsigned int -10 donc un très grand nombre  

pour la conversion il faut faire (i>(int)j)
*/
