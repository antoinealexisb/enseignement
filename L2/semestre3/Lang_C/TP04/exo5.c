#include <stdio.h>

int main(void)
{
	int i=-20;
	int *p1, **p2;
	p1=&i;
	p2=&p1;
	return(0);
}
