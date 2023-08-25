#include<string>
using namespace std;

class Cellule
{
private:
	string m_nom;
	unsigned int m_noyau;
	float m_taille;
	unsigned int m_division;

public:
	Cellule();
	Cellule(string, unsigned int, double, unsigned int);
	~Cellule();
	void Affiche() const;
	void Diviser(Cellule*);


	//Getters
	string GetCellule_nom()
	{
		return m_nom;
	}

	unsigned int GetCellule_noyau()
	{
		return m_noyau;
	}

	float GetCellule_taille()
	{
		return m_taille;
	}

	unsigned int GetCellule_division()
	{
		return m_division;
	}

	//Setters
	void SetCellule_nom(string nom)
	{
		m_nom = nom;
	}

	void SetCellule_noyau(unsigned int noyau)
	{
		m_noyau = noyau;
	}

	void SetCellule_taille(double taille)
	{
		m_taille = taille;
	}

	void SetCellule_division(unsigned int division)
	{
		m_division = division;
	}
};