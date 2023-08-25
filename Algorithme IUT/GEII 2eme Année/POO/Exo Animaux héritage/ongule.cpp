#include<string>
#include"ongule.h"
#include<iostream>
using namespace std;

Ongule::Ongule() : Animal("Inconnu", "Inconnu")
{
	carac_ongule = "Inconnu";
	cout << "Constructeur par defaut de la classe Felin." << endl << endl;
}

Ongule::Ongule(std::string input_espece, std::string input_nom, std::string input_carca_ongule) : Animal(input_espece, input_nom)
{
	carac_ongule = input_carca_ongule;
}

Ongule::~Ongule()
{
	cout << "Destructeur de la classe Felin appele pour l'individu " << Animal::GetNom() << "." << endl << endl;
}

void Ongule::Affiche() const
{
	Animal::Afficher();
	cout << "Mon pelage est " << carac_ongule << "." << endl;
}