/*
R: Calcule et retourne le terme d'indice n de la suite de Fibonacci
E: a, b : 2 entiers : les 2 premiers termes
   n : 1 entier l'indice a retourner
S: 1 entier corespondant au terme Un de la suite
*/
int Fibo_n(int a, int b, int n)
{
	//Lexique local à Fibo_n
	int v, w, u, i;

	//Algorithme local à Fibo_n
	//Début
	switch (n)
	{
	case 0: u = a;
		    break;
	case 1: u = b;
		    break;
	default: v = a;
		     w = b;
			 i = 2;
			 while (i <= n)
			 {
				 u = w + v;
				 v = w;
				 w = u;
				 i = i + 1;
			 }
			 //FinTantque
		break;
	}
	//FinSelon
	return u;
	//Fin
}