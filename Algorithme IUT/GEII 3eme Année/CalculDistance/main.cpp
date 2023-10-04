#include"fonction.h"

int main() {
    point2D point_1, point_2;
    float distance = 0;

    point_1.x = 4;
    point_1.y = 8;

    point_2.x = 5;
    point_2.y = 10;

    cout << "Point 1 : x = " << point_1.x << "; y = " << point_1.y << endl;
    cout << "Point 2 : x = " << point_2.x << "; y = " << point_2.y << endl;

    distance = Calcul_Distance(point_1, point_2);

    cout << "La distance entre le point 1 et le point 2 est de : d = " << distance << endl;

    return 0;
}
