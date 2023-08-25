#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include<iostream>
using namespace std;
#include<string>

struct animal
{
    string m_espece;
    string m_nom;
};

/* Déclaration de la structure FELIN */
struct felin {
    animal m_caract_animal;
    float m_puissance_machoire;
};

struct mammifere_ongule
{
    animal m_caract_animal;
    string m_couleur;
};

#endif // STRUCTURES_H_INCLUDED
