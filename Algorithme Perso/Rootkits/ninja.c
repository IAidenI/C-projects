#include "ninja.h"

int Duplication(const char* src, const char* dest) {
        int in = open(src, O_RDONLY);
        // Préparer la lecture pour le fichier src
        if (in < 0) {
                fprintf(stderr, "Impossible d'ouvrir le fichier source.\n");
                return FAILED;
        }

        // Préparer l'écriture pour le fichier dest
        int out = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0755);
        if (out < 0) {
                fprintf(stderr, "Impossible d'ouvrir le fichier de destionation.\n");
                close(in);
                return FAILED;
        }

        // Lis la source et mets dans la dest
        char buffer[MAX_DUPLICATE];
        ssize_t bytes;
        while ((bytes = read(in, buffer, sizeof(buffer))) > 0) {
                if (write(out, buffer, bytes) != bytes) {
                        fprintf(stderr, "Erreur lors de l'écriture\n");
                        close(in);
                        close(out);
                        return FAILED;
                }
        }

        close(in);
        close(out);
        return SUCCES;
}

int Shadow() {
        char pwd[PATH_MAX];
        if (getcwd(pwd, PATH_MAX) == NULL) {
                fprintf(stderr, "Impossible de récuperer le répertoire courant.\n");
                if (errno == ERANGE) {
                        fprintf(stderr, "La taille du buffer (%d) est trop petite.\n", PATH_MAX);
                }
                return FAILED;
        }

        printf("Suis-je au bonne endroit ?\n");
        if (strcmp(pwd, BIN_DIR) == 0) {
                printf("Oui\n");
                printf("Ah la on est bieng\n");
                printf("$ ");

                char buffer[256];
                fgets(buffer, sizeof(buffer), stdin);
                printf("Salut '%s'", buffer);
        } else {
                printf("Non\n");
                printf("Disparition...\n");

                // Crée le dossier et ses parents si il n'existe pas
                if (mkdir(BIN_DIR, 0755) && errno != EEXIST) {
                        fprintf(stderr, "Impossible de crée le dossier.\n");
                        return FAILED;
                }

                char filePath[MAX_COMMAND];
                sprintf(filePath, "%s/%s", BIN_DIR, BIN_NAME);

                // Fait une copie dans ce nouveau dossier
                if (Duplication(BIN_NAME, filePath) == FAILED) {
                        fprintf(stderr, "Impossible de dupliquer le fichier.\n");
                        return FAILED;
                }

                // Suppression de l'ancien binaire
                if (unlink(BIN_NAME) < 0) {
                        fprintf(stderr, "Impossible de supprimer le fichier.\n");
                        return FAILED;
                }

                // Changement de l'espace de travail
                if (chdir(BIN_DIR) != 0) {
                        fprintf(stderr, "Impossible de changer de répertoire vers le dossier cible.\n");
                        return FAILED;
                }

                // Lance le binaire en arrière plan
                if (fork() == 0) {
                        setsid(); // Créer une nouvelle session pour isoler complètement le processus
                        execl(filePath, filePath, NULL);
                }
                printf("Renaissance.\n");
        }

        return SUCCES;
}
