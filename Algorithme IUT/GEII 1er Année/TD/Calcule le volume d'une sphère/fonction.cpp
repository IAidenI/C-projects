#include<math.h>
/*
R: Calcule et retourne le volume d'une sph�re de rayon r
E: 1 r�el: le rayon (en cm)
S: 1 r�el: le volume (en cm)
*/
float Volume_sphere(float ray)
{
	//Lexique local � Volume_sphere
	float res;
	float PI = 3.14159265;

	//Algorithme local � Volume_shpere
	//D�but
	res = 4 * PI*pow(ray, 3) / 3;
	return res;
}