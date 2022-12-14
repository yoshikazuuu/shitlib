#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addBook();
void deleteBook();
void listBook();
void searchBook();

struct books
{
    int id;
    char book_name[1001];
    char author[1001];
};

void addBook()
{
    FILE *fptr;
    struct books book;

    fptr = fopen("docs/booklist.txt", "ab");

    printf("Book ID : ");
    scanf("%s", book.id);
    getchar();
    printf("Book Name : ");
    scanf("%[^\n]", book.book_name);
    getchar();
    printf("Author Name : ");
    scanf("%[^\n]", book.author);
    getchar();

    fwrite(&book, sizeof(book), 1, fptr);
    fclose(fptr);
}

void deleteBook()
{
    FILE *fptr1, *fptr2;
    struct books book;
    char ch;

    int ID;
    printf("Enter Book ID to be deleted : ");
    scanf("%d", &ID);
    getchar();

    fptr1 = fopen("docs/booklist.txt", "rb");
    fptr2 = fopen("docs/temp___.txt", "ab");

    if (fptr1 == NULL)
    {
        printf("Can't open File");
        exit(0);
    }

    while (fread(&book, sizeof(book), 1, fptr1))
    {
        if (book.id != ID)
        {
            fwrite(&book, sizeof(book), 1, fptr2);
        }
    }

    fclose(fptr1);
    fclose(fptr2);

    remove("docs/booklist.txt");
    rename("docs/temp___.txt", "docs/booklist.txt");
}

void listBook()
{
    FILE *fptr;
    struct books book;
    int counter = 1;
    fptr = fopen("docs/booklist.txt", "rb");
    while (fread(&book, sizeof(book), 1, fptr))
    {
        printf("%d.\n", counter++);
        printf("Book ID : %d\n", book.id);
        printf("Book Name = %s\n", book.book_name);
        printf("Author Name = %s\n", book.author);
        putchar('\n');
    }
    int size = 0;
    if (fptr != NULL)
    {
        fseek(fptr, 0, SEEK_END);

        size = ftell(fptr);
        rewind(fptr);
    }
    if (size == 0)
    {
        printf("List is empty\n\n");
    }
    fclose(fptr);
}

void searchBook()
{
    FILE *fptr;
    struct books book;
    int ID;
    printf("Book ID : ");
    scanf("%d", &ID);
    getchar();

    fptr = fopen("docs/booklist.txt", "rb");
    while (fread(&book, sizeof(book), 1, fptr))
    {
        if (book.id == ID)
        {
            printf("Book found!\n");
            printf("Book ID : %d\n", book.id);
            printf("Book Name = %s\n", book.book_name);
            printf("Author Name = %s\n", book.author);
        }
    }
    fclose(fptr);
}
