#include"fonction.h"

/*
R: Calcule et retourne la taille g�n�tique
E: 2 r�els: les tailles des parents et 1 charact�re: le sexe de l'enfant
S: 1 r�el: la taille g�n�tique
*/
float Taille_genetique(float taille_pere, float taille_mere, char sexe_enfant)
{
	//Lexique local � Taille_genetique
	float taille_enfant;

	//Algorithme local � Taille_genetique
	//D�but
	if (sexe_enfant == 'h')
	{
		taille_enfant = ((taille_pere + taille_mere) / 2) + 6;
	}
	else
	{
		taille_enfant = ((taille_pere + taille_mere) / 2) - 6;
	}
	return taille_enfant;
	//Fin Si
	//Fin
}