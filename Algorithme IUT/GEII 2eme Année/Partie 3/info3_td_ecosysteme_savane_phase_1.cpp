#include<iostream>
#include<string>
#include <fstream>
using namespace std;

#include "fonction.h"
#include"structures.h"

int main()
{
    cout << "*** Simulation d'un écosystème de savane africaine ***" << endl;
    
    unsigned int N_f = 0;
    unsigned int N_m = 0;
    unsigned int i = 0;
    felin* Felin = NULL;
    mammifere_ongule* Mamif = NULL;

    ifstream fichier_in("savane.txt");
    string ligne;
    if (fichier_in)
    {
        while (getline(fichier_in, ligne))
        {
            if (!ligne.empty())
            {
                switch (ligne[i])
                {
                case 'f':
                    N_f++;
                    break;
                case 'm':
                    N_m++;
                    break;
                default:
                    cout << "Erreur de l'espece." << endl;
                    break;
                }
            }
        }
        fichier_in.close();
    }
    else
    {
        cout << "Erreur d'ouverture du fichier." << endl;
    }
    Felin = new felin[N_f];
    Mamif = new mammifere_ongule[N_m];

    Initialiser(Felin);
    Initialiser(Mamif);
    Afficher(Felin, N_f);
    Afficher(Mamif, N_m);

    delete[] Mamif;
    delete[] Felin;
    Felin = NULL;


    return 0;
}
