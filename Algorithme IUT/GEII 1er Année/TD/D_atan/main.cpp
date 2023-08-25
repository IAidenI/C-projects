#include<iostream>
#include"fonction.h"
using namespace std;

int main()
{
	//Lexique principal
	float x_in, r;

	//Algorithme principal
	//Début
	cout << "Entrer x: " << endl;
	cin >> x_in;
	r = D_atan(x_in);
	cout << "D_atan(" << x_in << ")=" << r;
	//Fin
	return 0;
}