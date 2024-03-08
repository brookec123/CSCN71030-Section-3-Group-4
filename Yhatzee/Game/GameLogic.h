/// File Name: GameLogic
/// File Author: Brooke Cronin
/// Course Code: CSCN71030 Group 4
/// Description: 
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define NUMBER_OF_DICE 5

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "Die.h"
#include "Player.h"

/// @brief Calculates scores for Ones, Twos, Threes, Fours, Fives, and Sixes. Written by: Brooke Cronin
/// @param dice (DIE*)
/// @param valueToCheckFor (int)
/// @return (int)
int calculateUpper(DIE* dice, int valueToCheckFor);

/// @brief Written by: Brooke Cronin
/// @param dice (DIE*)
/// @return (int)
int calculateThreeOfAKind(DIE* dice);

/// @brief Written by: Brooke Cronin
/// @param dice (DIE*)
/// @return (int)
int calculateFourOfAKind(DIE* dice);

/// @brief Written by: Brooke Cronin
/// @param dice (DIE*)
/// @return (int)
int calculateFullHouse(DIE* dice);

/// @brief Written by: Brooke Cronin
/// @param dice (DIE*)
/// @return (int)
int calculateSmallStraight(DIE* dice);

/// @brief Written by: Brooke Cronin
/// @param dice (DIE*)
/// @return (int)
int calculateLargeStraight(DIE* dice);

/// @brief Written by: Brooke Cronin
/// @param dice (DIE*)
/// @return (int)
int calculateFirstYahtzee(DIE* dice);

/// @brief Written by: Brooke Cronin
/// @param dice (DIE*)
/// @return (int)
int calculateChance(DIE* dice);

/// @brief Written by: Brooke Cronin
/// @param dice (DIE*)
/// @param p (PPLAYER)
/// @return (void)
void calculateCanScore(DIE* dice, PPLAYER p);

/// @brief Written by: Brooke Cronin
/// @param p (PPLAYER)
/// @param choice (int)
/// @return (void)
void updateCurrentScore(PPLAYER p, int choice);

/// @brief Written by: Brooke Cronin
/// @param p (PPLAYER)
/// @return (void)
void calculateUpperSubTotal(PPLAYER p);

/// @brief Written by: Brooke Cronin
/// @param p (PPLAYER)
/// @return (void)
void calculateUpperBonus(PPLAYER p);

/// @brief Written by: Brooke Cronin
/// @param p (PPLAYER)
/// @return (void)
void calculateUpperTotal(PPLAYER p);

/// @brief Written by: Brooke Cronin
/// @param p (PPLAYER)
/// @return (void)
void calculateLowerTotal(PPLAYER p);

/// @brief Written by: Brooke Cronin
/// @param p (PPLAYER)
/// @return (void)
void calculateGrandTotal(PPLAYER p);

/// @brief Written by: Brooke Cronin
/// @param p (PPLAYER)
/// @return (void)
void calculateFinalTotalsAndBonuses(PPLAYER p);

/// @brief Written by: Brooke Cronin
/// @param arrayOfPlayers (PLAYER*)
/// @param numberOfPlayers (int)
/// @return (bool)
bool isGameDone(PLAYER* arrayOfPlayers, int numberOfPlayers);

/// @brief Written by: Brooke Cronin
/// @param arrayOfPlayers (PLAYER*)
/// @param numberOfPlayers (int)
/// @param currentWinnerIndexes (int**)
/// @return (void)
void whoWon(PLAYER* arrayOfPlayers, int numberOfPlayers, int** currentWinnerIndexes);
