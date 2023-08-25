#include<iostream>
using namespace std;

#include"triangle.h"

/*
R: Affiche le motif constitu� de n lignes avec i �toiles sur la ligne
E: 1 entier corespondant au nombre de lignes
S: vide
*/
void Triangle(unsigned int ligne)
{
	//Lexique local � Triangle
	unsigned int i, j;

	//Algorithme local � Triangle
	//D�but
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