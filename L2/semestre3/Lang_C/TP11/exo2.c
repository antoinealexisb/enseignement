#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void imprimer (char *s);
void imprimer_en_lettres (char *s);
char *conway (char *s);
void afficher_conway (unsigned int n);


void imprimer (char *s){
	printf ("%s \n",s);
	}

void imprimer_en_lettres (char *s){
	int i = 0;
	while (s[i] != '\0') {
		switch (s[i]) {
			case '3':
				printf ("trois ");
				break;
			case '2':
				printf ("deux ");
				break;
			default:
				printf ("un ");
				break;
			}
		if (i%2 == 0){
			printf ("occurences de ");
			}
		else {
			printf ("\n");
			}
		i ++;
		}
	}

char *conway (char *s){
	int i  = 0, j=0;
	int len = strlen(s);
	char cmp;
	char * ret = (char*)malloc((len*2)*sizeof(char));
	for (i=0; i < len; i++){
		cmp = '1';
		while (s[i] == s[i+1]){
			cmp ++;
			i ++;
			}
		ret[j] = cmp;
		ret [j+1] = s[i];
		j += 2;
		}
	return ret;
	}


void afficher_conway (unsigned int n){
	int i;
	char * s = malloc(sizeof(char));
	char * tmp;
	s[0] = '1';
	for (i = 0; i < n; i++){
		imprimer(s);
		tmp = conway(s);
		free(s);
		s = tmp;
		}
	}

int main (void) {
	int n = 20;
	afficher_conway (n);
	return 0;
	}
