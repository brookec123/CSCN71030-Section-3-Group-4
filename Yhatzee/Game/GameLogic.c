/// File Name: GameLogic
/// File Author: Brooke Cronin
/// Course Code: CSCN71030 Group 4
/// Description: 
#include "GameLogic.h"

/*
				 				 0			1		  2			3
              				  Game 1     Game 2    Game 3    Game 4      
 --------------------------------------------------------------------
   0 | Ones                |         |         |         |         |
 --------------------------------------------------------------------
   1 | Twos                |         |         |         |         |
 --------------------------------------------------------------------
   2 | Threes              |         |         |         |         |
 --------------------------------------------------------------------
   3 | Fours               |         |         |         |         |
 --------------------------------------------------------------------
   4 | Fives               |         |         |         |         |
 --------------------------------------------------------------------
   5 | Sixes               |         |         |         |         |
 --------------------------------------------------------------------
   6 | 3 of a kind         |         |         |         |         |
 --------------------------------------------------------------------
   7 | 4 of a kind         |         |         |         |         |
 --------------------------------------------------------------------
   8 | Full House          |         |         |         |         |
 --------------------------------------------------------------------
   9 | Small Straight      |         |         |         |         |
 --------------------------------------------------------------------
  10 | Large Straight      |         |         |         |         |
 --------------------------------------------------------------------
  11 | First Yahtzee       |         |         |         |         |
 --------------------------------------------------------------------
  12 | Chance              |         |         |         |         |
 --------------------------------------------------------------------
  13 | Subsequent Yahtzees |         |         |         |         |
 --------------------------------------------------------------------
  14 | Upper Subtotal      |         |         |         |         |
 --------------------------------------------------------------------
  15 | Upper Bonus         |         |         |         |         |
 --------------------------------------------------------------------
  16 | Upper Total         |         |         |         |         |
 --------------------------------------------------------------------
  17 | Lower Total         |         |         |         |         |
 --------------------------------------------------------------------
  18 | Grand Total         |         |         |         |         |
 --------------------------------------------------------------------
*/

int calculateUpper(DIE* dice, int valueToCheckFor)
{

    int score = 0;
    for(int index = 0; index < NUMBER_OF_DICE; index++)
    {
        if(GetValue(dice[index]) == valueToCheckFor)
        {
            score += valueToCheckFor;
        }
    }
    return score;
}

int calculateThreeOfAKind(DIE* dice)
{
    int dieValueCounter[] = {0, 0, 0, 0, 0, 0};

    for(int index = 0; index < NUMBER_OF_DICE; index++)
    {
        dieValueCounter[GetValue(dice[index])-1] ++;
        if(dieValueCounter[GetValue(dice[index])-1] == 3)
        {
            return TotalAllDice(dice, NUMBER_OF_DICE);
        }
    }

    return 0;
}

int calculateFourOfAKind(DIE* dice)
{
    int dieValueCounter[] = {0, 0, 0, 0, 0, 0};

    for(int index = 0; index < NUMBER_OF_DICE; index++)
    {
        dieValueCounter[GetValue(dice[index])-1] ++;
        if(dieValueCounter[GetValue(dice[index])-1] == 4)
        {
            return TotalAllDice(dice, NUMBER_OF_DICE);
        }
    }

    return 0;
}

int calculateFullHouse(DIE* dice)
{
    int dieValueCounter[] = {0, 0, 0, 0, 0, 0};
        bool checkFor2 = false;
    bool checkFor3 = false;

    for(int index = 0; index < NUMBER_OF_DICE; index++)
    {
        dieValueCounter[GetValue(dice[index])-1] ++;
        if(dieValueCounter[GetValue(dice[index])-1] == 2)
        {
            checkFor2 = true;
        }
        else if(dieValueCounter[GetValue(dice[index])-1] == 3)
        {
            checkFor3 = true;
        }
    }

    if(checkFor2 && checkFor3)
    {
        return 25;
    }

    return 0;
}

