#include <math.h>
#include <iostream>
using namespace std;

#include "fonction.h"

int main(void)
{
	setlocale(LC_ALL, "FR-fr");
	int N = 4;
	float moyenne, ecarttype;
	int tab_annees[] = {2017, 2018, 2019, 2020};
	float tab_mesures[] = {13.4, 13.9, 13.7, 14.4};

	cout << "Mesures des temperatures moyennes des années saisie :" << endl;
	AfficheMesures(tab_annees, tab_mesures, N);
	moyenne = CalculerMoyenneMesure(tab_mesures, N);
	cout << endl << "La moyenne sur les années saisie est de " << moyenne << " degres Celsius." << endl;
	ecarttype = CalculerEcarttypeMesures(tab_mesures, N, moyenne);
	cout << "L’ecart-type des années saisie est de " << ecarttype << " degres Celsius." << endl;
	ecarttype = CalculerEcarttypeMesuresAvecRecentrage(tab_mesures, N, moyenne);
	cout << "L’ecart-type des années saisie est de " << ecarttype << " degres Celsius." << endl;
	cout << endl << "Mesures des temperatures moyennes annuelles recentrees des années saisie :" << endl;
	AfficheMesures(tab_annees, tab_mesures, N);

	return 0;
}