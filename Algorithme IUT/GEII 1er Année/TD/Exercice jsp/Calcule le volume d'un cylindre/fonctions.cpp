/*
R: Calcule et retourne la surface d'un cercle
E: 1 réel: le rayon (en cm)
S: 1 réel: la surface (en cm²)
*/
float Surface_cercle(float r)
{
	//Lexique local à Surface_cercle
	float surf;
	const float PI = 3.14159265;

	//Algorithme localà Surface_cercle
	//Début
	surf = PI * r*r;
	return surf;
	//Fin
}

/*
R: Calcule et retourne le volume d'un cylindre
E: 2 réel: le rayon (en cm), la hauteur (en cm)
S: 1 réel: le volume (en cm^3)
*/
float Volume_cylindre(float rayon, float haut)
{
	//Lexique local à Volume_cylindre
	float surface, volume;

	//Algorithme local à Volume_cylindre
	//Début
	surface = Surface_cercle(rayon);
	volume = surface * haut;
	return volume;
	//Fin
}