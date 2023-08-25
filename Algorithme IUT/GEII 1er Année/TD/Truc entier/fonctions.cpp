#include<iostream>
using namespace std;

#include"Entier.h"

/*
R: Alloue une zone m�moire de taille n cases de type r�el et permet � l'utilisateur de remplir cette zone
E: n: un entier correspondant � la taille de la zone � allouer
S: un pointeur contenant l'adresse de la premi�re case de la zone
*/
int* Saisie_entier(unsigned int n)
{
	//Lexique local � Saisie_entier
	unsigned int i;
	int* p_f = nullptr;
	p_f = new int[n];

	//Algorithme local � Saisie_entier
	//D�but
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
R: Affiche le contenu d'une zone m�moire contenant n r�els
E: un pointeur vers entier: l'adresse de la premi�re case de la zone
   un entier corespondant � la taille de la zone
S: vide
*/
void Affiche_entier(const int* p_i, unsigned int n)
{
	//Lexique local � Affiche


	//Algorithme local � Affiche_entier
	unsigned int i;

	//Algorithme locla � Affiche_entier
	//D�but
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
R: R�aloue une zone m�moire pour augementer ou r�duire la taille des fonctions pr�c�dentes
E: un pointeur d'entier pointant vers la premi�re case de la zone � r�allouer
   un entier corespondant � la taille actuelle de la zone
   un entier corespondant � la taille de la nouvelle zone
S: un pointeur d'entier pointant vers la premiere case de la zone r�allou�
*/
int* Reallocation(int* p_i, unsigned int n, unsigned int nb)
{
	//Lexique local � Reallocation
	int* p_nouveau = nullptr;
	p_nouveau = new int[nb];

	//Algorithme local � Reallocation
	//D�but
	if (n <= nb)
	{
		for (unsigned int i = 0; i < n; i++)
		{
			p_nouveau[i] = p_i[i];
			//Autre m�thode: *(p_nouveau +i) = *(p_i + i);
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