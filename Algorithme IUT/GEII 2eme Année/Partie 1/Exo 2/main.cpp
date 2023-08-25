#include <math.h>
#include <iostream>
using namespace std;

#include "fonction.h"

int main(void)
{
	setlocale(LC_ALL, "FR-fr");
	int N;
	//int tab_annees[] = {2017, 2018, 2019, 2020};
	//float tab_mesures[] = {13.4, 13.9, 13.7, 14.4};
	float moyenne, ecarttype;
	float* ptr_mesures;
	int* ptr_annees;

	cout << "Saisir la taille du tableau" << endl;
	cin >> N;
	ptr_mesures = new float[N];
	ptr_annees = new int[N];
	ImporterMesures(ptr_mesures, ptr_annees, N);

	cout << "Mesures des temperatures moyennes des années saisie :" << endl;
	AfficheMesures(ptr_annees, ptr_mesures, N);
	moyenne = CalculerMoyenneMesure(ptr_mesures, N);
	cout << endl << "La moyenne sur les années saisie est de " << moyenne << " degres Celsius." << endl;
	ecarttype = CalculerEcarttypeMesures(ptr_mesures, N, moyenne);
	cout << "L’ecart-type des années saisie est de " << ecarttype << " degres Celsius." << endl;
	ecarttype = CalculerEcarttypeMesuresAvecRecentrage(ptr_mesures, N, moyenne);
	cout << "L’ecart-type des années saisie est de " << ecarttype << " degres Celsius." << endl;
	cout << endl << "Mesures des temperatures moyennes annuelles recentrees des années saisie :" << endl;
	AfficheMesures(ptr_annees, ptr_mesures, N);

	delete[] ptr_mesures;
	delete[] ptr_annees;
	return 0;
}