/*
    Written By: Nate C
    This file contains all the config options for the program
*/
#include "config.h"

char accFilePath[MAXLEN] = "data/accounts.txt";

void configMenu()
{
    char i[MAXLEN];

    system("clear");
    printf("Press 1 to change path to accounts text file (Not reccomended!):\nPress 2 to go back to mainMenu:\n");
    scanf("%s", i);
    if(strcmp(i, "1") == 0)
    {
        printf("Enter your NEW FILE path: ");
        scanf("%s", accFilePath);
        configMenu();
    }     
    //else if(strcmp(i, "2") == 0)
        //mainMenu();         
}