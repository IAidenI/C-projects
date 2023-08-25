/*
R: Demande à l'utilisateur de saisir un nombre strictement positif et lui retourne la valeur de ce nombre
E: vide
S: 1 réel
*/
float Saisie_positif(void);

/*
R: Calcule et retourne une valeur approché de racine carrée de a à l'ordre n selon l'algorithme de Newton
E: a : 1 réel positif
   n : un entier corespondant à l'ordre de l'approximation
S: 1 réel la valeur approché de racine carrée de a
*/
double Approx_racine_carree(double a, unsigned int n);