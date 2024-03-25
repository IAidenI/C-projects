#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
#include <winsock.h>
typedef SOCKET SocketType;
#define CloseSocket(sock) closesocket(sock)
#elif defined(__unix__)
#include <sys/utsname.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
typedef int SocketType;
#define CloseSocket(sock) close(sock)
#endif

#define WINDOWS "USERNAME"
#define UNIX "USER"

void CloseConnect();
SocketType Connect(const char* ipTarget, const unsigned int portTarget);

char* GetUsername(const char *varName);
const char* GetArchitecture_WINDOWS();
const char* GetOSVersion_WINDOWS();
char* GetHostname_WINDOWS();
char* GetHostname_UNIX();
