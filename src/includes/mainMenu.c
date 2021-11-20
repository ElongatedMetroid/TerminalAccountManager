/*
    Written By: Nate C
    This file is used to manage the mainMenu
*/
#include "mainMenu.h"

void mainMenu()
{
    newAcc = &acc;
    char i[MAXLEN];

    printf(CLEAR);
    printf("Press 1 to make a " GRE "newAccount" RESET":\nPress 2 to " BLU "view all current accounts" RESET ":\nPress 3 to " YEL "config" RESET ":\nPress 4 to " RED "exit" RESET ":\n");
    scanf("%3s", i);
    if(strcmp(i, "1") == 0)
        newAccount(newAcc);
    else if(strcmp(i, "2") == 0)
        printAllAcc();
    else if(strcmp(i, "3") == 0)
        configMenu();
    else if(strcmp(i, "4") == 0)
        exit(0);
    else 
    {
        printf("Invailid Expression!, Please try again!\n\n");
        sleep(2);
    }
    mainMenu();
}