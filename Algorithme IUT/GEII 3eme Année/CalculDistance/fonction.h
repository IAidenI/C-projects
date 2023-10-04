#include <iostream>
#include <math.h>
using namespace std;

struct point2D {
    float x;
    float y;
};

/*
Nom : Calcul_Distance
Entrée : deux point2D qui vont correspondre aux deux points dont on veux la distance
Entrée/Sortie : Aucun
Sortie : un réel qui correspond à la distance entre les deux points
Traitement : Permet de calculer la distance entre deux points 2D
*/
float Calcul_Distance(point2D point_1, point2D point_2);