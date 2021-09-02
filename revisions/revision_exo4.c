#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "revision_exo4.h"






int main (){
	element *tete=NULL;
	int n;
	
	printf("Donnez la taille de vote liste \n");
	scanf("%d",&n);
	
	remplissage(&tete,n);
	affichage(tete);
	printf("lindice du maximum de cette liste est : %d \n",indice_max(tete));
	
	
	
	
	
}
