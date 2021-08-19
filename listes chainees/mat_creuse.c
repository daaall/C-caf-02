#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mat_creuse_element.h"
#include "mat_creuse.h"



int main (){
	int mat [9][9];
	int i,j,n,val;
	element *tete;
	
	
	do {
		printf ("donnez les dimensions de la matrices \n");
		scanf ("%d",&n);
	}while (n<0 || n>9);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf ("donnez une valeurs \n");
			scanf ("%d",&val);
			mat[i][j]=val;
		}
	}
	
	for (i=0;i<n;i++){
	
		for (j=0;j<n;j++)
			printf (" %d ",mat[i][j]);
		printf ("\n");
		}
	
	
	*tete=remplissage ( n,mat);
	affichage_liste (tete);
	
	//retourner une val
	printf ("donnez le num de ligne de la val que vous voulez afficher \n");
	scanf ("%d",&i);
	printf ("donnez le num de colonne de la val que vous voulez afficher \n");
	scanf ("%d",&j);
	printf ("la valeur recherchee est : %d \n",affichage_val(i,j,tete));
	
	
	
}

