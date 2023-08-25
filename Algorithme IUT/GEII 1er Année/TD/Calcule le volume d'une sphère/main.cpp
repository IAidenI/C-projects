#include<iostream>
using namespace std;
#include"fonction.h"

int main()
{
	//Lexique principal
	float ray_sphere, vol_sphere;

	//Algorithme principal
	//Début
	cout << "Saisir le rayon de votre sphere en cm." << endl;
	cin >> ray_sphere;
	vol_sphere = Volume_sphere(ray_sphere);
	cout << "Le volume de votre sphere de rayon r = " << ray_sphere << " est de " << vol_sphere << " cm^3." << endl;
	//Fin
	return 0;
}