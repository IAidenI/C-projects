#include "fonction.h"

int main() {
    const char* ipTarget = "192.168.0.114";
    const unsigned int portTarget = 7777;
    char buffer_rcv[4096] = "";

    SocketType sock = Connect(ipTarget, portTarget);

    recv(sock, buffer_rcv, sizeof(buffer_rcv), 0);

    printf("%s\n", buffer_rcv);

    CloseConnect();

    return 0;
}