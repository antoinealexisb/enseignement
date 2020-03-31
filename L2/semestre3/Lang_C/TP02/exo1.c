#include <stdio.h>

int main(int argc, char* argv[])
{
	float nombre_or = 1.61803398875;
	printf("Ecriture no. 1 :\t %.6f\n", nombre_or);
        printf("Ecriture no. 2 :\t %9.6f\n", nombre_or);
        printf("Ecriture no. 3 :\t %09.6f\n", nombre_or);
        printf("Ecriture no. 4 :\t %10.6f\n", nombre_or);
        printf("Ecriture no. 5 :\t %010.6f\n", nombre_or);
        printf("Ecriture no. 6 :\t %11.6f\n", nombre_or);
        printf("Ecriture no. 7 :\t %011.6f\n", nombre_or);
        printf("Ecriture no. 8 :\t %11.3f\n", nombre_or);
        printf("Ecriture no. 9 :\t %011.3f\n", nombre_or);
return(0);
}
