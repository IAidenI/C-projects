#include "fonctions.h"

void Copie(const char* fileName, const char* fileNameCp) {
    char buffer[100];

    int check_r = open(fileName, O_RDONLY);
    int check_w = open(fileNameCp, O_WRONLY | O_CREAT, 00600);

    if (check_r == -1 && check_w != -1) {
        perror("[!] Erreur lors de l'ouverture d'un fichier.");
        return;
    }

    while (read(check_r, buffer, sizeof(buffer)) > 0) {
        write(check_w, buffer, sizeof(buffer));
    }

    printf("[+] Copie effectué : %s", fileNameCp);

    close(check_r);
    close(check_w);
}
