#include <stdio.h>
void echange_ptr (int **d, int **d1)
{
        int *tmp = *d;
        *d = *d1;
        *d1 = tmp;
}

int main (void)
{
        int *p, *p1;
        printf ("Avant échange p=%p \t et \t p1=%p. \n", p , p1);
        echange_ptr(&p, &p1);
        printf ("Après échange p=%p \t et \t p1=%p. \n", p , p1);
        return 0;
}


