/*
R: Alloue une zone mémoire de taille n cases de type réel et permet à l'utilisateur de remplir cette zone
E: n: un entier correspondant à la taille de la zone à allouer
S: un pointeur contenant l'adresse de la première case de la zone
*/
int* Saisie_entier(unsigned int n);

/*
R: Affiche le contenu d'une zone mémoire contenant n réels
E: un pointeur vers réels: l'adresse de la première case de la zone
   un entier corespondant à la taille de la zone
S: vide
*/
void Affiche_entier(const int* p_i, unsigned int n);

/*
R: Réaloue une zone mémoire pour augementer ou réduire la taille des fonctions précédentes
E: un entier corespondant à la taille actuelle de la zone
   un entier corespondant à la taille de la nouvelle zone
S: un pointeur d'entier pointant vers la premiere case de la zone réalloué
*/
int* Reallocation(int* p_i, unsigned int n, unsigned int nb);