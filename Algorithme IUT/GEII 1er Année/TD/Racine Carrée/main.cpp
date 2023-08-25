#include<iostream>
#include<iomanip>
using namespace std;

#include"racine_carree.h"

int main()
{
	//Lexique principal
	unsigned int ordre;
	float x;

	//Algorithme principal
	//Début
	x = Saisie_positif();
	cout << "A quel ordre ?" << endl;
	cin >> ordre;
	cout << "La valeur de racine carree de " << x << " a l'ordre " << ordre << " est: " << Approx_racine_carree(x, ordre) << endl;
	cout << setprecision(20) << Approx_racine_carree(x, ordre);
	//Fin
	return 0;
}