struct coureur
{
	char nom[30];
	unsigned int dos;
	float dist;
	float temps_ref;
	float temps;
};

/*
R: Demande à l'utilisateur de saisir des informations sur le coureur
E: vide
S: 1 coureur
*/
coureur Saisie_coureur(void);

/*
R: Affiche les caractéristiques d'un coureur
E: 1 coureur
S: vide
*/
void Affiche_coureur(coureur cour);