#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct client {
	char *nom;
	char *prenom;
	char *adresse;
	int num_compte;
	float solde;
};typedef struct client client;

void remplissage (client *tab,int n);
void affichage (client *tab,int n);
void calcule (client *tab,int n,float *STA,float *moy);
void taille (client *tab,int n ,int *max_nom, int *max_prenom, int *max_adresse);

int main (){
	client *tab;
	tab=(client *)malloc (sizeof(client));
	int n,choix;
	float STA,moy;
	
	
	printf ("donnez la taille du tab \n");
	scanf ("%d",&n);
	printf ("menu \n");
	
	while (1){
		printf ("1-remplissage du tableau \n");
		printf ("2-affichage du tableau \n");
		printf ("3-calculer la moyenne gnrlle et le STA \n");
		
		printf ("introduisez votre choix \n");
		scanf ("%d",&choix);
		
		switch(choix){
			case 1 : remplissage (tab,n);
			break;
			case 2 : affichage (tab,n);
			break;
			case 3 : calcule( tab,n,&STA,&moy);
					 printf (" le STA   est : %.2f \n",STA);
					 printf ("la moyenne generale est : %.2f \n",moy);
			break;
			default : printf ("ce nb nexiste pas dans le menu \n");
			break;
			
		}
	}
	
	
}

void remplissage (client  *tab,int n ){
	int i;
	
	
	
	for (i=0;i<n;i++){
		printf("donnez le nom du client \n");
		tab[i].nom=(char *)malloc(sizeof(char));
		scanf (" %s",tab[i].nom);
		printf ("donnez son prenom \n");
		tab[i].prenom=(char*)malloc(sizeof(char));
		scanf (" %s",tab[i].prenom);
		printf ("donnez son addresse \n");
		tab[i].adresse=(char *)malloc(sizeof(char));
		scanf (" %s",tab[i].adresse);
		printf ("donnez son solde \n");
		scanf ("%f",&tab[i].solde);
		printf ("donnez le numero de compte \n");
		scanf ("%d",&tab[i].num_compte);
	
	}
}

void affichage (client *tab,int n){
	int i,j;
	int max_n,max_p,max_a;
	int max_nc,max_s;
	
	
	taille(tab,n,&max_n,&max_p,&max_a);
	if (max_n<strlen("nom"))
		max_n=strlen("nom");
	if (max_p<strlen("prenom"))
		max_p=strlen("prenom");
	if (max_a<strlen("adresse"))
		max_a=strlen("adresse");
	
	max_nc=strlen("numero de compte");
	max_s=strlen("solde");
	
	
	printf (" | ");
	
	printf ("nom");
	for (i=0;i<(max_n-strlen("nom"));i++){
		printf (" ");
	}
	printf (" | ");
	printf ("prenom");
	for (i=0;i<(max_p-strlen("prenom"));i++){
		printf (" ");
	}
	printf (" | ");
	printf ("adresse");
	for (i=0;i<(max_a-strlen("adresse"));i++){
		printf (" ");
	}
	printf (" | ");
	printf ("numero de compte");
	for (i=0;i<(max_nc-strlen("numero de compte"));i++){
		printf (" ");
	}
	printf (" | ");
	printf ("solde");
	for (i=0;i<(max_s-strlen("solde"));i++){
		printf (" ");
	}

	printf ("\n");	
	for (j=0;j<n;j++){

		printf (" | ");
		printf ("%s",tab[j].nom);
		for (i=0;i<(max_n-strlen(tab[j].nom));i++){
			printf (" ");
		}
		printf (" | ");
		printf ("%s",tab[j].prenom);
		
		for (i=0;i<(max_p-strlen(tab[j].prenom));i++){
			printf (" ");
		}	
		printf (" | ");
		printf ("%s",tab[j].adresse);
		
		for (i=0;i<(max_a-strlen(tab[j].adresse));i++){
			printf (" ");
		}
		printf (" | ");
		printf ("%d",tab[j].num_compte);
		
		for (i=0;i<(max_nc-4);i++){
			printf (" ");
		}	
		printf (" | ");
		printf ("%.2f",tab[j].solde);
		
		for (i=0;i<(max_s-4);i++){
			printf (" ");
		}	
		printf ("\n");
	}
}

void calcule (client *tab,int n ,float *STA,float *moy){
	int i;
	
	*STA=0;
	*moy=0;
	
	for (i=0;i<n;i++){
		*STA=*STA+tab[i].solde;
	}
	*moy=*STA/n;
	
	
}

void taille (client *tab,int n ,int *max_nom, int *max_prenom, int *max_adresse){
	int i;
	
	
	*max_nom=0;
	*max_prenom=0;
	*max_adresse=0;
	
	for (i=0;i<n;i++){
		if (strlen(tab[i].nom)>*max_nom)
			*max_nom=strlen(tab[i].nom);
		if (strlen(tab[i].prenom)>*max_prenom)
			*max_prenom=strlen(tab[i].prenom);
		if (strlen(tab[i].adresse)>*max_adresse)
			*max_adresse=strlen(tab[i].adresse);		
	}
	
}
