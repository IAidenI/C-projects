#include<iostream>
using namespace std;

#include"bissextile.h"

int main()
{
	//Lexique principal
	unsigned int an;

	//Algorithme principal
	//D�but
	cout << "Saisir une annee." << endl;
	cin >> an;
	Bissextile(an);
	//Fin
	return 0;
}