#include<iostream>
#include<string>
#include"fonction.h"

using namespace std;

int main()
{
    /** Test de la classe Animal **/
    Animal individu("guepard", "Shakaponk");
    Animal* pt_individu2 = NULL;
    pt_individu2 = new Animal;


    pt_individu2->InitialiserAnimal("Loutre", "MegaLoutre");
    pt_individu2->Afficher();
    individu.Afficher();

    delete(pt_individu2);
    return 0;
}
