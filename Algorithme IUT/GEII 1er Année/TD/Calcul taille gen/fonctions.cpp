#include"fonction.h"

/*
R: Calcule et retourne la taille génétique
E: 2 réels: les tailles des parents et 1 charactère: le sexe de l'enfant
S: 1 réel: la taille génétique
*/
float Taille_genetique(float taille_pere, float taille_mere, char sexe_enfant)
{
	//Lexique local à Taille_genetique
	float taille_enfant;

	//Algorithme local à Taille_genetique
	//Début
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