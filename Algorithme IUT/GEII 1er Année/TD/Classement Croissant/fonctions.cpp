#include<iostream>
using namespace std;

#include"croissant.h"

/*
R: Affiche 3 nombre dans l'ordre croissant
E: 3 r�els: 3 nombres
S: 3 r�els: les 3 nombres dans l'ordre croissant
*/
float Croissant(float a, float b, float c)
{
	//Lexique local � Croissant


	//Algorithme local � Croissant
	//D�but
	if (a < b)
	{
		if (b < c)
		{
			cout << a << "<" << b << "<" << c;
		}
		else
		{
			if (a < c)
			{
				cout << a << "<" << c << "<" << b;
			}
			else
			{
				cout << c << "<" << a << "<" << b;
			}
		}
	}
	else
	{
		if (a < c)
		{
			cout << b << "<" << a << "<" << c;
		}
		else
		{
			if (b < c)
			{
				cout << b << "<" << c << "<" << a;
			}
			else
			{
				cout << c << "<" << b << "<" << a;
			}
		}
	}
	return 0;
}