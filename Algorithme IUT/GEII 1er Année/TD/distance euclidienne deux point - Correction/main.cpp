#include"dist_eucl.h"

int main()
{
	//Lexique principal
	const int TAILLE = 300;
	point2d tab_points[TAILLE];
	int taille_pratique;

	//Algorithme principal
	//Début
	taille_pratique = Saisie_point2d(tab_points, TAILLE);
	Affiche_coord(taille_pratique, tab_points);
}