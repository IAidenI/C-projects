/*
R: Génere une grille de sudoku rempli
E: vide
S: un pointeur d'entier qui corespond à l'emplacement du tableau crée
*/
//unsigned int* gen_sudoku(void);

/*
R: Génere une ligne de la grille de sudoku
E: vide
S: un pointeur d'entier qui corespond à l'emplacement de la ligne crée
*/
unsigned int* gen_ligne(void);

/*
R: Vérifie et modifie au besoin les lignes du sudoku
E: un pointeur qui corespond à la ligne du sudoku à vérifier
S: vide
*/
void verif_ligne(unsigned int* l);

/*
R: Vérifie et modifie au besoin les colonnes du sudoku
E: 9 pointeur qui corespondent aux colonnes du sudoku à vérifier
S: vide
*/
void verif_colonnes(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9);

/*
R: Vérifie et modifie au besoin les carrées de 9 case du sudoku
E: 9 pointeur qui corespondent aux carrées du sudoku à vérifier
S: vide
*/
void verif_carree(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9);

/*
R: Verifie si les lignes et les colonnes sont justes
E: vide
S: 9 pointeurs qui corespondent aux lignes et colonnes à vérifier
*/
//void verif_ligne2(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9);

/*
R: Affiche le sudoku
E: 9 pointeur d'entier qui corespond à l'emplacement des lignes du sudoku
S: vide
*/
void affiche_sudoku(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9);

/*
R: Affiche les règles et les consignes
E: vide
S: vide
*/
void affiche_jeu(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9);