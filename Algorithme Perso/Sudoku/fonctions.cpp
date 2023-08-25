#include<time.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

#include"sudoku.h"

/*
R: Génere une grille de sudoku rempli et correcte
E: vide
S: 1 pointeur de réels qui corespond à l'emplacement du tableau crée
*/
/*unsigned int* gen_sudoku(void)
{
	//Lexique local à gen_sudoku
	const int A = 9;
	const int B = 1;
	unsigned int* pf = nullptr;
	unsigned int i, j;

	//Algorithme local à gen_sudoku
	//Début
	pf = new unsigned int[81];
	
	i = 0;
	srand(time(NULL));
	//Génération des lignes justes
	while (i <= 8)
	{
		switch (i)
		{
		case 0:
			j = 1;
			*pf = 1 + rand() % 9;
			while (j <= 8)
			{
				//1
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *pf)
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//2
				while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//3
				while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//4
				while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//5
				while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//6
				while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//7
				while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//8
				while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 1:
			*(pf + 9) = 1 + rand() % 9;
			j = 10;
			while (j <= 17)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 9))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que
				
				//1
				if ((j - 1) >= 9)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				
				//2
				if (((j - 1) >= 9) && ((j - 2) >= 9))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 9) && ((j - 2) >= 9) && ((j - 3) >= 9))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 9) && ((j - 2) >= 9) && ((j - 3) >= 9) && ((j - 4) >= 9))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 9) && ((j - 2) >= 9) && ((j - 3) >= 9) && ((j - 4) >= 9) && ((j - 5) >= 9))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 9) && ((j - 2) >= 9) && ((j - 3) >= 9) && ((j - 4) >= 9) && ((j - 5) >= 9) && ((j - 6) >= 9))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 9) && ((j - 2) >= 9) && ((j - 3) >= 9) && ((j - 4) >= 9) && ((j - 5) >= 9) && ((j - 6) >= 9) && ((j - 7) >= 9))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 9) && ((j - 2) >= 9) && ((j - 3) >= 9) && ((j - 4) >= 9) && ((j - 5) >= 9) && ((j - 6) >= 9) && ((j - 7) >= 9) && ((j - 8) >= 9))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 2:
			*(pf + 18) = 1 + rand() % 9;
			j = 19;
			while (j <= 26)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 18))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 18)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 18) && ((j - 2) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18) && ((j - 5) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18) && ((j - 5) >= 18) && ((j - 6) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18) && ((j - 5) >= 18) && ((j - 6) >= 18) && ((j - 7) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18) && ((j - 5) >= 18) && ((j - 6) >= 18) && ((j - 7) >= 18) && ((j - 8) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 3:
			*(pf + 27) = 1 + rand() % 9;
			j = 28;
			while (j <= 35)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 27))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 27)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 27) && ((j - 2) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27) && ((j - 5) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27) && ((j - 5) >= 27) && ((j - 6) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27) && ((j - 5) >= 27) && ((j - 6) >= 27) && ((j - 7) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27) && ((j - 5) >= 27) && ((j - 6) >= 27) && ((j - 7) >= 27) && ((j - 8) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 4:
			*(pf + 36) = 1 + rand() % 9;
			j = 37;
			while (j <= 44)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 36))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 36)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 36) && ((j - 2) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36) && ((j - 5) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36) && ((j - 5) >= 36) && ((j - 6) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36) && ((j - 5) >= 36) && ((j - 6) >= 36) && ((j - 7) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36) && ((j - 5) >= 36) && ((j - 6) >= 36) && ((j - 7) >= 36) && ((j - 8) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 5:
			*(pf + 45) = 1 + rand() % 9;
			j = 46;
			while (j <= 53)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 45))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 45)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 45) && ((j - 2) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45) && ((j - 5) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45) && ((j - 5) >= 45) && ((j - 6) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45) && ((j - 5) >= 45) && ((j - 6) >= 45) && ((j - 7) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45) && ((j - 5) >= 45) && ((j - 6) >= 45) && ((j - 7) >= 45) && ((j - 8) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 6:
			*(pf + 54) = 1 + rand() % 9;
			j = 55;
			while (j <= 62)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 54))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 54)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 54) && ((j - 2) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54) && ((j - 5) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54) && ((j - 5) >= 54) && ((j - 6) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54) && ((j - 5) >= 54) && ((j - 6) >= 54) && ((j - 7) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54) && ((j - 5) >= 54) && ((j - 6) >= 54) && ((j - 7) >= 54) && ((j - 8) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 7:
			*(pf + 63) = 1 + rand() % 9;
			j = 64;
			while (j <= 71)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 63))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 63)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 63) && ((j - 2) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63) && ((j - 4) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63) && ((j - 4) >= 63) && ((j - 5) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63) && ((j - 4) >= 63) && ((j - 5) >= 63) && ((j - 6) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 63) >= 9) && ((j - 4) >= 63) && ((j - 5) >= 63) && ((j - 6) >= 63) && ((j - 7) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63) && ((j - 4) >= 63) && ((j - 5) >= 63) && ((j - 6) >= 63) && ((j - 7) >= 63) && ((j - 8) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Finn Tant que
			break;

		case 8:
			*(pf + 72) = 1 + rand() % 9;
			j = 73;
			while (j <= 80)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 72))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 72)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 72) && ((j - 2) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72) && ((j - 5) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72) && ((j - 5) >= 72) && ((j - 6) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72) && ((j - 5) >= 72) && ((j - 6) >= 72) && ((j - 7) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72) && ((j - 5) >= 72) && ((j - 6) >= 72) && ((j - 7) >= 72) && ((j - 8) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;
		}
		//Fin Selon
		i = i + 1;
	}
	//Fin Tant que

	//Génération des colones justes
	j = 0;
	while (j <= 1)
	{
		switch (j)
		{
		case 0:
			i = 1;
			while (i <= 8)
			{
				//0
				while (*(pf + (i * A)) == *pf)
				{
					*(pf + (i * A)) = 1 + rand() % 9;
				}
				//Fin Tant que

				//2
				while ((*(pf + (i * A)) == *(pf + ((i * A) - A))))
				{
					*(pf + (i * A)) = 1 + rand() % 9;
				}
				//Fin Tant que

				//2
				while ((*(pf + (i * A)) == *(pf + ((i * A) - A))) || (*(pf + (i * A)) == *(pf + ((i * A) - (2 * A)))))
				{
					*(pf + (i * A)) = 1 + rand() % 9;
				}
				//Fin Tant que
				
				//3
				while ((*(pf + (i * A)) == *(pf + ((i * A) - A))) || (*(pf + (i * A)) == *(pf + ((i * A) - (2 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (3 * A)))))
				{
					*(pf + (i * A)) = 1 + rand() % 9;
				}
				//Fin Tant que

				//4
				while ((*(pf + (i * A)) == *(pf + ((i * A) - A))) || (*(pf + (i * A)) == *(pf + ((i * A) - (2 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (3 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (4 * A)))))
				{
					*(pf + (i * A)) = 1 + rand() % 9;
				}
				//Fin Tant que

				//5
				while ((*(pf + (i * A)) == *(pf + ((i * A) - A))) || (*(pf + (i * A)) == *(pf + ((i * A) - (2 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (3 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (4 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (5 * A)))))
				{
					*(pf + (i * A)) = 1 + rand() % 9;
				}
				//Fin Tant que

				//6
				while ((*(pf + (i * A)) == *(pf + ((i * A) - A))) || (*(pf + (i * A)) == *(pf + ((i * A) - (2 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (3 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (4 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (5 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (6 * A)))))
				{
					*(pf + (i * A)) = 1 + rand() % 9;
				}
				//Fin Tant que

				//7
				while ((*(pf + (i * A)) == *(pf + ((i * A) - A))) || (*(pf + (i * A)) == *(pf + ((i * A) - (2 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (3 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (4 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (5 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (6 * A))) || (*(pf + (i * A)) == *(pf + ((i * A) - (7 * A))))))
				{
					*(pf + (i + A)) = 1 + rand() % 9;
				}
				//Fin Tant que

				//8
				while ((*(pf + (i * A)) == *(pf + ((i * A) - A))) || (*(pf + (i * A)) == *(pf + ((i * A) - (2 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (3 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (4 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (5 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (6 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (7 * A)))) || (*(pf + (i * A)) == *(pf + ((i * A) - (8 * A)))))
				{
					*(pf + (i * A)) = 1 + rand() % 9;
				}
				//Fin Tant que
				i = i + 1;
			}
			//Fin Tant que
			break;

		/*case 1:
			i = 1;
			while (i <= 8)
			{
				//0
				while (*(pf + (i * A) + B) == *pf)
				{
					*(pf + (i * A) + B) = 1 + rand() % 9;
				}
				//Fin Tant que

				//2
				while ((*(pf + (i * A) + B) == *(pf + ((i * A) + B - A))))
				{
					*(pf + (i * A) + B) = 1 + rand() % 9;
				}
				//Fin Tant que

				//2
				while ((*(pf + (i * A) + B) == *(pf + ((i * A) + B - A))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (2 * A)))))
				{
					*(pf + (i * A) + B) = 1 + rand() % 9;
				}
				//Fin Tant que

				//3
				while ((*(pf + (i * A) + B) == *(pf + ((i * A) + B - A))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (2 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (3 * A)))))
				{
					*(pf + (i * A) + B) = 1 + rand() % 9;
				}
				//Fin Tant que

				//4
				while ((*(pf + (i * A) + B) == *(pf + ((i * A) + B - A))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (2 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (3 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (4 * A)))))
				{
					*(pf + (i * A) + B) = 1 + rand() % 9;
				}
				//Fin Tant que

				//5
				while ((*(pf + (i * A) + B) == *(pf + ((i * A) + B - A))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (2 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (3 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (4 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (5 * A)))))
				{
					*(pf + (i * A) + B) = 1 + rand() % 9;
				}
				//Fin Tant que

				//6
				while ((*(pf + (i * A) + B) == *(pf + ((i * A) + B - A))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (2 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (3 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (4 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (5 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (6 * A)))))
				{
					*(pf + (i * A) + B) = 1 + rand() % 9;
				}
				//Fin Tant que

				//7
				while ((*(pf + (i * A) + B) == *(pf + ((i * A) + B - A))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (2 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (3 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (4 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (5 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (6 * A))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (7 * A))))))
				{
					*(pf + (i + A) + B) = 1 + rand() % 9;
				}
				//Fin Tant que

				//8
				while ((*(pf + (i * A) + B) == *(pf + ((i * A) + B - A))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (2 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (3 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (4 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (5 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (6 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (7 * A)))) || (*(pf + (i * A) + B) == *(pf + ((i * A) + B - (8 * A)))))
				{
					*(pf + (i * A) + B) = 1 + rand() % 9;
				}
				//Fin Tant que
				i = i + 1;
			}
			//Fin Tant que
			break;

		case 2:
			*(pf + 18) = 1 + rand() % 9;
			j = 19;
			while (j <= 26)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 18))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 18)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 18) && ((j - 2) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18) && ((j - 5) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18) && ((j - 5) >= 18) && ((j - 6) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18) && ((j - 5) >= 18) && ((j - 6) >= 18) && ((j - 7) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 18) && ((j - 2) >= 18) && ((j - 3) >= 18) && ((j - 4) >= 18) && ((j - 5) >= 18) && ((j - 6) >= 18) && ((j - 7) >= 18) && ((j - 8) >= 18))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 3:
			*(pf + 27) = 1 + rand() % 9;
			j = 28;
			while (j <= 35)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 27))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 27)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 27) && ((j - 2) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27) && ((j - 5) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27) && ((j - 5) >= 27) && ((j - 6) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27) && ((j - 5) >= 27) && ((j - 6) >= 27) && ((j - 7) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 27) && ((j - 2) >= 27) && ((j - 3) >= 27) && ((j - 4) >= 27) && ((j - 5) >= 27) && ((j - 6) >= 27) && ((j - 7) >= 27) && ((j - 8) >= 27))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 4:
			*(pf + 36) = 1 + rand() % 9;
			j = 37;
			while (j <= 44)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 36))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 36)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 36) && ((j - 2) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36) && ((j - 5) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36) && ((j - 5) >= 36) && ((j - 6) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36) && ((j - 5) >= 36) && ((j - 6) >= 36) && ((j - 7) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 36) && ((j - 2) >= 36) && ((j - 3) >= 36) && ((j - 4) >= 36) && ((j - 5) >= 36) && ((j - 6) >= 36) && ((j - 7) >= 36) && ((j - 8) >= 36))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 5:
			*(pf + 45) = 1 + rand() % 9;
			j = 46;
			while (j <= 53)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 45))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 45)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 45) && ((j - 2) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45) && ((j - 5) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45) && ((j - 5) >= 45) && ((j - 6) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45) && ((j - 5) >= 45) && ((j - 6) >= 45) && ((j - 7) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 45) && ((j - 2) >= 45) && ((j - 3) >= 45) && ((j - 4) >= 45) && ((j - 5) >= 45) && ((j - 6) >= 45) && ((j - 7) >= 45) && ((j - 8) >= 45))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 6:
			*(pf + 54) = 1 + rand() % 9;
			j = 55;
			while (j <= 62)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 54))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 54)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 54) && ((j - 2) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54) && ((j - 5) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54) && ((j - 5) >= 54) && ((j - 6) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54) && ((j - 5) >= 54) && ((j - 6) >= 54) && ((j - 7) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 54) && ((j - 2) >= 54) && ((j - 3) >= 54) && ((j - 4) >= 54) && ((j - 5) >= 54) && ((j - 6) >= 54) && ((j - 7) >= 54) && ((j - 8) >= 54))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 7:
			*(pf + 63) = 1 + rand() % 9;
			j = 64;
			while (j <= 71)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 63))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 63)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 63) && ((j - 2) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63) && ((j - 4) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63) && ((j - 4) >= 63) && ((j - 5) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63) && ((j - 4) >= 63) && ((j - 5) >= 63) && ((j - 6) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 63) >= 9) && ((j - 4) >= 63) && ((j - 5) >= 63) && ((j - 6) >= 63) && ((j - 7) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 63) && ((j - 2) >= 63) && ((j - 3) >= 63) && ((j - 4) >= 63) && ((j - 5) >= 63) && ((j - 6) >= 63) && ((j - 7) >= 63) && ((j - 8) >= 63))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Finn Tant que
			break;

		case 8:
			*(pf + 72) = 1 + rand() % 9;
			j = 73;
			while (j <= 80)
			{
				//0
				*(pf + j) = 1 + rand() % 9;
				while (*(pf + j) == *(pf + 72))
				{
					*(pf + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				//1
				if ((j - 1) >= 72)
				{
					while (*(pf + j) == *(pf + (j - 1)))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//2
				if (((j - 1) >= 72) && ((j - 2) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//3
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//4
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//5
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72) && ((j - 5) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//6
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72) && ((j - 5) >= 72) && ((j - 6) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//7
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72) && ((j - 5) >= 72) && ((j - 6) >= 72) && ((j - 7) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				//8
				if (((j - 1) >= 72) && ((j - 2) >= 72) && ((j - 3) >= 72) && ((j - 4) >= 72) && ((j - 5) >= 72) && ((j - 6) >= 72) && ((j - 7) >= 72) && ((j - 8) >= 72))
				{
					while ((*(pf + j) == *(pf + (j - 1))) || (*(pf + j) == *(pf + (j - 2))) || (*(pf + j) == *(pf + (j - 3))) || (*(pf + j) == *(pf + (j - 4))) || (*(pf + j) == *(pf + (j - 5))) || (*(pf + j) == *(pf + (j - 6))) || (*(pf + j) == *(pf + (j - 7))) || (*(pf + j) == *(pf + (j - 8))))
					{
						*(pf + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si
				j = j + 1;
			}
			//Fin Tant que
			break;
		}
		//Fin Selon
		j = j + 1;
	}
	//Fin Tant que
	return pf;
	//Fin
}*/

