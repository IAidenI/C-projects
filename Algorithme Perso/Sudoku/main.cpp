#include<iostream>;
using namespace std;

#include"sudoku.h";

int main()
{
	//Lexique principal
	//unsigned int* test2;
	bool test, test2;
	unsigned int* ligne1;
	unsigned int* ligne2;
	unsigned int* ligne3;
	unsigned int* ligne4;
	unsigned int* ligne5;
	unsigned int* ligne6;
	unsigned int* ligne7;
	unsigned int* ligne8;
	unsigned int* ligne9;

	//Algorithme principal
	//Début
	srand(time(NULL));
	ligne1 = gen_ligne();
	ligne2 = gen_ligne();
	ligne3 = gen_ligne();
	ligne4 = gen_ligne();
	ligne5 = gen_ligne();
	ligne6 = gen_ligne();
	ligne7 = gen_ligne();
	ligne8 = gen_ligne();
	ligne9 = gen_ligne();

	/*ligne1 = &tab1[0];
	ligne2 = &tab2[0];
	ligne3 = &tab3[0];
	ligne4 = &tab4[0];
	ligne5 = &tab5[0];
	ligne6 = &tab6[0];
	ligne7 = &tab7[0];
	ligne8 = &tab8[0];
	ligne9 = &tab9[0];*/

	/*verif_ligne(ligne1);
	verif_ligne(ligne2);
	verif_ligne(ligne3);
	verif_ligne(ligne4);
	verif_ligne(ligne5);
	verif_ligne(ligne6);
	verif_ligne(ligne7);
	verif_ligne(ligne8);
	verif_ligne(ligne9);
	verif_colonnes(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7, ligne8, ligne9);*/
	affiche_jeu(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7, ligne8, ligne9);
	verif_carree(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7, ligne8, ligne9);

	/*i = 0;
	while ((test == 0) || (test2 == 0))
	{
		if (test2 == 0)
		{
			test2 = verif_ligne2(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7, ligne8, ligne9);
		}
		//Fin Si
		if (test == 0)
		{
			test = verif_colonnes(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7, ligne8, ligne9);
		}
		//Fin Si
	}
	//Fin Tant que*/

	affiche_jeu(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7, ligne8, ligne9);
	//cout << endl << endl << "Test : " << test << endl;
	//cout << "Test2 : " << test2 << endl;
	
	delete[] ligne1;
	delete[] ligne2;
	delete[] ligne3;
	delete[] ligne4;
	delete[] ligne5;
	delete[] ligne6;
	delete[] ligne7;
	delete[] ligne8;
	delete[] ligne9;
	//Fin
	return 0;
}