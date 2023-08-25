#include<iostream>
using namespace std;

#include"fonction.h"

int main()
{
	//Lexique principal
	int u0, u1, nn, un;

	//Algorithme principal
	//Début
	cout << "Saisir la premiere valeur de vorte suite." << endl;
	cin >> u0;
	cout << "Saisir la seconde valeur de votre suite." << endl;
	cin >> u1;
	cout << "Quel n-eme terme voulez vous calculez ?" << endl;
	cin >> nn;
	un = Fibo_n(u0, u1, nn-1);
	cout << "u" << nn - 1 << " = " << un << endl;
	//Fin
}