
struct evaluation {
	float note;
	int coef;
	struct evaluation *suivant;
};typedef struct evaluation evaluation;


struct etud {
	int id;
	char nom[10];
	char prenom[10];
	float moy;
	struct evaluation *eval;
	struct etud *svt;
};typedef struct etud etud;

struct etud1 {
	int id;
	char nom[10];
	char prenom[10];
	float moy;
};typedef struct etud1 etud1;
