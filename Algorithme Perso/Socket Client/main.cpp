#include"fonctions.h"

int main() 
{
    /* =-=-=-=-= Indispensable pour utiliser les sockets =-=-=-=-= */
    WSADATA WSAData;
    int check_WSAStartup = WSAStartup(MAKEWORD(2, 2), &WSAData); // Initialise la bibliothèque Winsock
    if (check_WSAStartup != 0)
    {
        perror("Erreur lors de l'initialisation de Winsock");
        exit(1);
    }
    /* =-=-=-=-= Indispensable pour utiliser les sockets =-=-=-=-= */

    
    const char* URL = "212.129.38.224";
    const unsigned int PORT = 5202; // Chall1 : 52002 ; Chall2 : 52023 ; Chall3 : 52021
    SOCKADDR_IN sin;

    int check_connexion;
    char buffer_rcv[4096] = "";
    char buffer_send[4096] = "";
    
    sin.sin_addr.s_addr = inet_addr(URL);   // Spécifie une adresse IP à utiliser
    sin.sin_port = htons(PORT);             // Spécifie un port à utiliser
    sin.sin_family = AF_INET;               // Indique que l'on utiliser des adresses IPv4

    SOCKET sock;
    sock = socket(AF_INET, SOCK_STREAM, 0); // Création du socket

    check_connexion = connect(sock, (SOCKADDR*)&sin, sizeof(sin)); // Connexion au socket et au port spécifié

    if (check_connexion != 0)
    {
        perror("[!] Error lors de la connexion au serveur");
        closesocket(sock);
        WSACleanup();
        exit(1);
    }

    printf("[+] Connexion établie avec %s au port %d\n", URL, PORT);
    check_connexion = recv(sock, buffer_rcv, sizeof(buffer_rcv), 0); // Reception de l'ennoncé

    if (check_connexion == SOCKET_ERROR)
    {
        perror("[!] Erreur lors du recoit des données");
        closesocket(sock);
        WSACleanup();
        exit(1);
    }

    printf("%s\n", buffer_rcv);

    /* ############################### */
    /* ## Résolution du challenge 1 ## */
    /* ############################### */

    float to_send = TCP_Retour_Au_College(buffer_rcv);
    sprintf(buffer_send, "%.2f\n", to_send);
    printf("%s\n", buffer_send);

    /* ############################### */
    /* ## Résolution du challenge 2 ## */
    /* ############################### */

    /*char buffer_rcv_filtre[200] = ""; // Création d'une variable assez grande pour contenir le message à décoder

    Filtre_Ennonce(buffer_rcv, buffer_rcv_filtre);
    
    // Décodage de la chaine
    TCP_Chaine_Encode(buffer_rcv_filtre, buffer_send);
    sprintf(buffer_send, "%s\n", buffer_send);
    printf("%s\n", buffer_send);*/

    /* ############################### */
    /* ## Résolution du challenge 3 ## */
    /* ############################### */

    /*char buffer_rcv_filtre[200] = ""; // Création d'une variable assez grande pour contenir le message à décoder

    Filtre_Ennonce(buffer_rcv, buffer_rcv_filtre);

    // Réalisation du Rot13
    TCP_La_Roue_Romaine(buffer_rcv_filtre, buffer_send);
    sprintf(buffer_send, "%s\n", buffer_send);
    printf("%s\n", buffer_send);*/

    // Envoie du résultat trouvé
    check_connexion = send(sock, buffer_send, sizeof(buffer_send), 0);

    if (check_connexion == SOCKET_ERROR)
    {
        perror("[!] Erreur lors de l'envoie des données");
        closesocket(sock);
        WSACleanup();
        exit(1);
    }
    
    // Reception du flag
    memset(buffer_rcv, 0, sizeof(buffer_rcv)); // Clear le contenu de buffer_rcv pour le réutiliser
    check_connexion = recv(sock, buffer_rcv, sizeof(buffer_rcv), 0);

    if (check_connexion == SOCKET_ERROR)
    {
        perror("[!] Erreur lors du recoit des données");
        closesocket(sock);
        WSACleanup();
        exit(1);
    }

    printf("%s", buffer_rcv);

    // Fermeture du socket
    closesocket(sock);
    WSACleanup();
    return 0;
}