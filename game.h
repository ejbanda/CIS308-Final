
#include "types.h"

#ifndef game_h
#define game_h

typedef struct Game{
	GameDB GameData;
	player Players[2];
	Judge judge;
	GameStatus Status;
}Game;

//Create database for answers.
void * createAnswers(GameDB);

//Create database for questions.
void * createQuestions(GameDB);

// Get the name of the players.
void * getPlayerNames(player[]);

//Populate the hands of both players.
void * populateHands(GameDB, player[]);

//Current status of the game. Judge will have scores of both players.
GameStatus * currentStatus(Judge);

void * scoreRound(Judge, player[]);


#endif