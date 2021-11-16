#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXLEN 255

struct account
{
    char name[MAXLEN];
    char dob[MAXLEN];

};

void newAccount(struct account *pStruct);

int main()
{
    struct account acc;
    struct account *newAcc;

    newAcc = &acc;

    newAccount(newAcc);

    return 0;
}

void newAccount(struct account *pStruct)
{
    char temp[2];

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

        fp = fopen("data/accounts.txt", "w+");

        if(fp == NULL)
        {
            printf("Error in opening data/accounts.txt, try running the program again after it closes\n");
            system("mkdir data");
            perror("Error in opening file!");
            exit(-1);
        }

        fputs(pStruct->name, fp);

        fclose(fp);

        printf("Done!");
    }   
    else
    {
        system("clear");
        exit(0);
    }
}