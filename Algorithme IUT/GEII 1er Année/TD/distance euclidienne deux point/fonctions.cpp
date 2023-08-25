#include <iostream>
#include<math.h>
using namespace std;

#include"dist_eucl.h"

int Saisie_points(point2d tab[], int TAILLE)
{
	// Lexique
	int taille_pratique;
	int i = 0;

	// Algorithme
	do
	{
		cout << "Saisir le nombre de point que vous souhaiter declarer : ";
		cin >> taille_pratique;
		if (taille_pratique == 1)
		{
			cout << "Une distance ne peut pas etre calculee a partir d'un seul point." << endl;
		}
		cout << endl;
		//Fin Si

	} while (taille_pratique > TAILLE || taille_pratique <= 0);

	do
	{
		cout << "Saisir la composante x du" << i + 1 << "e point: ";
		cin >> tab[i].x;
		cout << endl;
		cout << "Saisir la composante y du" << i + 1 << "e point: ";
		cin >> tab[i].y;
		cout << endl << endl;
		i = i + 1;
	} while (i < taille_pratique);

	return taille_pratique;
}

float Distance(int a, int b, const point2d tab[])
{
	// Lexique
	float dist;

	// Algorithme
	dist = sqrt(pow((tab[a].x - tab[b].x), 2) + pow((tab[a].y - tab[b].y), 2));
	return dist;
}

void Points_proche(point2d tab[], int taille_pratique)
{
	// Lexique
	int i, j, a, b;
	float distance, d;

	// Algorithme
	i = 0;
	j = 0;

	d = Distance(0, 1, tab);
	distance = Distance(0, 1, tab);

	while (i < taille_pratique)
	{
		while (j < taille_pratique)
		{
			if (j != i)
			{
				distance = Distance(i, j, tab);
			}
			if (distance < d)
			{
				d = distance;
				a = i;
				b = j;
			}
			j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
	cout << "Les deux points les plus prche l'un de l'autre sont les point " << a + 1 << " et " << b + 1;
}