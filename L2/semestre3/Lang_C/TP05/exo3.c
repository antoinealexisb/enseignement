#include <stdio.h>
int main (void)
{
        unsigned int *a, *b;
        *a = 10;
        *b=*a;
        printf ("Après lecture A=%u B=%u \n", *a, *b);
        return 0;
}


