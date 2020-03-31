#include <stdio.h>

int main(int argc, char* argv[])
{
	unsigned char i='A';
	int j=1;
	printf("%c %c i=%d %c %c j=%d %c %c",10,9,i,9,34,j,34,10);
	printf("%c %c i=%c %c %c %c ",10,9,i,9,34,10);
	return(0);

}
