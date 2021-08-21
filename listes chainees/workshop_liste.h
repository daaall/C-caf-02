element * creation (){
	FILE *Fp,*Fim;
	char varp[10],varim[10];
	element *tete=NULL,*p,*q;
	float nbp,nbim;
	
	
	Fp=fopen("pair.txt","r");
	Fim=fopen("impair.txt","r");
	
	while (!feof(Fp) && !feof(Fim)){
		fgets(varp,10,Fp);
		fgets(varim,10,Fim);
		strtok(varp,"\n");
		nbp=atof(varp);
		strtok(varim,"\n");
		nbim=atof(varim);
		
		p=(element*) malloc(sizeof(element));
		
		p->moy=(nbp+nbim)/2;
		p->svt=NULL;
		if (tete==NULL)
			tete=p;
		else 
			q->svt=p;
			
		q=p;
	}
	
	fclose (Fp);
	fclose (Fim);
	return tete;
}



void affichage_liste(element *tete){
	element *p;
	
	p=tete;
	
	while (p!=NULL){
		printf ("%.2f ->",p->moy);
		
		p=p->svt;
	}
	printf ("NULL \n");
}

void suppression( float var,element **tete){
	element *p,*q;
	
	
	q=NULL;
	p=*tete;
	
	while (p!=NULL ){
		if(p->moy==var){
			
			if (p==*tete){
				printf ("teteeeeh \n");
				*tete=(*tete)->svt;
				free(p);
				p=*tete; 
			}else {
				q->svt=p->svt;
				free(p);
				p=q->svt;
			}
			
		}
		else {
			q=p;
			p=p->svt;
		}
	}
	
}


