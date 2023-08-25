#include<iostream>
using namespace std;

#include"3_reels_ordon.h"

int main()
{
	//Lexique principal
	float tab_saisi[3];

	//Algorithme principal
	//Début
	Saisie_ordon(tab_saisi);
	cout << "Votre ordonnee est : " << tab_saisi[0] << " <= " << tab_saisi[1] << " <= " << tab_saisi[2] << endl;
}