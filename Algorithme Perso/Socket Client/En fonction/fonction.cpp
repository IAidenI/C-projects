#include "fonction.h"

SocketType Connect(const char* ipTarget, const unsigned int portTarget) {
    struct sockaddr_in sin;

    int check_connexion;
    SocketType sock;

#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif
    sin.sin_addr.s_addr = inet_addr(ipTarget);
    sin.sin_port = htons(portTarget);
    sin.sin_family = AF_INET;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    check_connexion = connect(sock, (struct sockaddr *)&sin, sizeof(sin));

    if (check_connexion != 0) {
        perror("[!] Erreur lors de la connexion au serveur");
#ifdef _WIN32
        closesocket(sock);
#elif defined(__unix__)
        close(sock);
#endif
        exit(1);
    }

    printf("[+] Connexion établie avec %s au port %d\n", ipTarget, portTarget);

    return sock;
}

void CloseConnect() {
#ifdef _WIN32
    WSACleanup();
#endif
}