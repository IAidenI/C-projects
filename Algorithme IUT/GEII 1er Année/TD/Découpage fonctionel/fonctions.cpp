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
	//Lexique local � Presentation
	//vide

	//Algorithme local � Presentation
	//D�but
	cout << "Ce programme vous permet de saisir le rayon d'un disque et la hauteur d'un cylindre (ayant pour base le disque precedant)" << endl << "a partir duquel, le perimetre et la surface du disque ainsi que le volume du cylindre forme sont calcules puis affiches." << endl << "Il affiche et calcule aussi la distance parcouru par un velo a partir du nombre de tour fait par une roue." << endl;
	//Fin
}


/*
R: Demande � l'utilisateur  d'netrer un rayon et retourne la valeur saisie
E: vide
S: 1 r�el: le rayon (en cm)
*/
float Saisie_rayon(void)
{
	//Lexique local � Saisie_rayon
	float rayon;

	//Algorithme local � Saisie_rayon
	//D�but
	cout << "Saisir le rayon du disque en cm." << endl;
	cin >> rayon;
	//Fin
	return rayon;
}


/*
R: Demande � l'utilisateur d'entrer une hauteur et retourne la valeur saisie
E: vide
S: 1 r�el: la hauteur (en cm)
*/
float Saisie_hauteur(void)
{
	//Lexique local � Saisie_hauteur
	float hauteur;

	//Algorithme principal � Saisie_hauteur
	//D�but
	cout << "Saisir la heuteur de votre cylindre en cm." << endl;
	cin >> hauteur;
	//Fin
	return hauteur;
}


/*
R: Demande � l'utilisateur le nombre de tour fait par la roue avant de son v�lo et retourne la valeur saisie
E: vide
S: 1 r�el: le nombre de tour fait par la roue
*/
float Saisie_tours(void)
{
	//Lexique local � Saisie_tours
	float tours_roue;

	//Algorithme local � Saisie-tours
	//D�but
	cout << "Saisir le nombre de tours fait par la roue avant de votre velo." << endl;
	cin >> tours_roue;
	return tours_roue;
	//Fin
}


/*
R: Calcule et retourne le p�rim�tre d'un cercle de rayon r
E: 1 r�el: le rayon (en cm)
S: 1 r�el: le p�rim�tre (en cm)
*/
float Perimetre(float r)
{
	//Lexique local � Perimetre
	float p;
	float PI = 3.14159265;

	//Algorithme local � Perimetre
	//D�but
	p = 2 * PI*r;
	return p;
	//Fin
}


/*
R: Calcule et retourne la surface d'un disque de rayon r
E: 1 r�el: le rayon (en cm)
S: 1 r�el: la surface (en cm�)
*/
float Surface(float r)
{
	//Lexique local � Surface
	float s;
	float PI = 3.14159265;

	//Algorithme local � Surface
	//D�but
	s = PI * r*r;
	return s;
	//Fin
}


/*
R: Affiche les valeurs du p�rim�tre et de la surface
E: 2 r�el: le p�rim�tre (en cm) et la surface (en cm�)
S: vide
*/
void Affiche_resultats(float p, float s)
{
	//Lexique local � Affiche_resultats
	//vide

	//Algorithme local � Affiche_resultats
	//D�but
	cout << "Le perimetre de votre disque est: " << p << " cm et sa surface est: " << s << "." << endl;
	//Fin
}


/*
R: Calcule et retourne le volume d'un cylindre
E: 2 r�el: le rayon (en cm), la hauteur (en cm)
S: 1 r�el: le volume (en cm^3)
*/
float Volume_cylindre(float rayon, float haut)
{
	//Lexique local � Volume_cylindre
	float surface, volume;

	//Algorithme local � Volume_cylindre
	//D�but
	surface = Surface(rayon);
	volume = surface * haut;
	return volume;
	//Fin
}


/*
R: Calcule et retourne la distance parcouru par un v�lo
E: 2 r�els: le rayon (en cm) et le nombre de tour fait par la roue avant
S: 1 r�el: la distance parcouru par le v�o
*/
float Distance(float rayon, float tours)
{
	//Lexique local � Distance
	float peri, dist;

	//Algorithme local � Distance
	//D�but
	peri = Perimetre(rayon);
	dist = tours * peri;
	return dist;
	//Fin
}