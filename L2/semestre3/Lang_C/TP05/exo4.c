
#include <stdio.h>
int premier(int truc);

int premier(int truc)
{
        for (int i = 2; i < truc; i++) {
                if (truc % i == 0) {
                        return 0;
                        }
                }
        return 1;
}

int main (void)
{
        int a=7;
	premier(a) ? printf("le nombre est premier\n") : printf("Le nombre n'est pas premier \n");
        return 0;
}

