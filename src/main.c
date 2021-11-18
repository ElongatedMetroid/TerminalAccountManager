#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAXLEN 255

char accFilePath[MAXLEN] = "data/accounts.txt";

struct account
{
    char uname[MAXLEN];
    char rfname[MAXLEN];
    char rlname[MAXLEN];
    char dob[MAXLEN];
};

void newAccount(struct account *pStruct);
void configMenu();
void mainMenu();
void printAllAcc();

int main()
{
    mainMenu();

    return 0;
}

void mainMenu()
{
    char i[MAXLEN];
    struct account acc;
    struct account *newAcc;
    newAcc = &acc;

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
    else if(strcmp(i, "2") == 0)
        mainMenu();         
}

void newAccount(struct account *pStruct)
{
    char temp[2];

    system("clear");
    printf("Enter your account username name: ");
    scanf("%s", pStruct->uname);
    printf("\nEnter your real first name: ");
    scanf("%s", pStruct->rfname);
    printf("\nEnter your real last name: ");
    scanf("%s", pStruct->rlname);
    printf("\nEnter your account Date of Birth: ");
    scanf("%s", pStruct->dob);

    printf("\nIs this correct (Y/n)? Username: %s || Name: %s %s || DOB: %s\n", pStruct->uname, pStruct->rfname, pStruct->rlname, pStruct->dob);
    scanf("%s", temp);

    if(strcmp(temp, "y") == 0 || strcmp(temp, "Y") == 0)
    {
        printf("Writing to data/accounts.txt...\n");
        FILE *fp = NULL;

        fp = fopen(accFilePath, "a+");

        if(fp == NULL)
        {
            printf("Error in opening data/accounts.txt, try running the program again after it closes\n");
            system("mkdir data");
            perror("Error in opening file!");
            exit(-1);
        }

        fputc('\n', fp);
        fputs(pStruct->uname, fp);
        fputc('\n', fp);
        fputs(pStruct->rfname, fp); fputc(' ', fp); fputs(pStruct->rlname, fp);
        fputc('\n', fp);
        fputs(pStruct->dob, fp);
        fputc('\n', fp);

        fclose(fp);

        printf("\nDone!\n");
        system("clear");
        mainMenu();
    }   
    else
    {
        system("clear");
        mainMenu();
    }
}

void printAllAcc()
{
    FILE *fp = NULL;
    char buf;
    int i;

    fp = fopen(accFilePath, "a+");

    system("clear");

    while((buf = fgetc(fp)) != EOF)
    {
        printf("%c", buf);
    }

    scanf("%i", &i);

    system("clear");

    fclose(fp);
    fp = NULL;
}