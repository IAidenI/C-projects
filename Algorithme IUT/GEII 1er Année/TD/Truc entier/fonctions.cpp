#include<iostream>
using namespace std;

#include"Entier.h"

/*
R: Alloue une zone mémoire de taille n cases de type réel et permet à l'utilisateur de remplir cette zone
E: n: un entier correspondant à la taille de la zone à allouer
S: un pointeur contenant l'adresse de la première case de la zone
*/
int* Saisie_entier(unsigned int n)
{
	//Lexique local à Saisie_entier
	unsigned int i;
	int* p_f = nullptr;
	p_f = new int[n];

	//Algorithme local à Saisie_entier
	//Début
	i = 0;
	while (i < n)
	{
		cout << "Saisir votre " << i + 1 << "e valeur: ";
		cin >> *(p_f + i);
		i++;
	}
	//Fin Tantque
	return p_f;
	//Fin
}

/*
R: Affiche le contenu d'une zone mémoire contenant n réels
E: un pointeur vers entier: l'adresse de la première case de la zone
   un entier corespondant à la taille de la zone
S: vide
*/
void Affiche_entier(const int* p_i, unsigned int n)
{
	//Lexique local à Affiche


	//Algorithme local à Affiche_entier
	unsigned int i;

	//Algorithme locla à Affiche_entier
	//Début
	cout << "{";
	for (i = 0; i < n - 1; i++)
	{
		cout << *(p_i + i) << ",";
	}
	//Fin Pour
	cout << *(p_i + i) << "}" << endl;
	//Fin
}

/*
R: Réaloue une zone mémoire pour augementer ou réduire la taille des fonctions précédentes
E: un pointeur d'entier pointant vers la première case de la zone à réallouer
   un entier corespondant à la taille actuelle de la zone
   un entier corespondant à la taille de la nouvelle zone
S: un pointeur d'entier pointant vers la premiere case de la zone réalloué
*/
int* Reallocation(int* p_i, unsigned int n, unsigned int nb)
{
	//Lexique local à Reallocation
	int* p_nouveau = nullptr;
	p_nouveau = new int[nb];

	//Algorithme local à Reallocation
	//Début
	if (n <= nb)
	{
		for (unsigned int i = 0; i < n; i++)
		{
			p_nouveau[i] = p_i[i];
			//Autre méthode: *(p_nouveau +i) = *(p_i + i);
		}
		//Fin Pour
	}
	else //n > nb
	{
		for (unsigned int i = 0; i < nb; i++)
		{
			p_nouveau[i] = p_i[i];
		}
		//Fin Pour
	}
	//Fin Si
	delete[] p_i;
	return p_nouveau;
	//Fin
}