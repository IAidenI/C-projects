/*
R: Explique ce que fait le programme
E: vide
S: vide
*/
void Presentation(void);

/*
R: Demande � l'utilisateur d'entrer un rayon et retourne la valeur saisie
E: vide
S: 1 r�el: le rayon (en cm)
*/
float Saisie_rayon(void);

/*
R: Demande � l'utilisateur d'entrer une hauteur et retourne la valeur saisie
E: vide
S: 1 r�el: la hauteur (en cm)
*/
float Saisie_hauteur(void);

/*
R: Demande � l'utilisateur le nombre de tour fait par la roue avant de son v�lo
E: vide
S: 1 r�el: le nombre de tour fait par la roue
*/
float Saisie_tours(void);

/*
R: Calcule et retourne le p�rim�tre d'un cercle de rayon r
E: 1 r�el: le rayon (en cm)
S: 1 r�el: le p�rim�tre (en cm)
*/
float Perimetre(float r);

/*
R: Calcule et retourne la surface d'un disque de rayon r
E: 1 r�el: le rayon (en cm)
S: 1 r�el: la surface (en cm�)
*/
float Surface(float r);

/*
R: Affiche les valeurs du p�rim�tre et de la surface
E: 2 r�el: le p�rim�tre (en cm) et la surface (en cm�)
S: vide
*/
void Affiche_resultats(float p, float s);

/*
R: Calcule et retourne le volume d'un cylindre
E: 2 r�el: le rayon (en cm), la hauteur (en cm)
S: 1 r�el: le volume (en cm^3)
*/
float Volume_cylindre(float rayon, float haut);

/*
R: Calcule et retourne la distance parcouru par un v�lo
E: 2 r�els: le rayon (en cm) et le nombre de tour fait par la roue avant
S: 1 r�el: la distance parcouru par le v�o
*/
float Distance(float rayon, float tours);