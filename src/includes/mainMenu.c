#include "mainMenu.h"

//char i[MAXLEN];
//struct account acc;
//struct account *newAcc;

void mainMenu()
{
    newAcc = &acc;
    char i[MAXLEN];

    system("clear");
    printf("Press 1 to make a newAccount:\nPress 2 to view all current accounts:\nPress 3 to config:\nPress 4 to exit:\n");
    scanf("%s", i);
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