/*
R: Génere une ligne de la grille de sudoku
E: vide
S: un pointeur d'entier qui corespond à l'emplacement de la ligne crée
*/
unsigned int* gen_ligne(void)
{
	//Lexique local à gen_ligne
	unsigned int* pt;
	unsigned int i;

	//Algorithme local à gen_ligne
	//Début
	pt = new unsigned int[9];
	i = 0;
	while (i <= 8)
	{
		*(pt + i) = 1 + rand() % 9;
		i = i + 1;
	}
	//Fin Tant que
	return pt;
	//Fin
}

/*
R: Vérifie et modifie au besoin les lignes du sudoku
E: un pointeur qui corespond à la ligne du sudoku à vérifier
S: vide
*/
void verif_ligne(unsigned int* l)
{
	//Lexique local à verif_ligne
	unsigned int j;

	//Algorithme local à verif_ligne
	//Début
	j = 1;
	while (j <= 8)
	{
		while ((*(l + j) == *(l + (j - 1))) || (*(l + j) == *(l + (j - 2))) || (*(l + j) == *(l + (j - 3))) || (*(l + j) == *(l + (j - 4))) || (*(l + j) == *(l + (j - 5))) || (*(l + j) == *(l + (j - 6))) || (*(l + j) == *(l + (j - 7))) || (*(l + j) == *(l + (j - 8))))
		{
			*(l + j) = 1 + rand() % 9;
		}
		//Fin Tant que
		j = j + 1;
	}
	//Fin
}

