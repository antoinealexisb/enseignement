#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int partie1 (int n, int etage_min, int etage_bon, int k){
  int tmp;
  if (k == 0){
    return -1;
  }
  tmp = (etage_min + n)/2;
  if (tmp == etage_bon){
    return tmp;
  }
  else if(tmp < etage_bon){
    return partie1(n, tmp, etage_bon, k);
  }
  else{
    return partie1(tmp, etage_min, etage_bon, k-1);
  }
}


int partie2 (int n, int etage_min, int etage_bon, int k){
	int tmp;
	if (k == 0)
		return -1;
	if (k == 1){
		int i;
		for (i = etage_min; i < etage_bon; i++);
		return i;
	}
	tmp = (etage_min + n)/2;
	if(tmp < etage_bon)
		return partie1(n, tmp, etage_bon, k);
	else
		return partie1(tmp, etage_min, etage_bon, k-1);
}


int partie3 (int n, int etage_bon){
	int k = 2, pire = sqrt(n), cmp = 0;
	while (cmp < etage_bon){
		cmp+= pire;
	}
	cmp -= pire;
	while (cmp < etage_bon){
		cmp++;
	}
	return cmp;
}


int main(void){
	printf("%d, %d, %d \n",partie1(100,0,69,150), partie2(100,0,69,3), partie3(100,69));
	return(0);
}
