#include<stdbool.h>

struct noeud {
	char nom[10];
	int nb_hab;
	float superficie;
};typedef struct noeud noeud;

struct PILE {
	noeud champs;
	struct PILE *svt;
};typedef struct PILE PILE;


void init_pile (PILE **tete){
	*tete=NULL;
}

void empiler (PILE **tete, noeud val){
	PILE *p;
	
	
	p=(PILE*)malloc(sizeof(PILE));
	p->champs=val;
	p->svt=*tete;
	*tete=p;
	
}
void depiler (PILE **tete,noeud  *val){
	PILE *x;
	
	
	x=*tete;
	*val=x->champs;
	*tete=(*tete)->svt;
	free(x);
}

noeud sommet (PILE *tete){
	return tete->champs;
	
}
bool pile_vide ( PILE *tete){
	return (tete==NULL);
}

void afficher_pile (PILE *tete){
	noeud val;
	
	while (!pile_vide(tete)){
		depiler(&tete,&val);
		printf ("%d \n",val.nb_hab);
		printf (" %s \n",val.nom);
		printf ("%.2f \n",val.superficie);
		
		printf ("\n");
		printf ("\n");
	}
	
	
}
