#include<iostream>
using namespace std;

int main()
{
	//Lexique principal
	unsigned int sec, h, m, s; //Corespond respectivement aux variables secondes entr�e par l'utilisateur et heures, minutes, secondes sorti par l'algo

	//Algorithme principal
	//D�but
	cout << "Saisir votre nombre de secondes a convertir en h:m:s" << endl;
	cin >> sec;
	h = sec / 3600;
	m = sec % 3600;
	m = m / 60;
	s = sec % 3600;
	cout << sec << " secondes corespondent a " << h << ":" << m << ":" << s << endl;
	//Fin
	return 0;
}