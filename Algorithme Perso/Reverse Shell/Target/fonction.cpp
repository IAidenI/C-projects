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
        exit(1);
    }

    return sock;
}

void CloseConnect() {
#ifdef _WIN32
    WSACleanup();
#endif
}

#ifdef _WIN32
char* GetHostname_WINDOWS() {
    static char hostname[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD sizeHostname = sizeof(hostname);
    if (GetComputerName(hostname, &sizeHostname)) {
        return hostname;
    } else {
        return nullptr;
    }
}

const char* GetOSVersion_WINDOWS() {
    OSVERSIONINFOEX osInfo;
    ZeroMemory(&osInfo, sizeof(OSVERSIONINFOEX));
    osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (GetVersionEx((OSVERSIONINFO*)&osInfo)) {
        if (osInfo.dwMajorVersion == 5 && osInfo.dwMinorVersion == 0)
            return "Windows 2000";
        else if (osInfo.dwMajorVersion == 5 && osInfo.dwMinorVersion == 1)
            return "Windows XP";
        else if (osInfo.dwMajorVersion == 5 && osInfo.dwMinorVersion == 2)
            return "Windows Server 2003";
        else if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 0)
            return "Windows Vista";
        else if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 1)
            return "Windows 7";
        else if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 2)
            return "Windows 8";
        else if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 3)
            return "Windows 8.1";
        else if (osInfo.dwMajorVersion == 10 && osInfo.dwMinorVersion == 0)
            return "Windows 10";
        else
            return "Unknow";
    }
}

const char* GetArchitecture_WINDOWS() {
    const char* arch = getenv("PROCESSOR_ARCHITECTURE");
    if (arch != nullptr) {
        if (strcmp(arch, "AMD64") == 0 || strcmp(arch, "x86_64") == 0) {
            return "x86_64";
        } else {
            return "x86";
        }
    }
}
#endif

#if defined(__unix__)
char* GetHostname_UNIX() {
    static char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        return hostname;
    } else {
        return nullptr;
    }
}
#endif

char* GetUsername(const char *varName) {
    return getenv(varName);
}
