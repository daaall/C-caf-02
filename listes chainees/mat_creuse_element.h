
struct element {
	int num_ligne;
	struct element *svt_ligne;
	struct element2 *colonne;
};typedef struct element element;

struct element2 {
	int num_colonne;
	int val;
	struct element2 *svt_colonne;
}; typedef struct  element2 element2 ;









