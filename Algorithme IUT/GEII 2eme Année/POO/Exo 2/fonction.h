#ifndef CLASSE_ANIMAL_H_INCLUDED
#define CLASSE_ANIMAL_H_INCLUDED

#include<string>

/** CLASSE ANIMAL **/
class Animal
{
    /// Encapsulation en protégé
private:
    /** ATTRIBUTS **/
    std::string m_espece;      // L'espèce animale de l'individu
    std::string m_nom;         // Le nom de l'individu

public:
    /*
     * Constructeur par défaut de la classe Animal ()
     * {Construction des valeurs des attributs d'un objet de classe Animal}
     * Entrées :
     *     vide
     */
    Animal();

    /*
     * Constructeur de surcharge de la classe Animal (1 chaîne de caractères, 1 chaîne de caractères)
     * {Construction des valeurs des attributs d'un objet de classe Animal}
     * Entrées :
     *     input_espece     : 1 chaîne de caractères (l'espèce animale de l'individu)
     *     input_nom        : 1 chaîne de caractères (le nom de l'individu)
     */
    Animal(std::string, std::string);

    /*
     * Destructeur de la classe Animal
     *
     * Entrées :
     *     vide
     */
    ~Animal();

    /*
     * Méthode Afficher() -> vide
     * {Affichage des valeurs des attributs d'un objet de classe Animal}
     * {méthode constante (ne peut modifier le contenu de l'objet appelant)}
     * Entrées :
     *     vide
     * Sortie :
     *     vide
     */
    void Afficher() const;

    /*
     * Méthode Initialiser(1 chaîne de caractères, 1 chaîne de caractères) -> vide
     * {Initialisation des valeurs des attributs d'un objet de classe Animal}
     * {=> cette méthode est un "setter"}
     * Entrées :
     *     input_espece     : 1 chaîne de caractères (l'espèce animale de l'individu)
     *     input_nom        : 1 chaîne de caractères (le nom de l'individu)
     * Sortie :
     *     vide
     */
    void InitialiserAnimal(std::string, std::string);

    /*
     * Méthode GetEspece() -> 1 chaîne de caractères
     * {Renvoie l'espèce d'un objet de classe Animal}
     * {=> cette méthode est un "getter" = méthode constante (ne peut modifier le contenu de l'objet appelant)}
     * Entrées :
     *     vide
     * Sortie :
     *     1 chaîne de caractères (l'espèce de l'individu)
     */
    std::string GetEspece() const { return m_espece; }

    /*
     * Méthode GetNom() -> 1 chaîne de caractères
     * {Renvoie le nom d'un objet de classe Animal}
     * {=> cette méthode est un "getter" = méthode constante (ne peut modifier le contenu de l'objet appelant)}
     * Entrées :
     *     vide
     * Sortie :
     *     1 chaîne de caractères (le nom de l'individu)
     */
    std::string GetNom() const { return m_nom; }
};

#endif // E1_H_INCLUDED