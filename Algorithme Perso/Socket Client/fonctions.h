#include <stdio.h>
#include <stdlib.h>
#include<math.h>

// Bibliothèque où se trouve toutes les fonctions en lien avec les sockets
#include <winsock2.h>
// Bibliothèque où se trouve toutes les fonctions en lien avec le réseau windows
// Pas include car ce n'est pas un header mais un fichier binaire
#pragma comment(lib, "ws2_32.lib")


float TCP_Retour_Au_College(char* buffer_rcv);
void TCP_Chaine_Encode(char* buffer_rcv, char* buffer_send);
void Dec_To_Bin(int char_dec, char* buffer_bin);
void TCP_La_Roue_Romaine(char* buffer_rcv, char* buffer_send);
void Filtre_Ennonce(char* buffer_rcv, char* buffer_rcv_filtre);