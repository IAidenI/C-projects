#include <stdio.h>
#include <stdlib.h>

#include "pixel.h"

int main(void)
{
	unsigned int pix1[] = {
	0, 3, 1, 1, 0, 1, 0, 1, 0, 7, 1, 2, 0, 15, 1, 1, 0, 8, 1, 1, 0, 8, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 3, 1, 1, 0, 1, 1, 1, 0, 3, 1, 1, 0, 1, 1, 4, 0, 2, 1, 1, 25
	};
	unsigned int pix1_lenght = 62;

	unsigned int pix2[] = {
	0, 2, 1, 1, 0, 4, 1, 1, 0, 4, 1, 3, 0, 1, 1, 2, 0, 2, 1, 8, 0, 11, 1, 4, 0, 1, 1, 3, 0, 6, 1, 2, 0, 4, 1, 1, 0, 4, 1, 2, 0, 7, 1, 4, 0, 4, 1, 2, 0, 7, 1, 2, 0, 3, 1, 2, 0, 3
	};
	unsigned int pix2_lenght = 58;

	unsigned int pix3[] = {
	0, 3, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 0, 11, 1, 2, 0, 2, 1, 3, 0, 7, 1, 1, 0, 4, 1, 2, 0, 2, 1, 2, 0, 7, 1, 1, 0, 6, 1, 1, 0, 2, 1, 1, 0, 4, 1, 3, 0, 1, 1, 1, 0, 4, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 0, 3, 1, 1, 0, 2, 1, 3, 0, 2, 1, 2, 0, 3
	};
	unsigned int pix3_lenght = 78;

	unsigned int pix4[] = {
	1, 1, 0, 2, 1, 1, 0, 4, 1, 1, 0, 2 , 1, 1 , 0, 1 , 1, 1 , 0, 2 , 1, 1 , 0, 2 , 1, 1 , 0, 1 , 1, 2 , 0, 2 , 1, 2 , 0, 1 , 1, 2 , 0, 3 , 1, 1 , 0, 3 , 1, 1 , 0, 2 , 1, 2 , 0, 1 , 1, 3 , 0, 3 , 1, 1 , 0, 2 , 1, 1 , 0, 4 , 1, 2 , 0, 1 , 1, 1 , 0, 4 , 1, 1 , 0, 3 , 1, 2 , 0, 12 , 1, 2 , 0, 1 , 1, 1 , 0, 3 , 1, 7 , 0, 3
	};
	unsigned int pix4_lenght = 132;

	unsigned int pix5[] = {
	0, 3 , 1, 1 , 0, 7 , 1, 1 , 0, 1 , 1, 1 , 0, 4 , 1, 1 , 0, 2 , 1, 2 , 0, 2 , 1, 2 , 0, 4 , 1, 1 , 0, 2 , 1, 1 , 0, 1 , 1, 2 , 0, 1 , 1, 8 , 0, 1 , 1, 1 , 0, 4 , 1, 1 , 0, 5 , 1, 1 , 0, 3 , 1, 2 , 0, 2 , 1, 1 , 0, 1 , 1, 2 , 0, 2 , 1, 1 , 0, 3 , 1, 2 , 0, 9 , 1, 1 , 0, 1 , 1, 2 , 0, 2 , 1, 3 , 0, 2 , 1, 1
	};
	unsigned int pix5_lenght = 131;

	unsigned int pix6[] = {
	0, 7 , 1, 1 , 0, 4 , 1, 1 , 0, 4 , 1, 1 , 0, 1 , 1, 1 , 0, 1 , 1, 7 , 0, 3 , 1, 1 , 0, 1 , 1, 2 , 0, 3 , 1, 1 , 0, 1 , 1, 6 , 0, 1 , 1, 1 , 0, 3 , 1, 1 , 0, 2 , 1, 1 , 0, 14 , 1, 2 , 0, 8 , 1, 1 , 0, 10 , 1, 2 , 0, 3 , 1, 2 , 0, 1 , 1, 1 , 0, 1
	};
	unsigned int pix6_lenght = 104;

	unsigned int pix7[] = {
	0, 6 , 1, 5 , 0, 4 , 1, 1 , 0, 7 , 1, 1 , 0, 2 , 1, 1 , 0, 3 , 1, 2 , 0, 4 , 1, 1 , 0, 8 , 1, 1 , 0, 3 , 1, 2 , 0, 1 , 1, 2 , 0, 3 , 1, 1 , 0, 8 , 1, 1 , 0, 2 , 1, 2 , 0, 1 , 1, 1 , 0, 3 , 1, 7 , 0, 5 , 1, 2 , 0, 2 , 1, 1 , 0, 2 , 1, 2 , 0, 3
	};
	unsigned int pix7_lenght = 104;

	unsigned int pix8[] = {
	0, 1 , 1, 1 , 0, 2 , 1, 1 , 0, 1 , 1, 2 , 0, 5 , 1, 1 , 0, 6 , 1, 2 , 0, 3 , 1, 1 , 0, 2 , 1, 1 , 0, 1 , 1, 2 , 0, 20 , 1, 8 , 0, 1 , 1, 1 , 0, 1 , 1, 1 , 0, 4 , 1, 2 , 0, 3 , 1, 1 , 0, 2 , 1, 2 , 0, 3 , 1, 2 , 0, 7 , 1, 2 , 0, 3 , 1, 2 , 0, 4
	};
	unsigned int pix8_lenght = 104;

	unsigned int pix9[] = {
	0, 2 , 1, 1 , 0, 3 , 1, 5 , 0, 5 , 1, 2 , 0, 7 , 1, 1 , 0, 4 , 1, 2 , 0, 2 , 1, 1 , 0, 2 , 1, 2 , 0, 1 , 1, 1 , 0, 3 , 1, 1 , 0, 6 , 1, 2 , 0, 2 , 1, 2 , 0, 3 , 1, 2 , 0, 2 , 1, 3 , 0, 1 , 1, 1 , 0, 6 , 1, 3 , 0, 3 , 1, 5 , 0, 3 , 1, 1 , 0, 4 , 1, 1 , 0, 5
	};
	unsigned int pix9_lenght = 110;

	unsigned int pix10[] = {
	0, 4 , 1, 2 , 0, 3 , 1, 2 , 0, 3 , 1, 1 , 0, 5 , 1, 2 , 0, 2 , 1, 1 , 0, 1 , 1, 1 , 0, 1 , 1, 1 , 0, 1 , 1, 2 , 0, 9 , 1, 1 , 0, 3 , 1, 1 , 0, 2 , 1, 1 , 0, 1 , 1, 1 , 0, 2 , 1, 1 , 0, 1 , 1, 2 , 0, 2 , 1, 1 , 0, 2 , 1, 1 , 0, 1 , 1, 1 , 0, 4 , 1, 3 , 0, 1 , 1, 1 , 0, 2 , 1, 2 , 0, 3 , 1, 2 , 0, 3 , 1, 1 , 0, 5 , 1, 1 , 0, 4 , 1, 1 , 0, 2
	};
	unsigned int pix10_lenght = 146;

	unsigned int pix11[] = {
	0, 6 , 1, 5 , 0, 4 , 1, 1 , 0, 1 , 1, 1 , 0, 2 , 1, 2 , 0, 6 , 1, 1 , 0, 1 , 1, 7 , 0, 4 , 1, 3 , 0, 3 , 1, 1 , 0, 4 , 1, 1 , 0, 2 , 1, 2 , 0, 4 , 1, 1 , 0, 6 , 1, 1 , 0, 6 , 1, 8 , 0, 3 , 1, 1 , 0, 5 , 1, 1 , 0, 7
	};
	unsigned int pix11_lenght = 92;

	unsigned int pix12[] = {
	0, 2 , 1, 1 , 0, 3 , 1, 6 , 0, 4 , 1, 1 , 0, 1 , 1, 3 , 0, 4 , 1, 1 , 0, 2 , 1, 2 , 0, 4 , 1, 1 , 0, 5 , 1, 1 , 0, 2 , 1, 1 , 0, 3 , 1, 2 , 0, 3 , 1, 1 , 0, 2 , 1, 3 , 0, 1 , 1, 1 , 0, 2 , 1, 2 , 0, 3 , 1, 3 , 0, 2 , 1, 3 , 0, 9 , 1, 1 , 0, 4 , 1, 2 , 0, 7 , 1, 2
	};
	unsigned int pix12_lenght = 113;

	decry(pix1, pix1_lenght);
	printf("\n");
	decry(pix2, pix2_lenght);
	printf("\n");
	decry(pix3, pix3_lenght);
	printf("\n");
	decry(pix4, pix4_lenght);
	printf("\n");
	decry(pix5, pix5_lenght);
	printf("\n");
	decry(pix6, pix6_lenght);
	printf("\n");
	decry(pix7, pix7_lenght);
	printf("\n");
	decry(pix8, pix8_lenght);
	printf("\n");
	decry(pix9, pix9_lenght);
	printf("\n");
	decry(pix10, pix10_lenght);
	printf("\n");
	decry(pix11, pix11_lenght);
	printf("\n");
	decry(pix12, pix12_lenght);

	return 0;
}
