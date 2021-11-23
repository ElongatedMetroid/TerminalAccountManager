/*
    Written By: Nate C
    This handles all the functions related to accounts
*/
#include "account.h"

struct account
{
    char uname[MAXLEN];
    char rfname[MAXLEN];
    char rlname[MAXLEN];
    char dob[MAXLEN];
};

struct account acc;
struct account *newAcc;

void newAccount(struct account *pStruct)
{
    char temp[2];

    printf(CLEAR);
    printf("Enter your account " RED "username: " RESET);
    scanf("%254s", pStruct->uname);
    printf("\nEnter your " RED "real first name: " RESET);
    scanf("%50s", pStruct->rfname);
    printf("\nEnter your " RED "real last name: " RESET);
    scanf("%100s", pStruct->rlname);
    printf("\nEnter your Date of Birth: ");
    scanf("%100s", pStruct->dob);

    printf("\nIs this correct (Y/n)? Username: %s || Name: %s %s || DOB: %s\n", pStruct->uname, pStruct->rfname, pStruct->rlname, pStruct->dob);
    scanf("%3s", temp);

    if(strcmp(temp, "y") == 0 || strcmp(temp, "Y") == 0)
    {
        printf("Writing to data/accounts.txt...\n");
        FILE *fp = NULL;

        fp = fopen(accFilePath, "a+");

        if(fp == NULL)
        {
            printf("Error in opening ../data/accounts, try running the program again after it closes\n");
            system("cd ..; mkdir data");
            perror("Error in opening file!");
            exit(-1);
        }

        fputc('\n', fp);
        fputs(pStruct->uname, fp);
        fputc('\n', fp);                // Make function to check for spaces 
        fputs(pStruct->rfname, fp); fputc(' ', fp); fputs(pStruct->rlname, fp);
        fputc('\n', fp);
        fputs(pStruct->dob, fp);
        fputc('\n', fp);

        fclose(fp);

        printf("\nDone!\n");
        printf(CLEAR);
        mainMenu();
    }   
    else
    {
        printf(CLEAR);
        mainMenu();
    }
}

void printAllAcc()
{
    FILE *fp = NULL;
    char buf;
    int i;

    fp = fopen(accFilePath, "a+");

    printf(CLEAR);

    while((buf = fgetc(fp)) != EOF)
    {
        printf("%c", buf);
    }

    printf("\n\nDone! Press 1 to exit: ");

    scanf("%3i", &i);

    printf(CLEAR);

    fclose(fp);
    fp = NULL;
}