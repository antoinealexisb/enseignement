#include <stdio.h>
#include <string.h>

int majuscule (const char c);
int compte_majuscules (const char *s);

int majuscule (const char c) {
	return (c >= 'A' && c <= 'Z');
	}

int compte_majuscules (const char *s) {
	int cmp = 0, i = 0;
	while (s[i] != '\0'){
		cmp += majuscule(s[i]);
		i ++;
		}
	return cmp;
	}

int main (void) {
	char ch[] = "PROUT prout prout que je t'aime";
	printf ("Combien %d \n", compte_majuscules(ch));
	return 0;
	}
