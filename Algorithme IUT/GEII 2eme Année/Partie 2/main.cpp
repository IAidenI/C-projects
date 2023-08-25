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
	Mesure* data;

	ifstream fichier_in("mesures.txt");
	string ligne;
	while (getline(fichier_in, ligne))
	{
		if (!ligne.empty())
		{
			N++;
		}
	}
	fichier_in.close();

	data = new Mesure[N];

	ImporterMesures(data, N);
	Ecrire(data, N);
	cout << "[*] Fichier rempli avec les données" << endl;

	delete[] data;
	return 0;
}