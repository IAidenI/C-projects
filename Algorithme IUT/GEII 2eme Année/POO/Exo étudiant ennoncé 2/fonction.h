#include<string>
#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;
#define NB 10
#define TAILLE 50
#define UE 3
#define mois_actuelle 11

struct date_naissance
{
	unsigned int jour;
	unsigned int mois;
	unsigned int annee;
};
class Etudiant
{
private:
	string m_nom;
	string m_prenom;
	date_naissance m_date;
	unsigned int(*m_note)[TAILLE];
	unsigned int m_j[UE];
	unsigned int m_good_affiche[UE];

public:
	Etudiant();
	Etudiant(string, string, date_naissance, unsigned int[UE][NB]);
	~Etudiant();
	void Affiche();
	float Age();
	void RentrerNote();
	bool ObtentionDiplome();
	void ModifierNote();
	void AjouterNote();
	void SupprimerNote();

	//Getters
	string GetNom()
	{
		return m_nom;
	}

	string GetPrenom()
	{
		return m_prenom;
	}

	date_naissance GetDate()
	{
		return m_date;
	}

	unsigned int GetNote()
	{
		return m_note[UE][NB];
	}

	//Setters
	void SetNom(string nom)
	{
		m_nom = nom;
	}

	void SetPrenom(string prenom)
	{
		m_prenom = prenom;
	}

	void SetDate(date_naissance date)
	{
		m_date = date;
	}

	void SetNote(unsigned int note[UE][NB])
	{
		unsigned int i, j;
		for (j = 0; j < UE; j++)
		{
			for (i = 0; i < NB; i++)
			{
				m_note[j][i] = note[j][i];
			}
		}
	}
};

void VerifDiplome(bool input_diplome);