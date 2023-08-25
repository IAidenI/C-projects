#include<iostream>
using namespace std;

#include"fonction.h"

int main()
{
	//Lexique principal
	float taille, tp, tm, garcon_fille;

	//Algorithme principal
	//Début
	cout << "Saisir la taille du pere (en cm) (Ex 185 pour 1m85)." << endl;
	cin >> tp;
	cout << "Saisir la taille de la mere (en cm) (Ex 185 pour 1m85)." << endl;
	cin >> tm;
	cout << "Saisir le sexe de l'enfant (Saisir h pour homme et f pour femme)." << endl;
	cin >> garcon_fille;
	taille = Taille_genetique(tp, tm, garcon_fille);
	cout << "La taille de votre enfant sera de environ" << taille << " cm." << endl;
	return 0;
}