#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FILE.h"



int main (){
	File *tete;
	int val,choix;
	
	printf ("MENU \n");
	
	
	init_file(&tete);
	
	while (1){
		printf ("1-enfiler une valeur dans la file \n");
		printf ("2-defiler une val de la file \n");
		printf ("3-voir le premier element de la file \n");
		printf ("4-voir si la tete est vide \n");
		
		printf ("introduisez votre choix \n");
		scanf ("%d",&choix);
		
		switch(choix){
			
			case 1 : printf ("donnez la valeur que vous voulez enfiler \n");
					 scanf ("%d",&val);
					 enfiler (&tete,val);
			break;
			case 2 : defiler(&tete,&val);
					 printf ("la valeur qu'on a defile est : %d \n",val);
			break;
			case 3 : printf ("le premier element de la file est : %d \n",tete_file(tete));
			break;
			case 4 : if (file_vide(tete)==true)
						printf ("la file est vide \n");
					 else 
					 	printf ("la tete nest pas vide  \n");		
			
			
		}
		
		
	}
	
	
	
	
}
