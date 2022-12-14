
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y);
void adminPanel();
void bookManagement();
void userManagement();
void userOptions();
void userPanel();

void adminPanel(void){

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
            gotoxy(22,8);
            printf("---= Thank you for using this app. Have a nice Day :) =---");
            puts("\n");
        break;
    }
}

void bookManagement(void){

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
    printf ("Book Management");

    gotoxy(22,11);
    printf("----= 1. Add Book   ");

    gotoxy(22,13);
    printf("----= 2. Delete Book   ");

    gotoxy(22,15);
    printf("----= 3. Search Book ");

    gotoxy(22,17);
    printf("----= 4. List Book ");
    
    gotoxy(22, 19);
    printf("----= 0. Go back ");

    gotoxy(20,21);
    printf("============================================");

    gotoxy(22, 23);
    printf("----= Console :   "); 
    scanf("%d",&choice);

    switch (choice){
        case 1  : 
            // addBook();
        break;

        case 2 :
            // deleteBook();
        break;

        case 3 :
            // searchBook();
        break;

        case 4 :
            // listBook();
        break;

        case 0 :
            adminPanel();
        break;
    }
}

void userManagement(void){

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
    printf ("User Management");

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
            // addUser();
        break;

        case 2 :
            // deleteUser();
        break;

        case 3:
            // listUser();
        break;

        case 0 :
            adminPanel();
        break;
    }
}

void userPanel() {
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
    printf ("User Panel");

    gotoxy(22,11);
    printf("----= 1. List Book ");

    gotoxy(22,13);
    printf("----= 2. Search Book ");

    gotoxy(22,15);
    printf("----= 3. Borrow Book ");

    gotoxy(22, 17);
    printf("----= 4. Return Book");
    
    gotoxy(22, 19);
    printf("----= 0. Log Out");

    gotoxy(20,21);
    printf("============================================");

    gotoxy(22,23);
    printf("----= Console :   "); 
    scanf("%d",&choice);

    switch (choice){
        case 1  : 
            // addUser();
        break;

        case 2 :
            // deleteUser();
        break;

        case 0 :
            userOptions();
        break;
    }
}