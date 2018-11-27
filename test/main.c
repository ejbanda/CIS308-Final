#include <stdio.h>


void createBlack(){

   
   FILE *file = fopen ( "answers.txt", "r" );
   if ( file != NULL )
   {
      char line [ 128 ]; /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
         printf("%s", line); /* write the line */
      }
      fclose ( file );
   }
   
}	


int main(){
	createBlack();
	return 0;
}