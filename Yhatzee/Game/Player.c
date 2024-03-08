/// File Name: Player
/// File Author: Brooke Cronin
/// Course Code: CSCN71030 Group 4
/// Description: 
#include "Player.h"

PLAYER CreateNewPlayer(char* n)
{
    PLAYER p;

    // Allocate memory for the name field and copy the provided name into it
    p.name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    if (p.name != NULL) {
        strcpy(p.name, n, MAX_NAME_LENGTH);
    }
    else
    {
        fprintf(stderr, "Error allocating memory for name.\n");
        exit(1); // Terminate program if allocation fails
    }
   

    SetCurrentGameNumber(&p, 1);

    p.currentScore = (int**)malloc(sizeof(int*) * NUMBER_OF_ITEMS_TO_SCORE_FOR);
    if (p.currentScore == NULL)
    {
        fprintf(stderr, "Error allocating currentScore.\n");
        exit(1); // Terminate program if allocation fails
    }
    for (int r = 0; r < NUMBER_OF_ITEMS_TO_SCORE_FOR; r++)
    {
        p.currentScore[r] = (int*)malloc(sizeof(int) * MAX_NUMBER_OF_GAMES);
        if (p.currentScore[r] == NULL)
        {
            fprintf(stderr, "Error allocating currentScore[%d].\n", r);
            // Free previously allocated memory
            for (int i = 0; i < r; i++)
            {
                free(p.currentScore[i]);
            }
            free(p.currentScore);
            exit(1); // Terminate program if allocation fails
        }
        else
        {
            for (int c = 0; c < MAX_NUMBER_OF_GAMES; c++)
            {
                p.currentScore[r][c] = -1;
            }
        }
    }
    
    p.canScore = (int**)malloc(sizeof(int*) * NUMBER_OF_ITEMS_TO_SCORE_FOR);
    if (p.canScore == NULL)
    {
        fprintf(stderr, "Error allocating canScore.\n");
        exit(1); // Terminate program if allocation fails
    }
    for (int r = 0; r < NUMBER_OF_ITEMS_TO_SCORE_FOR; r++)
    {
        p.canScore[r] = (int*)malloc(sizeof(int) * MAX_NUMBER_OF_GAMES);
        if (p.canScore[r] == NULL)
        {
            fprintf(stderr, "Error allocating canScore[%d].\n", r);
            // Free previously allocated memory
            for (int i = 0; i < r; i++)
            {
                free(p.canScore[i]);
            }
            free(p.canScore);
            exit(1); // Terminate program if allocation fails
        }
        else
        {
            for (int c = 0; c < MAX_NUMBER_OF_GAMES; c++)
            {
                p.canScore[r][c] = -1;
            }
        }
    }

    return p;
}

int GetCurrentGameNumber(PLAYER p)
{
    return p.currentGameNumber;
}

void SetCurrentGameNumber(PPLAYER p, int gameNumber)
{
    // Check if the pointer is valid (not NULL)
    if (p == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to SetCurrentGameNumber.\n");
        return;
    }
    
    // Set the current game number
    p->currentGameNumber = gameNumber;
}

bool IsGameDoneForPlayer(PLAYER p)
{
    for (int item = 0; item < 12; item++)
    {
        if(p.currentScore[item][GetCurrentGameNumber(p) - 1] == -1)
        {
            return false;
        }
    }

    return true;
}

void DestroyPlayer(PPLAYER p)
{
    // Free memory for the name
    free(p->name);

    // Free memory for the currentScore array
    for (int item = 0; item < NUMBER_OF_ITEMS_TO_SCORE_FOR; item++)
    {
        free(p->currentScore[item]);
    }
    free(p->currentScore);

    // Free memory for the canScore array
    for (int item = 0; item < NUMBER_OF_ITEMS_TO_SCORE_FOR; item++)
    {
        free(p->canScore[item]);
    }
    free(p->canScore);
}

