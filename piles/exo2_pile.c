#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PILE.h"
#include <string.h>



int main (){
	char *phrase= (char*)malloc(sizeof(char));
	int i;
	PILE *tete;
	char chaar;
	
	initpile(&tete);
	
	
	printf ("donnez une phrase \n");
	gets(phrase);
	
	bool trouv=false;
	for (i=0;i<strlen(phrase) && trouv==false;i++){
		if(phrase[i]=='('){
			empiler(&tete,phrase[i]);
			
		}
		if(phrase[i]==')')
			if (pile_vid(tete))
				trouv=true;
				
			else
				depiler(&tete,&chaar);
	}
	if (pile_vid(tete) && trouv==false)
		printf ("la phrase est bien parenthesee \n");
	else 
		printf ("la phrase nest pas bien parenthesee \n");
	
}
