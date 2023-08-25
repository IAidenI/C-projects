#include<iostream>
using namespace std;

int main()
{
	//Lexique principal
	double frcs, euro; //frcs et euro representent respectivement le nombre de francs de l'utilisateur et la valeur corespondante en euros
	const double TAUX = 6.55957;

	//Algorithme principal
	//Début
	cout << "Saisir votre nombre de francs" << endl;
	cin >> frcs;
	euro = frcs / TAUX;
	cout << frcs << " francs corespondent a " << euro << " euros" << endl;
	//Fin
	return 0;
}