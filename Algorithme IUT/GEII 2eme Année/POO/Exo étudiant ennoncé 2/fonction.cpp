#include"fonction.h"

Etudiant::Etudiant()
{
	unsigned int i;

	m_nom = "Inconnu";
	m_prenom = "Inconnu";
	m_date.jour = 0;
	m_date.mois = 0;
	m_date.annee = 0;
	m_note = new unsigned int[UE][TAILLE];
	
	for (i = 0; i < UE; i++)
	{
		m_j[i] = 0;
	}

	for (i = 0; i < UE; i++)
	{
		m_good_affiche[i] = NB;
	}
}

Etudiant::Etudiant(string input_nom, string input_prenom, date_naissance input_date, unsigned int input_note[UE][NB])
{
	unsigned int i, j;

	m_nom = input_nom;
	m_prenom = input_prenom;
	m_date = input_date;
	m_note = new unsigned int[UE][TAILLE];
	
	for (i = 0; i < UE; i++)
	{
		m_j[i] = 0;
	}
	
	for (i = 0; i < UE; i++)
	{
		m_good_affiche[i] = NB;
	}
	
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
	delete[] m_note;
	cout << "L'objet a ete detruit.";
}

void Etudiant::Affiche()
{
	unsigned int i, j;
	bool diplome;
	float age;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Le nom de l'etudiant est " << m_nom << "." << endl;
	cout << "Le prenom de l'etudiant est " << m_prenom << "." << endl;
	cout << "Il est nee le " << m_date.jour << "/" << m_date.mois << "/" << m_date.annee << "." << endl;

	//Affichage des notes
	for (j = 0; j < UE; j++)
	{
		cout << "Ses notes pour le " << j + 1 << " eme UE sont ";
		if (m_good_affiche[j] != NB)
		{
			for (i = 0; i < m_good_affiche[m_j[j]]; i++)
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
		else
		{
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
	}

	//Calcul et affiche l'âge
	age = Age();
	cout << "L etudiant a " << age << " ans." << endl;

	//Vérifie si l'étudiant à sont diplôme
	diplome = ObtentionDiplome();
	VerifDiplome(diplome);
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
		cout << "## Note pour le " << j + 1 << " eme UE. ##" << endl;
		cout << "############################" << endl;
		for (i = 0; i < NB; i++)
		{
			while (true)
			{
				cout << "Saisir une note" << endl;
				cout << ">";
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

void Etudiant::ModifierNote()
{
	unsigned int choix_j, choix_i, choix_note, i;

	while (true)
	{
		cout << "Saisir l'UE-Competance dans laquel se trouve la note a modifier. (commence a 1)" << endl;
		cin >> choix_j;

		if ((choix_j >= 1) && (choix_j <= 3))
		{
			choix_j -= 1;
			break;
		}
		else
		{
			cout << "Saisie invalide." << endl;
		}
	}

	while (true)
	{
		cout << "Saisir la l'emplacementde la note a modifier. (commence a 1)" << endl;
		cout << "Pour rapelle, voici les notes de UE-Competance selectionne." << endl;
		cout << "[ ";
		for (i = 0; i < NB; i++)
		{
			cout << m_note[choix_j][i] << "/20 ";
		}
		cout << "]" << endl;
		cout << ">";
		cin >> choix_i;

		if ((choix_i >= 1) && (choix_i <= 3))
		{
			choix_i -= 1;
			break;
		}
		else
		{
			cout << "Saisie invalide." << endl;
		}
	}

	while (true)
	{
		cout << "Saisir la nouvelle note." << endl;
		cin >> choix_note;

		if ((choix_note >= 0) && (choix_note <= 20))
		{
			break;
		}
		else
		{
			cout << "Saisie invalide." << endl;
		}
	}

	m_note[choix_j][choix_i] = choix_note;
}

void Etudiant::AjouterNote()
{
	unsigned int choix_j, choix_note, i;

	while (true)
	{
		cout << "Saisir l'UE-Competance dans laquel se trouve la note a ajouter. (commence a 1)" << endl;
		cout << ">";
		cin >> choix_j;

		if ((choix_j >= 1) && (choix_j <= 3))
		{
			choix_j -= 1;
			break;
		}
		else
		{
			cout << "Saisie invalide." << endl;
		}
	}

	while (true)
	{
		cout << "Saisir la note a ajouter." << endl;
		cout << ">";
		cin >> choix_note;

		if ((choix_note >= 0) && (choix_note <= 20))
		{
			break;
		}
		else
		{
			cout << "Saisie invalide." << endl;
		}
	}

	m_j[choix_j] = choix_j;
	m_note[choix_j][m_good_affiche[choix_j]] = choix_note;
	m_good_affiche[choix_j] += 1;
}

void Etudiant::SupprimerNote()
{
	unsigned int choix_j, choix_note, i, indice_suppr, nb_suppr, indice;
	char confirmation;

	while (true)
	{
		cout << "Saisir l'UE-Competance dans laquel se trouve la note a supprimer. (commence a 1)" << endl;
		cout << ">";
		cin >> choix_j;

		if ((choix_j >= 1) && (choix_j <= 3))
		{
			choix_j -= 1;
			break;
		}
		else
		{
			cout << "Saisie invalide." << endl;
		}
	}

	while (true)
	{
		cout << "Saisir l'indice de la note a supprimer (ex: [ 20/20, 19/20, 04/20 ] pour supprimer 04/20 saisir '3')." << endl;
		cout << "Pour rapelle, voici les notes de UE-Competance selectionne." << endl;
		cout << "[ ";
		for (i = 0; i < NB; i++)
		{
			cout << m_note[choix_j][i] << "/20 ";
		}
		cout << "]" << endl;
		cout << ">";
		cin >> choix_note;

		if ((choix_note >= 0) && (choix_note <= 20))
		{
			choix_note -= 1;
			break;
		}
		else
		{
			cout << "Saisie invalide." << endl;
		}
	}

	m_j[choix_j] = choix_j;
	m_good_affiche[choix_j] -= 1;
	for (i = choix_note; i < m_good_affiche[choix_j]; i++)
	{
		m_note[choix_j][i] = m_note[choix_j][i + 1];
	}
}

void VerifDiplome(bool input_diplome)
{
	if (input_diplome == true)
	{
		cout << "L'etudiant a sont diplome." << endl;
	}
	else
	{
		cout << "L'etudiant n'a pas sont diplome." << endl;
	}
}