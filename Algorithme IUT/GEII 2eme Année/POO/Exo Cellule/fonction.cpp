#include<iostream>
using namespace std;

#include"fonction.h"

Cellule::Cellule()
{
	m_nom = "Inconnu";
	m_noyau = 0;
	m_taille = 0;
	m_division = 0;
}

Cellule::Cellule(string input_nom, unsigned int noyau, double taille, unsigned int division)
{
	m_nom = input_nom;
	m_noyau = noyau;
	m_taille = taille;
	m_division = division;
}

Cellule::~Cellule()
{
	cout << "Lobjet a ete detruit" << endl;
}

void Cellule::Affiche() const
{
	cout << "-----------------------------------------------------------" << endl;
	cout << "La cellule est " << m_nom << "." << endl;
	cout << "Elle possede " << m_noyau << " noyau." << endl;
	if (m_noyau == 0)
	{
		cout << "La cellule est une bacterie." << endl;
	}
	else if (m_noyau == 1)
	{
		cout << "La cellule est une cellule eucaryote." << endl;
	}
	else
	{
		cout << "La cellule n'est d'aucun type." << endl;
	}
	cout << "Sa taille est de " << m_taille << " microns." << endl;
	cout << "Elle a subit " << m_division << " division." << endl;
	cout << "-----------------------------------------------------------" << endl;
}

void Cellule::Diviser(Cellule* input_cellule)
{
	input_cellule->SetCellule_nom(m_nom);
	input_cellule->SetCellule_noyau(m_noyau);
	input_cellule->SetCellule_taille(m_taille);
	input_cellule->SetCellule_division(0);

	SetCellule_division(m_division + 1);
}