#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Color(int t, int f)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, f * 16 + t);
}

int decry(unsigned int pix[], unsigned int pix_lenght)
{
	unsigned int i, j;
	i = 0;
	while (i < pix_lenght)
	{
		j = 0;
		/*if (i != 0)
		{
			if (((pix[i - 2] == 0) && (pix[i] == 0)) || ((pix[i - 2] == 1) && (pix[i] == 1)))
			{
				printf(" ");
			}
		}*/

		while (j < pix[i + 1])
		{
			if (pix[i] == 0)
			{
				printf(" ");
			}
			else if (pix[i] == 1)
			{
				Color(4, 0);
				printf("#");
				Color(15, 0);
			}
			j = j + 1;
		}
		i = i + 2;
	}

	return 0;
}
