#include"fonction.h"

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

void SysInfo_WINDOWS(const char *hostname, const char *username, const char *osVersion, const char *arch) {
    printf("Computer     : %s\n", hostname);
    printf("User         : %s\n", username);
    printf("OS           : %s\n", osVersion);
    printf("Architecture : %s\n", arch);
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

void SysInfo_UNIX(const char *hostname, const char *username) {
    struct utsname info;
    uname(&info);
    printf("Computer       : %s\n", hostname);
    printf("User           : %s\n", username);
    printf("OS             : %s %s %s\n", info.sysname, info.version);
    printf("Kernel         : %s\n", info.release)
    printf("Architecture   : %s\n", info.machine);
}
#endif

char* GetUsername(const char *varName) {
    return getenv(varName);
}
