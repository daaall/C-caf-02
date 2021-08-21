#include<stdbool.h>



struct PILE {
	char champs;
	struct PILE *svt;
};typedef struct PILE PILE;


void initpile (PILE **tete){
	*tete=NULL;
}

void empiler (PILE **tete, char val){
	PILE *p;
	
	
	p=(PILE*)malloc(sizeof(PILE));
	p->champs=val;
	p->svt=*tete;
	*tete=p;
	
}
void depiler (PILE **tete, char *val){
	PILE *x;
	
	
	x=*tete;
	*val=x->champs;
	*tete=(*tete)->svt;
	free(x);
}

int sommet (PILE *tete){
	return tete->champs;
	
}
bool pile_vid ( PILE *tete){
	return (tete==NULL);
}

void afficher_pile (PILE *tete){
	char val;
	
	while (!pile_vid(tete)){
		depiler(&tete,&val);
		printf ("%c \n",val);
	}
	
	
}

