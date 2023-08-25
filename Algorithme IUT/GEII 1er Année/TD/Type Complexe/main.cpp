#include<iostream>
using namespace std;

#include"complexe.h"

int main()
{
	//Lexique principal
	complexe z1, inverse_z, conjugue_z;

	//Algorithme principal
	//Début
	cout << "Saisir la partie reel d'un nombre complexe." << endl;
	cin >> z1.re;
	cout << "Saisir la partie imaginaire d'un nombre complexe." << endl;
	cin >> z1.im;
	//conjugue_z = Conjugue(z1);
	//cout << "Le conjuge de votre nombre complexe est z = " << conjugue_z.re << " + j" << conjugue_z.im << "." << endl;
	inverse_z = Inverse(z1);
	if (inverse_z.im < 0)
	{
		inverse_z.im = -inverse_z.im;
	}
	cout << "L'inverse de votre nombre complexe est z = " << inverse_z.re << " + j" << inverse_z.im << "." << endl;
	return 0;
}