#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FILE.h"

void remplissage(File *F,int n);
void affichage_file(File F);
void mode(File F,int *tab,int *i);


int main (){
	File F;
	int n,i,val;
	int tab[5];
	
	printf ("donnez la taille de la file \n");
	scanf("%d",&n);
	
	init_file(&F);
	remplissage(&F,n);
	affichage_file(F);
	
	mode(F,tab,&n);
	for(i=0;i<n;i++)
		printf ("  %d  ",tab[i]);
	
	
	
}

void remplissage(File *F,int n){
	int i,val;
	
	
	for(i=0;i<n;i++){
		printf ("donnez une valeur a inserer dans la file \n");
		scanf("%d",&val);
		
		enfiler(&(*F),val);
		
	}
	
}

void affichage_file(File F){
	int val;
	
	while (!file_vide(F)){
		defiler(&F,&val);
		printf("%d",val);
		
	}
	printf("\n");
	
}

void mode(File F, int *tab,int *i){
	int nb_docc,val2,val,mode,nb_mode;
	File inter;
	*i=0;
	
	mode=tete_file(F);
	val=mode;
	nb_mode=1;
	nb_docc=1;
	
	
	
	while(!file_vide(F)){
		defiler(&F,&val);
		init_file(&inter);
		nb_docc=1;
	
		while(!file_vide(F)){
		
			defiler(&F,&val2);
			if(val==val2)
				nb_docc++;
			
			else
				enfiler(&inter,val2);
					
		}
	
		
		if(nb_docc>=nb_mode){
			nb_mode=nb_docc;	
			mode=val;
			tab[*i]=val;
			*i=*i+1;		
		}
		
		init_file(&F);
		
		while(!file_vide(inter)){
			defiler(&inter,&val);
			enfiler(&F,val);
		}
		}
		
	
}


