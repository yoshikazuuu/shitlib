#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addBook();
void deleteBook();
void listBook();
void searchBook();

struct books {
  int id;
  char book_name[1001];
  char author[1001];
};

void addBook() {
  struct books book;
  FILE *fp;
  fp = fopen("docs/book.txt", "a");
  printf("Enter Book ID : ");
  scanf("%d", &book.id);
  getchar();
  printf("Enter Book Name : ");
  scanf("%s", book.book_name);
  getchar();
  printf("Enter Author Name : ");
  scanf("%s", book.author);
  getchar();
  fprintf(fp, "%d %s %s\n", book.id, book.book_name, book.author);
  fclose(fp);
}

void deleteBook() {
  struct books book;
  FILE *fp, *ft;
  int id;
  fp = fopen("docs/book.txt", "r");
  ft = fopen("docs/bookTemp.txt", "w");
  printf("Enter Book ID : ");
  scanf("%d", &id);
  while (fscanf(fp, "%d %s %s", &book.id, book.book_name, book.author) != EOF) {
    if (book.id != id) {
      fprintf(ft, "%d %s %s\n", book.id, book.book_name, book.author);
    }
  }
  fclose(fp);
  fclose(ft);
  remove("docs/book.txt");
  rename("docs/bookTemp.txt", "docs/book.txt");
}

void listBook() {
  struct books book;
  FILE *fp;
  fp = fopen("docs/book.txt", "r");
  printf("Book ID\t\tBook Name\t\tAuthor Name\n");
  while (fscanf(fp, "%d %s %s", &book.id, book.book_name, book.author) != EOF) {
    printf("%d\t\t%s\t\t%s\n", book.id, book.book_name, book.author);
  }
  fclose(fp);
}

void searchBook() {
  struct books book;
  FILE *fp;
  char book_name[1001];
  fp = fopen("docs/book.txt", "r");
  printf("Enter Book Name : ");
  scanf("%s", book_name);
  while (fscanf(fp, "%d %s %s", &book.id, book.book_name, book.author) != EOF) {
    if (strcmp(book_name, book.book_name) == 0) {
      printf("%d\t%s\t%s\n", book.id, book.book_name, book.author);
    }
  }
  fclose(fp);
}
