
struct File{
	int champs;
	struct File *svt;
}; typedef struct File File;



void init_file (File **tete){
	*tete=NULL;
}

void enfiler(File **tete, int val){
	File *p,*a=*tete,*q;
	
	
	
	p=(File*)malloc(sizeof(File));
	p->champs=val;
	p->svt=NULL;
	if(*tete==NULL)
		*tete=p;
	else{
		while (a->svt!= NULL){
			a=a->svt;
		}
		a->svt=p;
	}
	
}



bool file_vide (File *tete){
	return tete==NULL;
}


void defiler(File **tete, int *val){
	if (file_vide(*tete))
		printf("la file est vide \n");
	else {
	*val=(*tete)->champs;
	*tete=(*tete)->svt;
	}
}

int tete_file (File *tete){
	
	return tete->champs;
	
}



