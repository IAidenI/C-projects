#include"fonction.h"


int main() 
{
    const unsigned int check = Sys_Check();
    const char Sys_expl_lst[3][10] = { {"Unix"}, {"Windows"}, {"Inconnu"} };
    char commande[100];

    if (check == 2)
    {
        printf("Système d'exploitation inconnu.");
        return 1;
    }

    printf("=-=-=-=-=-=-=-=-=\n");
    printf("= Reverse Shell =\n");
    printf("=-=-=-=-=-=-=-=-=\n");

    while (true)
    {
        printf("Saisir une commande %s :\n>", Sys_expl_lst[check]);

        fgets(commande, sizeof(commande), stdin);
        commande[strcspn(commande, "\n")] = '\0';
        
        if (strcmp(commande, "exit") == 0)
        {
            printf("Au revoir.");
            return 0;
        }

        system(commande);
    }

    return 0;
}