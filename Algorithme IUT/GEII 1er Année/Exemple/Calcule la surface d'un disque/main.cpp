#include<iostream> //iostream corespond � la biblioth�que qui contient toutes les interactions avec l'utilisateur comme cout ou cin
#include<math.h>//math.h corespond � la biblioth�que qui contient toues les fonction math�matique y compris la puissance (pow)
using namespace std;

int main()
{
	//Lexique principal
	const double PI = 3.14159265;
	double r, s; //r et s repr�sentent respectivement le rayon du cercle et la surface

	//Algorithme principal
	//D�but
	cout << "Saisir une valeur de rayon (en cm) pour votre disque." << endl;
	cin >> r;
	s = PI * pow(r, 2);
	cout << "La surface du rayon du disque de rayon " << r << " cm " << s << " cm^2.";
	//Fin
	return 0;
}