#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADDRESS_SIZE 50
#define VERSION "V 0.2"
#define DATE "21/09/2024"


typedef struct ReverseAddress {
    char address[ADDRESS_SIZE];
    size_t address_size;

    void (*CheckInput)(struct ReverseAddress*);
    void (*Reverse)(struct ReverseAddress*, int);
    void (*PrintAdd)(struct ReverseAddress*);
} ReverseAddress;

ReverseAddress* Create_Reverse_Address();
void Help();
