#include<iostream>
using namespace std;

#include"3_reels_ordon.h"

/*
R: Range dans l'ordre croissant 3 réels dans un tableau
E: vide
E/S: 1 tableau de 3 réels
S: vide
*/
void Saisie_ordon(float tab[3])
{
	//Lexique local à Saisie_ordon
	float temp;

	//Algorithme local à Saisie_ordon
	//Début
	cout << "Saisir une valeur." << endl;
	cin >> temp;
	tab[0] = temp;
	cout << "Saisir une valeur." << endl;
	cin >> temp;
	if (tab[0] > temp)
	{
		tab[1] = tab[0];
		tab[0] = temp;
	}
	else //tab[0] <= temp
	{
		tab[1] = temp;
	}
	//FinSi
	cout << "Saisir une valeur." << endl;
	cin >> temp;
	if (tab[1] < temp)
	{
		tab[2] = temp;
	}
	else //tab[1] >= temp
	{
		if (tab[0] > temp)
		{
			tab[2] = tab[1];
			tab[1] = tab[0];
			tab[0] = temp;
		}
		else //tab[1] < temp
		{
			tab[2] = tab[1];
			tab[1] = temp;
		}
		//FinSi
	}
	//FinSi
	//Fin
}