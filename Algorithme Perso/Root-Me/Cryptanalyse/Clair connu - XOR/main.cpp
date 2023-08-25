#define TAILLE_MAX 10
#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>

#include "couleur.h"

int main(void)
{
	FILE* fichier = NULL;
	FILE* fichier_out = NULL;
	FILE* fichier_init = NULL;
	char a;

	fichier = fopen("ch3.bmp", "rb");
	fichier_out = fopen("decrypt.bmp", "wb");
	fichier_init = fopen("init.bmp", "wb");
	char b[] = { 'f', 'a', 'l', 'l', 'e', 'n' };
	char chaine[TAILLE_MAX] = "";
	unsigned int lenght_b = 6;
	unsigned int i, j, q;
	char c, t;	

	if ((fichier != NULL) && (fichier_out != NULL))
	{
		/*printf("[*]Fichier non-modifier.\n");
		j = 0;

			do
			{
				a = fgetc(fichier);
				fputc(a, fichier_init);
				//printf("%c", a);
				j = j + 1;
			} while (j < 495605);*/

		//printf("[*]Fichier modifier.\n");
		i = 0;
		j = 0;
		do
		{
				a = fgetc(fichier);
				if (i < lenght_b)
				{
					c = a ^ b[i];
					fputc(c, fichier_out);
					//printf("%c", c);
				}
				else
				{
					i = 0;
					c = a ^ b[i];
					fputc(c, fichier_out);
					//printf("%c", c);
				}
				i = i + 1;
				j = j + 1;

				if (j == 9449)
				{
					q = 1;
				}
			//Color(4, 0);
			//printf("[_]Decryptage en cours...\n");
			//Color(15, 0);
		} while (j < 495606);
		//Bonne valeur = 495606

		Color(2, 0);
		printf("[*]Decryptage reussi.\n");
		Color(15, 0);
		//printf("\nj = %d\n", j);



		fclose(fichier);
		fclose(fichier_out);
		fclose(fichier_init);
	}
	else
	{
		printf("Erreur: Impossible d'ouvrir le fichier.");
	}
	return 0;
}