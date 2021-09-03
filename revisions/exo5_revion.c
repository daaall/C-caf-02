#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PILE.h"

struct element {
	int val;
	struct element *svt; 
};typedef struct element element;



int main (){
	element *tete=NULL,*p,*q;
	int n,i,val;
	PILE *P;
	
	printf ("donnez la taille de la lite \n");
	scanf("%d",&n);
	//remplissage
	for (i=0;i<n;i++){
		p=(element *)malloc(sizeof(element));
		printf ("donnez une valeur a inserer dans la liste \n");
		scanf("%d",&val);
		p->val=val;
		p->svt=NULL;
		
		if(tete==NULL)
			tete=p;
		else 
			q->svt=p;
		
		q=p;		
		
	}
	
	//affichage 
	p=tete;
	
	while(p!=NULL){
		printf (" %d ->",p->val);
		
		p=p->svt;
	}
	printf ("NULL \n");
	
	
	init_pile(&P);
	p=tete;
	//remplisage de la file
	while(p!=NULL){
		empiler(&P,p->val);
		
		p=p->svt;
		
	}
	
	afficher_pile(P);
	
	
}





