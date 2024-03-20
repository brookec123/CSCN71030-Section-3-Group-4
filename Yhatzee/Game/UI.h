#pragma once

#include "GameLogic.h"

#include <stdio.h>

#include <stdlib.h>

typedef struct ui {

      char* userInput;

}UI;

void printMainMenu(char* userInput, int num);

void printSubMenu(char* userInput);

void printScorecard(char* userInput);

void printRules();
