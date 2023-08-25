#include <locale>

struct Date
{
	int jours;
	string mois;
	int annees;
};

struct Mesure
{
	Date m_date;
	float m_donnee;
	string unite;
};

void AfficheMesures(const Mesure input_data[], const int input_taille);

float CalculerMoyenneMesure(const Mesure input_data[], int input_taille);

float CalculerEcarttypeMesures(const Mesure input_data[], int input_taille, float input_moyenne);

float CalculerEcarttypeMesuresAvecRecentrage(Mesure input_data[], int input_taille, float input_moyenne);

void ImporterMesures(Mesure* input_data, int input_taille);

void Ecrire(Mesure* input_data, const int input_taille);