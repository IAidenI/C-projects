#include<iostream> //iostream corespond à la bibliothèque qui contient toutes les interactions avec l'utilisateur comme cout ou cin
#include<math.h>//math.h corespond à la bibliothèque qui contient toues les fonction mathématique y compris la puissance (pow)
using namespace std;

int main()
{
	//Lexique principal
	const double PI = 3.14159265;
	double r, s; //r et s représentent respectivement le rayon du cercle et la surface

	//Algorithme principal
	//Début
	cout << "Saisir une valeur de rayon (en cm) pour votre disque." << endl;
	cin >> r;
	s = PI * pow(r, 2);
	cout << "La surface du rayon du disque de rayon " << r << " cm " << s << " cm^2.";
	//Fin
	return 0;
}