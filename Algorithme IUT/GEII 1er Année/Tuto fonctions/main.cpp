#include<iostream>
#include"fonctions.h"
using namespace std;

int main()
{
	//Lexique principal
	float rayon, peri, surf;

	//Algorithme principal
	//Début
	cout << "Ce programme vous permet de saisir le rayon d'un disque a partir duquel," << endl; 
	cout << "le perimetre et la surface du disque sont calcules puis affiches." << endl;
	cout << "Saisir le rayon du disque en cm." << endl;
	cin >> rayon;
	peri = Perimetre(rayon);
	surf = Surface(rayon);
	cout << "Le perimetre de votre disque est: " << peri << " cm." << endl;
	cout << "La surface de votre disque est: " << surf << " cm^2." << endl;
	//Fin
	return 0;
}