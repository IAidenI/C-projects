#include"fonction.h"

int main(void)
{
	float dist = 0;

	//1er partie
	//Coordonnées pour Saint-Etienne
	Coordonnee coord1;
	coord1.latitude = 45.439695;
	coord1.longitude = 4.3871779;

	//Coordonnées pour Paris
	Coordonnee coord2;
	coord2.latitude = 48.866667;
	coord2.longitude = 2.333333;

	//Coordonnées pour Toulouse
	Coordonnee coord3;
	coord3.latitude = 43.600000;
	coord3.longitude = 1.433333;

	//Initialise deux villes
	Ville ville1("Saint-Etienne", 42000, coord1);
	Ville ville2("Paris", 75000, coord2);
	Ville ville3("Toulouse", 31000, coord3);

	//Affiche les caractéristique des deux villes
	ville1.Afficher();
	ville2.Afficher();
	ville3.Afficher();

	//Deuxieme partie
	/*unsigned int nb_lignes, i;
	Ville* ptr_ville = NULL;

	nb_lignes = CompterLigne();
	ptr_ville = new Ville[nb_lignes];

	Lecture_fichier(ptr_ville, nb_lignes);
	for (i = 0; i < nb_lignes; i++)
	{
		ptr_ville[i].Afficher();
	}
	dist = Itineraire(ptr_ville, nb_lignes);*/

	
	//Calcul la distance entre ces deux villes
	dist = ville1.DistanceKms(&ville2);
	//Résultat en metre
	cout << "L'itinairaire est de " << endl;
	cout << dist << " m." << endl;
	//Résultat en kilometre
	dist /= 1000;
	cout << dist << " km." << endl << endl;

	//delete[] ptr_ville;
	return 0;
}