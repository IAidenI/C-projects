#include<math.h>

#include"fonction.h"

/*
R: Calcule et retourne la distance maximal a laquelle un humain peut voir l'horizon
E: 1 r�el: la hauteur des yeux (en m)
S: 1 r�el: la distance de l'horizon (en km)
*/
float Distance_horizon(float haut)
{
	//Lexique local � Distance_horizon
	float dist;
	const unsigned int ray_terre = 6371000;

	//Algorithme local � Distance_horizon
	//D�but
	dist = (sqrt(2 * haut*ray_terre + haut * haut) / 1000);
	return dist;
	//Fin
}