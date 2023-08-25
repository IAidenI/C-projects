struct complexe
{
	float re;
	float im;
};

/*
R: Calcule et retourne le conjugu� d'un complexe
E: 1 complexe
S: 1 complexe: son conjugu�
*/
complexe Conjugue(complexe z);

/*
R: Calcule et retourne l'inverse d'un complexe
E: 1 complexe
S: 1 complexe: son inverse
*/
complexe Inverse(complexe z);

/*
R: Calcule et retourne l'oppos� d'un complexe
E: 1 complexe
S: 1 complexe: son oppos�
*/
complexe Oppose(complexe z);

/*
R: Calcule et retourne le module d'un complexe
E: 1 complexe
S: 1 r�el: son module
*/
float Module(complexe z);

/*
R: Calcule et retourne l'argument d'un complexe
E: 1 complexe
S: 1 r�el: son argument
*/
float Argument(complexe z);

/*
R: Verifie qu'un nombre complexe est bien positif
E: 1 complexe
S: vide
*/
complexe Nb_positif(complexe z);