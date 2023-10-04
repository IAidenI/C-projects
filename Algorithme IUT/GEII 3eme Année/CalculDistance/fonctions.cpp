#include "fonction.h"

float Calcul_Distance(point2D point_1, point2D point_2){
    return sqrt(pow((point_2.x - point_1.x), 2) + pow((point_2.y - point_1.y), 2));
}