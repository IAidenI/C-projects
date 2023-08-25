/*
R: Alloue une zone m�moire de taille n cases de type r�el et permet � l'utilisateur de remplir cette zone
E: n: un entier correspondant � la taille de la zone � allouer
S: un pointeur contenant l'adresse de la premi�re case de la zone
*/
int* Saisie_entier(unsigned int n);

/*
R: Affiche le contenu d'une zone m�moire contenant n r�els
E: un pointeur vers r�els: l'adresse de la premi�re case de la zone
   un entier corespondant � la taille de la zone
S: vide
*/
void Affiche_entier(const int* p_i, unsigned int n);

/*
R: R�aloue une zone m�moire pour augementer ou r�duire la taille des fonctions pr�c�dentes
E: un entier corespondant � la taille actuelle de la zone
   un entier corespondant � la taille de la nouvelle zone
S: un pointeur d'entier pointant vers la premiere case de la zone r�allou�
*/
int* Reallocation(int* p_i, unsigned int n, unsigned int nb);