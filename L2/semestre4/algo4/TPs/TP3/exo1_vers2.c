#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int divNaive(int a, int b){
	int res = 0 ;
	while ( a >= b ) {
			a -= b;
			res++;
	}
	return res;
}

int degre(int a){
	int cpt=0;
	while (a>10){
		a/=10;
		cpt++;
	}
	return cpt+1;
}

int premierChiffre(int a){
	while (a>10){
		a/=10;
	}
	return a;
}

int divDecimal(int a, int b){
	int degre(int a); 
	int tab[degre(a)];
	int i, diviseur, tmp_a = a , taille = degre(a);
	for (i = 0 ; i <taille ; i++){
		diviseur = pow(10,taille-i-1);
		tab[i] = tmp_a/diviseur;
		tmp_a -= tab[i]*diviseur;
	}
	
	int res=0, cpt=0;
	int dividende = tab[cpt];
	while(a > b){
		if (dividende <b){
			cpt++;
			res *= 10;
			dividende *= 10;
			dividende += tab[cpt];
		}
		else{
			res+= dividende/b;
			dividende %= b;
			a-=pow(10,cpt+1);
		}
	}
	return (res);
}

int divisionBinaire(int a, int b){
   int somme=b, i=0, quotient=0;
   while(somme*2<a){
       somme*=2;
       i+=1;
   }
   quotient = pow(2,i);
   while(i>0){
       if((b*(pow(2,i-1))+somme)<a){
           somme+=b*(pow(2,i-1));
           quotient+=pow(2,i-1);
       }
       i-=1;
   }
   //printf("%d \n" , quotient);
   return quotient;
}


int main(void){
	int divisionBinaire(int a, int b);
	int divNaive(int a, int b);
	int degre(int a);
	int a=1045,b=54;
	printf("3564/17 = %d\n", divNaive(a,b));
	printf("3564/17 = %d\n", divisionBinaire(a,b));
	printf("3564/17 = %d\n", divDecimal(a,b));
	return 0;
}


