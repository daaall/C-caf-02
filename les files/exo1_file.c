#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FILE.h"



bool  recherche ( File tete, int val);
bool suppression(File *tete, int val);
void afficher_file (File tete);
void remplir(File *tete,int n);
void suppression_position (File *tete, int k);
void insertion ( File *tete, int k, int val);
File fusion(File A,File B);

int main (){
	File tete,A,B,C;
	int val,choix,n,k;
	
	printf ("MENU \n");
	
	
	init_file(&tete);
	
	while (1){
		printf ("1-enfiler une valeur dans la file \n");
		printf ("2-defiler une val de la file \n");
		printf ("3-voir le premier element de la file \n");
		printf ("4-voir si la tete est vide \n");
		printf ("5-rechercher une valeur \n");
		printf ("6-supprimer une valeur de la file \n");
		printf ("7-remplir la file \n");
		printf ("8-aficher la file \n");
		printf ("9-suppression par position \n");
		printf ("10-inserer une valeur par position \n");
		printf ("11-fusionner 2files A et B \n");
		
		
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
			case 6 : printf ("donnez la valeur que vous souhaitez supprimer de la file\n");
					 scanf("%d",&val);
					 if (suppression(&tete,val)==true)
					 	printf ("la suppressiona ete effectuee avec succes \n");
					 else 
					 	printf ("cette valeur nexiste paas initialement dans la file \n");
			break;
			case 7 : printf("donnez la taille de la file \n");
					 scanf("%d",&n);
					 remplir(&tete,n);
			break;
			case 8 : afficher_file(tete);
			break;
			case 9 : printf ("donnez la position de lelement que vous souhaitez supprimer \n");
					 scanf("%d",&k);
					 suppression_position(&tete,k);
			break;
			case 10 : printf ("donnez la position ou vous voullez inserer une valeur \n");
					  scanf ("%d",&k);
					  printf ("donnez la valeur que vous voulez inserer dans cette valeur \n");
					  scanf ("%d",&val);
					  insertion (&tete,k,val);
			break;
			case 11 : 
					 printf("donnez la taille de la file   A \n");
					 scanf("%d",&n);
					 remplir(&A,n);
					 printf ("affichage de la file A  \n");
					 afficher_file(A);
					 printf("donnez la taille de la file B \n");
					 scanf("%d",&n);
					 remplir(&B,n);
					 afficher_file(B);
					 
					 C=fusion(A,B);
					 printf ("aafichage de la file fusionnee \n");
					 afficher_file(C);
			break;
			
			default : printf ("ce num nexiste po dans le menu \n");
			break;

		}
		
		
	}
}
	
bool recherche ( File tete, int val){
	File p;
	bool trouv=false;
	int nb;
	
	p=tete;
	
	while (!file_vide(tete) && trouv==false){
		
		
		defiler(&tete,&nb);
		
		
		if(val==nb){
			trouv=true;
		}
	
		
	}
	
	return trouv;
}

bool suppression(File *tete, int val){
	File p;
	int nb;
	bool trouv=false;
	
	init_file(&p);
	
	while(!file_vide(*tete)){
		defiler(&(*tete),&nb);
		if(nb!=val)
			enfiler(&p,nb);
		else 
			trouv=true;
	}
	
	init_file(&(*tete));
	while (!file_vide(p)){
		defiler (&p,&nb);
		enfiler (&(*tete),nb);
	}
	return trouv;
}

void remplir(File *tete,int n){
	int i,val;
	
	init_file(&(*tete));
	for (i=0;i<n;i++){
		printf("donnez une valeur a enfiler dans la file \n");
		scanf("%d",&val);
		enfiler(&(*tete),val);
	}
	
}


void afficher_file (File tete){
	int nb;
	
	while (!file_vide(tete)){
		defiler(&tete,&nb);
		printf("%d \n",nb);
	}
	
	
}

void suppression_position (File *tete, int k){
	int p=0,val;
	File q;
	init_file(&q);
	
	
	
	while(!file_vide(*tete)){
		defiler(&(*tete),&val);
			
		if (p!=k)
		enfiler (&q,val);
		
		p++;			
	}
	
	init_file(&(*tete));
	while(!file_vide(q)){
		defiler(&q,&val);
		enfiler(&(*tete),val);
	}
	
}

void insertion ( File *tete, int k, int val){
	int p=0,nb;
	File q;
	init_file(&q);
	
	printf ("avant le 1er while \n");
	while(!file_vide(*tete) && p<k){
		defiler(&(*tete),&nb);
		enfiler(&q,nb);
		p++;
	}
	printf ("fin du 1er while \n");
	printf ("\n");
	enfiler (&q,val);
	
	printf ("avant le 2eme while \n");
	while (!file_vide(*tete) ){
		defiler (&(*tete),&nb);
		enfiler (&q,nb);
		
	}
	printf ("apres le 2eme while \n");
	init_file(&(*tete));
	while(!file_vide(q)){
		defiler(&q,&val);
		enfiler(&(*tete),val);
	}
	
	
}
File fusion(File A,File B){
	int nba,nbb;
	File C;
	
	init_file(&C);
	
	defiler(&A,&nba);
	defiler(&B,&nbb);
		
		
	while (!file_vide(A) && !file_vide(B)){
		
		if(nba<nbb){
			enfiler(&C,nba);
			defiler (&A,&nba);	
		}else if (nba>nbb){
			enfiler (&C,nbb);
			defiler (&B,&nbb);
			
		}else {
			enfiler (&C,nba);
			enfiler (&C,nbb);
			defiler (&A,&nba);
			defiler (&B,&nbb);
		}	
	}
	if(!file_vide(A)){
		
		while (!file_vide(A)){
			if(nbb<nba){
				enfiler (&C,nbb);
				nbb=nba;
			}else{
				enfiler (&C,nba);
				defiler (&A,&nba);
				}
		}
		
		enfiler (&C,nba);
	}
	
	if (!file_vide(B)){
			while (!file_vide(B)){
				if(nba<nbb){
					enfiler (&C,nba);
					nba=nbb;	
				}else{
					enfiler (&C,nbb);
					defiler (&B,&nbb);
				}
			}
		enfiler (&C,nbb);
	}
	return C;
}




