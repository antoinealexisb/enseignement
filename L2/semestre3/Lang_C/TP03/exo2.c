#include <stdio.h>
/*Lit un caractère hexa et affiche son équivalent décimal avec une boucle switch */
int main(int argc, char* argv)
{
	char hexa;
	printf("Veuilliez entrez votre caractère hexa : ");
	scanf("%c",&hexa);
	switch (hexa){
		case '0':
			printf("\n Le nombre décimal est : %d",0);
			break;
                case '1':
                        printf("\n Le nombre décimal est : %d",1);
                        break;
                case '2':
                        printf("\n Le nombre décimal est : %d",2);
                        break;
                case '3':
                        printf("\n Le nombre décimal est : %d",3);
                        break;
                case '4':
                        printf("\n Le nombre décimal est : %d",4);
                        break;
                case '5':
                        printf("\n Le nombre décimal est : %d",5);
                        break;
                case '6':
                        printf("\n Le nombre décimal est : %d",6);
                        break;
                case '7':
                        printf("\n Le nombre décimal est : %d",7);
                        break;
                case '8':
                        printf("\n Le nombre décimal est : %d",8);
                        break;
                case '9':
                        printf("\n Le nombre décimal est : %d",9);
                        break;
                case 'A':
                        printf("\n Le nombre décimal est : %d",10);
                        break;
                case 'B':
                        printf("\n Le nombre décimal est : %d",11);
                        break;
                case 'C':
                        printf("\n Le nombre décimal est : %d",12);
                        break;
                case 'D':
                        printf("\n Le nombre décimal est : %d",13);
                        break;
                case 'E':
                        printf("\n Le nombre décimal est : %d",14);
                        break;
                case 'F':
                        printf("\n Le nombre décimal est : %d",15);
                        break;
               default:
                        printf("\n Le nombre décimal est : %d",-1);
                        break;
	}
	return(0);
}

