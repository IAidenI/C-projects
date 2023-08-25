#ifndef PROCEDURES_H_INCLUDED
#define PROCEDURES_H_INCLUDED

#include<string>
#include"structures.h"

/**********************/
/** PROCÉDURES FELIN **/
/**********************/

/*
 * fonction Initialiser(1 pointeur sur FELIN, 1 chaine de caractères, 1 chaine de caractères, 1 réel) -> vide
 * {Fonction d'initialisation des champs d'un individu de type FELIN}
 * Entrées :
 *     local_individu : 1 pointeur sur FELIN (l'individu "appelant")
 *     local_esp      : 1 chaine de caractères (l'espèce de l'individu)
 *     local_nom      : 1 chaine de caractères (le nom de l'individu)
 *     local_machoire : 1 réel (la puissance de la machoire -> caractéristique spécifique FELIN)
 * Sortie :
 *     vide
*/
void Initialiser(felin* input_Felin);

void Initialiser(mammifere_ongule* input_mamif);

/*
 * fonction Afficher(1 pointeur sur FELIN) -> vide
 * {Fonction d'affichage des caractéristiques d'un individu de type FELIN}
 * Entrées :
 *     local_individu : 1 pointeur sur FELIN (l'individu "appelant")
 * Sortie :
 *     vide
*/
void Afficher(felin* local_individu, unsigned int input_N);

void Afficher(mammifere_ongule* local_individu, unsigned int input_N);

#endif // PROCEDURES_H_INCLUDED
