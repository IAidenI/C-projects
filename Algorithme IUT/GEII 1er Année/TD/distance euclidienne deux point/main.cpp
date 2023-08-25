#include"dist_eucl.h"

int main()
{
	//Lexique
	const int TAILLE_REEL = 1000;
	point2d tab[TAILLE_REEL];
	int taille_pratique;

	// Algorithme
	taille_pratique = Saisie_points(tab, TAILLE_REEL);
	Points_proche(tab, taille_pratique);
	return 0;
}