#include<iostream>
using namespace std;

#include"Entier.h"

int main()
{
	//Lexique principal
	int* p_zone_entier = nullptr;
	int* p_entier = nullptr;
	unsigned int nb_cases;
	unsigned int new_nb_cases;

	//Algorithme principal
	//Début
	cout << "Combien de cases memoires voulez vous reserver ?" << endl;
	cin >> nb_cases;
	p_zone_entier = Saisie_entier(nb_cases);
	Affiche_entier(p_zone_entier, nb_cases);
	cout << "Saisir le nouveau nombre de cases de vous voulez réserver." << endl;
	cin >> new_nb_cases;
	p_entier = Saisie_entier(nb_cases);
	p_entier = Reallocation(p_entier, nb_cases, new_nb_cases);
	Affiche_entier(p_entier, new_nb_cases);
	delete[] p_entier;
	//Fin
}