#include <stdio.h>
#include <stdlib.h>
#include "rppl_tab_din_elmnt.h"
#include <string.h>
#include <stdbool.h>
#include "rppl_tab_din.h"



int main (){
	int n;
	livre *tab;
	
	
	do{
	printf ("donnez la taille du tableau \n");
	scanf("%d",&n);
	}while(n<=0);
	
	tab=remplissage(n);
	affichage(tab,n);
	nb_dis(tab,n);
	nb_emprnt(tab,n);
}


