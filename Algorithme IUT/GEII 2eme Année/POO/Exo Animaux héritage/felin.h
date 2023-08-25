#include<string>
#include"fonction.h"
#include"ongule.h"

class Felin : public Animal
{
private:
	float carac_felin;

public:
	Felin();
	Felin(std::string, std::string, float);
	~Felin();
	void Affiche() const;
	void Chasser(Ongule*);

	float GetCarac_felin() const
	{
		return carac_felin;
	}

	void SetCarac_felin(float input_carac_felin)
	{
		carac_felin = input_carac_felin;
	}
};