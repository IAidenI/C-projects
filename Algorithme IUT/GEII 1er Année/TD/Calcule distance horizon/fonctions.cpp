#include<math.h>

#include"fonction.h"

/*
R: Calcule et retourne la distance maximal a laquelle un humain peut voir l'horizon
E: 1 réel: la hauteur des yeux (en m)
S: 1 réel: la distance de l'horizon (en km)
*/
float Distance_horizon(float haut)
{
	//Lexique local à Distance_horizon
	float dist;
	const unsigned int ray_terre = 6371000;

	//Algorithme local à Distance_horizon
	//Début
	dist = (sqrt(2 * haut*ray_terre + haut * haut) / 1000);
	return dist;
	//Fin
}