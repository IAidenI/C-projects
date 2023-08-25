#include<string>
#include"fonction.h"

class Ongule : public Animal
{
private:
	std::string carac_ongule;

public:
	Ongule();
	Ongule(std::string, std::string, std::string);
	~Ongule();
	void Affiche() const;

	std::string GetCarac_felin() const
	{
		return carac_ongule;
	}

	void SetCarac_felin(float input_carac_ongule)
	{
		carac_ongule = input_carac_ongule;
	}
};