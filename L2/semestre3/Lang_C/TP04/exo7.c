#include <stdio.h>
int main(void){
	int i=-20;
	int *p1;
	int **p2;
	int ***p3;
	int ****p4;
	p1=&i;
	p2=&p1;
	p3=&p2;
	p4=&p3;
	printf("La valeur absolue de i est : %d.\n", *(*(*(*(p4)))));
	return(0);
}
