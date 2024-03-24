#ifdef _WIN32
#include <winsock.h>
typedef SOCKET SocketType;
#elif defined(__unix__)
typedef int SocketType;
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>

SocketType Connect(const char* ipTarget, const unsigned int portTarget);
void CloseConnect();
