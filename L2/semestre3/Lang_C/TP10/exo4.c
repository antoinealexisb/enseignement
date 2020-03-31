#include <stdio.h>

int main(void)
{
	int tab[10][20]={{0}};
	printf("%d\n",tab);
        printf("%d\n",tab[2][3]);
        printf("%d\n",*tab);
        printf("%d\n",*(tab+2)+3);
        printf("%d\n",tab+1);



	return 0;
}

