#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	//Lexique principal
	float lon, lar, aire; //lon, lar et aire representent respectivement la longueur, la largeur et l'aire d'un terrain
	const int TAUX = pow(10, 4);

	//Algorithme principal
	//Début
	cout << "Saisir la longueur du terrain en m" << endl;
	cin >> lon;
	cout << "Saisir la largeur du terrain en m" << endl;
	cin >> lar;
	aire = lon * lar;
	aire = aire / TAUX;
	cout << "La superficie du terrain est de " << aire << " ha" << endl;
	return 0;
}