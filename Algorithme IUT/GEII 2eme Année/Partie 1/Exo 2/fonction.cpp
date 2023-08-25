#include <math.h>
#include <iostream>
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
	int local_i;
	int local_annee;
	float local_temperature;

	for (local_i = 0; local_i < input_taille; local_i++)
	{
		cout << "Saisir une annee:" << endl;
		cin >> local_annee;
		input_tab_annees[local_i] = local_annee;
		cout << "Saisir la temperature corespondante:" << endl;
		cin >> local_temperature;
		input_tab_mesures[local_i] = local_temperature;
	}
}