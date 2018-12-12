#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Player.h"

char answers[1048][200];
char questions[275][500];

char p1Deck[5][200];
char p2Deck[5][200];
void createAnswers(){
  FILE *file = fopen("answers.txt" ,"r");
  char buff[200];
  int i = 0;
  while(fgets(buff, 200, file) != NULL){
    strcpy(answers[i], buff);
    i++;
  }
  fclose(file);
  
}

void createQuestions(){
  FILE *file = fopen("questions.txt" ,"r");
  char buff[500];
  int i = 0;
  while(fgets(buff, 500, file) != NULL){
    strcpy(questions[i], buff);
    i++;
  }
  fclose(file);
  
}


void threePlayer(char * first, char * second){

  player playerOne, playerTwo;
  //playerOne.name = name1;
  strcpy(playerOne.name, first);
  strcpy(playerTwo.name, second);


  srand(time(NULL));
  while(playerOne.score < 5 && playerTwo.score < 5){
  int randomQuestion = rand() % 275;
  int player1Choice, player2Choice, judgeChoice;
  
  for(int count = 0; count < 5; count++){
    int rand1 = rand() % 1048;
    int rand2 = rand() % 1048;

    strcpy(p1Deck[count], answers[rand1]);
    strcpy(p2Deck[count], answers[rand2]);
  }

  printf("\n%s pick your card\n", second);
  printf("%s", questions[randomQuestion]);
  for(int count = 0; count < 5; count++){
    printf("%d. %s", count, p1Deck[count]);
  }
  scanf("%d", &player1Choice);

  printf("\n%s pick your card\n", second);
  printf("%s", questions[randomQuestion]);
  for(int count = 0; count < 5; count++){
    printf("%d. %s", count, p2Deck[count]);
  }
  scanf("%d", &player2Choice);

  printf("\n%s", questions[randomQuestion]);
  printf("1. %s", p1Deck[player1Choice]);
  printf("2. %s", p2Deck[player2Choice]);

  scanf("%d", &judgeChoice);

  if(judgeChoice == 1)
    playerOne.score += 1;
  else if(judgeChoice == 2)
    playerTwo.score += 1;

  system("clear");
  
}

if(playerOne.score == 5)
  printf("Player 1 won the game.\n");
else
  printf("Player 2 won the game.\n");

printf("Player one score:  %d\n", playerOne.score);
printf("Player two score:  %d\n", playerTwo.score);






}
int main(){
    createQuestions();
    createAnswers();

    char name1[10];
    char name2[10];




    printf("Player 1 enter your name:  ");
    //scanf("%s", &name);  - deprecated
    scanf("%s", name1);
    printf("Player 2 enter your name:  ");
    scanf("%s", name2);

    threePlayer(name1, name2);
    
	return 0;
}