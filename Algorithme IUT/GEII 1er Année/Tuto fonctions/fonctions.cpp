#include"fonctions.h"
#include<math.h>

/*
R: Calcule et retourne le périmètre d'un cercle de rayon r
E:1 réel: le rayon (en cm)
S:1 réel: le périmètre (en cm)
*/
float Perimetre(float r)
{
	//Lexique local à Perimetre
	double p; //corespond à la valeur final du périmètre
	const double PI = 3.14159265;
	
	//Algorithme local à Perimetre
	//Début
	p = 2 * PI*r;
	return p;
	//Fin
}

/*
R: Calcule et retourne la surface d'un disque de rayon r
E: 1 réel: le rayon (en cm)
S: 1 réel: la surface (en cm²)
*/
float Surface(float r)
{
	//Lexique local à Surface
	double s; //corespond à la valeur final de la surface
	const double PI = 3.14159265;

	//Algorithme local à Surface
	//Début
	s = PI * pow(r, 2);
	return s;
	//Fin
}