#include<iostream>
#include"fonctions.h"
using namespace std;

int main()
{
	//Lexique principal
	float latitude;
	double insol;
	unsigned int jours;

	//Algorithme principal
	//Début
	cout << "Saisir la latitude du lieu en degre." << endl;
	cin >> latitude;
	cout << "Saisir le jour de l'annee (Ex: 1 pour 1er janvier)." << endl;
	cin >> jours;
	insol = Duree_insol(latitude, jours);
	cout << "A l'emplacement choisit et a la date choisit, la duree d'insolation est de " << insol << " h." << endl;
	//Fin
	return 0;
}