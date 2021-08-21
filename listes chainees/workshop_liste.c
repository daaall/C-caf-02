#include <stdio.h>
#include <stdlib.h>
#include "workshop_liste_element.h"
#include <string.h>
#include "workshop_liste.h"




int main () {
	element *tete;
	
	tete=creation();
	affichage_liste(tete);
	
	printf ("introduisez la val que vous voulez supp de la liste");
	float var;
	scanf("%f",&var);
	printf ("hello \n");
	
	suppression( var,&tete);
	printf ("fini supp \n");
	
	affichage_liste(tete);

}
