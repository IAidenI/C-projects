#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>

#ifdef _WIN32
#include <windows.h>
#include <winsock.h>
typedef SOCKET SocketType;
#define CloseSocket(sock) closesocket(sock)
#else
#include <sys/utsname.h>
#include <arpa/inet.h>
#include <netinet/in.h>
typedef int SocketType;
#define CloseSocket(sock) close(sock)
#endif

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"
#define DELIMITER "|"

SocketType Listen(const unsigned int portTarget);
void CloseConnect();

void SysInfo(const char *hostname, const char *username, const char *osVersion, const char *kernel, const char *arch);
