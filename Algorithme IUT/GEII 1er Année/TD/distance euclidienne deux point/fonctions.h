struct point2d
{
	float x;
	float y;
};

/*
R: Demande � l'utilisateur de saisir des points
E: 1 entier corespondant � la taille r�el du tableau
E/S: 1 tableau de point2d
E: 1 entier corespondant � la taille pratique du tableau
*/
int Saisie_points	(point2d tab[], int TAILLE);

/*
R: Calcule un distance euclidienne entre deux points
E: 2 entiers qui corespondent � l'abscice et � l'ordonn�e d'un point, 1 tableau de point2d
S: 1 r�el associ� � la distance euclidienne entre 2 points
*/
float Distance(int a, int b, const point2d tab[]);

/*
R: Compare et affiche les 2 points les plus proches
E: 1 tableau de point2d, 1 entier qui corespond � la taille pratique du tableau
S: vide
*/
void Points_proche(point2d tab[], int taille_pratique);