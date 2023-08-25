#include<string>
#include"felin.h"
#include<iostream>
using namespace std;

Felin::Felin() : Animal("Inconnu", "Inconnu")
{
	carac_felin = 0;
	cout << "Constructeur par defaut de la classe Felin." << endl << endl;
}

Felin::Felin(std::string input_espece, std::string input_nom, float input_carca_felin) : Animal(input_espece, input_nom)
{
	carac_felin = input_carca_felin;
}

Felin::~Felin()
{
	cout << "Destructeur de la classe Felin appele pour l'individu " << Animal::GetNom() << "." << endl << endl;
}

void Felin::Affiche() const
{
	Animal::Afficher();
	cout << "J'ai une puissance dans ma machoire de " << carac_felin << " kg/cm^2." << endl;
}

void Felin::Chasser(Ongule* input_ongule)
{
	cout << "Le felin " << Animal::GetNom() << " chasse l'ongule " << input_ongule->GetNom() << endl;
}