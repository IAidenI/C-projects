#include<iostream>
#include<string>
#include"fonction.h"

using namespace std;

int main()
{
    /** Test de la classe Animal **/
    Animal individu1;
    Animal* pt_individu = NULL;
    Animal* pt_individu2 = NULL;
    pt_individu2 = new Animal;

    pt_individu = &individu1;

    pt_individu2->m_espece = "Loutre";
    pt_individu2->m_nom = "MegaLoutre";
    cout << pt_individu2->m_espece << endl;
    cout << pt_individu2->m_nom << endl;

    delete(pt_individu2);
    return 0;
}
