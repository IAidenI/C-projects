#include"fonction.h"

int main()
{
	date_naissance date1;
	date1.jour = 13;
	date1.mois = 01;
	date1.annee = 2003;

	unsigned int note[UE][NB] = { {1,2,3,4,5,6,7,8,9,10}, {11,12,13,14,15,16,17,18,19,20}, {19,18,17,16,15,14,13,12,11,10} };
	float age;
	bool diplome;

	Etudiant etudiant1("Dupond", "Joseph", date1, note);

	//etudiant1.RentrerNote();
	Lecture_fichier(&etudiant1);
	etudiant1.Affiche();
	age = etudiant1.Age();
	cout << "L etudiant a " << age << " ans." << endl;
	diplome = etudiant1.ObtentionDiplome();
	if (diplome == true)
	{
		cout << "L'etudiant a sont diplome." << endl;
	}
	else
	{
		cout << "L'etudiant n'a pas sont diplome." << endl;
	}

	return 0;
}