#include <math.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

void AfficheMesures(const int input_tab_annees[], const float input_tab_mesures[], const int input_taille)
{
	int local_i;

	for (local_i = 0; local_i < input_taille; local_i++)
	{
		cout << "Annee " << input_tab_annees[local_i] << " : " << input_tab_mesures[local_i] << " degres Celsius." << endl;
	}
}

float CalculerMoyenneMesure(const float input_tab_mesures[], int input_taille)
{
	int local_i;
	float local_moyenne;

	local_moyenne = 0;
	for (local_i = 0; local_i < input_taille; local_i++)
	{
		local_moyenne = local_moyenne + input_tab_mesures[local_i];
	}
	local_moyenne = local_moyenne / input_taille;
	return local_moyenne;
}

float CalculerEcarttypeMesures(const float input_tab_mesures[], int input_taille, float input_moyenne)
{
	int local_i;
	float local_ecart;

	local_ecart = 0;
	for (local_i = 0; local_i < input_taille; local_i++)
	{
		local_ecart = local_ecart + pow(input_tab_mesures[local_i] - input_moyenne, 2);
	}
	local_ecart = sqrt(local_ecart / input_taille);
	return local_ecart;
}

float CalculerEcarttypeMesuresAvecRecentrage(float input_tab_mesures[], int input_taille, float input_moyenne)
{
	int local_i;
	float local_ecart;

	local_ecart = 0;
	for (local_i = 0; local_i < input_taille; local_i++)
	{
		input_tab_mesures[local_i] = input_tab_mesures[local_i] - input_moyenne;
		local_ecart = local_ecart + pow(input_tab_mesures[local_i], 2);
	}
	local_ecart = sqrt(local_ecart / input_taille);
	return local_ecart;
}

void ImporterMesures(float input_tab_mesures[], int input_tab_annees[], int input_taille)
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
				stringstream(ligne) >> input_tab_annees[i] >> input_tab_mesures[i];
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

void Ecrire(float input_tab_mesures[], const int input_tab_annees[], const int input_taille)
{
	unsigned int local_i;
	float moyenne, ecarttype;
	ofstream fichier_out("résultat.txt");
	string ligne;

	if (fichier_out)
	{
		local_i = 0;
		fichier_out << "Mesures des temperatures moyennes des années saisie :" << endl;
		for (local_i = 0; local_i < input_taille; local_i++)
		{
			fichier_out << "Annee " << input_tab_annees[local_i] << " : " << input_tab_mesures[local_i] << " degres Celsius." << endl;
		}
		moyenne = CalculerMoyenneMesure(input_tab_mesures, input_taille);
		fichier_out << endl << "La moyenne sur les années saisie est de " << moyenne << " degres Celsius." << endl;
		ecarttype = CalculerEcarttypeMesures(input_tab_mesures, input_taille, moyenne);
		fichier_out << "L’ecart-type des années saisie est de " << ecarttype << " degres Celsius." << endl;
		ecarttype = CalculerEcarttypeMesuresAvecRecentrage(input_tab_mesures, input_taille, moyenne);
		fichier_out << "L’ecart-type des années saisie est de " << ecarttype << " degres Celsius." << endl;
		fichier_out << endl << "Mesures des temperatures moyennes annuelles recentrees des années saisie :" << endl;
		local_i = 0;
		fichier_out << "Mesures des temperatures moyennes des années saisie :" << endl;
		for (local_i = 0; local_i < input_taille; local_i++)
		{
			fichier_out << "Annee " << input_tab_annees[local_i] << " : " << input_tab_mesures[local_i] << " degres Celsius." << endl;
		}

		fichier_out.close();
	}
	else
	{
		cout << "Erreur d'ouverture du fichier." << endl;
	}
}