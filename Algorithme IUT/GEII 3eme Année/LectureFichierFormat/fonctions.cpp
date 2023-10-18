#include "fonctions.h"

void Lecture(const char* fileName) {
    int check = open(fileName, O_RDONLY);

    if (check == -1) {
        perror("[!] Erreur lors de l'ouverture du fichier.");
        return;
    }


    char buffer[100];
    ssize_t bytesLus;
    printf("[+] Contenu du fichier %s :\n", fileName);
    while ((bytesLus = read(check, buffer, sizeof(buffer))) > 0) {
        printf("%s\n", buffer);
    }

    close(check);

    return;
}
