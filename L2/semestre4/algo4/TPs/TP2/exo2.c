#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int div_euclid_naive(int a, int b){
	int res=0;
	while(a-b>0){
		res++;
		a-=b;
	}
	return res;


}

int div_eucli_dec(unsigned long int a,unsigned long int b){
    clock_t start_t, end_t;
    int q=0;
    int ret=0;
    int r=a;
    int n=1;
    double total_t;
    start_t=clock();
    while (r>=b){
        while(b*n<=a){
            n*=10;
        }
        n/=10;
        ret=b*n;
        while(r>=ret){
            r=r-ret;
            q=q+n;
            }
            n=1;    
    }
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Le quotient est %d le reste est %d\n le programme a pris %f de temps\n",q,r,total_t);
    return (r);
}

void binaire(int a, int b) {
	//assert(b);
	int r = a;
	int q = 0;
	int n = 0;
	int aux = b;
	while (aux <= a) {
		aux = (aux << 1);
		n++;
	}
	while (n > 0) {
		aux = (aux >> 1);
		n--;
		q = (q << 1);
		if (r >= aux) {
			r = r - aux;
			q++;
		}
	}
	printf("%d, %d\n",q,r);
	//return r;
}

int main(){
	int a = 18;
	int b = 5;
	
	double start_t, end_t, total_t;
	start_t = clock();
	
	/*Fonctions*/
	printf("naive : %d / %d = %d\n",a,b,div_euclid_naive(a,b));
	//printf("binaire : %d / %d = %d\n",a,b,binaire(a,b));
	binaire(a,b);

	end_t = clock();
	total_t = (end_t - start_t) / CLOCKS_PER_SEC;
	printf("Total time taken by CPU : %f\n", total_t);
	return(0);
}
