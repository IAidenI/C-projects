#include<iostream>
using namespace std;

#include"coureur.h"

/*
R: Demande � l'utilisateur de saisir des informations sur le coureur
E: vide
S: 1 coureur
*/
coureur Saisie_coureur(void)
{
	//Lexique local � Saisie_coureur
	coureur temp_cour;

	//Algorithme local Saisie_coureur
	//D�but
	cout << "Saisir le nom (par ex: U.Bolt pour Usain Bolt)." << endl;
	cin >> temp_cour.nom;
	cout << "Saisir le numero du dossard." << endl;
	cin >> temp_cour.dos;
	cout << "Saisir la distance de la course (en m)." << endl;
	cin >> temp_cour.dist;
	cout << "Saisir le temps de reference (en s) (par  ex: 9.58)" << endl;
	cin >> temp_cour.temps_ref;
	cout << "Saisir le temps realise (en s)." << endl;
	cin >> temp_cour.temps;
	return temp_cour;
	//Fin
}

/*
R: Affiche les caract�ristiques d'un coureur
E: 1 coureur
S: vide
*/
void Affiche_coureur(coureur cour)
{
	//Lexique local Affiche_coureur
	//vide

	//Algorithme local Affiche_coureur
	//D�but
	cout << "Nom: " << cour.nom << endl;
	cout << "Dossard: " << cour.dos << endl;
	cout << "Distance de la course: " << cour.dist << endl;
	cout << "Temps de reference: " << cour.temps_ref << endl;
	cout << "Temps realise: " << cour.temps << endl;
	//Fin
}