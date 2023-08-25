#include<iostream>
#include<string>
#include"fonction.h"
#include"felin.h"

using namespace std;

int main()
{
    /** Test de la classe Animal **/
    Felin lion("Lion", "Simba", 10);
    Ongule clement("Humain", "clement", "blanc");

    lion.Affiche();
    clement.Affiche();
    lion.Chasser(&clement);

    return 0;
}
