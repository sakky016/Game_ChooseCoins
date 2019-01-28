#include "header.h"

int generateRandomNumber(int interval)
{
    struct timeval tp;
    static int id = 1;
    time_t tm;

    /* Generate a random number */
    gettimeofday(&tp, NULL);
    srand(tp.tv_usec);
    int num = rand() % interval;
    return num;
}

void displayInfo(gameData_t gameData)
{
    string player;
    if (gameData.isComputerTurn)
    {
        player = "Computer";
    }
    else
    {
        player = "User";
    }

    printf("\n>> '%s' played:\n", player.c_str());
    printf(" Coins chosen     : %d\n", gameData.coinsChosen);
    printf(" Coins left       : %d\n", gameData.coinsLeft);
}
