#include<iostream>
using namespace std;

int main()
{
	//Lexique principal
	float prix_hors_taxe, tva, prix_ttc; //prix_hors_taxe, tva et prix_ttc representent respectivement le prix hors taxe d'un article, le % de TVA qui lui est appliqu� et le prix apr�s la TVA appliqu�
	int qte_art; //qte_art represent la quantit� d'article que poss�de l'utilisateur

	//Algorithme principal
	//D�but
	cout << "Saisir le prix hors taxe d'un article en euros." << endl;
	cin >> prix_hors_taxe;
	cout << "Saisir la quantite d'article commande." << endl;
	cin >> qte_art;
	cout << "Saisir le taux de TVA en % (Saisir 20 pour 20%)." << endl;
	cin >> tva;
	prix_hors_taxe = prix_hors_taxe * qte_art;
	tva = 1 + tva / 100;
	prix_ttc = prix_hors_taxe * tva;
	cout << "Le prix des articles avec la TVA d'applique est de " << prix_hors_taxe << " euros." << endl;
	//Fin
	return 0;
}