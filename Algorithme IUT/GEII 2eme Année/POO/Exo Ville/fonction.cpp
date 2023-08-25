#include"fonction.h"
#include <fstream>
#include <ostream>
#include <sstream>
#include<math.h>


Ville::Ville()
{
	m_nom = "Inconnu";
	m_code_postal = 00000;
	m_coordonnee.latitude = 0.0000;
	m_coordonnee.longitude = 0.0000;
}

Ville::Ville(string input_nom, int input_code_postal, Coordonnee input_coordonne_gps)
{
	m_nom = input_nom;
	m_code_postal = input_code_postal;
	m_coordonnee.latitude = input_coordonne_gps.latitude;
	m_coordonnee.longitude = input_coordonne_gps.longitude;
}

Ville::~Ville()
{
	cout << "L'objet a ete detruit" << endl;
}

void Ville::Afficher() const
{
	cout << "-----------------------------------------------------------" << endl;
	cout << "Le nom de la ville est " << m_nom << "." << endl;
	cout << "Son code postal est " << m_code_postal << "." << endl;
	cout << "Ses coordonnes GPS sont " << m_coordonnee.latitude << " " << m_coordonnee.longitude << "." << endl;
	cout << "-----------------------------------------------------------" << endl;
}

float Ville::DistanceKms(Ville* input_ville2)
{
	float distance = 0;
	unsigned int rayon_terre = 6378000;
	float conversion = 3.1415926/180;

	distance = rayon_terre * acos(sin(m_coordonnee.latitude * conversion) * sin(input_ville2->m_coordonnee.latitude * conversion) + cos(m_coordonnee.latitude * conversion) * cos(input_ville2->m_coordonnee.latitude * conversion) * cos(input_ville2->m_coordonnee.longitude * conversion - m_coordonnee.longitude * conversion));
	return distance;
}

float Itineraire(Ville* input_ville, unsigned int input_taille)
{
	float dist_f = 0;
	unsigned int i;
	for (i = 0; i < input_taille - 1; i++)
	{
		dist_f += input_ville[i].DistanceKms(&input_ville[i+1]);
	}
	return dist_f;
}

void Lecture_fichier(Ville* input_ville, unsigned int input_taille)
{
	unsigned int i;
	string nom;
	int code_postal;
	Coordonnee coo_gps;
	ifstream fichier_in("villes.txt");
	string ligne;

	if (fichier_in)
	{
		i = 0;
		while (getline(fichier_in, ligne))
		{
			if (!ligne.empty())
			{
				stringstream(ligne) >> nom >> code_postal >> coo_gps.latitude >> coo_gps.longitude;
				input_ville[i].SetVille_nom(nom);
				input_ville[i].SetVille_code(code_postal);
				input_ville[i].SetVille_coordonnee(coo_gps);
				i++;
			}
		}
		fichier_in.close();
	}
}

unsigned int CompterLigne(void)
{
	unsigned int N = 0;
	ifstream fichier_in("villes.txt");
	string ligne;
	while (getline(fichier_in, ligne))
	{
		if (!ligne.empty())
		{
			N++;
		}
	}
	fichier_in.close();
	return N;
}