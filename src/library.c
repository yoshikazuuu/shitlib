#ifdef _WIN32
#include <Windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include "../lib/momen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adminPanel(void){
    int choice;

    headerLMS("Main Menu");

    gotoxy(22,11);
    printf("----= 1. Book Management   ");

    gotoxy(22,13);
    printf("----= 2. User Management   ");

    gotoxy(22,15);
    printf("----= 0. Log Out ");

    gotoxy(20,17);
    printf("============================================");

    gotoxy(22,19);
    printf("----= Console :   "); 
    scanf("%d",&choice);

    switch (choice){
        case 1  : 
            bookManagement();
        break;

        case 2 :
            userManagement();
        break;

        case 0 :
            system("clear");
            gotoxy(15,8);
            printf("---= Thank you for using this app. Have a nice Day :) =---");
            gotoxy(15,16);
            puts("\n");
            exit(0);
        break;
    }
}

void bookManagement(void){
    int choice;

    headerLMS("Book Management");

    gotoxy(22,11);
    printf("----= 1. Add Book   ");

    gotoxy(22,13);
    printf("----= 2. Delete Book   ");

    gotoxy(22,15);
    printf("----= 3. List Book ");
    
    gotoxy(22, 17);
    printf("----= 0. Go back ");

    gotoxy(20,20);
    printf("============================================");

    gotoxy(22, 22);
    printf("----= Console :   "); 
    scanf("%d",&choice);

    getchar();

    switch (choice){
        case 1  : 
            addBook();
            bookManagement();
        break;

        case 2 :
            deleteBook();
            bookManagement();
        break;

        case 3 :
            listBook();
            bookManagement();
        break;

        case 0 :
            adminPanel();
            bookManagement();
        break;
    }
}

void userManagement(void){
    int choice;

    headerLMS("User Management");

    gotoxy(22,11);
    printf("----= 1. Add User   ");

    gotoxy(22,13);
    printf("----= 2. Delete User   ");

    gotoxy(22,15);
    printf("----= 3. List User ");

    gotoxy(22, 17);
    printf("----= 0. Go Back");

    gotoxy(20,19);
    printf("============================================");

    gotoxy(22,21);
    printf("----= Console :   "); 
    scanf("%d",&choice);

    switch (choice){
        case 1  : 
            addUser();
        break;

        case 2 :
            deleteUser();
        break;

        case 3:
            listUsers();
        break;

        case 0 :
            adminPanel();
        break;
    }
}

void userPanel() {
    int choice;

    headerLMS("User Panel");

    gotoxy(22,11);
    printf("----= 1. List Book ");

    gotoxy(22,13);
    printf("----= 2. Borrow Book ");

    gotoxy(22, 15);
    printf("----= 3. Return Book");
    
    gotoxy(22, 17);
    printf("----= 0. Log Out");

    gotoxy(20,19);
    printf("============================================");

    gotoxy(22,21);
    printf("----= Console :   "); 
    scanf("%d",&choice);

    getchar();
    
    switch (choice){
        case 1  : 
            listBook();
            userPanel();
        break;

        case 2 :
            borrowBook();
            userPanel();
        break;

        case 3 :
            returnBook();
            userPanel();
        break;

        case 0 :
            userOptions();
            userPanel();
        break;
    }
}