int calculateSmallStraight(DIE* dice)
{
    PDIE sortedDice = dice;
    SortDiceSmallestToLargest(sortedDice, NUMBER_OF_DICE);

    int previousValue = 0;
    int numberOfSubquentialDice = 0;

    for(int i = 0; i < NUMBER_OF_DICE; i++)
    {
        if(GetValue(sortedDice[i]) == previousValue)
        {
           numberOfSubquentialDice ++;
        }
    }

    if(numberOfSubquentialDice >= 4)
    {
        return 30;
    }

    return 0;
}

int calculateLargeStraight(DIE* dice)
{
    PDIE sortedDice = dice;
    SortDiceSmallestToLargest(sortedDice, NUMBER_OF_DICE);

    int previousValue = 0;
    int numberOfSubquentialDice = 0;

    for (int i = 0; i < NUMBER_OF_DICE; i++)
    {
        if (GetValue(sortedDice[i]) == previousValue)
        {
            numberOfSubquentialDice++;
        }
    }

    if (numberOfSubquentialDice == 5)
    {
        return 40;
    }

    return 0;
}

int calculateFirstYahtzee(DIE* dice)
{
    for(int i = 0; i < NUMBER_OF_DICE; i++)
    {
        if(GetValue(dice[i]) != GetValue(dice[0]))
        {
            return 0;
        }
    }

    return 50;
}

int calculateChance(DIE* dice)
{
    return TotalAllDice(dice, NUMBER_OF_DICE);
}

void calculateCanScore(DIE* dice, PPLAYER p)
{
    // calculating upper scores
    for(int num = 1; num <= 6; num++)
    {
        if(p->currentScore[num-1][GetCurrentGameNumber(*p) - 1] == -1)
        {
            p->canScore[num-1][GetCurrentGameNumber(*p) - 1] = calculateUpper(dice, num);
        }
    }
    // calculating lower scores
    if(p->currentScore[6][GetCurrentGameNumber(*p) - 1] == -1)
    {
        p->canScore[6][GetCurrentGameNumber(*p) - 1] = calculateThreeOfAKind(dice);
    }

    if(p->currentScore[7][GetCurrentGameNumber(*p) - 1] == -1)
    {
        p->canScore[7][GetCurrentGameNumber(*p) - 1] = calculateFourOfAKind(dice);
    }

    if(p->currentScore[8][GetCurrentGameNumber(*p) - 1] == -1)
    {
        p->canScore[8][GetCurrentGameNumber(*p) - 1] = calculateFullHouse(dice);
    }

    if(p->currentScore[9][GetCurrentGameNumber(*p) - 1] == -1)
    {
        p->canScore[9][GetCurrentGameNumber(*p) - 1] = calculateSmallStraight(dice);
    }

    if(p->currentScore[10][GetCurrentGameNumber(*p) - 1] == -1)
    {
        p->canScore[10][GetCurrentGameNumber(*p) - 1] = calculateLargeStraight(dice);
    }

    if(p->currentScore[11][GetCurrentGameNumber(*p) - 1] == -1 && p->currentScore[13][GetCurrentGameNumber(*p) - 1] == -1)
    {
        p->canScore[11][GetCurrentGameNumber(*p) - 1] = calculateFirstYahtzee(dice);
    }

    if(p->currentScore[12][GetCurrentGameNumber(*p) - 1] == -1)
    {
        p->canScore[12][GetCurrentGameNumber(*p) - 1] = calculateChance(dice);
    }

    if(p->currentScore[11][GetCurrentGameNumber(*p) - 1] == 50)
    {
        p->canScore[13][GetCurrentGameNumber(*p) - 1] += 2 * calculateFirstYahtzee(dice);
    }
}

void updateCurrentScore(PPLAYER p, int choice)
{
    // assuming choice is an int between 0 and 13, and that (choice == 13 && p->canScore[13][GetCurrentGameNumber(*p) - 1] > p->currentScore[13][GetCurrentGameNumber(*p) - 1]) is true
    p->currentScore[choice][GetCurrentGameNumber(*p) - 1] = p->canScore[choice][GetCurrentGameNumber(*p) - 1];
}

