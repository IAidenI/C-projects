#include<iostream>
#include<string>
#include"fonction.h"
#include"felin.h"

using namespace std;

/*
 * Constructeur par défaut de la classe Animal ()
 */
Animal::Animal() : m_espece("Inconnu"), m_nom("Inconnu") /// Affectation des valeurs d'attributs dans la liste d'initialisation
{
    /// Affectation des valeurs d'attributs dans le corps du constructeur
    // m_espece = "Inconnu" ;
    // m_nom = "Inconnu" ;

    cout << "Constructeur par defaut de la classe Animal." << endl << endl;
}

/*
 * Constructeur de surcharge de la classe Animal (1 chaîne de caractères, 1 chaîne de caractères)
 */
Animal::Animal(std::string input_espece, std::string input_nom) : m_espece(input_espece), m_nom(input_nom)  /// Affectation des valeurs d'attributs dans la liste d'initialisation
{
    /// Affectation des valeurs d'attributs dans le corps du constructeur
    // m_espece = input_espece ;
    // m_nom = input_nom ;

    cout << "Constructeur de surcharge de la classe Animal." << endl << endl;
}

/*
 * Destructeur de la classe Animal
 */
Animal::~Animal()
{
    cout << "Destructeur de la classe Animal appele pour l'individu " << Animal::GetNom() << "." << endl << endl;
}

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

