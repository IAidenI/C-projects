#include"fonction.h"

int main(void)
{
	Cellule cellule1("Michel", 0, 10, 0);
	Cellule cellule2;

	cellule1.Affiche();
	cellule2.Affiche();
	cellule1.Diviser(&cellule2);
	cellule1.Affiche();
	cellule2.Affiche();

	return 0;
}