#include<iostream>
#include<string>
#include"fonction.h"

using namespace std;

/*
 * Méthode Afficher() -> vide
 */
void Animal::Afficher() const
{
    cout << "-----------------------------------------------------------" << endl;
    cout << "Mon nom est " << m_nom << "." << endl;
    cout << "Je suis de l'espece " << m_espece << "." << endl;
    cout << "-----------------------------------------------------------" << endl;
}

/*
 * Méthode InitialiserAnimal(1 chaîne de caractères, 1 chaîne de caractères) -> vide
 */
void Animal::InitialiserAnimal(std::string input_espece, std::string input_nom)
{
    // Affectation des valeurs des "input_" aux attributs "m_" respectifs de l'objet appelant
    m_espece = input_espece;
    m_nom = input_nom;
}

