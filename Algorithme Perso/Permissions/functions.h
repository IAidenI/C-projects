#include <stdio.h>
#include <string.h>

#define MAX_BUFFER       11
#define MAX_BUFFER_COLOR 249
#define MAX_TYPE         51
#define MAX_MODE         4

typedef struct {
        const char* GREEN;
        const char* RED;
        const char* BLUE;
        const char* LIGHT;
        const char* YELLOW;
        const char* DARK_BLUE;
        const char* PINK;
        const char* GREY_PROMPT;
		const char* ORANGE;
		const char* YELLOW_WARNING;
		const char* RED_ERROR;
        const char* RESET;
} Colors;

void ModeToOctal(const char buffer[MAX_BUFFER]);
int CheckBuffer(const char buffer[MAX_BUFFER]);
void InputColor(const char input[MAX_BUFFER], char newInput[MAX_BUFFER_COLOR], Colors color);
