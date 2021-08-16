#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




struct element {
	int champ;
	struct element* suivant;
}; typedef struct element element;

element* remplissage (int n);
void affichage (element *tete);
bool verif(element *tete);
bool trouv(int val,element *tete);
void supp(int val,element *tete);

int main (){
	int n,val;
	element *tete;
	
	do{
		printf ("donnez la taille de la chaine \n");
		scanf ("%d",&n);
	}while (n<0);
	
	
	tete=remplissage(n);
	
	affichage (tete);
	
	if (verif(tete)==true)
		printf ("la liste est vide \n");
	else 
		printf ("la liste nest pas vide \n");
	
	
	printf ("donnez la val que vous recherchez \n");
	scanf ("%d",&val);
	if (trouv(val,tete)==true)
		printf ("la valeur existe dans la liste \n");
	else 
		printf ("la valeur nexiste pas dans la liste \n");
	printf ("donnez la valeur que vous voulez supp dans la liste \n");
	scanf ("%d",&val);
	supp(val,tete);
	affichage (tete);	
		
	
} 

element* remplissage (int n){
	int val,i;
	element * tete=NULL,*p,*q; 
	
	for (i=0;i<n;i++){
	
		p=(element*)malloc (sizeof (element));
		printf ("donnez une valeur \n");
		scanf("%d",&p->champ);
		if (tete==NULL){
			tete=p;
		}else q->suivant=p;
		
		q=p;
	} 
	if (tete!=NULL)
		p->suivant=NULL;
	return tete;

}

void affichage (element *tete){
	element* q;
	
	q=tete;
	while (q!=NULL){
		printf ("%d ->",q->champ);
		q=q->suivant;
	} 
	printf ("NULL \n");
}
bool verif(element *tete){
	
	
	return(tete==NULL);
	
}
bool trouv(int val,element *tete){
	element *q;
	bool trv=false;
	
	q=tete;
	while (q!=NULL && trv==false){
		if (q->champ==val)
			trv=true;
		q=q->suivant;

	}
	return trv;	
}
void supp (int val , element *tete){
	element *p,*q;
	
	q=NULL;
	p=tete;
	while (p!=NULL){
		if (p->champ==val){
			if (p==tete)
				tete=tete->suivant;
			else 
			
			q->suivant =p->suivant;
			free(p);
			p=q->suivant;
					
		}else  {
			q=p;
			p=q->suivant;
		}
		
		
	}
	
}



