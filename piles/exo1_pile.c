#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"PILE.h"




int main (){
	int val;	
	PILE *tete;
	
	initpile(&tete);
	empiler(&tete,4);
	empiler(&tete,15);
	empiler(&tete,8);
	
	afficher_pile(tete);
	
	depiler(&tete,&val);
	
	printf("la val de depiler est : %d \n",val);
	printf ("afficher la pile \n");
	afficher_pile(tete);
	printf ("la valeur du sommet est : %d",sommet(tete));
}



