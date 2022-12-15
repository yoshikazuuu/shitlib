#include "../momen.h"
#ifdef _WIN32
#include <Windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addBook()
{
    headerLMS("Add Book");
    gotoxy(22, 11);
    struct books book;
    FILE *fp;
    fp = fopen("docs/book.csv", "a");
    printf("Enter Book ID : ");
    scanf("%d", &book.id);
    getchar();
    gotoxy(22, 13);
    printf("Enter Book Name : ");
    scanf("%[^\n]s", book.book_name);
    getchar();
    gotoxy(22, 15);
    printf("Enter Author Name : ");
    scanf("%[^\n]s", book.author);
    getchar();
    fprintf(fp, "%d, %s, %s,\n", book.id, book.book_name, book.author);
    fclose(fp);
}

void deleteBook()
{
    headerLMS("Delete Book");
    gotoxy(22, 11);
    FILE *fp, *ft;
    char id[10];
    fp = fopen("docs/book.csv", "r");
    ft = fopen("docs/bookTemp.csv", "w");
    gotoxy(22, 13);
    printf("Enter Book ID : ");
    scanf("%s", id);
    char buffer[1024];
    int row = 12;
    int column = 0;
    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        char *value = strtok(buffer, ",");
        while (value)
        {
            printf("%s", value);
            if (strcmp(value, id))
                printf("PEN TURUUUU");
            value = strtok(NULL, ",");
            column++;
        }
    }
    getchar();
    getchar();
    getchar();
    // while (fscanf(fp, "%d %[^,] %[^,]", &book.id, book.book_name, book.author)
    // != EOF) {
    //     if (book.id != id) {
    //         fprintf(ft, "%d, %s, %s\n", book.id, book.book_name, book.author);
    //     }
    // }
    fclose(fp);
    fclose(ft);
    // remove("docs/book.csv");
    // rename("docs/bookTemp.csv", "docs/book.csv");
    // remove("docs/bookTemp.csv");
}

void listBook()
{
    headerLMS("List Book");
    FILE *fp;
    fp = fopen("docs/book.csv", "r");
    system(clear);
    gotoxy(13, 11);
    printf("Book ID\t\t   Book Name\t      Author Name\n");
    // while (fscanf(fp, "%d %s %s", &book.id, book.book_name, book.author) !=
    // EOF) {
    //   printf("%d\t\t%s\t\t%s\n", book.id, book.book_name, book.author);
    // }
    char buffer[1024];
    int row = 12;
    int column = 0;
    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        char *value = strtok(buffer, ",");
        gotoxy(11, ++row);
        int i = -9;
        while (value)
        {
            gotoxy(i += 22, row);
            printf("%s", value);
            value = strtok(NULL, ",");
            putchar('\t');
            putchar('\t');
            column++;
        }
    }
    getchar();

    fclose(fp);
}

void searchBook()
{
    headerLMS("Search Book");
    struct books book;
    FILE *fp;
    char book_name[1001];
    fp = fopen("docs/book.csv", "r");
    gotoxy(22, 11);
    printf("Enter Book Name : ");
    scanf("%[^\n]", book_name);
    while (fscanf(fp, "%d %[^,]s %[^,]s", &book.id, book.book_name,
                  book.author) != EOF)
    {
        if (strcmp(book_name, book.book_name) == 0)
        {
            printf("%d\t%s\t%s\n", book.id, book.book_name, book.author);
        }
    }
    fclose(fp);
}

void borrowBook()
{
    headerLMS("Borrow Book");

    // show book list
    listBook();

    // select book by id
    gotoxy(22, 22);
    int id;
    printf("Enter Book ID : ");
    scanf("%d", &id);
    getchar();

    // check book is available or not
    struct books book;
    FILE *fp;
    fp = fopen("docs/book.csv", "r");
    while (fscanf(fp, "%d, %[^,], %[^,],\n", &book.id, book.book_name,
                  book.author) != EOF)
    {
        if (book.id == id)
        {
            // if book is available then add to docs/borrow.csv
            FILE *fp2;
            fp2 = fopen("docs/borrow.csv", "a");
            fprintf(fp2, "%d, %s, %s,\n", book.id, book.book_name, book.author);
            fclose(fp2);

            // remove book from docs/book.csv
            FILE *fp3;
            fp3 = fopen("docs/book.csv", "w");
            while (fscanf(fp, "%d, %[^,], %[^,],\n", &book.id, book.book_name,
                          book.author) != EOF)
            {
                if (book.id != id)
                {
                    fprintf(fp3, "%d, %s, %s,\n", book.id, book.book_name, book.author);
                }
            }
            fclose(fp3);

            // show book is borrowed
            printf("Book is borrowed\n");

            break;
        }
        else
        {
            printf("Book is not available\n");
        }
    }
}

void returnBook()
{
    headerLMS("Return Book");

    // show borrow list
    struct books book;
    FILE *fp;
    fp = fopen("docs/borrow.csv", "r");
    printf("ID\tBook Name\tAuthor Name\t\n");
    while (fscanf(fp, "%d, %[^,], %[^,],\n", &book.id, book.book_name,
                  book.author) != EOF)
    {
        printf("%d\t%s\t%s\t\n", book.id, book.book_name, book.author);
    }
    fclose(fp);

    // select book by id
    gotoxy(22, 22);
    int id;
    printf("Enter Book ID : ");
    scanf("%d", &id);
    getchar();

    // check book is available or not
    fp = fopen("docs/borrow.csv", "r");
    while (fscanf(fp, "%d, %[^,], %[^,],\n", &book.id, book.book_name,
                  book.author) != EOF)
    {
        if (book.id == id)
        {
            // if book is available then add to docs/book.csv
            FILE *fp2;
            fp2 = fopen("docs/book.csv", "a");
            fprintf(fp2, "%d, %s, %s,\n", book.id, book.book_name, book.author);
            fclose(fp2);

            // remove book from docs/borrow.csv
            FILE *fp3;
            fp3 = fopen("docs/borrow.csv", "w");
            while (fscanf(fp, "%d, %[^,], %[^,],\n", &book.id, book.book_name,
                          book.author) != EOF)
            {
                if (book.id != id)
                {
                    fprintf(fp3, "%d, %s, %s,\n", book.id, book.book_name, book.author);
                }
            }
            fclose(fp3);

            // show book is returned
            printf("Book is returned\n");

            break;
        }
        else
        {
            printf("Book is not available\n");
        }
    }
}
