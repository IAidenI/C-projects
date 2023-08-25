#include"fonction.h"

int main()
{
	//Set menu
	unsigned int choix;
	
	//Set date naissance
	date_naissance date1;
	date1.jour = 13;
	date1.mois = 01;
	date1.annee = 2003;

	//Set etudiant
	unsigned int note[UE][NB];
	unsigned int note_set[UE][NB] = { {1,2,3,4,5,6,7,8,9,10}, {11,12,13,14,15,16,17,18,19,20}, {19,18,17,16,15,14,13,12,11,10} };

	Etudiant etudiant1("Dupond", "Joseph", date1, note_set);

	while (true)
	{
		cout << "##################################" << endl;
		cout << "## [1] Pour rentrer des notes.  ##" << endl;
		cout << "## [2] Pour modifier une note.  ##" << endl;
		cout << "## [3] Pour ajouter une note.   ##" << endl;
		cout << "## [4] Pour supprimer une note. ##" << endl;
		cout << "## [5] Pour simple affichage.   ##" << endl;
		cout << "## [99] Pour quitter.           ##" << endl;
		cout << "##################################" << endl;
		cout << ">";
		cin >> choix;

		switch (choix)
		{
		case 1:
			//Saisir des notes et les afficher
			etudiant1.RentrerNote();
			etudiant1.Affiche();
			break;

		case 2:
			//Modifier une note existante
			etudiant1.ModifierNote();
			cout << "[+] Notes modifier." << endl;
			etudiant1.Affiche();
			break;

		case 3:
			//Ajouter une note
			etudiant1.AjouterNote();
			cout << "[+] Notes ajouter." << endl;
			etudiant1.Affiche();
			break;

		case 4:
			//Supprimer une note
			etudiant1.SupprimerNote();
			cout << "[+] Note supprimer." << endl;
			etudiant1.Affiche();
			break;

		case 5:
			//Simple affichage
			etudiant1.Affiche();
			break;

		case 99:
			//Sortie
			cout << "Au revoir." << endl;
			etudiant1.~Etudiant();
			exit(EXIT_SUCCESS);
			break;

		default:
			cout << "Erreur de saisie." << endl;
			break;
		}
	}

	return 0;
}