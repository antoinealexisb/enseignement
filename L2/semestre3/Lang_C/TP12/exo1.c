#include <stdio.h>
#include <stdlib.h>

struct _flottant {
	int entiere;
	char *decimale;
	};

typedef struct _flottant flottant;

flottant diviser (int p, int q, int precision) {
	flottant f;
	f.entiere = p/q;
	int tmp = p/q;
	f.decimale = malloc (sizeof(char) * precision+1);

	for (int i = 0; i < precision; i++){
		if (tmp == 0){
		p*=10;
		}
		else {
			p -= q*tmp;
			p*=10;
			}
		tmp= p/q;
		f.decimale[i] = '0'+(char)tmp;
		}
	f.decimale[precision] = '\0';
	return f;
	}

void imprimer (flottant *d) {
	printf ("Le champs entiere est : %d.\nLe champs decimale est : %s \n", d->entiere, d->decimale);
	}

int main (void) {
	flottant f = diviser (1, 97, 1000);
	imprimer (&f);
	return 0;
	}	
