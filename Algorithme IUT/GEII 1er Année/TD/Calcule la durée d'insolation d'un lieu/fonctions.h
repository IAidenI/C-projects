//Les interactions faites avec l'utilisateur seront assurés par Lire et Ecrire

/*
R: Calcule et retourne la valeur en radian d'un angle en degré
E: 1 réel: l'angle en degré
S: 1 réel: l'angle en radian
*/
double Dey2rad(float deg);

/*
R: Calcule et retourne la déclinaison du soleil en radian
E: 1 entier: le jour de l'année
S: 1 réel: la déclinaison du soleil en radian
*/
double Declinaison(unsigned int j);

/*
R: Calcule et retourne la durée d'insolation en heure
E: 1 réel: la latitude en degré
   1 entier: le jour de l'année
S: 1 réel: la durée d'insolation en heure
*/
double Duree_insol(float lat, unsigned int jour);