#include<iostream>
using namespace std;

#include"pgcd.h"

int main()
{
	//Lexique principal
	unsigned int x, y;

	//Algorithme principal
	//Début
	x = Saisie_entier_positif();
	y = Saisie_entier_positif();
	cout << "Le PGCD de " << x << " et de " << y << " est : " << Pgcd(x, y) << endl;
	//Fin
	return 0;
}