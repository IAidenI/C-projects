#include"fonctions.h"

float TCP_Retour_Au_College(char* buffer_rcv)
{
    // Buffer et Index pour socker le premier nombre
    char buffer_nb_1[10] = "";
    int IndexOfBuffer_nb_1 = 0;

    // Buffer et Index pour socker le deuxi�me nombre
    char buffer_nb_2[10] = "";
    int IndexOfBuffer_nb_2 = 0;

    int check_buffer_nb = 0;
    int i = 0;
    
    while (buffer_rcv[i] != '\0')
    {
        // Si le caract�re est un nombre et qu'il ne corespond pas au caract�re qui est � la position 129 qui corespond � '2 secondes'
        if (isdigit(buffer_rcv[i]) && i != 129)
        {
            // Si c'est le premier nombre
            if (check_buffer_nb == 0)
            {
                // On stock le le i �me caract�re dans le buffer
                sprintf(&buffer_nb_1[IndexOfBuffer_nb_1], "%d", (buffer_rcv[i] - '0'));
                IndexOfBuffer_nb_1++;
            }
            else // Si c'est le deuxi�me
            {
                // On stock le le i �me caract�re dans le buffer
                sprintf(&buffer_nb_2[IndexOfBuffer_nb_2], "%d", (buffer_rcv[i] - '0'));
                IndexOfBuffer_nb_2++;
            }

            // Si le premier nombre est totalement stock� alors on passe au buffer suivant
            if (!isdigit(buffer_rcv[i + 1]))
            {
                check_buffer_nb = 1;
            }
        }
        i++;
    }

    // Convertit les buffers en int
    int nb_1 = atoi(buffer_nb_1);
    int nb_2 = atoi(buffer_nb_2);

    // Fait le calcul demand�
    float to_send = sqrt(nb_1) * nb_2;

    return to_send;
}

void TCP_Chaine_Encode(char* buffer_rcv, char* buffer_send)
{
    /*
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    Pour d�coder une chaine en base64, il faut tout d'abord 
    r�cup�rer la possition des caract�res dans TABLE_B64|64]
    Exemple : Y --> 24; j --> 35; Y --> 24; 0 --> 52
    Ensuite, convertir cette valeur en binaire et on les stocks 
    tous � la suite Exemple : 24 --> 011000 ce qui 
    donne 011000100011011000110100
    Et enfin, on viens les s�parer en bloc de 8 caract�res et les 
    convertir en ASCII Exemple : b, 6, 4 
    Source : https://www.dcode.fr/base-64-encoding
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    */

    const char TABLE_B64[64] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',\
                                 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',\
                                 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',\
                                 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',\
                                 '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };
    char buffer_bin_tot[4096] = "";
    char buffer_bin[7] = "";
    
    // On viens r�cuperer la position du buffer_rcv[i] �me caract�re. Exemple : si on � E on viens r�cuperer 4
    for (int i = 0; buffer_rcv[i] != '\0'; i++)
    {
        for (int j = 0; j < sizeof(TABLE_B64); j++)
        {
            if (buffer_rcv[i] == TABLE_B64[j])
            {
                Dec_To_Bin(j, buffer_bin);
                strcat(buffer_bin_tot, buffer_bin);
                break;
            }
        }
    }

    int subLength = 8;
    int totalLength = strlen(buffer_bin_tot);

    for (int i = 0; i < totalLength; i += subLength) // Boucle pour parcourir le buffer_bin_tot par intervalles de 8
    {
        char* subStr = (char*)malloc((subLength + 1) * sizeof(char));   // Alloue de la m�moire pour stocker la sous-cha�ne extraite
        strncpy(subStr, buffer_bin_tot + i, subLength);                 // Copie la sous-cha�ne de buffer_bin_tot dans subStr
        subStr[subLength] = '\0';                                       // Ajoute le caract�re nul de fin de cha�ne � subStr

        unsigned long decimal = strtol(subStr, NULL, 2); // Convertit la sous-cha�ne binaire en d�cimal
        char caractere = (char)decimal;                  // Convertit le d�cimal en caract�re
        sprintf(buffer_send + strlen(buffer_send), "%c", caractere);

        free(subStr);
        subStr = NULL;
    }
}

