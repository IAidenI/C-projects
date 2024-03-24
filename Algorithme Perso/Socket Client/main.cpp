#ifdef _WIN32
#include <winsock.h>
#elif defined(__unix__)
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* URL = "192.168.0.114";
    const unsigned int PORT = 7777;
    struct sockaddr_in sin;

    int check_connexion;
    char buffer_rcv[4096] = "";
#ifdef _WIN32
    SOCKET sock;
#elif defined(__unix__)
    int sock;
#endif

#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif
    sin.sin_addr.s_addr = inet_addr(URL);
    sin.sin_port = htons(PORT);
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

    printf("[+] Connexion établie avec %s au port %d\n", URL, PORT);
    check_connexion = recv(sock, buffer_rcv, sizeof(buffer_rcv), 0);

    if (check_connexion == SO_ERROR) {
        perror("[!] Erreur lors du recoit des données");
#ifdef _WIN32
        closesocket(sock);
#elif defined(__unix__)
        close(sock);
#endif
        exit(1);
    }

    printf("%s\n", buffer_rcv);

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}