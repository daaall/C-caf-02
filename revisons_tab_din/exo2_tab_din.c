#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct actr {
	char *nom;
};typedef struct actr actr;



struct film {
	char *nom;
	char *directeur;
	actr *acteur;
	char *date;	
	int num_salle;
	int nb_dact;
	
};typedef struct film film;

void remplissage(film *tab);

int main (){
	film *tab;
	
		remplissage(tab);
}

void remplissage(film *tab){
	char c;
	film flm;
	int i,n,j,m;
	time_t k;
	
	
	do {
		printf("donnez la taille du tableau \n");
		scanf ("%d",&n);
	}while(n<=0);
	
	tab=(film*)malloc(n*sizeof(film));
	for(i=0;i<n;i++){
		printf ("donnez le nom du film \n");
		flm.nom=(char*)malloc(sizeof(char));
		scanf(" %s",flm.nom);
		
		printf ("quel est le directeur de ce film \n");
		flm.directeur =(char*)malloc(sizeof(char));
		scanf(" %s",flm.directeur);
		
		printf ("donnez le numero de la salle \n");
		scanf("%d",&flm.num_salle);
		
		printf ("donnez le nombre dacteurs participants dans ce film \n");
		scanf("%d",&flm.nb_dact);
		
		flm.acteur=(actr*)malloc(sizeof(actr));
		
		for(j=0;j<flm.nb_dact;j++){
			printf ("donnez le nom de lacteur \n");
			flm.acteur[j].nom=(char*)malloc(sizeof(char));
			scanf(" %s",flm.acteur[j].nom);
				
		}
		
		flm.date=(char*)malloc(sizeof(char));
			
		time(&k);
		flm.date=ctime(&k);
		
		tab[i]=flm;
	}
	
	for(i=0;i<n;i++){
		printf("le nom du film : %s  \n",tab[i].nom);
		printf ("le directeur du film est :  %s \n",tab[i].directeur);
		printf ("le numro de la salle est :  %d \n",tab[i].num_salle);
		printf ("la date de diffusion est :  %s \n",tab[i].date);
		
		for(j=0;j<tab[i].nb_dact;j++){
			printf (" lacteur :  %s  \n",tab[i].acteur[j].nom);
		}
		
		
	}
		
	
}





