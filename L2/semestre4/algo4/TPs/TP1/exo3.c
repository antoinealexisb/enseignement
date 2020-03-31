#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int summ(int n){
	int r;
	while(n > 0){
		r += n % 10;
		n /= 10;
	}
	return r;
}

typedef struct contact{
	char nom[100];
	char num[11];
	struct contact *suivant;
} contact;

contact *cree_annuaire(){
	contact *c = malloc(sizeof(contact));
	strcpy(c->nom,"");
	strcpy(c->num,"");
	c->suivant = NULL;
	return c;
}

void ajoute_contact(contact *l, char *nom, char *num){
	if(!strcmp(nom,"") || strlen(num) != 10 || strlen(nom) > 100) return;
	if(!strcmp(l->nom,"")){
		strcpy(l->nom,nom);
		strcpy(l->num,num);
		return;
	}
	while(l->suivant != NULL) l = l->suivant;
	l->suivant = malloc(sizeof(contact));
	strcpy(l->suivant->nom, nom);
	strcpy(l->suivant->num, num);
}

void impp_contact(contact const *c){
	printf("nom : %s, numero : %s \n", c->nom, c -> num);
}

void impp_t_contact(contact const *c){
	contact *a = malloc(sizeof(contact));
	a = c;
	while (a->suivant != NULL)
	{
		impp_contact(a);
		a = (a->suivant);
	}
	impp_contact(a);
}

contact supprimer_contact_nom(contact *c, char *sup)
{
	contact *a = malloc(sizeof(contact));
	contact *prec = malloc(sizeof(contact));
	a = c;
	prec = a;
	while (c->suivant != NULL)
	{
		if (strcmp(c->nom,sup)==0){
			prec = c->suivant;
			printf("Hello\n");
		}
		prec = a;
		c->suivant = (c->suivant)->suivant;
	}
	return *c;
}

void supprimer_t_contact(contact **c)
{
	*c = cree_annuaire();
}

int main(){
  // int a;

  // printf("%p\n", &a);

	// printf("%d\n", summ(1999));

	contact *ann = cree_annuaire();

	ajoute_contact(ann,"marc1","1234567890");

	ajoute_contact(ann,"antoine2","2345678901");

	impp_t_contact(ann);
	ajoute_contact(ann,"antoine","2345678901");
	*ann = supprimer_contact_nom(ann, "antoine2");
	//supprimer_t_contact(&ann);
	impp_t_contact(ann);
  return 0;
}
