reservation lire_reservation (){
	reservation val;
	int pis;
	
	printf ("donnez le numero de la chambre \n");
	scanf ("%d",&val.num);
	do {printf ("donnez le type de pension \n");
	scanf (" %s",val.pension);
	}while (strcmp(val.pension,"petit_dej")!=0 && strcmp(val.pension,"demi-pension")!=0 && strcmp (val.pension,"all-inclusif"));
	printf ("donnez la duree de sejour \n");
	scanf ("%d",&val.sejour);
	printf ("acces piscine \n");
	scanf ("%d",&pis);
	val.piscine =pis;
	
	return val;
}

void afficher_reservation (reservation val){
	
	printf ("le num de chambre : %d \n",val.num);
	printf ("le type de pension : %s \n",val.pension);
	printf ("la duree de sejour : %d \n",val.sejour);
	if(val.piscine)
		printf ("acces piscine : vrai \n");
	else 
		printf ("acces piscine : faux \n");	
		
}

float facture (reservation val){
	float fac=0;
	int petit_dej=3300,demi_pension=4500,all_inclusif=6500,piscine=1500;
	
	
	
	if (val.piscine)
			if (strcmp(val.pension,"petit_dej")==0)
			
			fac=(petit_dej+piscine)*val.sejour;
			else if (strcmp(val.pension,"demi_pension")==0)
				fac=(demi_pension+piscine)*val.sejour;
			else  
				fac=(all_inclusif+piscine)*val.sejour;
	else 
			if (strcmp(val.pension,"petit_dej")==0)
			
			fac=(petit_dej)*val.sejour;
			else if (strcmp(val.pension,"demi-pension")==0)
				fac=(demi_pension)*val.sejour;
			else  
				fac=(all_inclusif)*val.sejour;
				
	return fac;
}

void aff(element *tete){
	element *p;
	reservation val;
	
	p=tete;
	
	while (p!=NULL){
		val=p->val;
		printf ("le num de chambre : %d \n",val.num);
		printf ("le type de pension : %s \n",val.pension);
		printf ("la duree de sejour : %d \n",val.sejour);
		if(val.piscine)
			printf ("acces piscine : vrai \n");
		else 
			printf ("acces piscine : faux \n");	
		p=p->svt; 
	}
	
}



