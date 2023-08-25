#include<iostream>
using namespace std;

#include"triangle.h"

/*
R: Affiche le motif constitué de n lignes avec i étoiles sur la ligne
E: 1 entier corespondant au nombre de lignes
S: vide
*/
void Triangle(unsigned int ligne)
{
	//Lexique local à Triangle
	unsigned int i, j;

	//Algorithme local à Triangle
	//Début
	i = 1;
	do
	{
		j = 1;
		do
		{
			cout << '*';
			j++;
		} while (j <= i);
		//FinTantque
		cout << endl;
		i++;
	} while (i <= ligne);
}