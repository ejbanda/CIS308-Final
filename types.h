#ifndef types_h
#define types_h
typedef struct player{
	int score;
	char name[10];
	int choice;
	Hand currentHand;
}player;

typedef struct GameDB{
	Card Answers[1048];
	Card Questions[275];
	int AnswersUsed[50];
	int QuestionsUsed[50];
}GameDB;

typedef struct Card{
	char info[200];
	int index;
}Card;

typedef struct Hand{
	Card hand[5];
}Hand;

typedef struct Judge{
	int Choice;
	int P1Score;
	int P2Score;
}Judge;

enum GameStatus{Win, OnGoing, Lose};
#endif