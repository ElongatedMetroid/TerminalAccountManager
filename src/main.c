#include "includes/mainMenu.h"
#include "includes/config.h"

void loadSavedData();

int main()
{
    //loadSavedData();
    mainMenu();

    return 0;
}

void loadSavedData()        //fix this function later
{
    char buf[MAXLEN];

    FILE *fp;
    fp = fopen(configFilePath, "w+");
    if(fp == NULL)
    {
        printf("Error in opening ../data/config\n");
        system("cd ..; mkdir data");
        perror("Error in opening file!");
        exit(-1);
    }

    fgets(buf, 255, fp);

    printf("%s", buf);

    fclose(fp);
    fp = NULL;
}