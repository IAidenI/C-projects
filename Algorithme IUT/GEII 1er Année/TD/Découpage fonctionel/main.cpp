#include<iostream>
using namespace std;

#include"Definition_fonctions.h"

int main()
{
	//Lexique principal
	float rayon, peri, surf, haut, vol_cylindre, distance, nb_tours;

	//Algorithme principal
	//Début
	Presentation();
	rayon = Saisie_rayon();
	haut = Saisie_hauteur();
	nb_tours = Saisie_tours();
	peri = Perimetre(rayon);
	surf = Surface(rayon);
	vol_cylindre = Volume_cylindre(rayon, haut);
	distance = Distance(rayon, nb_tours);
	cout << "Le perimetre de votre disque de rayon r = " << rayon << " est de " << peri << " cm." << endl;
	cout << "La surface de votre disque est de " << surf << " cm^2." << endl;
	cout << "Le volume de votre cylindre de rayon " << rayon << " cm et de hauteur " << haut << " cm est de " << vol_cylindre << " cm^3." << endl;
	cout << "Votre velo a parcouru un distance de " << distance << " m." << endl;
	//Fin
	return 0;
}