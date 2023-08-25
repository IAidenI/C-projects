#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	float e;
	cout << "Entrer deux entiers: " << endl;
	cin >> a >> b;
	cout << "Vous avez entre les valeurs " << a << " et " << b<< endl;
	c = a + b;
	cout << "Leur somme est: " << c << endl;
	c = a * b;
	cout << "Leur produit est: " << c << endl;
	c = a / b;
	cout << "Leur quotient est de " << c << endl;
	c = a % b;
	cout << "Leur reste est de " << c << endl;
	e = float (a) / b;
	cout << "Leur valeur approchee est de " << e << endl;
	return 0;
}