#include<iostream>
using namespace std;

#include"nombre_1_50.h"

/*
R: Affiche un message d'erreur si le nombre n'est pas entre 1 et 50
E: 1 r�el: 1 nombre
S: vide
*/
void Nombre(float nb)
{
	//Lexique local � Nombre
	//vide

	//Algorithme local � Nombre
	//D�but
	if (nb < 1 || nb>50)
	{
		cout << "Erreur, le nombre saisi n'est pas entre 1 et 50." << endl;
	}
}