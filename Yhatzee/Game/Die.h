/// File Name: Die
/// File Author: Brooke Cronin
/// Course Code: CSCN71030 Group 4
/// Description: 
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MIN_VALUE 1
#define MAX_VALUE 6

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Die
{
    int value;
} DIE, * PDIE;

/// @brief Written by: Brooke Cronin
/// @return (DIE)
DIE CreateDie();

/// @brief Written by: Brooke Cronin
/// @param d (DIE)
/// @return (int)
int GetValue(DIE d);

/// @brief Written by: Brooke Cronin
/// @param d (PDIE)
/// @param val (int)
/// @return (void)
void SetValue(PDIE d, int val);

/// @brief Written by: Brooke Cronin
/// @param d (PDIE)
/// @return (void)
void RollDie(PDIE d);

/// @brief Written by: Brooke Cronin
/// @param d (PDIE*)
/// @param size (int)
/// @return (void)
void RollArrayOfDice(PDIE d, int size);

/// @brief Written by: Brooke Cronin
/// @param dice (DIE*)
/// @param number (int)
/// @return (int)
int TotalAllDice(DIE* dice, int number_of_dice);

/// @brief Written by: Brooke Cronin
/// @param void* (const)
/// @param void* (const)
/// @return (int)
int compare(const void* a, const void* b);

/// @brief Written by: Brooke Cronin
/// @param dice (PDIE*)
/// @param number (int)
/// @return (void)
void SortDiceSmallestToLargest(PDIE* dice, int number_of_dice);

