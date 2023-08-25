#include <locale>

void AfficheMesures(const int input_tab_annees[], const float input_tab_mesures[], const int input_taille);

float CalculerMoyenneMesure(const float input_tab_mesures[], int input_taille);

float CalculerEcarttypeMesures(const float input_tab_mesures[], int input_taille, float input_moyenne);

float CalculerEcarttypeMesuresAvecRecentrage(float input_tab_mesures[], int input_taille, float input_moyenne);

void ImporterMesures(float input_tab_mesures[], int input_tab_annees[], int input_taille);