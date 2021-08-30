
struct element{
	int val;
	struct element *svt;
}; typedef struct element element;

struct File {
	element *premier;
	element *dernier;
};typedef struct File File;



void init_file (File *tete){
	(*tete).premier=NULL;
	(*tete).dernier=NULL;
}

void enfiler(File *tete, int val){
	element *r;
	
	r=(element*)malloc(sizeof(element));
	r->val=val;
	r->svt=NULL;
	if((*tete).dernier!=NULL)
		((*tete).dernier)->svt=r;
	else 
		(*tete).premier=r;
	
	(*tete).dernier=r;
}



bool file_vide (File tete){
	return tete.premier==NULL;
}


void defiler(File *tete, int *val){
	element *nb;
	
	if (file_vide(*tete))
		printf("la file est vide \n");
	else {
		*val=((*tete).premier)->val;
		nb=(*tete).premier;
		if((*tete).premier==(*tete).dernier){
			(*tete).dernier=NULL;	
		}
		(*tete).premier=((*tete).premier)->svt;
		free(nb);
	}
}

int tete_file (File tete){
	
	return (tete.premier)->val;
	
}


