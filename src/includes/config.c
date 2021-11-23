/*
    Written By: Nate C
    This file contains all the config options for the program
    The options it provides can also be edited in data/config
*/
#include "config.h"

char accFilePath[MAXLEN] = "../data/accounts";
char configFilePath[MAXLEN] = "../data/config";

void configMenu()
{
    char i[MAXLEN];

    printf(CLEAR);
    printf("Press 1 to change path to accounts text file " RED "(Not reccomended!)" RESET ":\nPress 2 to " GRE "reset accounts text file path" RESET ":\nPress 3 to go back to mainMenu:\n");
    scanf("%3s", i);
    if(strcmp(i, "1") == 0)
    {
        printf("Enter your NEW FILE path: ");       //Write PATH to config
        scanf("%254s", accFilePath);

        FILE *fp;
        fp = fopen(configFilePath, "w+");

        if(fp == NULL)
        {
            printf("Error in opening ../data/config\n");
            system("cd ..; mkdir data");
            perror("Error in opening file!");
            exit(-1);
        }

        fputs(accFilePath, fp);

        fclose(fp);
        fp = NULL;

        configMenu();
    }     
    else if(strcmp(i, "2") == 0)
    {
        FILE *fp;
        fp = fopen(configFilePath, "w+");
        if(fp == NULL)
        {
            printf("Error in opening ../data/config\n");
            system("cd ..; mkdir data");
            perror("Error in opening file!");
            exit(-1);
        }

        strcpy(accFilePath, "../data/accounts");

        fputs(accFilePath, fp);

        fclose(fp);
        fp = NULL;

        configMenu();
    }
    else if(strcmp(i, "3") == 0)
        mainMenu();         
}