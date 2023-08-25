#include<iostream>
using namespace std;

#include"racine.h"

int main()
{
	//Lexique principal
	float nb_a, nb_b, nb_c;

	//Algorithme principal
	//Début
	cout << "Votre polynome est de la forme, ax^2 + bx + c. Veuillez saisir la valeur de a." << endl;
	cin >> nb_a;
	cout << "Saisir la valeur de b." << endl;
	cin >> nb_b;
	cout << "Saisir la valeur de c" << endl;
	cin >> nb_c;
	Racine(nb_a, nb_b, nb_c);
	//Fin
	return 0;
}