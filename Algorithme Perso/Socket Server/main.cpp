#ifdef _WIN32
#include <winsock.h>
typedef SOCKET SocketType;
#define CloseSocket(sock) closesocket(sock)
#elif defined(__unix__)
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
typedef int SocketType;
#define CloseSocket(sock) close(sock)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const unsigned int PORT = 7777;
    struct sockaddr_in sin;
    SocketType sock, new_sock;

#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif

    sin.sin_addr.s_addr = INADDR_ANY; // Ecoute toutes les IP peut être modifier au besoin
    sin.sin_port = htons(PORT);
    sin.sin_family = AF_INET;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (bind(sock, (struct sockaddr *) &sin, sizeof sin) < 0) {
        perror("[!] Erreur lors de la liaison.");
        CloseSocket(sock);
        exit(1);
    }

    if (listen(sock, 1) <0 ) {
        perror("[!] Erreur lors de l'écoute.");
        CloseSocket(sock);
        exit(1);
    }

#ifdef _WIN32
    size_t addrlen = sizeof sin;
    if ((new_sock = accept(sock, (struct sockaddr *) &sin, (int*)&addrlen)) < 0) {
        perror("[!] Erreur lors de l'acceptation.");
        closesocket(sock);
        exit(1);
    }
#elif defined(__unix__)
    socklen_t addrlen = sizeof(sin);
    if ((new_sock = accept(sock, (struct sockaddr *) &sin, &addrlen)) < 0) {
        perror("[!] Erreur lors de l'acceptation.");
        close(sock);
        exit(1);
    }
#endif

    send(new_sock, "Hello world!", strlen("Hello world!"), 0);
    printf("[+] Message envoyé.");


#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}