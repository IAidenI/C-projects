#include<iostream>
using namespace std;

#include"triangle_inverse.h"

int main()
{
	//Lexique principal
	int l;

	//Algorithme principal
	cout << "Saisir un nombre de lignes." << endl;
	cin >> l;
	Triangle_inverse(l);
}