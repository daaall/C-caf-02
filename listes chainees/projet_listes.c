#include <stdio.h>
#include <stdlib.h>
#include "element_projet_listes.h"
#include <stdbool.h>
#include <string.h>
#include "projet_listes.h"


int main (){
	etud *tete;
	int i, n,choix;
	FILE *F,*F1;
	

	
	
	while (1){
		
	printf("****************\n");
	printf ("*****MENU******\n");
	printf("****************\n");
	printf ("\n");
	printf ("1-creation de la liste \n");
	printf ("2-affichage de la liste \n");
	printf ("3-mise a jour du champ moy \n");
	printf ("4-creation du fichier detudiants \n");
	printf ("5-affichage du fichier cre \n");
	printf ("6-tri  decroissant du fichier \n");
	printf ("7-creation dun fichier pour les 50%% premier \n");
	printf ("8-quitter le programme \n");
	
	printf ("introduisez votre choix \n");
	scanf ("%d",&choix);
	
	switch (choix) {
		case 1 : printf ("donnez le nombre detudiant que vous souhaitez ajouter a la liste \n");
				 scanf ("%d",&n);
				 remplissage (n,&tete);
				 printf("fin de remplissage \n"); 
		break;
		case 2 : 
				 affichage (tete);
		break;
		case 3 : maj_moy (tete);
		break;
		case 4 : F=fopen ("fich_etud.txt","w");
				 creation_fichier (tete, F);
				 fclose(F);
				 
		break;
		case 5 : F=fopen("fich_etud.txt","r");
				 affichage_F (F);
				 fclose(F);
		break;
		case 6 : 
				 
				 creation_tab();
				 
				 printf ("\n");
				 
				 //affichage_tab(tab,n);
				 
				 /*printf ("avant le tri :( \n");
				 tri(tab,n);
				 printf ("apres le trie \n");
				 
				 printf ("\n");
				 printf ("avant le 1eme affichage \n");
				 affichage_tab(tab,n);
				 printf ("apres le 2eme affichage :) \n");*/
		break;
		case 7 : creation_fichier50 (&F1);
				 F=fopen("fich_etud2.txt","r");
				 affichage_F (F);
				 fclose(F);
		break;
		case 8 :exit (1);
		break;
		default : printf ("ce nombre nexiste pas dans le menu \n");
		break;
	}
	}
}
	
	
	


