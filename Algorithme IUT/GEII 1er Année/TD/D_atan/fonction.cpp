#include"fonction.h"
/*
R: Calcule et retourne le calcul 1/(1+x*x)
E: 1 r�el: la valeur d'entr�e, x
S: 1r�el: le r�sultat, res
*/
float D_atan(float x)
{
	//Lexique local � D_atan
	float res;

	//Algorithme loacl � D_atan
	//D�but
	res = 1 / (1 + x * x);
	return res;
	//Fin
}