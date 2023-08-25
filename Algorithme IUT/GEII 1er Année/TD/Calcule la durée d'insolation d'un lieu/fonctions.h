//Les interactions faites avec l'utilisateur seront assur�s par Lire et Ecrire

/*
R: Calcule et retourne la valeur en radian d'un angle en degr�
E: 1 r�el: l'angle en degr�
S: 1 r�el: l'angle en radian
*/
double Dey2rad(float deg);

/*
R: Calcule et retourne la d�clinaison du soleil en radian
E: 1 entier: le jour de l'ann�e
S: 1 r�el: la d�clinaison du soleil en radian
*/
double Declinaison(unsigned int j);

/*
R: Calcule et retourne la dur�e d'insolation en heure
E: 1 r�el: la latitude en degr�
   1 entier: le jour de l'ann�e
S: 1 r�el: la dur�e d'insolation en heure
*/
double Duree_insol(float lat, unsigned int jour);