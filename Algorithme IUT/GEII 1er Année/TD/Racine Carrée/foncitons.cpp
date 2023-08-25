#include<iostream>
using namespace std;

#include"racine_carree.h"

/*
R: Demande � l'utilisateur de saisir un nombre strictement positif et lui retourne la valeur de ce nombre
E: vide
S: 1 r�el
*/
float Saisie_positif(void)
{
	//Lexique local � Saisie_positif
	float saisie;

	//Algorithme local � Saisie_positif
	//D�but
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
R: Calcule et retourne une valeur approch� de racine carr�e de a � l'ordre n selon l'algorithme de Newton
E: a : 1 r�el positif
   n : un entier corespondant � l'ordre de l'approximation
S: 1 r�el la valeur approch� de racine carr�e de a
*/
double Approx_racine_carree(double a, unsigned int n)
{
	//Lexique local � Approx_racine_carree
	unsigned int i;
	double u;

	//Algorithme local � Approx_racine_carree
	//D�but
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