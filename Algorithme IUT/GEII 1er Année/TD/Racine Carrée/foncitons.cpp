#include<iostream>
using namespace std;

#include"racine_carree.h"

/*
R: Demande à l'utilisateur de saisir un nombre strictement positif et lui retourne la valeur de ce nombre
E: vide
S: 1 réel
*/
float Saisie_positif(void)
{
	//Lexique local à Saisie_positif
	float saisie;

	//Algorithme local à Saisie_positif
	//Début
	do
	{
		cout << "Saisir un nombre strictement positif." << endl;
		cin >> saisie;
	} while (saisie <= 0);
	//FinFaireTantque
	return saisie;
	//Fin
}

/*
R: Calcule et retourne une valeur approché de racine carrée de a à l'ordre n selon l'algorithme de Newton
E: a : 1 réel positif
   n : un entier corespondant à l'ordre de l'approximation
S: 1 réel la valeur approché de racine carrée de a
*/
double Approx_racine_carree(double a, unsigned int n)
{
	//Lexique local à Approx_racine_carree
	unsigned int i;
	double u;

	//Algorithme local à Approx_racine_carree
	//Début
	u = 1.0;
	i = 0;
	while (i < n)
	{
		u = (u + (a / u)) / 2;
		i = i + 1;
	}
	//FinTanque
	return u;
	//Fin
}