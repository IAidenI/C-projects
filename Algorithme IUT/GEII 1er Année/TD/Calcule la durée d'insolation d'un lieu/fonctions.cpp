#include<math.h>
/*
R: Calcule et retourne la valeur en radian d'un angle en degr�
E: 1 r�el: l'angle en degr�
S: 1 r�el: l'angle en radian
*/
double Dey2rad(float deg)
{
	//Lexique local � Dey2ray
	double radian;
	const double PI = 3.141592;

	//Algorithme principal
	//D�but
	radian = deg * PI / 180;
	return radian;
	//Fin
}

/*
R: Calcule et retourne la d�clinaison du soleil en radian
E: 1 entier: le jour de l'ann�e
S: 1 r�el: la d�clinaison du soleil en radian
*/
double Declinaison(unsigned int j)
{
	//Lexique local � Declinaison
	double res;

	//Algorithme local � Declinaison
	//D�but
	res = asin(0.398*sin(0.0171915*j - 1.3962634));
	return res;
}

/*
R: Calcule et retourne la dur�e d'insolation en heure
E: 1 r�el: la latitude en degr�
   1 entier: le jour de l'ann�e
S: 1 r�el: la dur�e d'insolation en heure
*/
double Duree_insol(float lat, unsigned int jour)
{
	//Lexique local � Duree_insol
	double latitude_rad, dec, result;
	const double PI = 3.141592;
	//Algorithme local � Duree_insol
	//D�but
	latitude_rad = Dey2rad(lat);
	dec = Declinaison(jour);
	result = 24 / PI * acos(-tan(lat)*tan(dec));
	return result;
}