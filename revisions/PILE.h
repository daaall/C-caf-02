#include<stdbool.h>

struct PILE {
	int champs;
	struct PILE *svt;
};typedef struct PILE PILE;


void init_pile (PILE **tete){
	*tete=NULL;
}

void empiler (PILE **tete, int val){
	PILE *p;
	
	
	p=(PILE*)malloc(sizeof(PILE));
	p->champs=val;
	p->svt=*tete;
	*tete=p;
	
}
void depiler (PILE **tete,int *val){
	PILE *x;
	
	
	x=*tete;
	*val=x->champs;
	*tete=(*tete)->svt;
	free(x);
}

int sommet (PILE *tete){
	return tete->champs;
	
}
bool pile_vide ( PILE *tete){
	return (tete==NULL);
}

void afficher_pile (PILE *tete){
	int val;
	
	while (!pile_vide(tete)){
		depiler(&tete,&val);
		printf ("%d \n",val);
		printf ("\n");
		printf ("\n");
	}
	
	
}

