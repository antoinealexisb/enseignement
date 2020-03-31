#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("Taille  de char \t : \t %d \n", sizeof(char));
	printf("Taille avec sizeof de short \t : \t %d \n ", sizeof(short));
	printf("Taille avec sizeof de int \t : \t %d \n ", sizeof(int));
	printf("Taille avec sizeof de unsigned int \t: \t %d \n ", sizeof(unsigned int));
	printf("Taille avec sizeof de long \t: \t %d \n ", sizeof(long));
	printf("Taille avec sizeof de unsigned long \t : \t %d \n", sizeof(unsigned long));
	printf("Taille avec sizeof de float \t : \t %d \n", sizeof(float));
	printf("Taille avec sizeof de double \t : \t %d \n", sizeof(double));
	return(0);


}
