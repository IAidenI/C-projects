#include<iostream>
using namespace std;


//**********************************************************************
#include"conversions.h"
int main()
{
	//Lexique principal
	float cel, far;

	//Algorithme principal
	//Début
	cout << "Températeur en °C: " << endl;
	cin >> cel;
	far = Cel2far(cel);
	cout << "corespond a " << far << " °F";
	//Fin
	return 0;
}