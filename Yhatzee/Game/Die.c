/// File Name: Die
/// File Author: Brooke Cronin
/// Course Code: CSCN71030 Group 4
/// Description: 
#include "Die.h"

DIE CreateDie()
{
    DIE d;
    d.value = 0;
    return d;
}

int GetValue(DIE d)
{
    return d.value;
}

void SetValue(PDIE d, int val)
{
    d->value = val;
}

void RollDie(PDIE d)
{
    int value = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    SetValue(d, value);

}

void RollArrayOfDice(PDIE d, int size)
{
    for(int i = 0; i < size; i++)
    {
        RollDie(&d[i]);
    }
}

int TotalAllDice(DIE* dice, int number_of_dice)
{
    int sum = 0;
    for(int index = 0; index < number_of_dice; index++)
    {
        sum += GetValue(dice[index]);
    }
    return sum;
}

int compare( const void* a, const void* b)
{
    int int_a = * ( (int*) a );
    int int_b = * ( (int*) b );

    return (int_a > int_b) - (int_a < int_b);
}


void SortDiceSmallestToLargest(PDIE dice, int number_of_dice)
{
    qsort( dice, number_of_dice, sizeof(int), compare );
}
