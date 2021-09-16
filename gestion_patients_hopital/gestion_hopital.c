#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include ""
#include ""
#include ""
#include ""





int main (){
	FILE *F;
	int i,n;
	
	F=fopen("patients.txt","w");
	
	printf ("donnez le nombre total des patients \n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf ("donnez le nom et prenom de ce patient \n");
	}
	
	
	
}