void calculateUpperSubTotal(PPLAYER p)
{
    int sum = 0;

    for(int i = 0; i <= 5; i++)
    {
        sum += p->currentScore[i][GetCurrentGameNumber(*p) - 1];
    }

    p->currentScore[14][GetCurrentGameNumber(*p) - 1] = sum;
}

void calculateUpperBonus(PPLAYER p)
{
    if (p->currentScore[14][GetCurrentGameNumber(*p) - 1] >= 63)
    {
        p->currentScore[15][GetCurrentGameNumber(*p) - 1] = 35;
    }
    else
    {
        p->currentScore[15][GetCurrentGameNumber(*p) - 1] = 0;
    }
}

void calculateUpperTotal(PPLAYER p)
{
    p->currentScore[16][GetCurrentGameNumber(*p) - 1] = p->currentScore[14][GetCurrentGameNumber(*p) - 1] + p->currentScore[15][GetCurrentGameNumber(*p) - 1];
}

void calculateLowerTotal(PPLAYER p)
{
    int sum = 0;

    for(int i = 6; i <= 12; i++)
    {
        sum += p->currentScore[i][GetCurrentGameNumber(*p) - 1];
    }

    if(p->currentScore[13][GetCurrentGameNumber(*p) - 1] >= 100)
    {
        sum += p->currentScore[13][GetCurrentGameNumber(*p) - 1];
    }

    p->currentScore[17][GetCurrentGameNumber(*p) - 1] = sum;
}

void calculateGrandTotal(PPLAYER p)
{
    p->currentScore[18][GetCurrentGameNumber(*p) - 1] = p->currentScore[16][GetCurrentGameNumber(*p) - 1] + p->currentScore[17][GetCurrentGameNumber(*p) - 1];
}

void calculateFinalTotalsAndBonuses(PPLAYER p)
{
    calculateUpperSubTotal(p);
    calculateUpperBonus(p);
    calculateUpperTotal(p);
    calculateLowerTotal(p);
    calculateGrandTotal(p);
}

bool isGameDone(PLAYER* arrayOfPlayers, int numberOfPlayers)
{
    for(int p = 0; p < numberOfPlayers; p++)
    {
        if(!IsGameDoneForPlayer(arrayOfPlayers[p]))
        {
            return false;
        }
    }

    return true;
}


void whoWon(PLAYER* arrayOfPlayers, int numberOfPlayers, int** currentWinnerIndexes)
{
    for(int i = 0; i < numberOfPlayers; i++)
    {
        currentWinnerIndexes[i] = -1;
    }

    if(isGameDone(arrayOfPlayers, numberOfPlayers))
    {
        int lastIndex = 1;
        currentWinnerIndexes[0] = arrayOfPlayers[0].currentScore[18][arrayOfPlayers[0].currentGameNumber-1];
        for(int p = 0; p < numberOfPlayers; p++)
        {
            // checking if current player has a larger grand total then the current player with the largest grand total
            if(arrayOfPlayers[p].currentScore[18][GetCurrentGameNumber(arrayOfPlayers[p]) - 1] > arrayOfPlayers[*currentWinnerIndexes[0]].currentScore[18][GetCurrentGameNumber(arrayOfPlayers[*currentWinnerIndexes[0]]) - 1])
            {
                for(int i = 0; i < numberOfPlayers; i++)
                {
                }
            }
            // checking for ties
            else if(arrayOfPlayers[p].currentScore[18][GetCurrentGameNumber(arrayOfPlayers[p]) - 1] == arrayOfPlayers[*currentWinnerIndexes[0]].currentScore[18][GetCurrentGameNumber(arrayOfPlayers[*currentWinnerIndexes[0]]) - 1])
            {
                lastIndex ++;
            }
        }
        return;
    }
    return; // game isn't done yet
}
