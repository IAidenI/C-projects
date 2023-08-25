/*
R: Explique ce que fait le programme
E: vide
S: vide
*/
void Presentation(void);

/*
R: Demande à l'utilisateur d'entrer un rayon et retourne la valeur saisie
E: vide
S: 1 réel: le rayon (en cm)
*/
float Saisie_rayon(void);

/*
R: Demande à l'utilisateur d'entrer une hauteur et retourne la valeur saisie
E: vide
S: 1 réel: la hauteur (en cm)
*/
float Saisie_hauteur(void);

/*
R: Demande à l'utilisateur le nombre de tour fait par la roue avant de son vélo
E: vide
S: 1 réel: le nombre de tour fait par la roue
*/
float Saisie_tours(void);

/*
R: Calcule et retourne le périmètre d'un cercle de rayon r
E: 1 réel: le rayon (en cm)
S: 1 réel: le périmètre (en cm)
*/
float Perimetre(float r);

/*
R: Calcule et retourne la surface d'un disque de rayon r
E: 1 réel: le rayon (en cm)
S: 1 réel: la surface (en cm²)
*/
float Surface(float r);

/*
R: Affiche les valeurs du périmètre et de la surface
E: 2 réel: le périmètre (en cm) et la surface (en cm²)
S: vide
*/
void Affiche_resultats(float p, float s);

/*
R: Calcule et retourne le volume d'un cylindre
E: 2 réel: le rayon (en cm), la hauteur (en cm)
S: 1 réel: le volume (en cm^3)
*/
float Volume_cylindre(float rayon, float haut);

/*
R: Calcule et retourne la distance parcouru par un vélo
E: 2 réels: le rayon (en cm) et le nombre de tour fait par la roue avant
S: 1 réel: la distance parcouru par le véo
*/
float Distance(float rayon, float tours);