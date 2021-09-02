#include <stdio.h>
#include <stdlib.h>


struct liste {
	int val;
	struct liste *svt;
};typedef struct liste liste;


void affichage(liste *tete);
void remplissage (liste **tete,int n);
void tri( liste **tete, int n);

int main (){
	liste *tete;
	int n;
	
	printf ("donnez la taile initiale de votre liste \n");
	scanf("%d",&n);
	remplissage(&tete,n);
	affichage(tete);
	tri(&tete,n);
	affichage(tete);
}

void remplissage (liste **tete,int n){
	liste *p,*q;
	int i=0,val;
	*tete=NULL;
	
	while (i<n){
		printf ("donnez une valeur \n");
		scanf ("%d",&val);
		p=(liste *)malloc(sizeof(liste));
		p->val=val;
		p->svt=NULL;
		
		if(*tete==NULL)
			*tete=p;
		else 
			q->svt=p;
			
		q=p;
		
		i++;
	}
	
}


void affichage( liste *tete){
	
	
	printf ("[ ");
	while(tete!=NULL){
		printf(" %d | ",tete->val);
		tete=tete->svt;
	}
	
	printf ("] \n");
	
}

void tri( liste **tete, int n){
	liste *Lpos=NULL,*Lneg=NULL,*p,*q,*a,*b;
	int i=0;
	
	while (*tete!=NULL){
		if((*tete)->val<0){
			a=(liste*)malloc(sizeof(liste));
			a->val=(*tete)->val;
			a->svt=NULL;
			if(Lneg==NULL)
				Lneg=a;
			else 
				b->svt=a;
				
			b=a;
		}else{
		
			p=(liste*)malloc(sizeof(liste));
			p->val=(*tete)->val;
			p->svt=NULL;
			if(Lpos==NULL)
				Lpos=p;
			else
				q->svt=p;
				
			q=p;
		}
		*tete=(*tete)->svt;
	}
	
	b->svt=Lpos;
	*tete=Lneg;
}



