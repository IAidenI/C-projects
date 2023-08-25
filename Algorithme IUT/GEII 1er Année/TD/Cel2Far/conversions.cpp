#include"conversions.h"
/*
R: Calcule et retourne une température en far
E: 1 réel: la température en celsius
S: 1 réel: la température en fahrenheit
*/
float Cel2far(float t)
{
	//Lexique local à Cel2far
	float res;

	//Algorithme local à Cel2far
	//Début
	res = 9.0 / 5 * t + 32;
	return res;
	//Fin
}