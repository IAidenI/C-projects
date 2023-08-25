#include<iostream>
using namespace std;

#include"signe_produit.h"

int main()
{
	//Lexique principal
	float a, b;

	//Algorithme principal
	//Début
	cout << "Saisir votre premier nombre." << endl;
	cin >> a;
	cout << "Saisir votre seconde nombre." << endl;
	cin >> b;
	Signe_produit(a, b);
}