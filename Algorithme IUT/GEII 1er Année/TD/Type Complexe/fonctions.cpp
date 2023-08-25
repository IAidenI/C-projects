#include<iostream>
#include<math.h>
using namespace std;

#include"complexe.h"

/*
R: Calcule et retourne le conjugu� d'un complexe
E: 1 complexe
S: 1 complexe: son conjugu�
*/
complexe Conjugue(complexe z)
{
	//Lexiqu local � Conjugue
	complexe temp_z;

	//Algorithme local � Conjugue
	//D�but
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
	//Lexique local � Inverse
	complexe inv_z, inv_z_temp;

	//Algorithme local � Inverse
	//D�but
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
	//Lexique local � Nb_positif
	complexe z_temp;

	//Algorithme local � Nb_positif
	//D�but
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
R: Calcule et retourne l'oppos� d'un complexe
E: 1 complexe
S: 1 complexe: son oppos�
*/
complexe Oppose(complexe z)
{
	//Lexique local � Oppose
	complexe opp_z;

	//Algorithme local � Oppose
	//D�but
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
S: 1 r�el: son module
*/
float Module(complexe z)
{
	//Lexique local � Module
	float mod_z;

	//Algorithme local � Module
	//D�but
	mod_z = sqrt((z.re * z.re) + (z.im * z.im));
	return mod_z;
	//Fin
}

/*
R: Calcule et retourne l'argument d'un complexe
E: 1 complexe
S: 1 r�el: son argument
*/
float Argument(complexe z)
{
	//Lexique local � Argument
	float arg;
	const float PI = 3.14159;

	//Algorithle local � Argument
	//D�but
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