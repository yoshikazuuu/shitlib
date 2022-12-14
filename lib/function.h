#include <stdio.h>

void gotoxy(int x, int y) {
    // Use the ANSI escape sequence "\033[y;xH" to move the cursor to the specified position
    printf("\033[%d;%dH", y, x);
}