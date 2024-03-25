#include "fonction.h"

int main() 
{
    char command[100];

#ifdef _WIN32
    const char *hostname = GetHostname_WINDOWS();
    const char *username = GetUsername(WINDOWS);
    const char *osVersion = GetOSVersion_WINDOWS();
    const char *arch = GetArchitecture_WINDOWS();

    printf("Informations du systeme :\n");
    SysInfo_WINDOWS(hostname, username, osVersion, arch);

#elif defined(__unix__)
    const char *hostname = GetHostname_UNIX();
    const char *username = GetUsername(UNIX);

    printf("Informations du système :\n");
    SysInfo_UNIX(hostname, username);

#else
    printf("Système d'exploitation inconnu.");
    return 1;

#endif

    while (true) {
        printf(GREEN "%s@%s" RESET " $ ", username, hostname);

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';
        
        if (strcmp(command, "exit") == 0) {
            printf("Sortie du shell.");
            return 0;
        } else if (strcmp(command, "sysinfo") == 0) {
#ifdef _WIN32
    SysInfo_WINDOWS(hostname, username, osVersion, arch);
#elif defined(__unix__)
    SysInfo_UNIX(hostname, username);
#endif
            continue;
        }

        system(command);
    }
}