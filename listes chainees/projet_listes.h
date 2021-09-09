

void remplissage (int n, etud **tete){
	etud *q,*p;
	int i, nb_eval,j;
	evaluation *a,*b;
	float s=0,s_coef=0;
	
	
	*tete=NULL;
	for (i=0;i<n;i++){
		p=(etud*)malloc(sizeof(etud));
		printf ("donnez le nom de letudiant \n");
		scanf (" %s",p->nom);
		printf ("donnez son prenom \n");
		scanf (" %s",p->prenom);
		printf ("donnez son identifiant \n");
		scanf ("%d",&p->id);
		p->svt=NULL;
		printf ("donnez le nb deval passees par cet etudiant \n");
		scanf ("%d",&nb_eval);
		p->eval=NULL;
		
		s=0;
		s_coef=0;
		for (j=0;j<nb_eval;j++){
			a=(evaluation*)malloc(sizeof(evaluation));
			
			
			printf ("donnez la note du module \n");
			scanf ("%f",&a->note);
			printf ("donnez le coef de ce module \n");
			scanf ("%d",&a->coef);
			
			s=s + (a->note)*(a->coef);
			//printf ("la somme des notes est: %.2f \n",s);
			s_coef= s_coef + a->coef;
			//printf ("la somme des coefficients est: %.2f \n",s_coef);
			a->suivant=NULL;			
			if(p->eval==NULL)
				p->eval=a;
			else 
				b->suivant=a;
			
			b=a;
		}
		if(p->eval==NULL)
			p->moy=0;
		else
			p->moy =s / s_coef;
		printf ("la moyenne de cet etudiant est de : %f \n",p->moy);
		
		if(*tete==NULL)
			*tete=p;
		else 
			q->svt=p;
		
		q=p;
	}
	
	
}

void affichage( etud *tete){
	etud *p;
	evaluation *q;
	
	p=tete;
	while (p!=NULL){
		printf (" %s ",p->nom);
		printf (" %s ",p->prenom);
		printf ("%.2f ",p->moy);
		printf (" eval -> \n");
		q=p->eval;
		while (q!=NULL){
			printf (" la note : %.2f ",q->note);
			printf ("le coef : %d ->",q->coef);
			q=q->suivant;	
		}
		p=p->svt;
		printf("NULL \n");
	}
	printf ("NULL \n");
	
} 


void creation_fichier (etud *tete, FILE *F){
	etud *p;
	bool verif;
	etud1 etudiant;
	
	p=tete;
	
	
	while (p!=NULL){
		strcpy(etudiant.nom,p->nom);
		strcpy(etudiant.prenom,p->prenom);
		etudiant.moy=p->moy;
		etudiant.id=p->id;
		fwrite (&etudiant,sizeof(etud1),1,F);
		
		p=p->svt;
	}
	if(F==NULL)		
		printf ("le fichier na pas ete cre correctement \n");
	else 
		printf ("le fichier a ete cre correctement \n");
}

void maj_moy ( etud *tete){
	etud *p;
	evaluation *q,*a,*b;
	int id,i,nb_eval,j, s_coef=0;
	float s=0;
	bool trv=false;
	
	
	p=tete;
	
	printf("donnez l id de cet etudiant \n");
	scanf("%d",&id);
	while (p!=NULL && trv==false){
		
		if(p->id==id){
			p->eval=NULL;

			q=p->eval;
			printf ("donnez le nb deval passees par cet etudiants \n");
			scanf ("%d",&nb_eval);
			printf ("avant la boucle for \n");
				
			s=0;
			s_coef=0;
			for (j=0;j<nb_eval;j++){
				a=(evaluation*)malloc(sizeof(evaluation));
				
				
				printf ("donnez la note du module \n");
				scanf ("%f",&a->note);
				printf ("donnez le coef de ce module \n");
				scanf ("%d",&a->coef);
				
				s=s + (a->note)*(a->coef);
				//printf ("la somme des notes est: %.2f \n",s);
				s_coef= s_coef + a->coef;
				//printf ("la somme des coefficients est: %.2f \n",s_coef);
				a->suivant=NULL;			
				if(p->eval==NULL)
					p->eval=a;
				else 
					b->suivant=a;
				
				b=a;
			}
			if(p->eval==NULL)
				p->moy=0;
			else
				p->moy =s / s_coef;
			printf ("la moyenne de cet etudiant est de : %f \n",p->moy);
			trv=true;
		}
		
		p=p->svt;
	}
	
	if(trv==false)
		printf("l id nexiste pas \n");
}


void creation_tab(){
	
	etud1 val;
	int i;
	FILE *F;
	etud1 *tab,x;
	int n=0;
	
	F=fopen("fich_etud.txt","r");
	
	while(fread(&val,sizeof(etud1),1,F)){
		n++;
		
	}
	fclose(F);
	tab=(etud1 *)malloc(n*sizeof(etud1));
	F=fopen("fich_etud.txt","r");
	
	i=0;
	
	while (fread(&val,sizeof(etud1),1,F) ){
	
		tab[i]=val;
		i=i+1;		
		
	}
	fclose(F);
	printf("XX creatiion \n");
	int j;
	
	F=fopen("fich_etud.txt","w");
	printf("%d",n);
	for (i=0;i<n-1;i++)
		for(j=1;j<n;j++){
			if((tab[i]).moy<(tab[j]).moy){
				x=tab[i];
				tab[i]=tab[j];
				tab[j]=x;
			}
		}
	printf("avant le for \n");
	
	for (i=0;i<n;i++){
		printf ("affichage tab[i] : %d \n",tab[i].id);
		fwrite(&tab[i],sizeof(etud1),1,F);
	
	}
	printf ("apres le for :) \n");
	
	fclose(F);

	
}

void affichage_tab ( etud1 *tab,int n){
	int i=0;
	
	printf ("le tableau : \n");
	printf ("la taille est : %d \n",n);
	for (i=0;i<n;i++){
		printf ("%d ",tab[i].id);
		
	}
	
}











void tri(etud1 *tab, int n){
	FILE *F;
	int i,j;
	etud1 x;
	
	
	F=fopen("fich_etud.txt","w");
	printf("%d",n);
	for (i=0;i<n-1;i++)
		for(j=1;j<n;j++){
			if((tab[i]).moy<(tab[j]).moy){
				x=tab[i];
				tab[i]=tab[j];
				tab[j]=x;
			}
		}
	printf("avant le for \n");
	for (i=0;i<n;i++){
		fwrite(&tab[i],sizeof(etud1),1,F);
	}
	printf ("apres le for :) \n");
	
	fclose(F);
}

void creation_fichier50 ( FILE **F1){
	FILE *F;
	int i=0,n=0;
	int m;
	etud1 val;
	
	F=fopen("fich_etud.txt","r");
	
	while(fread(&val,sizeof(etud1),1,F)){
		n++;
		
	}
	fclose(F);
	F=fopen("fich_etud.txt","r");
	*F1=fopen("fich_etud2.txt","w");
	m=n/2;
	
	
	while (i<m){
		fread(&val,sizeof(etud1),1,F);
		fwrite(&val,sizeof(etud1),1,*F1);
		i++;
	}
	
	fclose(F);
	fclose(*F1);
}


void affichage_F ( FILE *F){
	 etud1 etudiant;
	
	printf("afichage \n");
	while (fread(&etudiant,sizeof( etud1),1,F)){
		
		printf ("%d \n",etudiant.id);
		printf (" %s \n",etudiant.nom);
		printf (" %s \n",etudiant.prenom);
		printf ("%f \n",etudiant.moy);
	}

}





