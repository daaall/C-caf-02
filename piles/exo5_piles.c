#include <stdio.h>
#include <stdlib.h>
#include "PILE.h"



PILE* supp(PILE *tete);
int main (){
	PILE *tete;
	noeud p;
	char c;
	
	init_pile (&tete);
	do {
		printf ("donnez le nom de la ville \n");
		scanf (" %s",p.nom);
		printf ("donnez la superficie de cette ville \n");
		scanf ("%f",&p.superficie);
		printf ("donnez le nb dhabitants de cette ville \n");
		scanf ("%d",&p.nb_hab);
		empiler(&tete,p);
		printf ("estce que vous voulez poursuivre ou pas (o/n) \n");
		scanf (" %c",&c);
	}while (c=='o');
	
	afficher_pile (tete);
	tete=supp(tete);
	printf ("APRES SUPPRESIION \n");
	afficher_pile(tete);
	
	
	
}

PILE* supp(PILE *tete){
	PILE *P1;
	int i=0;
	noeud var1,var2;
	init_pile(&P1);
	
	
	while(!pile_vide(tete)){
		if(i!=2){
			depiler (&tete,&var1);
			empiler (&P1,var1);
		}
		i++;
	}
	init_pile(&tete);
	
	while(!pile_vide(P1)){
		depiler (&P1,&var1);
		empiler (&tete,var1);
		
	}
	return tete;
} 


