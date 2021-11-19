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