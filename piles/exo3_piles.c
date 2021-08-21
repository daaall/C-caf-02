#include <stdio.h>
#include <stdlib.h>
#include "PILE.h"



int main (){
	int tab[]={1,2,3,4,5};
	int i,n=5;
	PILE *tete;
	initpile(&tete);
	
	for (i=0;i<n;i++){
		empiler(&tete,tab[i]);
	}
	
	i=0;
	while(!pile_vid(tete)){
		depiler(&tete,&tab[i]);
		i++;
	}
	for (i=0;i<n;i++)
		printf ("%d ",tab[i]);
	
	
}
