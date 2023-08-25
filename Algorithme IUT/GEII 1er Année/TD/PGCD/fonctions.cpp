#include<iostream>
using namespace std;

/*
R: Demande à l'utilisateur de rentrer un entier positif et lui retourne l'affichage si ce n'est pas le cas
E: vide
S: 1 entier
*/
int Saisie_entier_positif(void)
{
	//Lexique local à Saisie_entier_positif
	int saisie;

	//Algorithme local à Saisie_entier_positif
	//Début
	do
	{
		cout << "Saisir un entier positif." << endl;
		cin >> saisie;
	} while (saisie < 0);
	//FinFaireTantque
	return saisie;
	//Fin
}

/*
R: Calcule et retourne le PGCD de 2 nombres entiers positifs à l'aide de l'algorithme d'Euclide
E: a, b : 2 entier positif
S: gcd : 1 entier : leurs PGCD
*/
unsigned int Pgcd(unsigned int a, unsigned int b)
{
	//Lexique local à Pgcd
	unsigned int res, u, w, gcd;

	//Algorithme local à Pgcd
	//Début
	u = a;
	w = b;
	if (w == 0)
	{
		//Alors
		gcd = u;
	}
	else // w != 0
	{
		res = u % w;
		while (res != 0)
		{
			u = w;
			w = res;
			res = u % w;
		}
		//FinTantque
		gcd = w;
	}
	//FinSi
	return gcd;
	//Fin
}
