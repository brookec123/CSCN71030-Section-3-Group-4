#include "UI.h"
#include "GameLogic.h"

void printMainMenu(char* userInput, int numOfPlayers) {

      printf("Number of players: %d", numOfPlayers);

      printf("\n\nWelcome to Yhatzee! This is a console based version of the beloved classic dice game... known as Yahtzee.\n");
      printf("\n=================================================================================================================\n");

      printf("Menu:\n\n");
      printf("1. Play Game.\n");
      printf("2. View Rules.\n");
      printf("3. Exit Game.\n");
      printf("\nChoice: ");

      int choice = 0;

      scanf_s("%d", &choice);

      switch (choice)
      {

      case 1:

            // TODO: Play game

            break;

      case 2:

            printRules();

            break;

      case 3:


            break;

      default:

            fprintf(stderr, "ERROR: Invalid menu selection. ");

            printMainMenu(userInput, numOfPlayers);

            break;
      }


}

void printRules() {

      //TODO: Game RUles

}

void printSubMenu(char* userInput) {



}

void printScorecard(char* userInput) {



}
