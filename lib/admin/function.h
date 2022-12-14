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


void gotoxy(int x, int y);
void headerLMS(char str[]);
void addUser();
void deleteUser();
void listUsers();
void userManagement();

struct users {
  int ID;
  char username[50];
  char password[50];
  int role;
};

void addUser() {
  system(clear);
  gotoxy(20,2);
  printf("============================================");
  gotoxy(29,4);
  printf ("Library Management System ");   
  gotoxy(34,5);
  printf ("Binus University ");
  gotoxy(20,7);
  printf("============================================");
  gotoxy(37,9);
  printf ("Add User");

  struct users user;
  FILE *fp;
  fp = fopen("docs/users.txt", "a");
  if (fp == NULL) {
    system(clear);
    printf("File doesn't exists.");
    sleep(1);
    userManagement();
  }
  gotoxy(22,11);  
  printf("Enter ID: ");
  scanf("%d", &user.ID);

  // Check if ID already exists
  struct users temp;
  FILE *fp2;
  fp2 = fopen("docs/users.txt", "r");
  while (fscanf(fp2, "%d %s %s %d", &temp.ID, temp.username, temp.password,
                &temp.role) != EOF) {
    if (temp.ID == user.ID) {
      gotoxy(22,12);
      printf("ID already exists. Please try again.\n");
      sleep(1);
      addUser();
    }
  }

  if (isExists(fopen("docs/users.txt","r"), user.username)) {
    userRegistration();
  } 

  fclose(fp2);

  gotoxy(22,13);
  printf("Enter username: ");
  scanf("%s", user.username);
  gotoxy(22,15);
  printf("Enter password: ");
  scanf("%s", user.password);
  gotoxy(22,17);
  printf("Enter role: ");
  scanf("%d", &user.role);

  // check if role is valid
  if (user.role != 1 && user.role != 2) {
    gotoxy(22,19);
    printf("Invalid role. Please try again.\n");
    sleep(1);
    addUser();
  }

  fprintf(fp, "%d %s %s %d\n", user.ID, user.username, user.password, user.role);
  fclose(fp);


  gotoxy(22,19);
  printf("User added.\n");
  sleep(1);

  userManagement();
}

void deleteUser() {
  system(clear);
  gotoxy(20,2);
  printf("============================================");
  gotoxy(29,4);
  printf ("Library Management System ");   
  gotoxy(34,5);
  printf ("Binus University ");
  gotoxy(20,7);
  printf("============================================");
  gotoxy(37,9);
  printf ("Delete user");  
  struct users user;
  FILE *fp;
  fp = fopen("docs/users.txt", "r");
  if (fp == NULL) {
    system(clear);
    printf("File doesn't exists.");
    sleep(1);
    userManagement();
  }
  gotoxy(22,11);
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
    gotoxy(23,12);
    printf("ID does not exist. Please try again.\n");
    sleep(1);
    deleteUser();
  }

  // Delete user
  FILE *fp3;
  fp3 = fopen("temp.txt", "w");
  while (fscanf(fp, "%d %s %s %d", &temp.ID, temp.username, temp.password,
                &temp.role) != EOF) {
    if (temp.ID != user.ID) {
      fprintf(fp3, "%d %s %s %d\n", temp.ID, temp.username, temp.password,
              temp.role);
    }
  }
  fclose(fp);
  fclose(fp3);
  remove("docs/users.txt");
  rename("temp.txt", "docs/users.txt");

  gotoxy(22,13);
  printf("User deleted.\n");
  sleep(1);

  userManagement();
}

void listUsers() {
  system(clear);
  gotoxy(20,2);
  printf("============================================");
  gotoxy(29,4);
  printf ("Library Management System ");   
  gotoxy(34,5);
  printf ("Binus University ");
  gotoxy(20,7);
  printf("============================================");
  gotoxy(37,9);
  printf ("User Lists");

  struct users user;
  FILE *fp;
  fp = fopen("docs/users.txt", "r");
  if (fp == NULL) {
    printf("File doesn't exists.");
    userManagement();
  }
  gotoxy(28,11);
  printf("ID  Username   Password  Role\n");
  int rep = 12;
  while (fscanf(fp, "%d %s %s %d", &user.ID, user.username, user.password, &user.role) != EOF) {
    gotoxy(28,rep++);
    printf("%2d  %-8s   %-8s  %-2d\n", user.ID, user.username, user.password, user.role);
  }

  gotoxy(28, ++rep);
  printf("Enter to continue.\n");
  getchar();
  getchar();
  fclose(fp);


  userManagement();
}