void Dec_To_Bin(int char_dec, char* buffer_bin)
{
    /* 
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    Pour convertir du d�cimal en binaire, il faut r�aliser
    des divisions successives par 2 et de noter les restes (0 ou 1)
    dans l'ordre inverse. Exemple : pour 6 : 6 / 2 = 3 reste 0,
    puis 3 / 2 = 1 reste 1, puis 1 / 2 = 0 reste 1.
    Les restes successifs sont 0,1,1 donc 6 s'�crit 110 en binaire.
    Source : https://www.dcode.fr/code-binaire
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    */
    
    int index = 5;

    int i = 0;
    do
    {
        buffer_bin[index] = '0' + (char_dec % 2);   // On r�cup�re le reste de la division euclidienne que l'on place � la fin Exemple : 3 % 2 --> buffer_bin = "\0\0\0\0\01"
        char_dec = char_dec / 2;                    // On remplace le caract�re d�cimal par le quotient

        if (char_dec == 0 && index != 0) // A la fin du proc�ssus on ajout des 0 � la place des \0 au besoin
        {
            while (index > 0)
            {
                buffer_bin[index - 1] = '0';
                index--;
            }
        }
        index--;
        i++;
    } while (char_dec != 0 && index >= 0);
}

void TCP_La_Roue_Romaine(char* buffer_rcv, char* buffer_send)
{
    for (int i = 0; i < strlen(buffer_rcv); i++)
    {
        char temp;
        if ((int)buffer_rcv[i] >= 65 && (int)buffer_rcv[i] <= 90) // Si c'est une majuscule
        {
            /*
            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            (int)buffer_rcv[i] : convertit le caract�re en un entier
            (int)'A' : convertit le caract�re en un entier --> 65
            (int)buffer_rcv[i] - (int)'A' : Pour avoir le d�calage avec 'A'
            - 13 : Pour le Rot13
            + 26 : Pour gerer les valeurs n�gatives
            % 26 : Pour avoir un r�sultat dans la plage 0 - 25 (alphabet)
            + (int)'A' : Pour ramener le r�sultat dans la plage des lettres majuscules
            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
            */
            temp = (char)(((int)buffer_rcv[i] - (int)'A') - 13 + 26) % 26 + (int)'A';
        }
        else if ((int)buffer_rcv[i] >= 97 && (int)buffer_rcv[i] <= 122) // Si c'est une minuscule
        {
            /*
            =-=-=-=-=-=-=-=-=-=-=-=
            M�me id�e que au dessus
            =-=-=-=-=-=-=-=-=-=-=-=
            */
            temp = (char)(((int)buffer_rcv[i] - (int)'a') - 13 + 26) % 26 + (int)'a';
        }
        else // Si c'est un nombre
        {
            temp = buffer_rcv[i];
        }
        sprintf(buffer_send + strlen(buffer_send), "%c", temp);
    }
}

void Filtre_Ennonce(char* buffer_rcv, char* buffer_rcv_filtre)
{
    for (int i = 0; i < strlen(buffer_rcv); i++) // Boucle pour "voir" chaque caract�res un par un des donn�es recu
    {
        if (buffer_rcv[i] == '\'') // Charche le caract�re '
        {
            for (int j = 1; buffer_rcv[i + 1] != '\''; j++) // Fait un boucle pour r�cuperer ce qui est entre les deux guillements
            {
                if (buffer_rcv[i + j] == '=') // On ne si il y a des caact�res = � la fin on ne les prend pas en compte
                {
                    continue;
                }
                else if (buffer_rcv[i + j] == '\'') // Si on � atteint le deuxi�me caract�re ' on sort
                {
                    break;
                }
                else
                {
                    sprintf(buffer_rcv_filtre + strlen(buffer_rcv_filtre), "%c", buffer_rcv[i + j]); // On place chaque caract�res qui est entre les guillements dans la variable buffer_rcv_filtre
                }
            }
            break;
        }
    }
}