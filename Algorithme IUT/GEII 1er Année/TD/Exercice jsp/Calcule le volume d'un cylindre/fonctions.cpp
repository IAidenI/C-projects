/*
R: Calcule et retourne la surface d'un cercle
E: 1 r�el: le rayon (en cm)
S: 1 r�el: la surface (en cm�)
*/
float Surface_cercle(float r)
{
	//Lexique local � Surface_cercle
	float surf;
	const float PI = 3.14159265;

	//Algorithme local� Surface_cercle
	//D�but
	surf = PI * r*r;
	return surf;
	//Fin
}

/*
R: Calcule et retourne le volume d'un cylindre
E: 2 r�el: le rayon (en cm), la hauteur (en cm)
S: 1 r�el: le volume (en cm^3)
*/
float Volume_cylindre(float rayon, float haut)
{
	//Lexique local � Volume_cylindre
	float surface, volume;

	//Algorithme local � Volume_cylindre
	//D�but
	surface = Surface_cercle(rayon);
	volume = surface * haut;
	return volume;
	//Fin
}