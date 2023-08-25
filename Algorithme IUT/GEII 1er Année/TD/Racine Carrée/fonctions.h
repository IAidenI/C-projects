/*
R: Demande � l'utilisateur de saisir un nombre strictement positif et lui retourne la valeur de ce nombre
E: vide
S: 1 r�el
*/
float Saisie_positif(void);

/*
R: Calcule et retourne une valeur approch� de racine carr�e de a � l'ordre n selon l'algorithme de Newton
E: a : 1 r�el positif
   n : un entier corespondant � l'ordre de l'approximation
S: 1 r�el la valeur approch� de racine carr�e de a
*/
double Approx_racine_carree(double a, unsigned int n);