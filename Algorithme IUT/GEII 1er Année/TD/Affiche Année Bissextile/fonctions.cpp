#include<iostream>
using namespace std;

#include"bissextile.h"

/*
R: Affice si une ann�e est bissextile ou non
E: 1 entier: une ann�e
S: vide
*/
void Bissextile(unsigned int annee)
{
	//Lexique local � Bissextile
	//vide

	//Algorithme local � Bissextile
	//D�but
	if (annee % 4 == 0)
	{
		if ((annee % 400 == 0) && (annee % 4000 == 0))
		{
			cout << "Annee non bissextile." << endl;
		}
		else //((annee % 400 != 0) || (annee % 4000 == 0))
		{
			cout << "Annee bissextile." << endl;
		}
		//FinSi
	}
	else //annee % 4 != 0
	{
		cout << "Annee non bissextile." << endl;
	}
}