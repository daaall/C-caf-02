#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PILE.h"

void remplissage(PILE **val,PILE **coef,int n);
float moyenne(PILE *val,PILE *coef);


int main (){
	PILE *val,*coef;
	int n;
	
	printf("donnez la taille des piles \n");
	scanf("%d",&n); 
	remplissage(&val,&coef,n);
	printf ("affichage de la pile VAL  \n");
	afficher_pile(val);
	printf ("affichage de la pile COEF \n");
	afficher_pile(coef);
	
	printf ("la moyenne des deux piles est : %.2f \n",moyenne(val,coef));	
}
void remplissage(PILE **val,PILE **coef,int n){
	int i=0;
	float vall,coeff;
	
	
	init_pile ( &(*val));
	init_pile ( &(*coef));

	while (i<n){
		printf ("donnez une valeur \n");
		scanf("%f",&vall);
		empiler(&(*val),vall);
		printf ("donnez son coefficient \n");
		scanf("%f",&coeff);
		empiler(&(*coef),coeff);
		
		i++;
	}
	
	
}

float moyenne(PILE *val,PILE *coef){
	float S=0;
	float vall,somme=0,coeff;
	
	
	
	while (!pile_vide(val) && !pile_vide(coef)){
		
		depiler(&val,&vall);
		
		depiler(&coef,&coeff);
		
		somme=somme+(vall*coeff);
		S=S+coeff;
		

	}
	
	return somme/S;
}


