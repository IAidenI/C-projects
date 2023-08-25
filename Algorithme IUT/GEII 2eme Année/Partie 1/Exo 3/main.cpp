#include <math.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
using namespace std;

#include "fonction.h"

int main(void)
{
	setlocale(LC_ALL, "FR-fr");
	unsigned int N = 0;
	float* ptr_mesures;
	int* ptr_annees;
	
	ifstream fichier_in("mesures.txt");
	string ligne;
	while (getline(fichier_in, ligne))
	{
		N++;
	}
	fichier_in.close();

	ptr_mesures = new float[N];
	ptr_annees = new int[N];

	ImporterMesures(ptr_mesures, ptr_annees, N);
	Ecrire(ptr_mesures, ptr_annees, N);
	cout << "[*] Fichier rempli avec les données" << endl;

	delete[] ptr_mesures;
	delete[] ptr_annees;
	return 0;
}