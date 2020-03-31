#include <stdio.h>
#include <time.h>

int div_euclidienne_naive (int a, int b){
	int res = 0;
	while (a > b){
		res++;
		a -= b;
		}
	return res;
	}

int div_euclidienne_binaire (int a, int b){
	int test = 1, res = 0, somme = 0;
	while (test*b < a){
		test *=2;
		}
	res += test;
	somme = test*b;
	while (test != 1){
		test /= 2;
		if (test*b+somme < a){
			res += test;
			somme = test*b;
			}
		}
	return res;
	}

int div_euclidienne_dec(unsigned long int a,unsigned long int b){
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

int main(){
	clock_t start_t,end_t;
	start_t = clock();
	printf("%d\n\n",div_euclidienne_naive(35,17));
	printf("%d\n\n",div_euclidienne_binaire(35,17));
	printf("%d",div_euclidienne_dec(35,17));
	return 0;
}
