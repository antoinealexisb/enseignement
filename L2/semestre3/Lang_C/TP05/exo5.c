#include <stdio.h>
void init_pointeur(int **p);

void init_pointeur(int **p)
{
	*p=NULL;
}


int main(void)
{
	int i;
	int *q;
	q=&i;
	printf("Avant initialisation, la valeur du pointeur q est : %p.\n", q);
	init_pointeur(&q);
	printf("Après initialisation, la valeur du pointeur q est : %p.\n", q);
	return(0);
}
