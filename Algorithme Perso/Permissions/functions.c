#include "functions.h"

int CheckBuffer(const char buffer[MAX_BUFFER]) {
        if (buffer[0] != '-' && buffer[0] != 'd' && buffer[0] != 'l') {
                return 0;
        }

        for (unsigned int i = 1; i < MAX_BUFFER - 1; i++) {
                if (buffer[i] != '-' && buffer[i] != 'r' && buffer[i] != 'w' && buffer[i] != 'x') {
                        return 0;
                }
        }
        return 1;
}

void InputColor(const char input[MAX_BUFFER], char newInput[MAX_BUFFER_COLOR], Colors color) {
	char *current_pos = newInput;

	for (unsigned int i = 0; i < MAX_BUFFER - 1; i++) {
		if (input[i] == '-') {
			current_pos += sprintf(current_pos, "%s%c", color.RESET, input[i]);
		} else if (input[i] == 'd') {
			current_pos += sprintf(current_pos, "%s%c%s", color.DARK_BLUE, input[i], color.RESET);
		} else if (input[i] == 'l') {
			current_pos += sprintf(current_pos, "%s%c%s", color.PINK, input[i], color.RESET);
		} else if (input[i] == 'r') {
			current_pos += sprintf(current_pos, "%s%c%s", color.RED, input[i], color.RESET);
		} else if (input[i] == 'w') {
			current_pos += sprintf(current_pos, "%s%c%s", color.YELLOW, input[i], color.RESET);
		} else if (input[i] == 'x') {
			current_pos += sprintf(current_pos, "%s%c%s", color.BLUE, input[i], color.RESET);
		} else {
			current_pos += sprintf(current_pos, "%s%c%s", color.RESET, input[i], color.RESET);
		}
	}
	printf("len : %ld\n", strlen(newInput));
}

void ModeToOctal(const char buffer[MAX_BUFFER]) {
         Colors color = {
                 .GREEN       = "\033[38;2;0;255;0m",
                 .BLUE        = "\033[38;2;102;204;255m",
                 .RED         = "\033[38;2;204;0;50m",
                 .YELLOW      = "\033[38;2;255;255;102m",
                 .DARK_BLUE   = "\033[38;2;51;0;255m",
                 .PINK        = "\033[38;2;255;0;204m",
                 .GREY_PROMPT = "\033[38;2;102;102;153m",
				 .RED_ERROR   = "\033[1;31;1;40m",
                 .RESET       = "\033[0;0m"
         };

		char bufferColor[MAX_BUFFER_COLOR];
        char tab[MAX_MODE][MAX_MODE];
        char octal[MAX_MODE] = "";
        char binary[MAX_BUFFER + 4] = "";
        char type[MAX_TYPE] = "";
        char rights[3][54];

        if (strlen(buffer) == MAX_BUFFER - 2) {
                strncpy(tab[0], "#", 1);
                tab[0][1] = '\0';
        } else {
                strncpy(tab[0], buffer, 1);
                tab[0][1] = '\0';
        }

        strncpy(tab[1], buffer + 1, 3);
        tab[1][3] = '\0';

        strncpy(tab[2], buffer + 4, 3);
        tab[2][3] = '\0';

        strncpy(tab[3], buffer + 7, 3);
        tab[3][3] = '\0';

        if (strcmp(tab[0], "d") == 0) {
                snprintf(type, 42, "Type : %sDossier%s", color.GREEN, color.RESET);
        } else if (strcmp(tab[0], "l") == 0) {
                snprintf(type, 50, "Type : %sLien Symbolique%s", color.GREEN, color.RESET);
        } else if (strcmp(tab[0], "-") == 0) {
                snprintf(type, 42, "Type : %sFichier%s", color.GREEN, color.RESET);
        } else {
                snprintf(type, 49, "Type : %sFormat Inconnu%s", color.GREEN, color.RESET);
        }

        unsigned int pos = 0;
    	for (unsigned int i = 1; i < MAX_MODE; i++) {
                if (strcmp(tab[i], "---") == 0) {
                        strcat(binary, "000 ");
                        strcat(octal, "0");
                        strcpy(rights[pos++], "Aucun droits.");
                } else if (strcmp(tab[i], "--x") == 0) {
                        strcat(binary, "001 ");
                        strcat(octal, "1");
                        strcpy(rights[pos++], "Exécution uniquement.");
                } else if (strcmp(tab[i], "-w-") == 0) {
                        strcat(binary, "010 ");
                        strcat(octal, "2");
                        strcpy(rights[pos++], "Ecriture uniquement.");
                } else if (strcmp(tab[i], "-wx") == 0) {
                        strcat(binary, "011 ");
                        strcat(octal, "3");
                        strcpy(rights[pos++], "Ecriture et exécution.");
                } else if (strcmp(tab[i], "r--") == 0) {
                        strcat(binary, "100 ");
                        strcat(octal, "4");
                        strcpy(rights[pos++], "Lecture uniquement");
                } else if (strcmp(tab[i], "r-x") == 0) {
                        strcat(binary, "101 ");
                        strcat(octal, "5");
                        strcpy(rights[pos++], "Lecture et exécution.");
                } else if (strcmp(tab[i], "rw-") == 0) {
                        strcat(binary, "110 ");
                        strcat(octal, "6");
                        strcpy(rights[pos++], "Lecture et écriture.");
                } else if (strcmp(tab[i], "rwx") == 0) {
                        strcat(binary, "111 ");
                        strcat(octal, "7");
                        strcpy(rights[pos++], "Lecture, écriture et exécution.");
                } else {
                        printf("\n%s[!] Erreur dans le format fournit.%s\n\n", color.RED_ERROR, color.RESET);
                        return;
                }
    }

    strcat(binary, "\0");
    strcat(octal, "\0");
    InputColor(buffer, bufferColor, color);
    printf("\n%s[%s+%s] Informations trouvé à partir de la chaîne : %s%s\n", color.GREY_PROMPT, color.GREEN, color.GREY_PROMPT, color.RESET, bufferColor);
    printf("\t%s[ ] %s\n", color.GREY_PROMPT, type);
    printf("\t%s[ ] Détails des permissions :\n", color.GREY_PROMPT);
    printf("\t\t- Le propriétaire du fichier à les droits de              : %s%s%s\n", color.GREEN, rights[0], color.GREY_PROMPT);
    printf("\t\t- Le groupe associer au fichier à les droits de           : %s%s%s\n", color.GREEN, rights[1], color.GREY_PROMPT);
    printf("\t\t- Le les autres utilisateurs du fichier ont les droits de : %s%s%s\n", color.GREEN, rights[2], color.GREY_PROMPT);
    printf("\t[ ] File mode en binaire : %s%s%s\n", color.GREEN, binary, color.GREY_PROMPT);
    printf("\t[ ] File mode en octal   : %s%s%s\n\n", color.GREEN, octal, color.RESET);
}