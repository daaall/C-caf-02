#include <stdio.h>
#include <stdlib.h>




void remplissage (int *tab,int n);
void affichage ( int *tab,int n );
int position (int nb, int *tab,int n);

int main (){
	int *tab;
	tab =(int *) malloc(sizeof(int));
	int n;
	printf ("donnez la taille du tableau \n");
	scanf ("%d",&n);
	
	
	printf ("*********************\n");
	printf ("********MENU*********\n");
	printf ("**********************\n");
	
	while (1){
		printf ("1-remplir le tableau \n");
		printf ("2-afficher le tableau \n");
		printf ("3-position dun nb donn� \n");
		
		printf ("introduisez votre choix  \n");
		scanf ("%d",&choix);
		
		switch (choix){
			case 1 : printf ("remplir  le tableau \n");
					 remplissage ( *tab,n );
					 printf ("\n");
			break;
			case 2 : printf ("afficher le tableau \n");
					 affichage (tab,n );
					 printf ("\n");
			break;
			case 3 : printf ("donnez le nb dont vous chercher la position \n");
					 scanf ("%d",&nb);
					 printf ("la position de %d est : %d \n",nb,position(nb,tab,n));
			break;
			default : printf ("le numero introduit nexiste pas dans le menu \n");
			break;	 	 
		}
		
	}
void remplissage (int *tab,int n){
	int i,c;
	
	for (i=0;i<n;i++){
		printf ("donnez un entier \n");
		scanf ("%d",&c);
		tab[i]=c;
	}
	
	
void affichage (int *tab,int n){
	int i;
	
	for (i=0;i<n;i++)
		printf ("%d \n",tab[i]);
}

int position (int nb, int *tab,int n){
	int i;
	int pos;
	bool trouv=false;
	
	
	while (i<n && trouv=false ){
		if (tab[i]==nb){
			trouv=true;
			pos=i;
		}
		i++;
	}
	return pos;
}


}	
	
	
	
	
	
}




