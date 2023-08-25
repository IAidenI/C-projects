#include<iostream>
using namespace std;

#include"sapin.h"

/*
R: Affiche un sapin d'�toiles qui contient au moins 2 lignes
E: 1 entier corespondant au nombre de lignes
S: vide
*/
void Sapin(int ligne)
{
	//Lexique local � Sapin
	unsigned int i, j;

	//Aglorithme local � Sapin
	//D�but
	i = 0;
	while (i < ligne)
	{
		j = 1;
		while (j < ligne - i)
		{
			cout << ' ';
			j++;
		}
		//FinTantque
		j = 0;
		while (j < 2 * i + 1)
		{
			cout << '*';
			j++;
		}
		//FinTantque
		cout << endl;
		i++;
	}
	//FinTantque
	//Fin
}