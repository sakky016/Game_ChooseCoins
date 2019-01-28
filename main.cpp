#include "header.h"

/***********************************************************************
  * This is a game where user/computer chooses some coins, minimum 
  * being 1. The player who chooses the last coin, wins. As of now
  * the computer randomly selects the number of coins.
************************************************************************/
int main()
{
    bool gameOver = false;
    int val = 0;

    printf("+---------------------------------------------+\n");
    printf("|                Choose coins                 |\n");
    printf("+---------------------------------------------+\n");

    bool isComputerTurn = generateRandomNumber(2);
    gameData_t gameData;
    gameData.coinsChosen = 0;
    gameData.coinsLeft = TOTAL_COINS;
    gameData.isComputerTurn = isComputerTurn;


    if (isComputerTurn)
    {
        printf("Computer plays first\n");
        sleep(1);
    }
    else
    {
    }

    while (!gameOver)
    {
        if (isComputerTurn)
        {
            printf("\nComputer's move...\n");
            sleep(1);

            /* Give computer some intelligence */
            if (gameData.coinsLeft <= MAX_COINS_TO_CHOOSE)
            {
                printf("!BANG1!\n");
                val = gameData.coinsLeft;
            }
            else if (gameData.coinsLeft - MAX_COINS_TO_CHOOSE <= MAX_COINS_TO_CHOOSE)
            {
                printf("!BANG2!!\n");
                val = 1;
            }
            else
            {
                /* Do ranndom selection */
                val = generateRandomNumber(MAX_COINS_TO_CHOOSE) + 1;
                if (val > MAX_COINS_TO_CHOOSE || 
                        val < 1 || 
                        val > gameData.coinsLeft)
                {
                    continue;
                }
            }

            gameData.coinsChosen = val;
            gameData.coinsLeft -= val;
            gameData.isComputerTurn = true;
            displayInfo(gameData);
            isComputerTurn = false;

            /* Win logic */
            if (gameData.coinsLeft <= 0)
            {
                printf("\nComputer Wins!\n");
                gameOver = true;
            }
        }
        else
        {
            printf("\nYour turn\n");
            printf("Choose number of coins (1-%d): ", MAX_COINS_TO_CHOOSE);
            cin>>val;
            if (val > MAX_COINS_TO_CHOOSE || 
                val < 1 || 
                val > gameData.coinsLeft)
            {
                printf(" Invalid choice! Choose again.\n");
                continue;
            }
            gameData.coinsChosen = val;
            gameData.coinsLeft -= val;
            gameData.isComputerTurn = false;
            displayInfo(gameData);
            isComputerTurn = true;

            /* Win logic */
            if (gameData.coinsLeft <= 0)
            {
                printf("\nCongratulations!! You have won!\n");
                gameOver = true;
            }

        }
    }/* End of while loop */

    return 0;
}


