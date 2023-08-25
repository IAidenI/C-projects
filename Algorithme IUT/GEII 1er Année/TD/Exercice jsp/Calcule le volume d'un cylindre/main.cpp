#include<iostream>
using namespace std;

#include"fonctions.h"

int main()
{
	//Lexique principal
	float hauteur, vol, ray;

	//Algorithme principal
	//Début
	cout << "Saisir la hauteur du cylindre en cm." << endl;
	cin >> hauteur;
	cout << "Saisir le rayon du cylindre en cm." << endl;
	cin >> ray;
	vol = Volume_cylindre(ray, hauteur);
	cout << "Le volume de votre cylindre est de " << vol << " cm^3." << endl;
	//Fin
	return 0;
}