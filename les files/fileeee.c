#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FILE.h"



bool  recherche ( File *tete, int val);

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
		printf ("5-rechercher une valeur \n");
		
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
			break;		
			case 5 : printf ("donnez la valeur que vous vouler rechercher \n");
					 scanf ("%d",&val);
					 if ( recherche(tete,val)==true)
					 	printf ("la valeur existe dans la file \n");
					 else 
					 	printf ("la valeur nexiste pas dans la file \n");
			break;	 
			
		}
		
		
	}
	
bool recherche ( File *tete, int val){
	File *p;
	bool trouv=false;
	int nb;
	

	while (!file_vide(tete) && trouv==false){
		defiler(&tete,&nb);
		if(val==nb){
			trouv=true;
		}
		
	}
	
	return trouv;
}
	
	
	
	
	
	
}
