#include <stdio.h>
#include <stdlib.h>
#include "PILE.h"


int nb_element( PILE *tete);
int max (PILE *tete);
int min (PILE *tete);

int main (){
	PILE *tete;
	int n,i,val;
	
	
	
	initpile(&tete);
	printf ("donnez la taille de l pile \n");
	scanf ("%d",&n);
	for(i=0;i<n;i++){
		printf ("donnez une valeur a inserer dans la pile \n");
		scanf ("%d",&val);
		empiler( &tete,val);
	}
	
	afficher_pile (tete);
	printf ("\n");
	printf ("le nombre delements de cette pile est de : %d \n",nb_element(tete));
	printf ("le maximum de cette pile est de : %d \n",max(tete));
	printf ("le minimum de cette pile est de : %d \n",min(tete));
	
	
		
}

int nb_element( PILE *tete){
	int nb=0;
	int val;
	
	while (!pile_vide(tete)){
		
		nb++;
		depiler(&tete,&val);
	}
	
	return nb;
}
int max (PILE *tete){
	int M;
	int val;
	
	depiler (&tete,&M);
	while (!pile_vide(tete)){
		depiler (&tete,&val);
		if(M<val)
			M=val;
	}
	
	return M;
}

int min (PILE *tete){
	int MI;
	int val;
	
	depiler (&tete,&MI);
	while (!pile_vide(tete)){
		depiler (&tete,&val);
		if(val<MI)
			MI=val;
	}
	return MI;
}

