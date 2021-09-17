#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arbre {
	int cle;
	struct arbre* fgauche;
	struct arbre* fdroit;
};typedef struct arbre arbre ;


void recherche (arbre **p,arbre **prec,int val){
	
	
	while(*p!=NULL && (*p)->cle!=val){
		*prec=*p;
		if((*p)->cle<val){
			*p=(*p)->fdroit;
		}else 
			*p=(*p)->fgauche;
		
	}
	
}

void creation (arbre **racine,int n){
	int i,val;
	arbre *p,*prec;
	
	for(i=0;i<n;i++){
		printf ("donnez une val a inserer \n");
		scanf("%d",&val);
		p=*racine;
		prec=NULL;
		recherche(&p,&prec,val);
		if(p!=NULL){
			printf ("la valeur existe deja dans larbre \n");
		}else{
			p=(arbre*)malloc(sizeof(arbre));
			p->cle=val;
			p->fgauche=NULL;
			p->fdroit=NULL;
			if(prec==NULL){
				*racine=p;
			}else if(prec->cle > val){
				prec->fgauche=p;
			}else 
				prec->fdroit=p;
			
		}
			
		
	}
	
}

void affichage (arbre *racine){
	
	if (racine!=NULL){
		affichage(racine->fgauche);
		printf ("  %d  ",racine->cle);
		affichage(racine->fdroit);
	}
	
}

void max_min(arbre *racine,int *max,int *min){
	arbre *p,*q;
	
	p=racine;
	q=racine;
	
	while (p->fdroit!=NULL){
		p=p->fdroit;
	}
	*max=p->cle;
	
	while (q->fgauche!=NULL){
		q=p->fgauche;
	}*min=q->cle;
	
}

int main (){
	int n,min,max;
	arbre *racine=NULL;
	
	
	do{
		printf ("donnez la taille de larbre \n");
		scanf("%d",&n);
	}while (n<=0);
	
	creation(&racine,n);
	affichage (racine);
	printf ("\n");
	max_min(racine,&max,&min);
	printf ("le max de cet arbre est : %d  le min est :  %d  \n",max,min);
	
	
}



 
