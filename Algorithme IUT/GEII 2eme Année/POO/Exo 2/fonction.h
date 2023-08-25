#ifndef CLASSE_ANIMAL_H_INCLUDED
#define CLASSE_ANIMAL_H_INCLUDED

#include<string>

/** CLASSE ANIMAL **/
class Animal
{
    /// Encapsulation en prot�g�
private:
    /** ATTRIBUTS **/
    std::string m_espece;      // L'esp�ce animale de l'individu
    std::string m_nom;         // Le nom de l'individu

public:
    /*
     * Constructeur par d�faut de la classe Animal ()
     * {Construction des valeurs des attributs d'un objet de classe Animal}
     * Entr�es :
     *     vide
     */
    Animal();

    /*
     * Constructeur de surcharge de la classe Animal (1 cha�ne de caract�res, 1 cha�ne de caract�res)
     * {Construction des valeurs des attributs d'un objet de classe Animal}
     * Entr�es :
     *     input_espece     : 1 cha�ne de caract�res (l'esp�ce animale de l'individu)
     *     input_nom        : 1 cha�ne de caract�res (le nom de l'individu)
     */
    Animal(std::string, std::string);

    /*
     * Destructeur de la classe Animal
     *
     * Entr�es :
     *     vide
     */
    ~Animal();

    /*
     * M�thode Afficher() -> vide
     * {Affichage des valeurs des attributs d'un objet de classe Animal}
     * {m�thode constante (ne peut modifier le contenu de l'objet appelant)}
     * Entr�es :
     *     vide
     * Sortie :
     *     vide
     */
    void Afficher() const;

    /*
     * M�thode Initialiser(1 cha�ne de caract�res, 1 cha�ne de caract�res) -> vide
     * {Initialisation des valeurs des attributs d'un objet de classe Animal}
     * {=> cette m�thode est un "setter"}
     * Entr�es :
     *     input_espece     : 1 cha�ne de caract�res (l'esp�ce animale de l'individu)
     *     input_nom        : 1 cha�ne de caract�res (le nom de l'individu)
     * Sortie :
     *     vide
     */
    void InitialiserAnimal(std::string, std::string);

    /*
     * M�thode GetEspece() -> 1 cha�ne de caract�res
     * {Renvoie l'esp�ce d'un objet de classe Animal}
     * {=> cette m�thode est un "getter" = m�thode constante (ne peut modifier le contenu de l'objet appelant)}
     * Entr�es :
     *     vide
     * Sortie :
     *     1 cha�ne de caract�res (l'esp�ce de l'individu)
     */
    std::string GetEspece() const { return m_espece; }

    /*
     * M�thode GetNom() -> 1 cha�ne de caract�res
     * {Renvoie le nom d'un objet de classe Animal}
     * {=> cette m�thode est un "getter" = m�thode constante (ne peut modifier le contenu de l'objet appelant)}
     * Entr�es :
     *     vide
     * Sortie :
     *     1 cha�ne de caract�res (le nom de l'individu)
     */
    std::string GetNom() const { return m_nom; }
};

#endif // E1_H_INCLUDED