#ifndef PROCEDURES_H_INCLUDED
#define PROCEDURES_H_INCLUDED

#include<string>
#include"structures.h"

/**********************/
/** PROC�DURES FELIN **/
/**********************/

/*
 * fonction Initialiser(1 pointeur sur FELIN, 1 chaine de caract�res, 1 chaine de caract�res, 1 r�el) -> vide
 * {Fonction d'initialisation des champs d'un individu de type FELIN}
 * Entr�es :
 *     local_individu : 1 pointeur sur FELIN (l'individu "appelant")
 *     local_esp      : 1 chaine de caract�res (l'esp�ce de l'individu)
 *     local_nom      : 1 chaine de caract�res (le nom de l'individu)
 *     local_machoire : 1 r�el (la puissance de la machoire -> caract�ristique sp�cifique FELIN)
 * Sortie :
 *     vide
*/
void Initialiser(felin* input_Felin);

void Initialiser(mammifere_ongule* input_mamif);

/*
 * fonction Afficher(1 pointeur sur FELIN) -> vide
 * {Fonction d'affichage des caract�ristiques d'un individu de type FELIN}
 * Entr�es :
 *     local_individu : 1 pointeur sur FELIN (l'individu "appelant")
 * Sortie :
 *     vide
*/
void Afficher(felin* local_individu, unsigned int input_N);

void Afficher(mammifere_ongule* local_individu, unsigned int input_N);

#endif // PROCEDURES_H_INCLUDED
