
struct reservation{
	int num;
	char pension[20];
	int sejour;
	bool piscine;
};typedef struct reservation reservation;


struct element {
	reservation val;
	struct element *svt;
};typedef struct element element;

