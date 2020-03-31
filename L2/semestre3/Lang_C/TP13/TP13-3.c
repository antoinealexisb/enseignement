#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _passager {
	unsigned long int numero_billet;
	struct _passager *suivant;
};
typedef struct _passager passager;
struct _attente {
	char numvol[10];
	passager *queue;
	passager *tete;
};
typedef struct _attente attente;

attente creer_vol(char nvol[])
{
	attente att;
	strcpy(att.numvol, nvol);
	att.queue = NULL;
	att.tete = NULL;
	return att;
}

passager *creer_passager (unsigned long billet)
{
	passager *pass = malloc(sizeof(passager));
	pass->numero_billet = billet;
	pass->suivant = NULL;
	return pass;
}

int est_vide(attente vol)
{
	return ((vol.queue == NULL) && (vol.tete == NULL));
}

void ajouter(attente *vol, unsigned long billet)
{
	passager *p = creer_passager(billet);
	if (est_vide(*vol))
	{
		vol->tete = p;
		vol->queue = p;
	} else  {
		vol->queue->suivant = p;
		vol->queue = vol->queue->suivant;
	}
}

void imprimer_liste(attente vol)
{
	printf("Les passagers:\n");
	passager *curr = vol.tete;
	while (curr != NULL)
	{
		printf("%lu\n", curr->numero_billet);
		curr = curr->suivant;
	}
}

int un_seul_passager(attente vol)
{
	return ((vol.tete == vol.queue) && !est_vide(vol));
}

unsigned long int retirer(attente *vol)
{
	if (!estvide(*vol))
	{
		passager res = vol->tete.numero_billet;
		if (un_seul_passager(*vol))
		{
			vol->tete = NULL;
			vol->queue = NULL;
		} else {
			vol->tete = vol->tete->suivant;
	}
	return res;
}

int main(void) 
{
	attente vol = creer_vol("0123456789");
	printf("%s%d\n\n", "Est vide: ", est_vide(vol));
	passager *pass1 = creer_passager(4444);
	passager *pass2 = creer_passager(5555);
	passager *pass3 = creer_passager(6666);
	printf("%s%lu\n%lu\n%lu\n\n", "Les passagers: \n", pass1->numero_billet,pass2->numero_billet,pass3->numero_billet);
	
	ajouter(&vol, 1111);
	ajouter(&vol, 2222);
	ajouter(&vol, 3333);
	imprimer_liste(vol);
	printf("Un seul passager: %d\n", un_seul_passager(vol));
	
	
}
