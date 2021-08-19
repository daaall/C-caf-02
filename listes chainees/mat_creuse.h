//fonction qui retourne la val dune case (i,j) à partir de l liste

int affichage_val(int i,int j , element *tete){
	element *p;
	element2 *q;
	bool trouv=false;
	int x=0;
	
	
	p=tete;
	while (p!=NULL && trouv==false){
		q=p->colonne;
		while (q!=NULL){
			if (p->num_ligne == i && q->num_colonne==j){
				x=q->val;
				trouv=true;			
			}
		q=q->svt_colonne;	
		}
	p=p->svt_ligne;
	}
	
	return x;
}
	
void affichage_liste (element *tete)  {
	element *p;
	element2 *q;
	p=tete;
	
	
	//printf ("tete -> ");
	
	while (p!=NULL){
		printf ("%d->",p->num_ligne);
		q=p->colonne;
		while (q!=NULL){
			printf("%d - %d->",q->num_colonne,q->val);
			q=q->svt_colonne; 
		}
		printf ("NULL \n");
		p=p->svt_ligne;
	}
	
}
	
element* remplissage (int n,int mat[9][9]){
	int i,j;
	element *tete=NULL,*p,*q;
	element2 *t,*t2;
	
	
	for (i=0;i<n;i++){
	
		p=(element*)malloc (sizeof (element));
		p->num_ligne=i;
		p->colonne=NULL;
		/*j=0;
		while (j<n){
			if (mat[i][j]!=0){
				t=(element2 *)malloc(sizeof(element2))
			}
		}*/
		if (tete==NULL)
			tete=p;
		else q->svt_ligne=p;
		
		q=p;
	}
	
	if (tete!=NULL)
		p->svt_ligne=NULL;
	
	
	q=tete;
	while (q!=NULL){
		
		for (j=0;j<n;j++){
			if (mat[q->num_ligne][j]!=0){
					t=(element2*)malloc (sizeof(element2));
					t->val=mat[q->num_ligne][j];
					t->num_colonne=j;
					t->svt_colonne=NULL;
					if (q->colonne==NULL)
						q->colonne=t;
					
					else t2->svt_colonne=t;
					
					t2=t;		
			}
		}
	
		q=q->svt_ligne;	
	}
	
	
	return tete;
}


