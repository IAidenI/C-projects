#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/utsname.h>
#endif

#define WINDOWS "USERNAME"
#define UNIX "USER"

#define GREEN "\033[32m"
#define RESET "\033[0m"

char* GetHostname_WINDOWS();
const char* GetOSVersion_WINDOWS();
const char* GetArchitecture_WINDOWS();
void SysInfo_WINDOWS(const char *hostname, const char *username, const char *osVersion, const char *arch);

char* GetHostname_UNIX();
void SysInfo_UNIX(const char *hostname, const char *username);

char* GetUsername(const char *varName);
