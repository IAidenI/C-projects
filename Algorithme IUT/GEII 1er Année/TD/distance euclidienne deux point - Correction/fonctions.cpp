#include<iostream>
using namespace std;

#include"dist_eucl.h"

int Saisie_point2d(point2d tab2d[], int taille)
{
	//Lexique local
	int i, c;

	//Algorithme local
	//Début
	i = 0;
	cout << "Combien de points voulez vous saisir ?" << endl;
	cin >> c;
	do
	{
		cout << "Saisir l'abscice de votre point." << endl;
		cin >> tab2d[i].x;
		cout << "Saisir l'ordonnee de votre point." << endl;
		cin >> tab2d[i].y;
		i = i + 1;
	} while (i < c && i < taille);
	//Fin FaireTantque
	return c;
	//Fin
}

float Distance(point2d p, point2d q)
{
	//Lexique local
	float d;

	//Algorithme local
	//Début
	d = sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
	return d;
	//Fin
}

void Affiche_coord(int tp, point2d tab2d[])
{
	//Lexique local
	int i, j, imin, jmin;
	float d, dmin;

	//Algorithme local
	//Début
	i = 0;
	j = 1;
	dmin = Distance(tab2d[i], tab2d[j]);
	imin = i;
	jmin = j;
	while (i < tp - 1)
	{
		j = i + 1;
		while (j < tp)
		{
			d = Distance(tab2d[i], tab2d[j]);
			if (d < dmin)
			{
				imin = i;
				jmin = j;
				dmin = d;
			}
			//Fin Si
			j = j + 1;
		}
		//Fin Tantque
		i = i + 1;
	}
	//Fin Tantque
	cout << "Les 2 points qui minimisent d sont: ("<<tab2d[imin].x << " , " << tab2d[imin].y << ") et (" << tab2d[jmin].x << " , " << tab2d[jmin].y << ")" << endl;
	//Fin
}