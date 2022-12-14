
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pass {
    char username[50];
    char fname[50];
    char lname[50];
    char phone_number[50];
};

struct userpass {
    char password[50];
};

void gotoxy(int x, int y);
void welcomePage();
void adminLogin();
void adminPanel();
void userOptions();
void userLogin();
void userRegistration();
void userPanel();

void welcomePage() {
    system("clear");

    gotoxy(20,2);
    printf("============================================");
    gotoxy(20,4);
    printf ("---= Welcome TO                         =---");   
    gotoxy(20,5);
    printf ("---= Library Management System          =---");
    gotoxy(20,6);
    printf ("---= Binus Universitry                  =---");
    gotoxy(20,8);
    printf("============================================");
    gotoxy(0, 12);
    printf("press any key to continue...");
    getchar();
}

void adminLogin() {
    system("clear");

    char username[50];
    char password[50];

    char ch;

    FILE *fp, *fu;

    struct pass u1;
    struct userpass u2;

    fp = fopen("docs/admin.txt","rb");
    if (fp == NULL ){
        printf("ERROR OPENING FILE");
    }

    gotoxy(20,2);
    printf("============================================");
    gotoxy(36,4);
    printf ("Admin Login ");
    gotoxy(20,6);
    printf("============================================");

    gotoxy(22,8);
    printf("---= Username :   ");
    scanf("%s", username);

    gotoxy(22,10);
    printf("---= Password :   ");
    scanf("%s", password);
    

    while (fread(&u1, sizeof(u1),1, fp)) {
        if (strcmp(username,u1.username)== 0) {
            adminPanel();
        }
        
    }

    fclose(fp);
}

void userOptions() {
    system("clear");
    int choice;

    gotoxy(20,2);
    printf("============================================");
    gotoxy(29,4);
    printf ("Library Management System ");   
    gotoxy(34,5);
    printf ("Binus University ");
    gotoxy(20,7);
    printf("============================================");
    
    gotoxy(34,9);
    printf ("User Menu ");

    gotoxy(22,11);
    printf("----= 1. Login   ");

    gotoxy(22,13);
    printf("----= 2. Register   ");

    gotoxy(22,15);
    printf("----= 0. Close Program   ");

    gotoxy(20,17);
    printf("============================================");
        
    gotoxy(22,19);
    printf("----= Console :   "); 
    scanf("%d",&choice);

    switch (choice){

        case 1: 
            userLogin();
        break;

        case 2 :
            userRegistration();
        break;

        case 0 :
            system("clear");
            gotoxy(22,8);
            printf("---= Thank you for using this app. Have a nice Day :) =---");
            puts("\n");
        break;
    }
}

void userLogin() {
    system("clear");

    char username [50];
    char password [50];

    char ch;

    FILE *fp, *fu;

    struct pass u1;
    struct userpass u2;

    fp = fopen ("docs/users.txt","rb");
    if (fp == NULL ){
        printf("ERROR OPENING FILE");
    }

    gotoxy(20,2);
    printf("============================================");
    gotoxy(36,4);
    printf ("User Login ");
    gotoxy(20,6);
    printf("============================================");

    gotoxy(22,8);
    printf("---= Username :   ");
    scanf("%s", username);

    gotoxy(22,10);
    printf("---= Password :   ");
    scanf("%s", password);
    

    while (fread(&u1, sizeof(u1),1, fp)) {
        if (strcmp(username,u1.username)== 0) {
            userPanel();
        }
        
    }

    fclose(fp);
}

void userRegistration() {
    char password [50];
    int passwordlenght, i, seek = 0;
    char ch;

    FILE *fp, *fu;
    struct pass u1;
    struct userpass p1;
    struct userpass u2;

    fp = fopen("docs/users.txt","ab");
    system("clear");

    gotoxy(20,2);
    printf("============================================");
    gotoxy(32,4);
    printf ("User Register Form ");
    gotoxy(20,6);
    printf("============================================");
    
    gotoxy(22,8);
    printf("---= First name :   ");
    scanf("%s",u1.fname);

    gotoxy(22,10);
    printf("---= Last Name  :   ");
    scanf("%s",u1.lname);

    gotoxy(22,12);
    printf("---= username   :   ");
    scanf("%s",u1.username);
    getchar();

    gotoxy(22,14);
    printf("---= password   :   ");
    scanf("%s", password);

    fwrite(&u1, sizeof(u1),1,fp);
    fclose(fp);
    
    userOptions();
}

