#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
using namespace std;

#include "fonction.h"
#include"structures.h"

/***********************/
/** PROCÉDURES FELIN **/
/***********************/

/*
 * fonction Initialiser(1 pointeur sur FELIN, 1 chaine de caractères, 1 chaine de caractères, 1 réel) -> vide
 * {Fonction d'initialisation des champs d'un individu de type FELIN}
 * Entrées :
 *     local_individu : 1 pointeur sur FELIN (l'individu "appelant")
 *     local_esp      : 1 chaine de caractères (l'espèce de l'individu)
 *     local_nom      : 1 chaine de caractères (le nom de l'individu)
 *     local_machoire : 1 réel (la puissance de la machoire -> caractéristique spécifique FELIN)
 * Sortie :
 *     vide
*/

void Initialiser(felin* input_Felin)
{
    unsigned int i = 0;
    char poubelle;
    ifstream fichier_in("savane.txt");
    string ligne;
    if (fichier_in)
    {
        while (getline(fichier_in, ligne))
        {
            if (!ligne.empty() && ligne[0] == 'f')
            {
                stringstream(ligne) >> poubelle >> input_Felin[i].m_caract_animal.m_espece >> input_Felin[i].m_caract_animal.m_nom >> input_Felin[i].m_puissance_machoire;
                i++;
            }
        }

        fichier_in.close();
    }
    else
    {
        cout << "Erreur d'ouverture du fichier." << endl;
    }
}

void Initialiser(mammifere_ongule* input_mamif)
{
    unsigned int i = 0;
    char poubelle;
    ifstream fichier_in("savane.txt");
    string ligne;
    if (fichier_in)
    {
        while (getline(fichier_in, ligne))
        {
            if (!ligne.empty() && ligne[0] == 'm')
            {
                stringstream(ligne) >> poubelle >> input_mamif[i].m_caract_animal.m_espece >> input_mamif[i].m_caract_animal.m_nom >> input_mamif[i].m_couleur;
                i++;
            }
        }

        fichier_in.close();
    }
    else
    {
        cout << "Erreur d'ouverture du fichier." << endl;
    }
}


/*
 * fonction Afficher(1 pointeur sur FELIN) -> vide
 * {Fonction d'affichage des caractéristiques d'un individu de type FELIN}
 * Entrées :
 *     local_individu : 1 pointeur sur FELIN (l'individu "appelant")
 * Sortie :
 *     vide
*/
void Afficher(felin* local_individu, unsigned int input_N)
{
    unsigned int i = 0;

    while (i < input_N)
    {
        cout << endl << "Bonjour ! Mon nom est " << local_individu[i].m_caract_animal.m_nom << " et je suis de l'espece " << local_individu[i].m_caract_animal.m_espece << "." << endl;
        cout << "La puissance de ma machoire est de : " << local_individu[i].m_puissance_machoire << "." << endl;
        i++;
    }
}

void Afficher(mammifere_ongule* local_individu, unsigned int input_N)
{
    unsigned int i = 0;
    
    while (i < input_N)
    {
        cout << endl << "Bonjour ! Mon nom est " << local_individu[i].m_caract_animal.m_nom << " et je suis de l'espece " << local_individu[i].m_caract_animal.m_espece << "." << endl;
        cout << "La couleur de mon pelage est : " << local_individu[i].m_couleur << "." << endl;
        i++;
    }
}