#include"fonctions.h"
#include<math.h>

/*
R: Calcule et retourne le p�rim�tre d'un cercle de rayon r
E:1 r�el: le rayon (en cm)
S:1 r�el: le p�rim�tre (en cm)
*/
float Perimetre(float r)
{
	//Lexique local � Perimetre
	double p; //corespond � la valeur final du p�rim�tre
	const double PI = 3.14159265;
	
	//Algorithme local � Perimetre
	//D�but
	p = 2 * PI*r;
	return p;
	//Fin
}

/*
R: Calcule et retourne la surface d'un disque de rayon r
E: 1 r�el: le rayon (en cm)
S: 1 r�el: la surface (en cm�)
*/
float Surface(float r)
{
	//Lexique local � Surface
	double s; //corespond � la valeur final de la surface
	const double PI = 3.14159265;

	//Algorithme local � Surface
	//D�but
	s = PI * pow(r, 2);
	return s;
	//Fin
}