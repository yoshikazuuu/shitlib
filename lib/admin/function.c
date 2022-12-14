#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void addUser();
void deleteUser();
void listUsers();

struct users {
  int ID;
  char username[50];
  char password[50];
  int role;
};

void addUser() {
  struct users user;
  FILE *fp;
  fp = fopen("docs/users.txt", "a");
  printf("Enter ID: ");
  scanf("%d", &user.ID);

  // Check if ID already exists
  struct users temp;
  FILE *fp2;
  fp2 = fopen("docs/users.txt", "r");
  while (fscanf(fp2, "%d %s %s %d", &temp.ID, temp.username, temp.password,
                &temp.role) != EOF) {
    if (temp.ID == user.ID) {
      printf("ID already exists. Please try again.\n");
      return;
    }
  }
  fclose(fp2);

  printf("Enter username: ");
  scanf("%s", user.username);
  printf("Enter password: ");
  scanf("%s", user.password);

  printf("Enter role: ");
  scanf("%d", &user.role);

  // check if role is valid
  if (user.role != 1 && user.role != 2) {
    printf("Invalid role. Please try again.\n");
    return;
  }

  fprintf(fp, "%d %s %s %d", user.ID, user.username, user.password, user.role);
  fclose(fp);
}

void deleteUser() {
  struct users user;
  FILE *fp;
  fp = fopen("docs/users.txt", "r");
  printf("Enter ID: ");
  scanf("%d", &user.ID);

  // Check if ID exists
  struct users temp;
  FILE *fp2;
  fp2 = fopen("docs/users.txt", "r");
  int found = 0;
  while (fscanf(fp2, "%d %s %s %d", &temp.ID, temp.username, temp.password,
                &temp.role) != EOF) {
    if (temp.ID == user.ID) {
      found = 1;
      break;
    }
  }
  fclose(fp2);

  if (found == 0) {
    printf("ID does not exist. Please try again.\n");
    return;
  }

  // Delete user
  FILE *fp3;
  fp3 = fopen("temp.txt", "w");
  while (fscanf(fp, "%d %s %s %d", &temp.ID, temp.username, temp.password,
                &temp.role) != EOF) {
    if (temp.ID != user.ID) {
      fprintf(fp3, "%d %s %s %d", temp.ID, temp.username, temp.password,
              temp.role);
    }
  }
  fclose(fp);
  fclose(fp3);
  remove("docs/users.txt");
  rename("temp.txt", "docs/users.txt");
}

void listUsers() {
  struct users user;
  FILE *fp;
  fp = fopen("docs/users.txt", "r");
  printf("ID\tUsername\tPassword\tRole\n");
  while (fscanf(fp, "%d %s %s %d", &user.ID, user.username, user.password,
                &user.role) != EOF) {
    printf("%d\t%s\t%s\t%d\n", user.ID, user.username, user.password,
           user.role);
  }
  fclose(fp);
}
