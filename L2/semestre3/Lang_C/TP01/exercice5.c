#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[])
{
	printf("Nombre de bits mot : %d \n", CHAR_BIT);
	printf("La valeur min pour signed char est %d\n", SCHAR_MIN);

        printf("La valeur max pour signed char est %d\n", SCHAR_MAX);
        printf("La valeur max pour unsigned char est %d\n", UCHAR_MAX);
        printf("La valeur min pour char est %d\n", CHAR_MIN);
        printf("La valeur max pour char est %d\n", CHAR_MAX);

        printf("La valeur min pour short int est %d\n", SHRT_MIN);
        printf("La valeur max pour short int est %d\n", SHRT_MAX);
        printf("La valeur max pour unsigned short est %d\n", USHRT_MAX);

        printf("La valeur min pour int est %d\n", INT_MIN);
        printf("La valeur max pour int est %d\n", INT_MAX);
        printf("La valeur max pour usigned int est %u\n", UINT_MAX);

        printf("La valeur min pour long int est %ld\n", LONG_MIN);
        printf("La valeur max pour long int est %ld\n", LONG_MAX);
        printf("La valeur min pour signed char est %lu\n", ULONG_MAX);


return(0);
}

