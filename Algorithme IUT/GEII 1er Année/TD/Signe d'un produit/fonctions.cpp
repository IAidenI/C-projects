#include<iostream>
using namespace std;

#include"signe_produit.h"

/*
R: Affiche le signe du produit de nombres
E: 2 réels: 2 nombres
S: 1 réel: le signe de leur produit
*/
float Signe_produit(float nb_a, float nb_b)
{
	//Lexique local à Signe_produit
	//vide

	//Algorithme local à Signe_produit
	//Début
	if (nb_a > 0)
	{
		if (nb_b > 0)
		{
			cout << "Le produit est positif." << endl;
		}
		else
		{
			cout << "Le produit est negatif." << endl;
		}
	}
	else
	{
		if (nb_b > 0)
		{
			cout << "Le produit est negatif." << endl;
		}
		else
		{
			cout << "Le produit est positif." << endl;
		}
	}
	return 0;
}