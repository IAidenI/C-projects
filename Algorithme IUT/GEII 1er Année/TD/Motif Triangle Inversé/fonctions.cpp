#include<iostream>
using namespace std;

#include"triangle_inverse.h"

/*
R: Affiche le motif constitu� de n lignes avec i �toiles sur la ligne
E: 1 entier corespondant au nombre de lignes
S: vide
*/
void Triangle_inverse(unsigned int ligne)
{
	//Lexique local � Triangle_inverse
	int i, j;

	//Algorithme local � Triangle_inverse
	//D�but
	i = ligne;
	do
	{
		j = 0;
		do
		{
			cout << '*';
			j++;
		} while (j <= i);
		//FinFaireTantque
		cout << endl;
		i--;
	} while (i >= 0);
	//FinFaireTantque
}