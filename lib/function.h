#include <stdio.h>
#define BUF_SIZE 65536

void gotoxy(int x, int y);

void gotoxy(int x, int y) {
    // Use the ANSI escape sequence "\033[y;xH" to move the cursor to the specified position
    printf("\033[%d;%dH", y, x);
}

int countLines(FILE* file)
{
    char buf[BUF_SIZE];
    int counter = 0;
    for(;;)
    {
        size_t res = fread(buf, 1, BUF_SIZE, file);
        if (ferror(file))
            return -1;

        int i;
        for(i = 0; i < res; i++)
            if (buf[i] == '\n')
                counter++;

        if (feof(file))
            break;
    }

    return counter;
}