/*
R: Vérifie et modifie au besoin les colonnes du sudoku
E: 9 pointeur qui corespondent au colonnes du sudoku à vérifier
S: vide
*/
void verif_colonnes(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9)
{
	//Lexique local à verif_colonne
	unsigned int j, z;
	bool verif;

	//Algorithme local à verif_colonne
	//Début
	j = 0;
	while (j <= 8)
	{
		//if ((*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l4 + j)) || (*(l1 + j) == *(l5 + j)) || (*(l1 + j) == *(l6 + j)) || (*(l1 + j) == *(l7 + j)) || (*(l1 + j) == *(l8 + j)) || (*(l1 + j) == *(l9 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)) || (*(l8 + j) == *(l9 + j)))
		//{
			z = 2;
			while ((*(l1 + j) == *(l2 + j) == *(l3 + j) == *(l4 + j) == *(l5 + j) == *(l6 + j) == *(l7 + j) == *(l8 + j) == *(l9 + j)) || (z == 2))
			{
				while ((*(l2 + j) == *(l1 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)))
				{
					*(l2 + j) = 1 + rand() % 9;
				}
				//Fin Tant que

				if ((*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l4 + j)) || (*(l1 + j) == *(l5 + j)) || (*(l1 + j) == *(l6 + j)) || (*(l1 + j) == *(l7 + j)) || (*(l1 + j) == *(l8 + j)) || (*(l1 + j) == *(l9 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)) || (*(l8 + j) == *(l9 + j)))
				{
					while ((*(l3 + j) == *(l1 + j)) || (*(l3 + j) == *(l2 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)))
					{
						*(l3 + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				if ((*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l4 + j)) || (*(l1 + j) == *(l5 + j)) || (*(l1 + j) == *(l6 + j)) || (*(l1 + j) == *(l7 + j)) || (*(l1 + j) == *(l8 + j)) || (*(l1 + j) == *(l9 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)) || (*(l8 + j) == *(l9 + j)))
				{
					while ((*(l4 + j) == *(l1 + j)) || (*(l4 + j) == *(l2 + j)) || (*(l4 + j) == *(l3 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)))
					{
						*(l4 + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				if ((*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l4 + j)) || (*(l1 + j) == *(l5 + j)) || (*(l1 + j) == *(l6 + j)) || (*(l1 + j) == *(l7 + j)) || (*(l1 + j) == *(l8 + j)) || (*(l1 + j) == *(l9 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)) || (*(l8 + j) == *(l9 + j)))
				{
					while ((*(l5 + j) == *(l1 + j)) || (*(l5 + j) == *(l2 + j)) || (*(l5 + j) == *(l3 + j)) || (*(l5 + j) == *(l4 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)))
					{
						*(l5 + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				if ((*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l4 + j)) || (*(l1 + j) == *(l5 + j)) || (*(l1 + j) == *(l6 + j)) || (*(l1 + j) == *(l7 + j)) || (*(l1 + j) == *(l8 + j)) || (*(l1 + j) == *(l9 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)) || (*(l8 + j) == *(l9 + j)))
				{
					while ((*(l6 + j) == *(l1 + j)) || (*(l6 + j) == *(l2 + j)) || (*(l6 + j) == *(l3 + j)) || (*(l6 + j) == *(l4 + j)) || (*(l6 + j) == *(l5 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)))
					{
						*(l6 + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				if ((*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l4 + j)) || (*(l1 + j) == *(l5 + j)) || (*(l1 + j) == *(l6 + j)) || (*(l1 + j) == *(l7 + j)) || (*(l1 + j) == *(l8 + j)) || (*(l1 + j) == *(l9 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)) || (*(l8 + j) == *(l9 + j)))
				{
					while ((*(l7 + j) == *(l1 + j)) || (*(l7 + j) == *(l2 + j)) || (*(l7 + j) == *(l3 + j)) || (*(l7 + j) == *(l4 + j)) || (*(l7 + j) == *(l5 + j)) || (*(l7 + j) == *(l6 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)))
					{
						*(l7 + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				if ((*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l4 + j)) || (*(l1 + j) == *(l5 + j)) || (*(l1 + j) == *(l6 + j)) || (*(l1 + j) == *(l7 + j)) || (*(l1 + j) == *(l8 + j)) || (*(l1 + j) == *(l9 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)) || (*(l8 + j) == *(l9 + j)))
				{
					while ((*(l8 + j) == *(l1 + j)) || (*(l8 + j) == *(l2 + j)) || (*(l8 + j) == *(l3 + j)) || (*(l8 + j) == *(l4 + j)) || (*(l8 + j) == *(l5 + j)) || (*(l8 + j) == *(l6 + j)) || (*(l8 + j) == *(l7 + j)) || (*(l8 + j) == *(l9 + j)))
					{
						*(l8 + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				if ((*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l4 + j)) || (*(l1 + j) == *(l5 + j)) || (*(l1 + j) == *(l6 + j)) || (*(l1 + j) == *(l7 + j)) || (*(l1 + j) == *(l8 + j)) || (*(l1 + j) == *(l9 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)) || (*(l8 + j) == *(l9 + j)))
				{
					while ((*(l9 + j) == *(l1 + j)) || (*(l9 + j) == *(l2 + j)) || (*(l9 + j) == *(l3 + j)) || (*(l9 + j) == *(l4 + j)) || (*(l9 + j) == *(l5 + j)) || (*(l9 + j) == *(l6 + j)) || (*(l9 + j) == *(l7 + j)) || (*(l9 + j) == *(l8 + j)))
					{
						*(l9 + j) = 1 + rand() % 9;
					}
					//Fin Tant que
				}
				//Fin Si

				z = 1;
			}
			//Fin Tant que
		//}
		//Fin Si
		j = j + 1;
	}
	//Fin Tant que

	/*j = 0;
	while (j <= 8)
	{
		if ((*(l1 + j) == *(l1 + (j - 1))) || (*(l1 + j) == *(l1 + (j - 2))) || (*(l1 + j) == *(l1 + (j - 3))) || (*(l1 + j) == *(l1 + (j - 4))) || (*(l1 + j) == *(l1 + (j - 5))) || (*(l1 + j) == *(l1 + (j - 6))) || (*(l1 + j) == *(l1 + (j - 7))) || (*(l1 + j) == *(l1 + (j - 8))) || (*(l2 + j) == *(l2 + (j - 1))) || (*(l2 + j) == *(l2 + (j - 2))) || (*(l2 + j) == *(l2 + (j - 3))) || (*(l2 + j) == *(l2 + (j - 4))) || (*(l2 + j) == *(l2 + (j - 5))) || (*(l2 + j) == *(l2 + (j - 6))) || (*(l2 + j) == *(l2 + (j - 7))) || (*(l2 + j) == *(l2 + (j - 8))) || (*(l3 + j) == *(l3 + (j - 1))) || (*(l3 + j) == *(l3 + (j - 2))) || (*(l3 + j) == *(l3 + (j - 3))) || (*(l3 + j) == *(l3 + (j - 4))) || (*(l3 + j) == *(l3 + (j - 5))) || (*(l3 + j) == *(l3 + (j - 6))) || (*(l3 + j) == *(l3 + (j - 7))) || (*(l3 + j) == *(l3 + (j - 8))) || (*(l4 + j) == *(l4 + (j - 1))) || (*(l4 + j) == *(l4 + (j - 2))) || (*(l4 + j) == *(l4 + (j - 3))) || (*(l4 + j) == *(l4 + (j - 4))) || (*(l4 + j) == *(l4 + (j - 5))) || (*(l4 + j) == *(l4 + (j - 6))) || (*(l4 + j) == *(l4 + (j - 7))) || (*(l4 + j) == *(l4 + (j - 8))) || (*(l5 + j) == *(l5 + (j - 1))) || (*(l5 + j) == *(l5 + (j - 2))) || (*(l5 + j) == *(l5 + (j - 3))) || (*(l5 + j) == *(l5 + (j - 4))) || (*(l5 + j) == *(l5 + (j - 5))) || (*(l5 + j) == *(l5 + (j - 6))) || (*(l5 + j) == *(l5 + (j - 7))) || (*(l5 + j) == *(l5 + (j - 8))) || (*(l6 + j) == *(l6 + (j - 1))) || (*(l6 + j) == *(l6 + (j - 2))) || (*(l6 + j) == *(l6 + (j - 3))) || (*(l6 + j) == *(l6 + (j - 4))) || (*(l6 + j) == *(l6 + (j - 5))) || (*(l6 + j) == *(l6 + (j - 6))) || (*(l6 + j) == *(l6 + (j - 7))) || (*(l6 + j) == *(l6 + (j - 8))) || (*(l7 + j) == *(l7 + (j - 1))) || (*(l7 + j) == *(l7 + (j - 2))) || (*(l7 + j) == *(l7 + (j - 3))) || (*(l7 + j) == *(l7 + (j - 4))) || (*(l7 + j) == *(l7 + (j - 5))) || (*(l7 + j) == *(l7 + (j - 6))) || (*(l7 + j) == *(l7 + (j - 7))) || (*(l7 + j) == *(l7 + (j - 8))) || (*(l8 + j) == *(l8 + (j - 1))) || (*(l8 + j) == *(l8 + (j - 2))) || (*(l8 + j) == *(l8 + (j - 3))) || (*(l8 + j) == *(l8 + (j - 4))) || (*(l8 + j) == *(l8 + (j - 5))) || (*(l8 + j) == *(l8 + (j - 6))) || (*(l8 + j) == *(l8 + (j - 7))) || (*(l8 + j) == *(l8 + (j - 8))) || (*(l9 + j) == *(l9 + (j - 1))) || (*(l9 + j) == *(l9 + (j - 2))) || (*(l9 + j) == *(l9 + (j - 3))) || (*(l9 + j) == *(l9 + (j - 4))) || (*(l9 + j) == *(l9 + (j - 5))) || (*(l9 + j) == *(l9 + (j - 6))) || (*(l9 + j) == *(l9 + (j - 7))) || (*(l9 + j) == *(l9 + (j - 8))))
		{
			verif = 0;
		}
		else
		{
			verif = 1;
		}
		//Fin Si
		j = j + 1;
	}
	//Fin Tant que*/
	//return verif;
	//Fin
}

/*
R: Vérifie et modifie au besoin les carrées de 9 case du sudoku
E: 9 pointeur qui corespondent aux carrées du sudoku à vérifier
S: vide
*/
void verif_carree(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9)
{
	//Lexique local à verif_carree
	unsigned int i, j, z;

	//Algorithme local à verif_carree
	//Début
	//i = 0;
	//while (i <= 0)
	//{
	//	switch (i)
	//	{
	//	case 0:
			j = 0;
//***************************************************************************************************************************************************************\\

			while ((*(l1 + j) == *(l1 + j + 1)) || (*(l1 + j) == *(l1 + j + 2)) || (*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l2 + j + 1)) || (*(l1 + j) == *(l2 + j + 2)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l3 + j + 1)) || (*(l1 + j) == *(l3 + j + 2)))
			{
				*(l1 + j) = 1 + rand() % 9;
				cout << "1 : " << *(l1 + j) << endl;
			}
			//Fin Tant que

			while ((*(l1 + j + 1) == *(l1 + j)) || (*(l1 + j + 1) == *(l1 + j + 2)) || (*(l1 + j + 1) == *(l2 + j)) || (*(l1 + j + 1) == *(l2 + j + 1)) || (*(l1 + j + 1) == *(l2 + j + 2)) || (*(l1 + j + 1) == *(l3 + j)) || (*(l1 + j + 1) == *(l3 + j + 1)) || (*(l1 + j + 1) == *(l3 + j + 2)))
			{
				*(l1 + j + 1) = 1 + rand() % 9;
				cout << "2 : " << *(l1 + j + 1) << endl;
			}
			//Fin Tant que

			while ((*(l1 + j + 2) == *(l1 + j)) || (*(l1 + j + 2) == *(l1 + j + 1)) || (*(l1 + j + 2) == *(l2 + j)) || (*(l1 + j + 2) == *(l2 + j + 1)) || (*(l1 + j + 2) == *(l2 + j + 2)) || (*(l1 + j + 2) == *(l3 + j)) || (*(l1 + j + 2) == *(l3 + j + 1)) || (*(l1 + j + 2) == *(l3 + j + 2)))
			{
				cout << "3.1 : " << *(l1 + j + 2) << endl;
				*(l1 + j + 2) = 1 + rand() % 9;
				cout << "3 : " << *(l1 + j + 2) << endl;
			}
			//Fin Tant que
//***************************************************************************************************************************************************************\\
						
			while ((*(l2 + j) == *(l1 + j)) || (*(l2 + j) == *(l1 + j + 1)) || (*(l2 + j) == *(l1 + j + 2)) || (*(l2 + j) == *(l2 + j + 1)) || (*(l2 + j) == *(l2 + j + 2)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l3 + j + 1)) || (*(l2 + j) == *(l3 + j + 2)))
			{
				*(l2 + j) = 1 + rand() % 9;
				cout << "4 : " << *(l2 + j) << endl;
			}
			//Fin Tant que

			while ((*(l2 + j + 1) == *(l1 + j)) || (*(l2 + j + 1) == *(l1 + j + 1)) || (*(l2 + j + 1) == *(l1 + j + 2)) || (*(l2 + j + 1) == *(l2 + j)) || (*(l2 + j + 1) == *(l2 + j + 2)) || (*(l2 + j + 1) == *(l3 + j)) || (*(l2 + j + 1) == *(l3 + j + 1)) || (*(l2 + j + 1) == *(l3 + j + 2)))
			{
				*(l2 + j + 1) = 1 + rand() % 9;
				cout << "5 : " << *(l2 + j + 1) << endl;
			}
			//Fin Tant que

			while ((*(l2 + j + 2) == *(l1 + j)) || (*(l2 + j + 2) == *(l1 + j + 1)) || (*(l2 + j + 2) == *(l1 + j + 2)) || (*(l2 + j + 2) == *(l2 + j)) || (*(l2 + j + 2) == *(l2 + j + 1)) || (*(l2 + j + 2) == *(l3 + j)) || (*(l2 + j + 2) == *(l3 + j + 1)) || (*(l2 + j + 2) == *(l3 + j + 2)))
			{
				cout << "6.1 : " << *(l2 + j + 2) << endl;
				*(l2 + j + 2) = 1 + rand() % 9;
				cout << "6 : " << *(l2 + j + 2) << endl;
			}
			//Fin Tant que
//***************************************************************************************************************************************************************\\

			while ((*(l3 + j) == *(l1 + j)) || (*(l3 + j) == *(l1 + j + 1)) || (*(l3 + j) == *(l1 + j + 2)) || (*(l3 + j) == *(l2 + j)) || (*(l3 + j) == *(l2 + j + 1)) || (*(l3 + j) == *(l2 + j + 2)) || (*(l3 + j) == *(l3 + j + 1)) || (*(l3 + j) == *(l3 + j + 2)))
			{
				*(l3 + j) = 1 + rand() % 9;
				cout << "7 : " << *(l3 + j) << endl;
			}
			//Fin Tant que

			while ((*(l3 + j + 1) == *(l1 + j)) || (*(l3 + j + 1) == *(l1 + j + 1)) || (*(l3 + j + 1) == *(l1 + j + 2)) || (*(l3 + j + 1) == *(l2 + j)) || (*(l3 + j + 1) == *(l2 + j + 1)) || (*(l3 + j + 1) == *(l2 + j + 2)) || (*(l3 + j + 1) == *(l3 + j)) || (*(l3 + j + 1) == *(l3 + j + 2)))
			{
				*(l3 + j + 1) = 1 + rand() % 9;
				cout << "8 : " << *(l3 + j + 1) << endl;
			}
			//Fin Tant que

			while ((*(l3 + j + 2) == *(l1 + j)) || (*(l3 + j + 2) == *(l1 + j + 1)) || (*(l3 + j + 2) == *(l1 + j + 2)) || (*(l3 + j + 2) == *(l2 + j)) || (*(l3 + j + 2) == *(l2 + j + 1)) || (*(l3 + j + 2) == *(l2 + j + 2)) || (*(l3 + j + 2) == *(l3 + j)) || (*(l3 + j + 2) == *(l3 + j + 1)))
			{
				cout << "9.1 : " << *(l3 + j + 2) << endl;
				*(l3 + j + 2) = 1 + rand() % 9;
				cout << "9 : " << *(l3 + j + 2) << endl;
			}
			//Fin Tant que
//***************************************************************************************************************************************************************\\
			
			j = 3;
			while ((*(l1 + j) == *(l1 + j + 1)) || (*(l1 + j) == *(l1 + j + 2)) || (*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l2 + j + 1)) || (*(l1 + j) == *(l2 + j + 2)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l3 + j + 1)) || (*(l1 + j) == *(l3 + j + 2)))
			{
				*(l1 + j) = 1 + rand() % 9;
				cout << "10 : " << *(l1 + j) << endl;
			}
			//Fin Tant que
							
			while ((*(l1 + j + 1) == *(l1 + j)) || (*(l1 + j + 1) == *(l1 + j + 2)) || (*(l1 + j + 1) == *(l2 + j)) || (*(l1 + j + 1) == *(l2 + j + 1)) || (*(l1 + j + 1) == *(l2 + j + 2)) || (*(l1 + j + 1) == *(l3 + j)) || (*(l1 + j + 1) == *(l3 + j + 1)) || (*(l1 + j + 1) == *(l3 + j + 2)))
			{
				*(l1 + j + 1) = 1 + rand() % 9;
				cout << "11 : " << *(l1 + j + 1) << endl;
			}
			//Fin Tant que

			while ((*(l1 + j + 2) == *(l1 + j)) || (*(l1 + j + 2) == *(l1 + j + 1)) || (*(l1 + j + 2) == *(l2 + j)) || (*(l1 + j + 2) == *(l2 + j + 1)) || (*(l1 + j + 2) == *(l2 + j + 2)) || (*(l1 + j + 2) == *(l3 + j)) || (*(l1 + j + 2) == *(l3 + j + 1)) || (*(l2 + j + 2) == *(l3 + j + 2)))
			{
				cout << "12.1 : " << *(l1 + j + 2) << endl;
				*(l1 + j + 2) = 1 + rand() % 9;
				cout << "12 : " << *(l1 + j + 2) << endl;
			}
			//Fin Tant que
//***************************************************************************************************************************************************************\\
						
			while ((*(l2 + j) == *(l1 + j)) || (*(l2 + j) == *(l1 + j + 1)) || (*(l2 + j) == *(l1 + j + 2)) || (*(l2 + j) == *(l2 + j + 1)) || (*(l2 + j) == *(l2 + j + 2)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l3 + j + 1)) || (*(l2 + j) == *(l3 + j + 2)))
			{
				*(l2 + j) = 1 + rand() % 9;
				cout << "13 : " << *(l2 + j) << endl;
			}
			//Fin Tant que
							
			while ((*(l2 + j + 1) == *(l1 + j)) || (*(l2 + j + 1) == *(l1 + j + 1)) || (*(l2 + j + 1) == *(l1 + j + 2)) || (*(l2 + j + 1) == *(l2 + j)) || (*(l2 + j + 1) == *(l2 + j + 2)) || (*(l2 + j + 1) == *(l3 + j)) || (*(l2 + j + 1) == *(l3 + j + 1)) || (*(l2 + j + 1) == *(l3 + j + 2)))
			{
				*(l2 + j + 1) = 1 + rand() % 9;
				cout << "14 : " << *(l2 + j + 1) << endl;
			}
			//Fin Tant que

			while ((*(l2 + j + 2) == *(l1 + j)) || (*(l2 + j + 2) == *(l1 + j + 1)) || (*(l2 + j + 2) == *(l1 + j + 2)) || (*(l2 + j + 2) == *(l2 + j)) || (*(l2 + j + 2) == *(l2 + j + 1)) || (*(l2 + j + 2) == *(l3 + j)) || (*(l2 + j + 2) == *(l3 + j + 1)) || (*(l2 + j + 2) == *(l3 + j + 2)))
			{
				cout << "15.1 : " << *(l2 + j + 2) << endl;
				*(l2 + j + 2) = 1 + rand() % 9;
				cout << "15 : " << *(l2 + j + 2) << endl;
			}
			//Fin Tant que
//***************************************************************************************************************************************************************\\

			while ((*(l3 + j) == *(l1 + j)) || (*(l3 + j) == *(l1 + j + 1)) || (*(l3 + j) == *(l1 + j + 2)) || (*(l3 + j) == *(l2 + j)) || (*(l3 + j) == *(l2 + j + 1)) || (*(l3 + j) == *(l2 + j + 2)) || (*(l3 + j) == *(l3 + j + 1)) || (*(l3 + j) == *(l3 + j + 2)))
			{
				*(l3 + j) = 1 + rand() % 9;
				cout << "16 : " << *(l3 + j) << endl;
			}
			//Fin Tant que

			while ((*(l3 + j + 1) == *(l1 + j)) || (*(l3 + j + 1) == *(l1 + j + 1)) || (*(l3 + j + 1) == *(l1 + j + 2)) || (*(l3 + j + 1) == *(l2 + j)) || (*(l3 + j + 1) == *(l2 + j + 1)) || (*(l3 + j + 1) == *(l2 + j + 2)) || (*(l3 + j + 1) == *(l3 + j)) || (*(l3 + j + 1) == *(l3 + j + 2)))
			{
				*(l3 + j + 1) = 1 + rand() % 9;
				cout << "17 : " << *(l3 + j + 1) << endl;
			}
			//Fin Tant que

			while ((*(l3 + j + 2) == *(l1 + j)) || (*(l3 + j + 2) == *(l1 + j + 1)) || (*(l3 + j + 2) == *(l1 + j + 2)) || (*(l3 + j + 2) == *(l2 + j)) || (*(l3 + j + 2) == *(l2 + j + 1)) || (*(l3 + j + 2) == *(l2 + j + 2)) || (*(l3 + j + 2) == *(l3 + j)) || (*(l3 + j + 2) == *(l3 + j + 1)))
			{
				cout << "18.1 : " << *(l3 + j + 2) << endl;
				*(l3 + j + 2) = 1 + rand() % 9;
				cout << "18 : " << *(l3 + j + 2) << endl;
			}
			//Fin Tant que
//***************************************************************************************************************************************************************\\

			j = 6;
			while ((*(l1 + j) == *(l1 + j + 1)) || (*(l1 + j) == *(l1 + j + 2)) || (*(l1 + j) == *(l2 + j)) || (*(l1 + j) == *(l2 + j + 1)) || (*(l1 + j) == *(l2 + j + 2)) || (*(l1 + j) == *(l3 + j)) || (*(l1 + j) == *(l3 + j + 1)) || (*(l1 + j) == *(l3 + j + 2)))
			{
				*(l1 + j) = 1 + rand() % 9;
				cout << "19 : " << *(l1 + j) << endl;
			}
			//Fin Tant que

			while ((*(l1 + j + 1) == *(l1 + j)) || (*(l1 + j + 1) == *(l1 + j + 2)) || (*(l1 + j + 1) == *(l2 + j)) || (*(l1 + j + 1) == *(l2 + j + 1)) || (*(l1 + j + 1) == *(l2 + j + 2)) || (*(l1 + j + 1) == *(l3 + j)) || (*(l1 + j + 1) == *(l3 + j + 1)) || (*(l1 + j + 1) == *(l3 + j + 2)))
			{
				*(l1 + j + 1) = 1 + rand() % 9;
				cout << "20 : " << *(l1 + j + 1) << endl;
			}
			//Fin Tant que

			while ((*(l1 + j + 2) == *(l1 + j)) || (*(l1 + j + 2) == *(l1 + j + 1)) || (*(l1 + j + 2) == *(l2 + j)) || (*(l1 + j + 2) == *(l2 + j + 1)) || (*(l1 + j + 2) == *(l2 + j + 2)) || (*(l1 + j + 2) == *(l3 + j)) || (*(l1 + j + 2) == *(l3 + j + 1)) || (*(l2 + j + 2) == *(l3 + j + 2)))
			{
				cout << "21.1 : " << *(l1 + j + 2) << endl;
				*(l1 + j + 2) = 1 + rand() % 9;
				cout << "21 : " << *(l1 + j + 2) << endl;
			}
			//Fin Tant que
//***************************************************************************************************************************************************************\\
						
			while ((*(l2 + j) == *(l1 + j)) || (*(l2 + j) == *(l1 + j + 1)) || (*(l2 + j) == *(l1 + j + 2)) || (*(l2 + j) == *(l2 + j + 1)) || (*(l2 + j) == *(l2 + j + 2)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l3 + j + 1)) || (*(l2 + j) == *(l3 + j + 2)))
			{
				*(l2 + j) = 1 + rand() % 9;
				cout << "22 : " << *(l2 + j) << endl;
			}
			//Fin Tant que

			while ((*(l2 + j + 1) == *(l1 + j)) || (*(l2 + j + 1) == *(l1 + j + 1)) || (*(l2 + j + 1) == *(l1 + j + 2)) || (*(l2 + j + 1) == *(l2 + j)) || (*(l2 + j + 1) == *(l2 + j + 2)) || (*(l2 + j + 1) == *(l3 + j)) || (*(l2 + j + 1) == *(l3 + j + 1)) || (*(l2 + j + 1) == *(l3 + j + 2)))
			{
				*(l2 + j + 1) = 1 + rand() % 9;
				cout << "23 : " << *(l2 + j + 1) << endl;
			}
			//Fin Tant que

			while ((*(l2 + j + 2) == *(l1 + j)) || (*(l2 + j + 2) == *(l1 + j + 1)) || (*(l2 + j + 2) == *(l1 + j + 2)) || (*(l2 + j + 2) == *(l2 + j)) || (*(l2 + j + 2) == *(l2 + j + 1)) || (*(l2 + j + 2) == *(l3 + j)) || (*(l2 + j + 2) == *(l3 + j + 1)) || (*(l2 + j + 2) == *(l3 + j + 2)))
			{
				*(l2 + j + 2) = 1 + rand() % 9;
				cout << "24 : " << *(l2 + j + 2) << endl;
			}
			//Fin Tant que
//***************************************************************************************************************************************************************\\

			while ((*(l3 + j) == *(l1 + j)) || (*(l3 + j) == *(l1 + j + 1)) || (*(l3 + j) == *(l1 + j + 2)) || (*(l3 + j) == *(l2 + j)) || (*(l3 + j) == *(l2 + j + 1)) || (*(l3 + j) == *(l2 + j + 2)) || (*(l3 + j) == *(l3 + j + 1)) || (*(l3 + j) == *(l3 + j + 2)))
			{
				*(l3 + j) = 1 + rand() % 9;
				cout << "25 : " << *(l3 + j) << endl;
			}
			//Fin Tant que

			while ((*(l3 + j + 1) == *(l1 + j)) || (*(l3 + j + 1) == *(l1 + j + 1)) || (*(l3 + j + 1) == *(l1 + j + 2)) || (*(l3 + j + 1) == *(l2 + j)) || (*(l3 + j + 1) == *(l2 + j + 1)) || (*(l3 + j + 1) == *(l2 + j + 2)) || (*(l3 + j + 1) == *(l3 + j)) || (*(l3 + j + 1) == *(l3 + j + 2)))
			{
				*(l3 + j + 1) = 1 + rand() % 9;
				cout << "26 : " << *(l3 + j + 1) << endl;
			}
			//Fin Tant que

			while ((*(l3 + j + 2) == *(l1 + j)) || (*(l3 + j + 2) == *(l1 + j + 1)) || (*(l3 + j + 2) == *(l1 + j + 2)) || (*(l3 + j + 2) == *(l2 + j)) || (*(l3 + j + 2) == *(l2 + j + 1)) || (*(l3 + j + 2) == *(l2 + j + 2)) || (*(l3 + j + 2) == *(l3 + j)) || (*(l3 + j + 2) == *(l3 + j + 1)))
			{
				*(l3 + j + 2) = 1 + rand() % 9;
				cout << "27 : " << *(l3 + j + 2) << endl;
			}
			//Fin Tant que
//***************************************************************************************************************************************************************\\

		//	break;

		/*case 1:
			j = 0;
//***************************************************************************************************************************************************************\\

			while ((*(l4 + j) == *(l4 + j + 1)) || (*(l4 + j) == *(l4 + j + 2)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l5 + j + 1)) || (*(l4 + j) == *(l5 + j + 2)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l6 + j + 1)) || (*(l4 + j) == *(l6 + j + 2)))
			{
				*(l4 + j) = 1 + rand() % 9;
			}
			//Fin Tant que

			if ((j + 1) <= 2)
			{
				while ((*(l4 + j + 1) == *(l4 + j)) || (*(l4 + j + 1) == *(l4 + j + 2)) || (*(l4 + j + 1) == *(l5 + j)) || (*(l4 + j + 1) == *(l5 + j + 1)) || (*(l4 + j + 1) == *(l5 + j + 2)) || (*(l4 + j + 1) == *(l6 + j)) || (*(l4 + j + 1) == *(l6 + j + 1)) || (*(l4 + j + 1) == *(l6 + j + 2)))
				{
					*(l4 + j + 1) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si

			if ((j + 2) <= 2)
			{
				while ((*(l4 + j + 2) == *(l4 + j)) || (*(l4 + j + 2) == *(l4 + j + 1)) || (*(l4 + j + 2) == *(l5 + j)) || (*(l4 + j + 2) == *(l5 + j + 1)) || (*(l4 + j + 2) == *(l5 + j + 2)) || (*(l4 + j + 2) == *(l6 + j)) || (*(l4 + j + 2) == *(l6 + j + 1)) || (*(l5 + j + 2) == *(l6 + j + 2)))
				{
					*(l4 + j + 2) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si
//***************************************************************************************************************************************************************\\
						
			while ((*(l5 + j) == *(l4 + j)) || (*(l5 + j) == *(l4 + j + 1)) || (*(l5 + j) == *(l4 + j + 2)) || (*(l5 + j) == *(l5 + j + 1)) || (*(l5 + j) == *(l5 + j + 2)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l6 + j + 1)) || (*(l5 + j) == *(l6 + j + 2)))
			{
				*(l5 + j) = 1 + rand() % 9;
			}
			//Fin Tant que

			if ((j + 1) <= 2)
			{
				while ((*(l5 + j + 1) == *(l4 + j)) || (*(l5 + j + 1) == *(l4 + j + 1)) || (*(l5 + j + 1) == *(l4 + j + 2)) || (*(l5 + j + 1) == *(l5 + j)) || (*(l5 + j + 1) == *(l5 + j + 2)) || (*(l5 + j + 1) == *(l6 + j)) || (*(l5 + j + 1) == *(l6 + j + 1)) || (*(l5 + j + 1) == *(l6 + j + 2)))
				{
					*(l5 + j + 1) = 1 + rand() % 9;
				}
				//Fin Tant que
				}
			//Fin Si

			if ((j + 2) <= 2)
			{
				while ((*(l5 + j + 2) == *(l4 + j)) || (*(l5 + j + 2) == *(l4 + j + 1)) || (*(l5 + j + 2) == *(l4 + j + 2)) || (*(l5 + j + 2) == *(l5 + j)) || (*(l5 + j + 2) == *(l5 + j + 1)) || (*(l5 + j + 2) == *(l6 + j)) || (*(l5 + j + 2) == *(l6 + j + 1)) || (*(l5 + j + 2) == *(l6 + j + 2)))
				{
					*(l5 + j + 2) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si
//***************************************************************************************************************************************************************\\

			while ((*(l6 + j) == *(l4 + j)) || (*(l6 + j) == *(l4 + j + 1)) || (*(l6 + j) == *(l4 + j + 2)) || (*(l6 + j) == *(l5 + j)) || (*(l6 + j) == *(l5 + j + 1)) || (*(l6 + j) == *(l5 + j + 2)) || (*(l6 + j) == *(l6 + j + 1)) || (*(l6 + j) == *(l6 + j + 2)))
			{
				*(l6 + j) = 1 + rand() % 9;
			}
			//Fin Tant que

			if ((j + 1) <= 2)
			{
				while ((*(l6 + j + 1) == *(l4 + j)) || (*(l6 + j + 1) == *(l4 + j + 1)) || (*(l6 + j + 1) == *(l4 + j + 2)) || (*(l6 + j + 1) == *(l5 + j)) || (*(l6 + j + 1) == *(l5 + j + 1)) || (*(l6 + j + 1) == *(l5 + j + 2)) || (*(l6 + j + 1) == *(l6 + j)) || (*(l6 + j + 1) == *(l6 + j + 2)))
				{
					*(l6 + j + 1) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si

			if ((j + 2) <= 2)
			{
				while ((*(l6 + j + 2) == *(l4 + j)) || (*(l6 + j + 2) == *(l4 + j + 1)) || (*(l6 + j + 2) == *(l4 + j + 2)) || (*(l6 + j + 2) == *(l5 + j)) || (*(l6 + j + 2) == *(l5 + j + 1)) || (*(l6 + j + 2) == *(l5 + j + 2)) || (*(l6 + j + 2) == *(l6 + j)) || (*(l6 + j + 2) == *(l6 + j + 1)))
				{
					*(l6 + j + 2) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si
//***************************************************************************************************************************************************************\\
			
			j = 3;
			while ((*(l4 + j) == *(l4 + j + 1)) || (*(l4 + j) == *(l4 + j + 2)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l5 + j + 1)) || (*(l4 + j) == *(l5 + j + 2)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l6 + j + 1)) || (*(l4 + j) == *(l6 + j + 2)))
			{
				*(l4 + j) = 1 + rand() % 9;
			}
			//Fin Tant que
							
			if ((j + 1) <= 5)
			{
				while ((*(l4 + j + 1) == *(l4 + j)) || (*(l4 + j + 1) == *(l4 + j + 2)) || (*(l4 + j + 1) == *(l5 + j)) || (*(l4 + j + 1) == *(l5 + j + 1)) || (*(l4 + j + 1) == *(l5 + j + 2)) || (*(l4 + j + 1) == *(l6 + j)) || (*(l4 + j + 1) == *(l6 + j + 1)) || (*(l4 + j + 1) == *(l6 + j + 2)))
				{
					*(l4 + j + 1) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si

			if ((j + 2) <= 5)
			{
				while ((*(l4 + j + 2) == *(l4 + j)) || (*(l4 + j + 2) == *(l4 + j + 1)) || (*(l4 + j + 2) == *(l5 + j)) || (*(l4 + j + 2) == *(l5 + j + 1)) || (*(l4 + j + 2) == *(l5 + j + 2)) || (*(l4 + j + 2) == *(l6 + j)) || (*(l4 + j + 2) == *(l6 + j + 1)) || (*(l5 + j + 2) == *(l6 + j + 2)))
				{
					*(l4 + j + 2) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si
//***************************************************************************************************************************************************************\\
						
			while ((*(l5 + j) == *(l4 + j)) || (*(l5 + j) == *(l4 + j + 1)) || (*(l5 + j) == *(l4 + j + 2)) || (*(l5 + j) == *(l5 + j + 1)) || (*(l5 + j) == *(l5 + j + 2)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l6 + j + 1)) || (*(l5 + j) == *(l6 + j + 2)))
			{
				*(l5 + j) = 1 + rand() % 9;
			}
			//Fin Tant que
							
			if ((j + 1) <= 5)
			{
				while ((*(l5 + j + 1) == *(l4 + j)) || (*(l5 + j + 1) == *(l4 + j + 1)) || (*(l5 + j + 1) == *(l4 + j + 2)) || (*(l5 + j + 1) == *(l5 + j)) || (*(l5 + j + 1) == *(l5 + j + 2)) || (*(l5 + j + 1) == *(l6 + j)) || (*(l5 + j + 1) == *(l6 + j + 1)) || (*(l5 + j + 1) == *(l6 + j + 2)))
				{
					*(l5 + j + 1) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si

			if ((j + 2) <= 5)
			{
				while ((*(l5 + j + 2) == *(l4 + j)) || (*(l5 + j + 2) == *(l4 + j + 1)) || (*(l5 + j + 2) == *(l4 + j + 2)) || (*(l5 + j + 2) == *(l5 + j)) || (*(l5 + j + 2) == *(l5 + j + 1)) || (*(l5 + j + 2) == *(l6 + j)) || (*(l5 + j + 2) == *(l6 + j + 1)) || (*(l5 + j + 2) == *(l6 + j + 2)))
				{
					*(l5 + j + 2) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si
//***************************************************************************************************************************************************************\\

			while ((*(l6 + j) == *(l4 + j)) || (*(l6 + j) == *(l4 + j + 1)) || (*(l6 + j) == *(l4 + j + 2)) || (*(l6 + j) == *(l5 + j)) || (*(l6 + j) == *(l5 + j + 1)) || (*(l6 + j) == *(l5 + j + 2)) || (*(l6 + j) == *(l6 + j + 1)) || (*(l6 + j) == *(l6 + j + 2)))
			{
				*(l6 + j) = 1 + rand() % 9;
			}
			//Fin Tant que

			if ((j + 1) <= 5)
			{
				while ((*(l6 + j + 1) == *(l4 + j)) || (*(l6 + j + 1) == *(l4 + j + 1)) || (*(l6 + j + 1) == *(l4 + j + 2)) || (*(l6 + j + 1) == *(l5 + j)) || (*(l6 + j + 1) == *(l5 + j + 1)) || (*(l6 + j + 1) == *(l5 + j + 2)) || (*(l6 + j + 1) == *(l6 + j)) || (*(l6 + j + 1) == *(l6 + j + 2)))
				{
					*(l6 + j + 1) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si

			if ((j + 2) <= 5)
			{
				while ((*(l6 + j + 2) == *(l4 + j)) || (*(l6 + j + 2) == *(l4 + j + 1)) || (*(l6 + j + 2) == *(l4 + j + 2)) || (*(l6 + j + 2) == *(l5 + j)) || (*(l6 + j + 2) == *(l5 + j + 1)) || (*(l6 + j + 2) == *(l5 + j + 2)) || (*(l6 + j + 2) == *(l6 + j)) || (*(l6 + j + 2) == *(l6 + j + 1)))
				{
					*(l6 + j + 2) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si
//***************************************************************************************************************************************************************\\

			j = 6;
			while ((*(l4 + j) == *(l4 + j + 1)) || (*(l4 + j) == *(l4 + j + 2)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l5 + j + 1)) || (*(l4 + j) == *(l5 + j + 2)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l6 + j + 1)) || (*(l4 + j) == *(l6 + j + 2)))
			{
				*(l4 + j) = 1 + rand() % 9;
			}
			//Fin Tant que

			if ((j + 1) <= 8)
			{
				while ((*(l4 + j + 1) == *(l4 + j)) || (*(l4 + j + 1) == *(l4 + j + 2)) || (*(l4 + j + 1) == *(l5 + j)) || (*(l4 + j + 1) == *(l5 + j + 1)) || (*(l4 + j + 1) == *(l5 + j + 2)) || (*(l4 + j + 1) == *(l6 + j)) || (*(l4 + j + 1) == *(l6 + j + 1)) || (*(l4 + j + 1) == *(l6 + j + 2)))
				{
					*(l4 + j + 1) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si

			if ((j + 2) <= 8)
			{
				while ((*(l4 + j + 2) == *(l4 + j)) || (*(l4 + j + 2) == *(l4 + j + 1)) || (*(l4 + j + 2) == *(l5 + j)) || (*(l4 + j + 2) == *(l5 + j + 1)) || (*(l4 + j + 2) == *(l5 + j + 2)) || (*(l4 + j + 2) == *(l6 + j)) || (*(l4 + j + 2) == *(l6 + j + 1)) || (*(l5 + j + 2) == *(l6 + j + 2)))
				{
					*(l4 + j + 2) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si
//***************************************************************************************************************************************************************\\
						
			while ((*(l5 + j) == *(l4 + j)) || (*(l5 + j) == *(l4 + j + 1)) || (*(l5 + j) == *(l4 + j + 2)) || (*(l5 + j) == *(l5 + j + 1)) || (*(l5 + j) == *(l5 + j + 2)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l6 + j + 1)) || (*(l5 + j) == *(l6 + j + 2)))
			{
				*(l5 + j) = 1 + rand() % 9;
			}
			//Fin Tant que

			if ((j + 1) <= 8)
			{
				while ((*(l5 + j + 1) == *(l4 + j)) || (*(l5 + j + 1) == *(l4 + j + 1)) || (*(l5 + j + 1) == *(l4 + j + 2)) || (*(l5 + j + 1) == *(l5 + j)) || (*(l5 + j + 1) == *(l5 + j + 2)) || (*(l5 + j + 1) == *(l6 + j)) || (*(l5 + j + 1) == *(l6 + j + 1)) || (*(l5 + j + 1) == *(l6 + j + 2)))
				{
					*(l5 + j + 1) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si

			if ((j + 2) <= 8)
			{
				while ((*(l5 + j + 2) == *(l4 + j)) || (*(l5 + j + 2) == *(l4 + j + 1)) || (*(l5 + j + 2) == *(l4 + j + 2)) || (*(l5 + j + 2) == *(l5 + j)) || (*(l5 + j + 2) == *(l5 + j + 1)) || (*(l5 + j + 2) == *(l6 + j)) || (*(l5 + j + 2) == *(l6 + j + 1)) || (*(l5 + j + 2) == *(l6 + j + 2)))
				{
					*(l5 + j + 2) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si
//***************************************************************************************************************************************************************\\

			while ((*(l6 + j) == *(l4 + j)) || (*(l6 + j) == *(l4 + j + 1)) || (*(l6 + j) == *(l4 + j + 2)) || (*(l6 + j) == *(l5 + j)) || (*(l6 + j) == *(l5 + j + 1)) || (*(l6 + j) == *(l5 + j + 2)) || (*(l6 + j) == *(l6 + j + 1)) || (*(l6 + j) == *(l6 + j + 2)))
			{
				*(l6 + j) = 1 + rand() % 9;
			}
			//Fin Tant que

			if ((j + 1) <= 8)
			{
				while ((*(l6 + j + 1) == *(l4 + j)) || (*(l6 + j + 1) == *(l4 + j + 1)) || (*(l6 + j + 1) == *(l4 + j + 2)) || (*(l6 + j + 1) == *(l5 + j)) || (*(l6 + j + 1) == *(l5 + j + 1)) || (*(l6 + j + 1) == *(l5 + j + 2)) || (*(l6 + j + 1) == *(l6 + j)) || (*(l6 + j + 1) == *(l6 + j + 2)))
				{
					*(l6 + j + 1) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si

			if ((j + 2) <= 8)
			{
				while ((*(l6 + j + 2) == *(l4 + j)) || (*(l6 + j + 2) == *(l4 + j + 1)) || (*(l6 + j + 2) == *(l4 + j + 2)) || (*(l6 + j + 2) == *(l5 + j)) || (*(l6 + j + 2) == *(l5 + j + 1)) || (*(l6 + j + 2) == *(l5 + j + 2)) || (*(l6 + j + 2) == *(l6 + j)) || (*(l6 + j + 2) == *(l6 + j + 1)))
				{
					*(l6 + j + 2) = 1 + rand() % 9;
				}
				//Fin Tant que
			}
			//Fin Si
//***************************************************************************************************************************************************************\\
			
			break;

		case 2:

			break;*/
		//}
		//Fin Selon
		//i = i + 1;
	//}
	//Fin Tant que
	//Fin
}

/*
R: Verifie si les lignes et les colonnes sont justes
E: vide
S: 9 pointeurs qui corespondent aux lignes et colonnes à vérifier
*/
/*bool verif_ligne2(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9)
{
	//Lexique local à verif_sudoku
	bool verif;
	unsigned int j;

	//Algorithme local à verif_sudoku
	//Début

	//(*(l1 + j) == *(l2 + j)) || (*(l1 + j) == (*(l3 + j)) || (*(l1 + j) == *(l4 + j)) || (*(l1 + j) == *(l5 + j)) || (*(l1 + j) == *(l6 + j)) || (*(l1 + j) == *(l7 + j)) || (*(l1 + j) == *(l8 + j)) || (*(l1 + j) == *(l9 + j))) || (*(l2 + j) == (*(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j))) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j))) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j))) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j))) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j))) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j))) || (*(l8 + j) == *(l9 + j)))

	j = 0;
	while (j <= 8)
	{
		if ((*(l2 + j) == *(l1 + j)) || (*(l2 + j) == *(l3 + j)) || (*(l2 + j) == *(l4 + j)) || (*(l2 + j) == *(l5 + j)) || (*(l2 + j) == *(l6 + j)) || (*(l2 + j) == *(l7 + j)) || (*(l2 + j) == *(l8 + j)) || (*(l2 + j) == *(l9 + j)) || (*(l3 + j) == *(l1 + j)) || (*(l3 + j) == *(l2 + j)) || (*(l3 + j) == *(l4 + j)) || (*(l3 + j) == *(l5 + j)) || (*(l3 + j) == *(l6 + j)) || (*(l3 + j) == *(l7 + j)) || (*(l3 + j) == *(l8 + j)) || (*(l3 + j) == *(l9 + j)) || (*(l4 + j) == *(l1 + j)) || (*(l4 + j) == *(l2 + j)) || (*(l4 + j) == *(l3 + j)) || (*(l4 + j) == *(l5 + j)) || (*(l4 + j) == *(l6 + j)) || (*(l4 + j) == *(l7 + j)) || (*(l4 + j) == *(l8 + j)) || (*(l4 + j) == *(l9 + j)) || (*(l5 + j) == *(l1 + j)) || (*(l5 + j) == *(l2 + j)) || (*(l5 + j) == *(l3 + j)) || (*(l5 + j) == *(l4 + j)) || (*(l5 + j) == *(l6 + j)) || (*(l5 + j) == *(l7 + j)) || (*(l5 + j) == *(l8 + j)) || (*(l5 + j) == *(l9 + j)) || (*(l6 + j) == *(l1 + j)) || (*(l6 + j) == *(l2 + j)) || (*(l6 + j) == *(l3 + j)) || (*(l6 + j) == *(l4 + j)) || (*(l6 + j) == *(l5 + j)) || (*(l6 + j) == *(l7 + j)) || (*(l6 + j) == *(l8 + j)) || (*(l6 + j) == *(l9 + j)) || (*(l7 + j) == *(l1 + j)) || (*(l7 + j) == *(l2 + j)) || (*(l7 + j) == *(l3 + j)) || (*(l7 + j) == *(l4 + j)) || (*(l7 + j) == *(l5 + j)) || (*(l7 + j) == *(l6 + j)) || (*(l7 + j) == *(l8 + j)) || (*(l7 + j) == *(l9 + j)) || (*(l8 + j) == *(l1 + j)) || (*(l8 + j) == *(l2 + j)) || (*(l8 + j) == *(l3 + j)) || (*(l8 + j) == *(l4 + j)) || (*(l8 + j) == *(l5 + j)) || (*(l8 + j) == *(l6 + j)) || (*(l8 + j) == *(l7 + j)) || (*(l8 + j) == *(l9 + j)) || (*(l9 + j) == *(l1 + j)) || (*(l9 + j) == *(l2 + j)) || (*(l9 + j) == *(l3 + j)) || (*(l9 + j) == *(l4 + j)) || (*(l9 + j) == *(l5 + j)) || (*(l9 + j) == *(l6 + j)) || (*(l9 + j) == *(l7 + j)) || (*(l9 + j) == *(l8 + j)))
		{
			verif = 0;
		}
		else
		{
			verif = 1;
		}
		//Fin Si
		j = j + 1;
	}
	//Fin Tant que
	return verif;

	/*z = 2;
	j = 0;
	while (j <= 8)
	{
		while ((*(l1 + j) == *(l2 + j) == *(l3 + j) == *(l4 + j) == *(l5 + j) == *(l6 + j) == *(l7 + j) == *(l8 + j) == *(l9 + j)) || (*(l1 + j) == *(l1 + j + 1) == *(l1 + j + 2) == *(l1 + j + 3) == *(l1 + j + 4) == *(l1 + j + 5) == *(l1 + j + 6) == *(l1 + j + 7) == *(l1 + j + 8)) || (*(l2 + j) == *(l2 + j + 1) == *(l2 + j + 2) == *(l2 + j + 3) == *(l2 + j + 4) == *(l2 + j + 5) == *(l2 + j + 6) == *(l2 + j + 7) == *(l2 + j + 8)) || (*(l3 + j) == *(l3 + j + 1) == *(l3 + j + 2) == *(l3 + j + 3) == *(l3 + j + 4) == *(l3 + j + 5) == *(l3 + j + 6) == *(l3 + j + 7) == *(l3 + j + 8)) || (*(l4 + j) == *(l4 + j + 1) == *(l4 + j + 2) == *(l4 + j + 3) == *(l4 + j + 4) == *(l4 + j + 5) == *(l4 + j + 6) == *(l4 + j + 7) == *(l4 + j + 8)) || (*(l5 + j) == *(l5 + j + 1) == *(l5 + j + 2) == *(l5 + j + 3) == *(l5 + j + 4) == *(l5 + j + 5) == *(l5 + j + 6) == *(l5 + j + 7) == *(l5 + j + 8)) || (*(l6 + j) == *(l6 + j + 1) == *(l6 + j + 2) == *(l6 + j + 3) == *(l6 + j + 4) == *(l6 + j + 5) == *(l6 + j + 6) == *(l6 + j + 7) == *(l6 + j + 8)) || (*(l7 + j) == *(l7 + j + 1) == *(l7 + j + 2) == *(l7 + j + 3) == *(l7 + j + 4) == *(l7 + j + 5) == *(l7 + j + 6) == *(l7 + j + 7) == *(l7 + j + 8)) || (*(l8 + j) == *(l8 + j + 1) == *(l8 + j + 2) == *(l8 + j + 3) == *(l8 + j + 4) == *(l8 + j + 5) == *(l8 + j + 6) == *(l8 + j + 7) == *(l8 + j + 8)) || (*(l9 + j) == *(l9 + j + 1) == *(l9 + j + 2) == *(l9 + j + 3) == *(l9 + j + 4) == *(l9 + j + 5) == *(l9 + j + 6) == *(l9 + j + 7) == *(l9 + j + 8)) || (z == 2))
		{
			verif_ligne(l1);
			verif_ligne(l2);
			verif_ligne(l3);
			verif_ligne(l4);
			verif_ligne(l5);
			verif_ligne(l6);
			verif_ligne(l7);
			verif_ligne(l8);
			verif_ligne(l9);
			verif_colonnes(l1, l2, l3, l4, l5, l6, l7, l8, l9);
			z = 1;
		}
		//Fin Tant que
		j = j + 1;
	}
	//Fin Tant que
	//Fin
}*/

/*
R: Affiche le sudoku
E: un pointeur d'entier qui corespond à l'emplacement du sudoku
S: vide
*/
void affiche_sudoku(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9)
{
	//Lexique local à affiche_sudoku
	unsigned int i;

	//Algorithme local à affiche_sudoku
	//Début

//**************************************************************************************************************************************************\\
	//Affiche la première ligne
	i = 0;
	cout << "|";
	while (i <= 2)
	{
		cout << *(l1 + i)<<"|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 5)
	{
		cout << *(l1 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 8)
	{
		cout << *(l1 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que
	cout << endl;
//**************************************************************************************************************************************************\\
	//Affiche la seconde ligne
	i = 0;
	cout << "|";
	while (i <= 2)
	{
		cout << *(l2 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 5)
	{
		cout << *(l2 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 8)
	{
		cout << *(l2 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que
	cout << endl;
//**************************************************************************************************************************************************\\
	//Affiche la troisième ligne
	i = 0;
	cout << "|";
	while (i <= 2)
	{
		cout << *(l3 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 5)
	{
		cout << *(l3 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 8)
	{
		cout << *(l3 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que
	cout << endl << endl;
//**************************************************************************************************************************************************\\
	//Affiche la quatrième ligne
	i = 0;
	cout << "|";
	while (i <= 2)
	{
		cout << *(l4 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 5)
	{
		cout << *(l4 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 8)
	{
		cout << *(l4 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que
	cout << endl;
//**************************************************************************************************************************************************\\
	//Affiche la cinquième ligne
	i = 0;
	cout << "|";
	while (i <= 2)
	{
		cout << *(l5 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 5)
	{
		cout << *(l5 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 8)
	{
		cout << *(l5 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que
	cout << endl;
//**************************************************************************************************************************************************\\
	//Affiche la sixième ligne
	i = 0;
	cout << "|";
	while (i <= 2)
	{
		cout << *(l6 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 5)
	{
		cout << *(l6 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 8)
	{
		cout << *(l6 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que
	cout << endl << endl;
//**************************************************************************************************************************************************\\
	//Affiche la septième ligne
	i = 0;
	cout << "|";
	while (i <= 2)
	{
		cout << *(l7 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 5)
	{
		cout << *(l7 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 8)
	{
		cout << *(l7 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que
	cout << endl;
//**************************************************************************************************************************************************\\
	//Affiche la huitième ligne
	i = 0;
	cout << "|";
	while (i <= 2)
	{
		cout << *(l8 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 5)
	{
		cout << *(l8 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 8)
	{
		cout << *(l8 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que
	cout << endl;
//**************************************************************************************************************************************************\\
	//Affiche la neuvième ligne
	i = 0;
	cout << "|";
	while (i <= 2)
	{
		cout << *(l9 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 5)
	{
		cout << *(l9 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que

	cout << "  |";
	while (i <= 8)
	{
		cout << *(l9 + i) << "|";
		i = i + 1;
	}
	//Fin Tant que
	cout << endl;
//**************************************************************************************************************************************************\\

	/*i = 0;
	while (i <= 8)
	{
		switch (i)
		{
		case 0: 
			j = 0;
			cout << "|";
			while (j <= 2)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 5)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 8)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 1: 
			j = 9;
			cout << "|";
			while (j <= 11)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 14)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 17)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 2: 
			j = 18;
			cout << "|";
			while (j <= 20)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 23)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			cout << " ";
			cout << "|";
			while (j <= 26)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			cout << endl;
			break;

		case 3: 
			j = 27;
			cout << "|";
			while (j <= 29)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 32)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			cout << " ";
			cout << "|";
			while (j <= 35)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 4: 
			j = 36;
			cout << "|";
			while (j <= 38)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 41)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 44)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 5: 
			j = 45;
			cout << "|";
			while (j <= 47)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 50)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 53)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			cout << endl;
			break;

		case 6: 
			j = 54;
			cout << "|";
			while (j <= 56)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 59)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 62)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 7: 
			j = 63;
			cout << "|";
			while (j <= 65)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 68)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 71)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			break;

		case 8: 
			j = 72;
			cout << "|";
			while (j <= 74)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 77)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que

			cout << " ";
			cout << "|";
			while (j <= 80)
			{
				cout << *(po + j);
				cout << "|";
				j = j + 1;
			}
			//Fin Tant que
			break;
		}
		//Fin Selon
		cout << endl;
		i = i + 1;
	}
	//Fin Tant que*/
	//Fin
}

/*
R: Affiche les règles et les consignes
E: vide
S: vide
*/
void affiche_jeu(unsigned int* l1, unsigned int* l2, unsigned int* l3, unsigned int* l4, unsigned int* l5, unsigned int* l6, unsigned int* l7, unsigned int* l8, unsigned int* l9)
{
	//Lexique local à affiche_consignes
	int nb;
	unsigned int lv;

	//Algorithme local à affiche_consigne
	//Début
	cout << "/*********************************************************************\\" << endl;
	cout << "                         Le jeu du Sudoku" << endl;
	cout << "                     Pour sortir appuiez sur '-1'." << endl;
	cout << "                Pour voir les regles appuiez sur '1'." << endl;
	cout << "              Pour commencer a jouer appuiez sur '2'." << endl;
	cout << "                Pour voir le sudoku appuiez sur '99'" << endl;
	cout << "/*********************************************************************\\" << endl;
	cin >> nb;
	cout << endl;
	
	if (nb == 1)
	{
		while (nb == 1)
		{
			cout << "                         Voici les regles :" << endl;
			cout << "Le but du jeu est de remplir les cases avec des chiffres allant de 1 à 9" << endl;
			cout << "en veillant toujours a ce qu'un meme chiffre ne figure qu'une seule fois" << endl;
			cout << "par colonne, par ligne, et par carre de neuf cases." << endl << endl;
			cout << "Au debut du jeu, une vingtaine de chiffres sont deja places et il vous" << endl;
			cout << "reste a trouver les autres." << endl << endl;
			cout << "En effet, une grille initiale de sudoku correctement constituee ne peut" << endl;
			cout << "aboutir qu'a une et une seule solution." << endl;
			cout << "Pour trouver les chiffres manquants, tout est une question de logique et" << endl;
			cout << "d'observation." << endl;

			cout << endl;

			cout << "/*********************************************************************\\" << endl;
			cout << "                       Le jeu du Sudoku" << endl;
			cout << "                    Pour sortir appuiez sur '-1'." << endl;
			cout << "               Pour voir les regles appuiez sur '1'." << endl;
			cout << "              Pour commencer a jouer appuiez sur '2'." << endl;
			cout << "               Pour voir le sudoku appuiez sur '99'" << endl;
			cout << "/*********************************************************************\\" << endl;
			cin >> nb;
			cout << endl << endl;
		}
	}
	//Fin Si

	switch (nb)
	{
	case -1:
		EXIT_SUCCESS;
		break;

	case 2:
		cout << "Quel niveau de difficulte voulez vous." << endl;
		cout << "1 = Facile." << endl;
		cout << "2 = Moyen" << endl;
		cout << "3 = Difficile" << endl;
		cin >> lv;
		cout << endl;
		switch (lv)
		{
		case 1:
			cout << "A faire." << endl;
			break;
		case 2:
			cout << "A faire." << endl;
			break;
		case 3:
			cout << "A faire." << endl;
			break;
		}
		cout << endl;
		break;

	case 99:
		affiche_sudoku(l1, l2, l3, l4, l5, l6, l7, l8, l9);
		break;
	}
}