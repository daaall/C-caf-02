typedef struct element element ;
struct element {
	int val;
	element *svt;
};


void remplissage (element **tete, int n){
	int i=0,val;
	element *q,*p;
	
	for(i=0;i<n;i++){
		p=(element*)malloc(sizeof(element));
		printf("donnez une valeur a inserer dans la lite \n");
		scanf("%d",&val);
		
		p->val =val;
		p->svt=NULL;
		
		if(*tete== NULL)
			*tete=p;
		else 
			q->svt=p;
			
		q=p;
		
	}
	
	
	
}

void affichage(element *tete){
	element *p=tete;
	
	
	while(p!=NULL){
		printf(" %d->",p->val);
		p=p->svt;
	}
	printf ("NULL");
}

int indice_max(element *tete){
	int indice_max,i=0,max=tete->val;
	
	
	while(tete!=NULL){
		i++;
		if(tete->val>max){
			max=tete->val;
			indice_max=i;
		}
		tete=tete->svt;
	}
	
	return indice_max;
	
}

 
