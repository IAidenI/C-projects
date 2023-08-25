#include<iostream>
#include<math.h>
using namespace std;

#include"complexe.h"

/*
R: Calcule et retourne le conjugué d'un complexe
E: 1 complexe
S: 1 complexe: son conjugué
*/
complexe Conjugue(complexe z)
{
	//Lexiqu local à Conjugue
	complexe temp_z;

	//Algorithme local à Conjugue
	//Début
	if (z.im < 0)
	{
		temp_z.re = z.re;
		temp_z.im = z.im;
	}
	else // z.im > 0
	{
		temp_z.re = z.re;
		temp_z.im = -z.im;
	}
	return temp_z;
}

/*
R: Calcule et retourne l'inverse d'un complexe
E: 1 complexe
S: 1 complexe: son inverse
*/
complexe Inverse(complexe z)
{
	//Lexique local à Inverse
	complexe inv_z, inv_z_temp;

	//Algorithme local à Inverse
	//Début
	inv_z_temp = Nb_positif(z);
		inv_z.re = inv_z_temp.re / (inv_z_temp.re * inv_z_temp.re + inv_z_temp.im * inv_z_temp.im);
		inv_z.im = inv_z_temp.im / (inv_z_temp.re * inv_z_temp.re + inv_z_temp.im * inv_z_temp.im);
	return inv_z;
	//Fin
}

/*
R: Verifie qu'un nombre complexe est bien positif
E: 1 complexe 
S: vide
*/
complexe Nb_positif(complexe z)
{
	//Lexique local à Nb_positif
	complexe z_temp;

	//Algorithme local à Nb_positif
	//Début
	if ((z.re == 0) || (z.im == 0))
	{
		do
		{
			cout << "Operation impossible car division par 0 impossible." << endl;
			cout << "Saisir la partie reel d'un nombre complexe." << endl;
			cin >> z_temp.re;
			cout << "Saisir la partie imaginaire d'un nombre complexe." << endl;
			cin >> z_temp.im;
		} while ((z_temp.re == 0) || (z_temp.im == 0));
	}
	return z_temp;
}

/*
R: Calcule et retourne l'opposé d'un complexe
E: 1 complexe
S: 1 complexe: son opposé
*/
complexe Oppose(complexe z)
{
	//Lexique local à Oppose
	complexe opp_z;

	//Algorithme local à Oppose
	//Début
	opp_z = z;
	if (opp_z.re < 0)
	{
		opp_z.re = z.re;
		if (opp_z.im < 0)
		{
			opp_z.im = z.re;
		}
		else // opp_z.im > 0
		{
			opp_z.im = -z.re;
		}
		//FinSi
	}
	else // opp_z.re > 0
	{
		opp_z.re = -z.re;
		if (opp_z.im < 0)
		{
			opp_z.im = z.re;
		}
		else // opp_z.im
		{
			opp_z.im = -z.re;
		}
		//FinSi
	}
	//FinSi
	return opp_z;
	//Fin
}

/*
R: Calcule et retourne le module d'un complexe
E: 1 complexe
S: 1 réel: son module
*/
float Module(complexe z)
{
	//Lexique local à Module
	float mod_z;

	//Algorithme local à Module
	//Début
	mod_z = sqrt((z.re * z.re) + (z.im * z.im));
	return mod_z;
	//Fin
}

/*
R: Calcule et retourne l'argument d'un complexe
E: 1 complexe
S: 1 réel: son argument
*/
float Argument(complexe z)
{
	//Lexique local à Argument
	float arg;
	const float PI = 3.14159;

	//Algorithle local à Argument
	//Début
	if (z.re == 0)
	{
		if (z.im == 0)
		{
			arg = 0;
		}
		else // z.im != 0
		{
			if (z.im > 0)
			{
				arg = PI / 2;
			}
			else // z.im < 0
			{
				arg = -PI / 2;
			}
			//FinSi
		}
		//FinSi
	}
	else // z.re != 0
	{
		if (z.re > 0)
		{
			arg = atan(z.im / z.re);
		}
		else // z.re < 0
		{
			arg = atan(z.im / z.re) + PI;
			if (arg > PI)
			{
				while (arg > PI)
				{
					arg = arg - 2 * PI;
				}
				//FinTantque
			}
			//FinSi
		}
		//FinSi
		//FinSi
	}
	//FinSi
	return arg;
	//Fin
}