#include<iostream>
using namespace std;

#include"signe_produit.h"

/*
R: Affiche le signe du produit de nombres
E: 2 r�els: 2 nombres
S: 1 r�el: le signe de leur produit
*/
float Signe_produit(float nb_a, float nb_b)
{
	//Lexique local � Signe_produit
	//vide

	//Algorithme local � Signe_produit
	//D�but
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