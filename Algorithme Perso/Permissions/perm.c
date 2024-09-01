#include "functions.h"

int main() {
        Colors color = {
        		.GREEN          = "\033[38;2;0;255;0m",
                .BLUE           = "\033[38;2;102;204;255m",
                .RED            = "\033[38;2;204;0;50m",
                .YELLOW         = "\033[38;2;255;255;102m",
                .DARK_BLUE      = "\033[38;2;51;0;255m",
                .PINK           = "\033[38;2;255;0;204m",
                .GREY_PROMPT    = "\033[38;2;102;102;153m",
                .ORANGE         = "\033[38;2;255;102;0m",
                .YELLOW_WARNING = "\033[1;33;1;40m",
                .RED_ERROR      = "\033[1;31;1;40m",
                .RESET          = "\033[0;0m"
        };
        char* prompt = " _    _\n"
                       "| |  (_)_ _ _  ___ __\n"
                       "| |__| | ' \\ || \\ \\ /\n"
                       "|____|_|_||_\\_,_/_\\_\\\n"
                       " ___               _       _\n"
                       "| _ \\___ _ _ _ __ (_)_____(_)___ _ _  ___\n"
                       "|  _/ -_) '_| '  \\| (_-<_-< / _ \\ ' \\(_-<\n"
                       "|_| \\___|_| |_|_|_|_/__/__/_\\___/_||_/__/\n"
                       "                V 0.1\n"
                       "   from Aiden\n\n"
                       "%s[ ] Rappel :\n"
                       "  %sr%s : %sRead\n"
                       "  %sw%s : %sWrite\n"
                       "  %sx%s : %sExecutable%s\n"
                       "  - : %sAucun droits%s\n\n"
                       "                  -       %sr%sw%sx       %sr%sw%s-   %sr%s-%sx%s\n"
                       "                  │        │         │     │\n"
                       "  %sType de fichier%s ╯  %sPropriétaire  Groupe%s  ╰ %sAutres utilisateurs%s\n"
                       "        │\n"
                       "        ├ - : %sFichier%s\n"
                       "        ├ %sd%s : %sDossier%s\n"
                       "        ╰ %sl%s : %sLien Symbolique\n\n"
                       "%s[!] Ce script ne prend pas en compte les bits spéciaux (comme par exemple les bits de setuid)%s\n\n";
        char choice;
        char mode[MAX_BUFFER];
        char* permissions = "╭───────┬────────┬───────────╮\n"
                            "│ %sOctal%s │ %sBinary%s │ %sFile Mode%s │\n"
                            "├───────┼────────┼───────────┤\n"
                            "│   0   │   000  │    ---    │\n"
                            "│   1   │   001  │    --%sx%s    │\n"
                            "│   2   │   010  │    -%sw%s-    │\n"
                            "│   3   │   011  │    -%sw%sx%s    │\n"
                            "│   4   │   100  │    %sr%s--    │\n"
                            "│   5   │   101  │    %sr%s-%sx%s    │\n"
                            "│   6   │   110  │    %sr%sw%s-    │\n"
                            "│   7   │   111  │    %sr%sw%sx%s    │\n"
                            "╰───────┴────────┴───────────╯\n";

        printf(prompt, color.GREY_PROMPT, color.RED, color.RESET, color.GREY_PROMPT, color.YELLOW,
        		color.RESET, color.GREY_PROMPT, color.BLUE, color.RESET, color.GREY_PROMPT,
        		color.RESET, color.GREY_PROMPT, color.RESET, color.RED, color.YELLOW, color.BLUE,
        		color.RED, color.YELLOW, color.RESET, color.RED, color.RESET, color.BLUE, color.RESET,
        		color.GREY_PROMPT, color.RESET, color.GREY_PROMPT, color.RESET, color.GREY_PROMPT,
        		color.RESET, color.GREY_PROMPT, color.RESET, color.DARK_BLUE, color.RESET,
        		color.GREY_PROMPT, color.RESET, color.PINK, color.RESET, color.GREY_PROMPT,
        		color.YELLOW_WARNING, color.RESET);
        do {
                printf("[1] - Liste des permissions\n");
                printf("[2] - Conversion file mode en octal/binaire\n");
                printf("[3] - Exit\n\n> ");
                scanf("%c", &choice);
                int temp;
                while ((temp = getchar()) != '\n' && temp != EOF);

                if (choice == '1') {
                        printf(permissions, color.GREY_PROMPT, color.RESET, color.GREY_PROMPT, color.RESET, color.GREY_PROMPT, color.RESET,
                        		color.BLUE, color.RESET, color.YELLOW, color.RESET, color.YELLOW, color.BLUE, color.RESET, color.RED, color.RESET,
                        		color.RED, color.RESET, color.BLUE, color.RESET, color.RED, color.YELLOW, color.RESET, color.RED, color.YELLOW, color.BLUE,
                        		color.RESET);
                } else if (choice == '2') {
                        printf("\n%s[%s*%s] Saisir un file mode. Par exemple : %s-%sr%sw%sx%sr%s-%sx%sr%s-%sx%s\n> ", color.GREY_PROMPT, color.ORANGE, color.GREY_PROMPT,
                        																							  color.RESET, color.RED, color.YELLOW, color.BLUE,
                        																						      color.RED, color.RESET, color.BLUE, color.RED,
                        																						      color.RESET, color.BLUE, color.RESET);
                        scanf("%10s", mode);
                        while ((temp = getchar()) != '\n' && temp != EOF);

                        if (!CheckBuffer(mode)) {
                                printf("\n%s[!] Erreur de saisie. Vous avez saisi :%s %s\n\n", color.RED_ERROR, color.RESET, mode);
                        } else {
                                ModeToOctal(mode);
                        }
                } else if (choice != '3') {
                        printf("\n%s[!] Erreur de saisie. Vous avez saisi :%s %c\n\n", color.RED_ERROR, color.RESET, choice);
                }
        } while (choice != '3');
        return 0;
}
