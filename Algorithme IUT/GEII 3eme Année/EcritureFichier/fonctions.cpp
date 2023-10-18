#include "fonctions.h"

void Ecriture(const char* fileName) {
    const char *rawData = "Bonnesoirée";

    int check = open(fileName, O_WRONLY | O_CREAT, 00600);

    if (check == -1) {
        perror("[!] Erreur lors de l'ouverture du fichier.");
        return;
    }


    ssize_t data = write(check, rawData, strlen(rawData));

    if (data == -1) {
        perror("[!] Erreur lors de l'écriture dans le fichier");
        close(check);
        return;
    }

    printf("[+] Données stocké dans %s\n", fileName);

    close(check);

}
