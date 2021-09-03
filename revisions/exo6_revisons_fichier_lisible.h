void remplissage (){
	int tab1[6]={1,2,3,7,9,11};
	int i;
	FILE *F=fopen("fichier1.txt","w");
	
	
	for (i=0;i<6;i++){
		fprintf(F,"%d",tab1[i]); /*les fichiers lisibles n'acceptent que de chaine de caracteres pour cela nous avons convertit l'int en chaine de caractere en le
		                             mettant entre les ""<- en C : chaine de char et ''<-en C caractere       
		*/
		fputs("\n",F);
		
	}
	fclose(F);
	
	int tab2[8]={7,8,5,1,3,6,2,9};
	F=fopen("fichier2.txt","w");


	for (i=0;i<8;i++){
		fprintf(F,"%d",tab2[i]);
		fputs("\n",F);
		
	}
	fclose(F);
	
}

void affichage (char nom[40]){
	int val;
	char chaine[30];
	FILE *F;
	
	
	F=fopen(nom,"r");
	
	while(fgets(chaine,30,F)){// fgets lit les chaines de caractere (toute la ligne) elle s'arrete au niveau du \n
	
	
		
		strtok(chaine,"\n");// on utilise strtok pour exclure le \n qui a ete lu par fgets pour assurer l'arret de la fct
		val=atoi(chaine);//les var lues sont de type chaine de char alor qu'on veut afficher des int, pour cela on les convertit en int avec atoi
		printf (" %d ",val);
	}
	printf ("\n");
	fclose(F);
	
}

bool recherche (char nom[40], int val){
	char chaine[30];
	int nb;
	bool trouv=false;
	FILE *F;
	F=fopen(nom,"r");
	
	while(fgets(chaine,30,F) && trouv==false){
		strtok(chaine,"\n");
		nb=atoi(chaine);
		if(nb==val)
			trouv=true;
			
		
	}
	
	return trouv;
}

void fusion (char nom1[40], char nom2[40]){
	FILE *F1,*F2,*F3;
	char chaine[30];
	int nb;
	
	F1=fopen(nom1,"r");
	F3=fopen("fichier3.txt","w");
	F2=fopen(nom2,"r");
	
	while (fgets(chaine,30,F1)){
		
		fputs(chaine,F3);//on ecrit la chaine dans le fichier sans les "" prcq elle est deja de nature chaine donc pas besoin de les rajouter
	}
	fclose(F1);
	
	while(fgets(chaine,30,F2)){
		
		strtok(chaine,"\n");
		nb=atoi(chaine);
		
		if(recherche("fichier1.txt",nb)==false){
			fputs(chaine,F3);
			fputs("\n",F3);	
		}
	}
	fclose(F2);
	fclose(F3);
	
}



