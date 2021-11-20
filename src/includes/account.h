#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "config.h"
#include "mainMenu.h"
#include "ansiEscapes.h"

#define MAXLEN 255

void printAllAcc();
void newAccount();

extern struct account acc;
extern struct account *newAcc;

#endif // ACCOUNT_H_