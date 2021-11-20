/*
    Written By: Nate C
    This file contains all the config options for the program
    The options it provides can also be edited in data/config.txt
*/
#include "config.h"

char accFilePath[MAXLEN] = "../../data/accounts";

void configMenu()
{
    char i[MAXLEN];

    system("clear");
    printf("Press 1 to change path to accounts text file " RED "(Not reccomended!)" RESET ":\nPress 2 to " GRE "reset accounts text file path" RESET ":\nPress 3 to go back to mainMenu:\n");
    scanf("%s", i);
    if(strcmp(i, "1") == 0)
    {
        printf("Enter your NEW FILE path: ");       //Write PATH to config
        scanf("%s", accFilePath);
        configMenu();
    }     
    else if(strcmp(i, "2") == 0)
        strcpy(accFilePath, "../../data/accounts");
    else if(strcmp(i, "3") == 0)
        mainMenu();         
}