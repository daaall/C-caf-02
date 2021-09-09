
livre * remplissage (int n){
	livre *tab;
	int i;
	
	tab=(livre *)malloc(n* sizeof(livre));
	
	
	for(i=0;i<n;i++){
		getchar();
		tab[i].nom=(char *)malloc(sizeof(char));
		printf ("donnez le nom du livre \n");
		gets(tab[i].nom);
		
		printf ("donnez le nb de livre initial \n");
		scanf("%d",&tab[i].nb_init);
		do{
		printf ("donnez le nombre de livre courants \n");
		scanf("%d",&tab[i].nb_cour);
		}while(tab[i].nb_cour>tab[i].nb_init);
	}
	
	return tab;
}

void affichage (livre *tab  ,int n){
	int i,max_init,max_cour,max_nom;
	
	max_init=calcul_init(tab,n);
	max_cour=calcul_cour(tab,n);
	max_nom=calcul_nom(tab,n);
	
	if(strlen("nom")>max_nom)
		max_nom=strlen("nom");
		
	if(strlen("nombre initial")>max_init)
		max_init=strlen("nombre initial");
	
	if(strlen("nombre courant")>max_cour)
		max_cour=strlen("nombre courant");
		
	
	
	printf ("nom");
	if(strlen("nom")<max_nom){
		int c=max_nom-strlen("nom");
		for(i=0;i<c;i++){
			printf (" ");
		}
	}
	printf ("|");
	
	printf ("nombre initial");
	if(strlen("nombre initial")<max_init){
		int d=max_init-strlen("nombre initial");
		for(i=0;i<d;i++){
			printf (" ");
		}
	}
	printf ("|");
	
	printf ("nombre courant");
	if(strlen("nombre courant")<max_cour){
		int e=max_cour-strlen("nombre initial");
		for(i=0;i<e;i++){
			printf (" ");
		}
	}
	
	printf ("|");
	
	printf ("\n");
	int p;
	char var_init[max_init],var_cour[max_cour];
	int j;
	
	for(j=0;j<n;j++){
		printf ("%s",tab[j].nom);
		if(strlen(tab[j].nom)<max_nom){
			p=max_nom-strlen(tab[j].nom);
			for (i=0;i<p;i++){
				printf (" ");
			}	
		}
		printf ("|");
		
		printf ("%d",tab[j].nb_init);
		sprintf(var_init,"%d",tab[j].nb_init);
		if(strlen(var_init)<max_init){
			p=max_init-strlen(var_init);
			
			for (i=0;i<p;i++){
				printf (" ");
			}	
		}
		
		printf ("|");
		printf ("%d",tab[j].nb_cour);
		sprintf (var_cour,"%d",tab[j].nb_cour);
		
		if(strlen(var_cour)<max_cour){
			p=max_cour-strlen(var_cour);
			
			for (i=0;i<p;i++){
				printf (" ");
			}	
		}
		printf ("|");
		printf ("\n");
		
	}
	
}

int calcul_init (livre *tab,int n){
	int nb_chiffre;
	int i,nb_max=0;
	int c;
	
	for(i=0;i<n;i++){
		nb_chiffre=0;
		c=(tab[i].nb_init);
		while(c!=0){
			nb_chiffre++;
			c=c/10;
		}
		
		if(nb_chiffre>nb_max)
			nb_max=nb_chiffre;
	}
	
	return nb_max;
	
}

int calcul_cour (livre *tab, int n){
	int nb_chiffre;
	int i,nb_max=0;
	int c;
	
	for(i=0;i<n;i++){
		nb_chiffre=0;
		c=(tab[i].nb_cour);
		while(c!=0){
			nb_chiffre++;
			c=c/10;
		}
		
		if(nb_chiffre>nb_max)
			nb_max=nb_chiffre;
	}
	
	return nb_max;
	
	
}

int calcul_nom (livre *tab,int n){
	int nb_lettre;
	int i,nb_max=0;
	
	for(i=0;i<n;i++){
		nb_lettre=strlen(tab[i].nom);
		
		if(nb_lettre>nb_max){
			nb_max=nb_lettre;
		}
		
		
	}
	
	return nb_max;
}

void nb_dis (livre *tab, int n){
	char nom[20];
	int i;
	bool trouv=false;
	
	getchar();
	printf ("donnez le nom du livre dont vous voulez savoir le stockage \n");
	gets(nom);
	
	for (i=0;i<n && trouv==false;i++ ){
		if(strcmp(nom,tab[i].nom)==0){
			trouv=true;
			printf ("le nb de livre restant eyt de : %d \n",tab[i].nb_cour);
			
		}
		
	}
	if(trouv==false)
		printf ("ce livre nexiste pas dans le tableau \n");	
}
void nb_emprnt(livre *tab,int n){
	int i,nb;
	bool trouv=false;
	char nom[20];
	
	printf ("donnez le nom du livres dont vous voulez savoir le nb des empreuntes \n");
	gets(nom);
	
	for(i=0;i<n && trouv==false;i++){
		if(strcmp(nom,tab[i].nom)==0){
			trouv=true;
			nb=tab[i].nb_init - tab[i].nb_cour;
		}
		
	}	
	if(trouv==false)
		printf ("le nom du livre nexiste pas dans le tableau \n");
	else 	
		printf ("le nb de livre empruntes est de : %d \n",nb);
	
}
