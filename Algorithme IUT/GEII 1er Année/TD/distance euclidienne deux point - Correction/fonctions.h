struct point2d
{
	float x;
	float y;
};

int Saisie_point2d(point2d tab2d[], int taille);

float Distance(point2d p, point2d q);

void Affiche_coord(int tp, point2d tab2d[]);