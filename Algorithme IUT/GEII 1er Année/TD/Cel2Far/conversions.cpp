#include"conversions.h"
/*
R: Calcule et retourne une temp�rature en far
E: 1 r�el: la temp�rature en celsius
S: 1 r�el: la temp�rature en fahrenheit
*/
float Cel2far(float t)
{
	//Lexique local � Cel2far
	float res;

	//Algorithme local � Cel2far
	//D�but
	res = 9.0 / 5 * t + 32;
	return res;
	//Fin
}