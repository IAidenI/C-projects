#include"fonction.h"
/*
R: Calcule et retourne le calcul 1/(1+x*x)
E: 1 réel: la valeur d'entrée, x
S: 1réel: le résultat, res
*/
float D_atan(float x)
{
	//Lexique local à D_atan
	float res;

	//Algorithme loacl à D_atan
	//Début
	res = 1 / (1 + x * x);
	return res;
	//Fin
}