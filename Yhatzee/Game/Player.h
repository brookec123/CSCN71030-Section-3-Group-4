/// File Name: Player
/// File Author: Brooke Cronin
/// Course Code: CSCN71030 Group 4
/// Description: 
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LENGTH 51 // including '/0' character at end
#define MAX_NUMBER_OF_GAMES 10
#define NUMBER_OF_ITEMS_TO_SCORE_FOR 19 // includes totals, bonuses, and individual parts of the sections

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Player
{
	char* name;
  	int currentGameNumber; // SUBTRACT 1 FOR INDEX
	int** currentScore;
	int** canScore;
	// include file name where player's info is stored????

} PLAYER, *PPLAYER;

/// @brief Written by: Brooke Cronin
/// @param n (char*)
/// @return (PLAYER)
PLAYER CreateNewPlayer(char* n);

/// @brief Written by: Brooke Cronin
/// @param p (PLAYER)
/// @return (int)
int GetCurrentGameNumber(PLAYER p);

/// @brief Written by: Brooke Cronin
/// @param p (PPLAYER)
/// @param gameNumber (int)
/// @return (void)
void SetCurrentGameNumber(PPLAYER p, int gameNumber);

/// @brief Written by: Brooke Cronin
/// @param p (PLAYER)
/// @return (bool)
bool IsGameDoneForPlayer(PLAYER p);

/// @brief Written by: Brooke Cronin
/// @param p (PPLAYER)
/// @return (void)
void DestroyPlayer(PPLAYER p);
