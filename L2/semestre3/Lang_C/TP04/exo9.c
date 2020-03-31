# include <stdio.h>
int main( void )
{
	char c , * p = &c ;
	int i , * p1 = &i ;
	double d , * p2 = &d ;
	printf ( " Voici les adresses des variables :\n" );
	printf ( " &c=%p &i=%p &d=%p &p=%p &p1=%p &p2=%p \n \n" , &c , &i , &d , &p , &p1 , &p2 );
	printf ( " Voici la valeurs des variables :\n" );
	printf ( " p=%p p1=%p p2=%p \n \n " , p , p1 , p2 );
	printf ( " Voici la valeurs des variables ++ de 1 :\n " );
	printf ( " p+1=%p p1+1=%p p2+1=%p \n " , p+1 , p1+1 , p2+1);
	return (0);
}
