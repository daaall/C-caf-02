#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "type_reservation.h"
#include "reservation_hotel.h"


int main (){
	element *tete=NULL;
	element *p,*q;
	char rep;
	int num;
	bool trouv=false;
	
	
	do {
		p=(element *)malloc(sizeof(element));
		p->val=lire_reservation();
		p->svt=tete;
		tete=p;
		printf ("est-ce que vous voulez ajouter une autre reservation ( o/n) \n");
		scanf (" %c",&rep);
	}while (rep=='o');
	
	aff(tete);
	
	printf ("calcule de la facture \n");
	printf ("donnez le num de la chambre a qui vous voulez calculerla facture \n");
	scanf ("%d",&num);
	
	p=tete;
	while (p!=NULL && trouv==false){
		if (p->val.num==num)
			trouv=true;		
		else 
		p=p->svt;
	}
	printf ("la facture de ce client est : %.2f \n",facture(p->val));
	
	trouv=false;
	printf ("affichage : \n");
	p=tete;
	while (p!=NULL){
		if (strcmp(p->val.pension,"all-inclusif")==0 && p->val.piscine==1)
			printf ("le num de la chambre ayant une pension all-inclusif et un supplement piscine : %d \n",p->val.num);
		p=p->svt;
	}
	
	
	printf ("\n");
	printf ("apres la suppresion des clients ayant comme pension le ptit dej \n");
	p=tete;
	q=NULL;
	while (p!=NULL){
		
		if (strcmp(p->val.pension,"petit_dej")==0){
			if (p==tete){
				tete=tete->svt;
				free(p);
				p=tete;
			}else{
				q->svt=p->svt;
				free(p);
				p=q->svt;
			}
		}else{
			q=p;
			p=p->svt; 
		}
		
	
	}
	aff(tete);
	
}


