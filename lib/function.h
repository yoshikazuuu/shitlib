#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void account (void);
void accountcreated (void);
void login(void);
void loginsu (void);
void logout (void);
void registermenu(void);
void mainmenu(void);
void welcoming (void);

struct pass {
    char username[50];
    char fname[50];
    char lname[50];
    char phone_number[50];
};

struct userpass{
    char password[50];
};

void gotoxy(int x, int y) {
    // Use the ANSI escape sequence "\033[y;xH" to move the cursor to the specified position
    printf("\033[%d;%dH", y, x);
}

void registermenu (void) {
    system("clear");
    int choice;

    printf("\033[20;2H");
    printf("============================================");
    printf("\033[20;2H");
    printf ("Library Management System ");   
    gotoxy(34,5);
    printf ("Binus University ");
    gotoxy(20,7);
    printf("============================================");
    
    gotoxy(34,9);
    printf ("Account Handling ");

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
            login();
        break;

        case 2 :
            account();
        break;

        case 0 :
            system("clear");
            gotoxy(22,8);
            printf("---= Thank you for using this app. Have a nice Day :) =---");
            puts("\n");
        break;
    }
}

void account (void) {
    char password [50];
    int passwordlenght, i, seek = 0;
    char ch;

    FILE *fp, *fu;
    struct pass u1;
    struct userpass p1;
    struct userpass u2;

    fp = fopen("username.txt","ab");
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
    
    accountcreated();
}


void accountcreated (void) {
    int i;
    char ch;
    system("clear");
    printf("PLEASE WAIT....\n\nPROCESSING YOUR DATA....");
    for (i = 0; i < 200000000; i++) {
        i++;
        i--;
    }
 
    gotoxy(30, 10);
    printf("ACCOUNT CREATED SUCCESSFULLY....");
    gotoxy(0, 20);
 
    printf("Press enter to Back account Handling");
    getchar();

    registermenu();
}

void login (void) {
    system("clear");

    char username [50];
    char password [50];

    char ch;

    FILE *fp, *fu;

    struct pass u1;
    struct userpass u2;

    fp = fopen ("username.txt","rb");
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
            loginsu();
            mainmenu();
            getchar();
        }
        
    }

    fclose(fp);
    
}

void loginsu(void) {
    int i;
    FILE* fp;
    struct pass u1;
    system("clear");
    printf("Fetching account details");
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 25000000; j++) {
            i++;
            i--;
        }
    }
 
    gotoxy(30, 10);
    printf("LOGIN SUCCESSFUL....");
    gotoxy(0, 20);
    printf("Press enter to continue");
    getchar();

    puts("\n");
}

void mainmenu(void) {

    system ("clear");
    int choice;

    gotoxy(20,2);
    printf("============================================");
    gotoxy(29,4);
    printf ("Library Management System ");   
    gotoxy(34,5);
    printf ("Binus University ");
    gotoxy(20,7);
    printf("============================================");
    gotoxy(37,9);
    printf ("Main Menu");
    gotoxy(22,11);
    printf("----= 1. Add Book   ");
    gotoxy(22,13);
    printf("----= 2. Delete Book   ");
    gotoxy(22,15);
    printf("----= 3. Show Book List ");
    gotoxy(22,17);
    printf("----= 0. Log Out ");
    gotoxy(20,19);
    printf("============================================");
        
    gotoxy(22,21);
    printf("----= Console :   "); 
    scanf("%d",&choice);

    switch (choice){
        case 1  : 
            printf("nah belum beres cok");
        break;

        case 2 :
            printf("Under Development");
        break;

        case 0 :
            logout();
        break;
    }
}

void logout(void) {
    system("clear");
    printf("please wait, logging out");
 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 25000000; j++) {
            for (int k = 0; k < 10; k++) {
                i++;
                i--;
            }
        }
        printf(".");
    }
 
    gotoxy(30, 10);
    printf("Sign out successfully..\n");
 
    gotoxy(0, 20);
    printf("press any key to continue..");
 
    getchar();
    registermenu();
}

void welcoming (void) {
    // system("clear");
    // printf("Syncronizing system, please wait");
 
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 25000000; j++) {
    //         i++;
    //         i--;
    //     }
    //     printf(".");
    // }
 
    // gotoxy(30, 10);
    // printf("Syncronize system successfully..\n");

    // gotoxy(0, 20);
    // printf("press any key to continue..");
 
    // getchar();

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
    printf("press any key to continue..");
    getchar();

    registermenu();
}
