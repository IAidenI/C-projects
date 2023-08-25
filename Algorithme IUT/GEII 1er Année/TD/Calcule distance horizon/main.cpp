#include<iostream>
using namespace std;

#include"fonction.h"

int main()
{
	//Lexique principal
	float distance, hauteur;

	//Algorithme principal
	//Début
	cout << "Saisir la hauteur de vos yeux pa rapport au sol (en m)." << endl;
	cin >> hauteur;
	distance = Distance_horizon(hauteur);
	cout << "Vous voyez l'horizon jusqu'a " << distance << " km." << endl;
	//Fin
	return 0;
}