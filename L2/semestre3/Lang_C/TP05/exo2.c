#include <stdio.h>
void echange_adr(int *a, int *b);

void echange_adr(int *a, int *b)
{
int c=*a;
*a=*b;
*b=c;
}

int main(void)
{
	unsigned int x,y;
	unsigned int *p=&x, *p1=&y;
	x=5;
	y=10;
	echange_adr(p,p1);
	printf("Grâce aux pointeurs, après l'appel à la fonction echange_adr x=%u et y=%u.\n", x,y);
	return(0);
}
