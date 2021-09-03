#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "exo6_revisons_fichier_lisible.h"


int main (){
	
	
	remplissage();
	affichage("fichier1.txt");
	affichage("fichier2.txt");
	
	fusion("fichier1.txt","fichier2.txt");
	affichage("fichier3.txt");
	
}




