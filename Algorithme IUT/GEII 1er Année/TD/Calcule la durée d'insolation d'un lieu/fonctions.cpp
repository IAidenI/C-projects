#include<math.h>
/*
R: Calcule et retourne la valeur en radian d'un angle en degré
E: 1 réel: l'angle en degré
S: 1 réel: l'angle en radian
*/
double Dey2rad(float deg)
{
	//Lexique local à Dey2ray
	double radian;
	const double PI = 3.141592;

	//Algorithme principal
	//Début
	radian = deg * PI / 180;
	return radian;
	//Fin
}

/*
R: Calcule et retourne la déclinaison du soleil en radian
E: 1 entier: le jour de l'année
S: 1 réel: la déclinaison du soleil en radian
*/
double Declinaison(unsigned int j)
{
	//Lexique local à Declinaison
	double res;

	//Algorithme local à Declinaison
	//Début
	res = asin(0.398*sin(0.0171915*j - 1.3962634));
	return res;
}

/*
R: Calcule et retourne la durée d'insolation en heure
E: 1 réel: la latitude en degré
   1 entier: le jour de l'année
S: 1 réel: la durée d'insolation en heure
*/
double Duree_insol(float lat, unsigned int jour)
{
	//Lexique local à Duree_insol
	double latitude_rad, dec, result;
	const double PI = 3.141592;
	//Algorithme local à Duree_insol
	//Début
	latitude_rad = Dey2rad(lat);
	dec = Declinaison(jour);
	result = 24 / PI * acos(-tan(lat)*tan(dec));
	return result;
}