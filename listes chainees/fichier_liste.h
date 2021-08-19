liste* remplissage (int n){
	liste *p,*q,*tete=NULL;
	int i;
	
	
	for (i=0;i<n;i++){
		p=(liste*)malloc(sizeof(liste));
		printf ("donnez le nb \n");
		scanf ("%d",&p->nb);
		printf ("donnez son nb de reccurence \n");
		scanf ("%d",&p->nb_recc);
		p->svt=NULL;
		
		if (tete==NULL)
			tete=p;
		else 
			q->svt=p;
			
		q=p;
	}
	
	return tete;
	
}

void affichage (liste *tete){
	liste *p;
	
	p=tete;
	
	while (p!=NULL){
		printf ("%d / %d ->",p->nb,p->nb_recc);
	
	p=p->svt;
	}
	printf ("NULL \n");
	
}
void creation(liste *tete){
	liste *p;
	FILE *F;
	int i;
	
	
	F=fopen("fichier_liste.txt","w");
	p=tete;
	
	while (p!=NULL){
		for(i=0;i<p->nb_recc;i++){	
			fprintf  (F,"%d",p->nb);
			
		}
		fprintf(F,"%d",0);
		fputs("\n",F);
		p=p->svt;
		
	}
	fclose (F);
	
}


void aff_fichier(){
	FILE *F;
	char nb;
	
	F=fopen("fichier_liste.txt","r");
	while (!feof(F)){
		nb=fgetc(F);
		printf ("%c",nb);	
	}
	fclose (F);
}




