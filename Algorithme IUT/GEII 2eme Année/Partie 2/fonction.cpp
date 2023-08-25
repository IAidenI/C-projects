#include <math.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

#include "fonction.h"

ofstream fichier_out("r�sultat.txt");

void AfficheMesures(const Mesure input_data[], const int input_taille)
{
	int local_i;

	for (local_i = 0; local_i < input_taille; local_i++)
	{
		fichier_out << input_data[local_i].m_date.jours << " " << input_data[local_i].m_date.mois << " " << input_data[local_i].m_date.annees << " : " << input_data[local_i].m_donnee << input_data[local_i].unite << endl;
	}
}

float CalculerMoyenneMesure(const Mesure input_data[], int input_taille)
{
	int local_i;
	float local_moyenne;

	local_moyenne = 0;
	for (local_i = 0; local_i < input_taille; local_i++)
	{
		local_moyenne = local_moyenne + input_data[local_i].m_donnee;
	}
	local_moyenne = local_moyenne / input_taille;
	return local_moyenne;
}

float CalculerEcarttypeMesures(const Mesure input_data[], int input_taille, float input_moyenne)
{
	int local_i;
	float local_ecart;

	local_ecart = 0;
	for (local_i = 0; local_i < input_taille; local_i++)
	{
		local_ecart = local_ecart + pow(input_data[local_i].m_donnee - input_moyenne, 2);
	}
	local_ecart = sqrt(local_ecart / input_taille);
	return local_ecart;
}

float CalculerEcarttypeMesuresAvecRecentrage(Mesure input_data[], int input_taille, float input_moyenne)
{
	int local_i;
	float local_ecart;

	local_ecart = 0;
	for (local_i = 0; local_i < input_taille; local_i++)
	{
		input_data[local_i].m_donnee = input_data[local_i].m_donnee - input_moyenne;
		local_ecart = local_ecart + pow(input_data[local_i].m_donnee, 2);
	}
	local_ecart = sqrt(local_ecart / input_taille);
	return local_ecart;
}

void ImporterMesures(Mesure* input_data, int input_taille)
{
	unsigned int i;
	ifstream fichier_in("mesures.txt");
	string ligne;

	if (fichier_in)
	{
		i = 0;
		while (getline(fichier_in, ligne))
		{
			if (!ligne.empty())
			{
				stringstream(ligne) >> input_data[i].m_date.jours >> input_data[i].m_date.mois >> input_data[i].m_date.annees >> input_data[i].m_donnee;
				i++;
			}
		}

		fichier_in.close();
	}
	else
	{
		cout << "Erreur d'ouverture du fichier." << endl;
	}
}

void Ecrire(Mesure* input_data, const int input_taille)
{
	unsigned int local_i;
	float moyenne, ecarttype;
	string ligne;

	if (fichier_out)
	{
		fichier_out << "Mesures des temperatures moyennes des ann�es saisie :" << endl;
		AfficheMesures(input_data, input_taille);
		moyenne = CalculerMoyenneMesure(input_data, input_taille);
		fichier_out << endl << "La moyenne sur les ann�es saisie est de " << moyenne << " degres Celsius." << endl;
		ecarttype = CalculerEcarttypeMesures(input_data, input_taille, moyenne);
		fichier_out << "L�ecart-type des ann�es saisie est de " << ecarttype << " degres Celsius." << endl;
		ecarttype = CalculerEcarttypeMesuresAvecRecentrage(input_data, input_taille, moyenne);
		fichier_out << "L�ecart-type des ann�es saisie est de " << ecarttype << " degres Celsius.\n" << endl;
		fichier_out << "Mesures des temperatures moyennes des ann�es saisie :" << endl;
		AfficheMesures(input_data, input_taille);

		fichier_out.close();
	}
	else
	{
		cout << "Erreur d'ouverture du fichier." << endl;
	}
}