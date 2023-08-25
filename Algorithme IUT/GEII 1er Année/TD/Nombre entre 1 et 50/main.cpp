#include<iostream>
using namespace std;

#include"nombre_1_50.h"

int main()
{
	//Lexique principal
	float nombre;

	//Algorithme principal
	//Début
	cout << "Saisir un nombre entre 1 et 50." << endl;
	cin >> nombre;
	Nombre(nombre);
	return 0;
}