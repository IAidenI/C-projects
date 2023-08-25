#include"fonction.h"

unsigned int Sys_Check()
{
    unsigned int check;
#ifdef _WIN32 // Si le syst�me d'exploitation est Windows
    check = 1;
#elif defined(__unix__) // Si le syst�me d'exploitation est Linux
    check = 0;
#else // Si le syst�me d'exploitation est inconnu
    check = 2;
#endif
    return check;
}