#include<iostream>
#include<iomanip>
using namespace std;

#include"Table_Pyth.h"

/*
R: Affiche la table de Pythagore
E: vide
S: vide
*/
void Table(void)
{
	//Lexique local à Table
	int i, j;
	char c = ' ';
	//Algorithme local à Table
	//Début
	cout << c;
	j = 1;
	while (j <= 10)
	{
		cout << c << j;
		cout << setw(4) << setfill(' ') << (' ');
		j = j + 1;
	}
	//FinTantque
	cout << endl;
	i = 1;
	while (i <= 10)
	{
		cout << c << i;
		j = 1;
		while (j <= 10)
		{
			cout << c << i * j;
			cout << setw(4) << setfill(' ') << (' ');
			j = j + 1;
		}
		//FinTantque
		cout << endl;
		i = i + 1;
	}
	//FinTantque
}