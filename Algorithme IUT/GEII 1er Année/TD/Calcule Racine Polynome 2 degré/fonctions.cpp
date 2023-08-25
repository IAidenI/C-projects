#include<iostream>
#include<math.h>
using namespace std;

#include"racine.h"

/*
R: Calcule et affiche les racine d'un polyn�me du second degr�
E: 3 r�els: les 3 nombres saisie
S: vide
*/
void Racine(float a, float b, float c)
{
	//Lexique local � Racine
	float delta, x1, x2;

	//Algorithme local � Racine
	//D�but
	delta = b * b - 4 * a * c;
	if (delta == 0)
	{
		x1 = -b / (2 * a);
		cout << "La racine de votre polynome est x = " << x1 << "." << endl;
	}
	else //delta != 0
	{
		if (delta > 0)
		{
			x1 = (-b - sqrt(delta)) / (2 * a);
			x2 = (-b + sqrt(delta)) / (2 * a);
			cout << "Les racine de votre polynome sont x1 = " << x1 << " et x2 = " << x2 << "." << endl;
		}
		else //delta < 0
		{
			cout << "Il n'existe pas de racine reel pour votre polynome." << endl;
		}
		//FinSi
	}
	//FinSi
	//Fin
}