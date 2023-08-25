#include<iostream>
using namespace std;

#include"bissextile.h"

/*
R: Affice si une année est bissextile ou non
E: 1 entier: une année
S: vide
*/
void Bissextile(unsigned int annee)
{
	//Lexique local à Bissextile
	//vide

	//Algorithme local à Bissextile
	//Début
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