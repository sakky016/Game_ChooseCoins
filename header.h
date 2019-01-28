#ifndef _HEADER_H_
#define _HEADER_H_

#include<stdio.h>
#include<iostream>
#include<string>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

#define MAX_COINS_TO_CHOOSE 4
#define TOTAL_COINS 23

typedef struct gameData_tag
{
    int coinsChosen;
    int coinsLeft;
    bool isComputerTurn;
}gameData_t;

int generateRandomNumber(int);
void displayInfo(gameData_t);



#endif
