#include<iostream>
using namespace std;

#include"Definition_fonctions.h"


/*
R: Ecxplique ce que fait le programme
E: vide
S: vide
*/
void Presentation(void)
{
	//Lexique local à Presentation
	//vide

	//Algorithme local à Presentation
	//Début
	cout << "Ce programme vous permet de saisir le rayon d'un disque et la hauteur d'un cylindre (ayant pour base le disque precedant)" << endl << "a partir duquel, le perimetre et la surface du disque ainsi que le volume du cylindre forme sont calcules puis affiches." << endl << "Il affiche et calcule aussi la distance parcouru par un velo a partir du nombre de tour fait par une roue." << endl;
	//Fin
}


/*
R: Demande à l'utilisateur  d'netrer un rayon et retourne la valeur saisie
E: vide
S: 1 réel: le rayon (en cm)
*/
float Saisie_rayon(void)
{
	//Lexique local à Saisie_rayon
	float rayon;

	//Algorithme local à Saisie_rayon
	//Début
	cout << "Saisir le rayon du disque en cm." << endl;
	cin >> rayon;
	//Fin
	return rayon;
}


/*
R: Demande à l'utilisateur d'entrer une hauteur et retourne la valeur saisie
E: vide
S: 1 réel: la hauteur (en cm)
*/
float Saisie_hauteur(void)
{
	//Lexique local à Saisie_hauteur
	float hauteur;

	//Algorithme principal à Saisie_hauteur
	//Début
	cout << "Saisir la heuteur de votre cylindre en cm." << endl;
	cin >> hauteur;
	//Fin
	return hauteur;
}


/*
R: Demande à l'utilisateur le nombre de tour fait par la roue avant de son vélo et retourne la valeur saisie
E: vide
S: 1 réel: le nombre de tour fait par la roue
*/
float Saisie_tours(void)
{
	//Lexique local à Saisie_tours
	float tours_roue;

	//Algorithme local à Saisie-tours
	//Début
	cout << "Saisir le nombre de tours fait par la roue avant de votre velo." << endl;
	cin >> tours_roue;
	return tours_roue;
	//Fin
}


/*
R: Calcule et retourne le périmètre d'un cercle de rayon r
E: 1 réel: le rayon (en cm)
S: 1 réel: le périmètre (en cm)
*/
float Perimetre(float r)
{
	//Lexique local à Perimetre
	float p;
	float PI = 3.14159265;

	//Algorithme local à Perimetre
	//Début
	p = 2 * PI*r;
	return p;
	//Fin
}


/*
R: Calcule et retourne la surface d'un disque de rayon r
E: 1 réel: le rayon (en cm)
S: 1 réel: la surface (en cm²)
*/
float Surface(float r)
{
	//Lexique local à Surface
	float s;
	float PI = 3.14159265;

	//Algorithme local à Surface
	//Début
	s = PI * r*r;
	return s;
	//Fin
}


/*
R: Affiche les valeurs du périmètre et de la surface
E: 2 réel: le périmètre (en cm) et la surface (en cm²)
S: vide
*/
void Affiche_resultats(float p, float s)
{
	//Lexique local à Affiche_resultats
	//vide

	//Algorithme local à Affiche_resultats
	//Début
	cout << "Le perimetre de votre disque est: " << p << " cm et sa surface est: " << s << "." << endl;
	//Fin
}


/*
R: Calcule et retourne le volume d'un cylindre
E: 2 réel: le rayon (en cm), la hauteur (en cm)
S: 1 réel: le volume (en cm^3)
*/
float Volume_cylindre(float rayon, float haut)
{
	//Lexique local à Volume_cylindre
	float surface, volume;

	//Algorithme local à Volume_cylindre
	//Début
	surface = Surface(rayon);
	volume = surface * haut;
	return volume;
	//Fin
}


/*
R: Calcule et retourne la distance parcouru par un vélo
E: 2 réels: le rayon (en cm) et le nombre de tour fait par la roue avant
S: 1 réel: la distance parcouru par le véo
*/
float Distance(float rayon, float tours)
{
	//Lexique local à Distance
	float peri, dist;

	//Algorithme local à Distance
	//Début
	peri = Perimetre(rayon);
	dist = tours * peri;
	return dist;
	//Fin
}