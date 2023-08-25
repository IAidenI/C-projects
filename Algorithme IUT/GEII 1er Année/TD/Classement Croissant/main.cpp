#include<iostream>
using namespace std;

#include"croissant.h"

int main()
{
	//Lexique principal
	float nb_a, nb_b, nb_c;

	//Algorithme principal
	//Début
	cout << "Saisir le premier nombre." << endl;
	cin >> nb_a;
	cout << "Saisir le deuxieme nombre." << endl;
	cin >> nb_b;
	cout << "Saisir le troisieme nombre." << endl;
	cin >> nb_c;
	Croissant(nb_a, nb_b, nb_c);
	//Fin
	return 0;
}