#include<iostream>
using namespace std;


//**********************************************************************
#include"conversions.h"
int main()
{
	//Lexique principal
	float cel, far;

	//Algorithme principal
	//D�but
	cout << "Temp�rateur en �C: " << endl;
	cin >> cel;
	far = Cel2far(cel);
	cout << "corespond a " << far << " �F";
	//Fin
	return 0;
}