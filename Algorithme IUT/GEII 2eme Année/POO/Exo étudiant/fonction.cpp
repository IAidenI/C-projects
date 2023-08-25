#include"fonction.h"

Etudiant::Etudiant()
{
	unsigned int i, j;

	m_nom = "Inconnu";
	m_prenom = "Inconnu";
	m_date.jour = 0;
	m_date.mois = 0;
	m_date.annee = 0;
	for (j = 0; j < UE; i++)
	{
		for (i = 0; i < NB; i++)
		{
			m_note[j][i] = 0;
		}
	}
}

Etudiant::Etudiant(string input_nom, string input_prenom, date_naissance input_date, unsigned int input_note[UE][NB])
{
	unsigned int i, j;

	m_nom = input_nom;
	m_prenom = input_prenom;
	m_date.jour = input_date.jour;
	m_date.mois = input_date.mois;
	m_date.annee = input_date.annee;
	for (j = 0; j < UE; j++)
	{
		for (i = 0; i < NB; i++)
		{
			m_note[j][i] = input_note[j][i];
		}
	}
}

Etudiant::~Etudiant()
{
	cout << "L'objet a ete detruit.";
}

void Etudiant::Affiche() const
{
	unsigned int i, j;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Le nom de l'etudiant est " << m_nom << "." << endl;
	cout << "Le prenom de l'etudiant est " << m_prenom << "." << endl;
	cout << "Il est nee le " << m_date.jour << "/" << m_date.mois << "/" << m_date.annee << "." << endl;
	for (j = 0; j < UE; j++)
	{
		cout << "Ses notes pour le " << j + 1 << " eme UE sont ";
		for (i = 0; i < NB; i++)
		{
			if (m_note[j][i] < 10)
			{
				cout << "0" << m_note[j][i] << "/20 ";
			}
			else
			{
				cout << m_note[j][i] << "/20 ";
			}
		}
		cout << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
}

float Etudiant::Age()
{
	float age;

	age = 2022 - m_date.annee;
	age += (mois_actuelle - m_date.mois) / 12.0;

	return age;
}

void Etudiant::RentrerNote()
{
	unsigned int i, j, note;

	for (j = 0; j < UE; j++)
	{
		cout << "############################" << endl;
		cout << "## Note pour le " << j + 1  << " eme UE. ##" << endl;
		cout << "############################" << endl;
		for (i = 0; i < NB; i++)
		{
			while (true)
			{
				cout << "Saisir une note" << endl;
				cin >> note;
				if ((note >= 0) && (note <= 20))
				{
					break;
				}
				else
				{
					cout << "Erreur de saisie." << endl;
				}
			}
			m_note[j][i] = note;
		}
	}
}

bool Etudiant::ObtentionDiplome()
{
	unsigned int i, j;
	bool diplome, diplome_past;
	float moyenne = 0;

	for (j = 0; j < UE; j++)
	{
		for (i = 0; i < NB; i++)
		{
			moyenne += m_note[j][i];
		}
		moyenne /= i;


		if (moyenne >= 10.0)
		{
			diplome = true;
		}
		else
		{
			diplome = false;
			break;
		}

		diplome_past = diplome;
	}

	return diplome;
}

void Lecture_fichier(Etudiant* input_etudiant)
{
	unsigned int i, j, k;
	unsigned int notes[UE][NB];
	ifstream fichier_in("notes.txt");
	string ligne;

	if (fichier_in)
	{
		i = 0;
		j = 0;
		while (getline(fichier_in, ligne))
		{
			if (!ligne.empty())
			{
				for (i = 0; i < NB; i++)
				{
					getline(fichier_in, ligne);
					stringstream(ligne) >> notes[j][i];
				}
				j++;
			}
		}
		input_etudiant->SetNote(notes);
		fichier_in.close();
	}
}