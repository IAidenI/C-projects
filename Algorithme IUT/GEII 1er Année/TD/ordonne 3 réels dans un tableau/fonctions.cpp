#include<iostream>
using namespace std;

#include"3_reels_ordon.h"

/*
R: Range dans l'ordre croissant 3 r�els dans un tableau
E: vide
E/S: 1 tableau de 3 r�els
S: vide
*/
void Saisie_ordon(float tab[3])
{
	//Lexique local � Saisie_ordon
	float temp;

	//Algorithme local � Saisie_ordon
	//D�but
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