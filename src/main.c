#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAXLEN 255
#define ACCFILEPATH "data/accounts.txt"

struct account
{
    char name[MAXLEN];
    char dob[MAXLEN];

};

void newAccount(struct account *pStruct);
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

    printf("Press 1 to make a newAccount:\nPress 2 to view all current accounts:\nPress 3 to exit:\n");
    scanf("%s", i);
    if(strcmp(i, "1") == 0)
        newAccount(newAcc);
    else if(strcmp(i, "2") == 0)
        printAllAcc();
    else if(strcmp(i, "3") == 0)
        exit(0);
    else 
        printf("Invailid Expression!, Please try again!\n\n");

    i[0] = '\0';
    mainMenu();
}

void newAccount(struct account *pStruct)
{
    char temp[2];
    fpos_t position;

    system("clear");
    printf("Enter your account name: ");
    scanf("%s", pStruct->name);
    printf("\nEnter your account Date of Birth: ");
    scanf("%s", pStruct->dob);

    printf("\nIs this correct (Y/n)? Name: %s || DOB: %s\n", pStruct->name, pStruct->dob);
    scanf("%s", temp);

    if(strcmp(temp, "y") == 0 || strcmp(temp, "Y") == 0)
    {
        printf("Writing to data/accounts.txt...\n");
        FILE *fp = NULL;

        fp = fopen(ACCFILEPATH, "a+");

        if(fp == NULL)
        {
            printf("Error in opening data/accounts.txt, try running the program again after it closes\n");
            system("mkdir data");
            perror("Error in opening file!");
            exit(-1);
        }

        fputc('\n', fp);
        fputs(pStruct->name, fp);
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

    fp = fopen(ACCFILEPATH, "a+");

    system("clear");

    while((buf = fgetc(fp)) != EOF)
    {
        printf("%c", buf);
    }

    sleep(5);

    system("clear");

    fclose(fp);
    fp = NULL;
}