#include<math.h>
/*
R: Calcule et retourne le volume d'une sphère de rayon r
E: 1 réel: le rayon (en cm)
S: 1 réel: le volume (en cm)
*/
float Volume_sphere(float ray)
{
	//Lexique local à Volume_sphere
	float res;
	float PI = 3.14159265;

	//Algorithme local à Volume_shpere
	//Début
	res = 4 * PI*pow(ray, 3) / 3;
	return res;
}