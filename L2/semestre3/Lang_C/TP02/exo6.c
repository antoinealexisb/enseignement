#include <stdio.h>

int main(void)
{
        char expr1=1 , expr2=0;
	int test =0;
        test = (expr1||++expr2);
	printf("expression1 : %d , expression2 : %d",expr1 , expr2);
	expr1 = 0;
	test = (expr1||++expr2);
	printf("\nexpression1 : %d , expression2 : %d", expr1, expr2);
        return(0);
}

