#include<iostream>
#include<string>
using namespace std;

struct Coordonnee
{
	double latitude;
	double longitude;
};

class Ville
{
private:
	string m_nom;
	int m_code_postal;
	Coordonnee m_coordonnee;

public:
	Ville();
	Ville(string, int, Coordonnee);
	~Ville();
	void Afficher() const;
	float DistanceKms(Ville*);

	//Getters
	string GetVille_nom() const
	{
		return m_nom;
	}

	int GetVille_code() const
	{
		return m_code_postal;
	}

	Coordonnee GetVille_coordonnee() const
	{
		return m_coordonnee;
	}

	//Setters
	void SetVille_nom(string nom)
	{
		m_nom = nom;
	}

	void SetVille_code(int code_postal)
	{
		m_code_postal = code_postal;
	}

	void SetVille_coordonnee(Coordonnee coordonnee)
	{
		m_coordonnee = coordonnee;
	}
};

void Lecture_fichier(Ville* input_ville, unsigned int input_taille);
float Itineraire(Ville* input_ville, unsigned int input_taille);
unsigned int CompterLigne(void);