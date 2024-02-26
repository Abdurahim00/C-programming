#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUMBER 10

int main(int argc, char const *argv[])
{   srand(time(NULL)); 

    int number;
    int random;
    int guesses;
    char playagain;
    bool wantsToPlay;
    
   do{
    random = rand() % 100 + 1;
    wantsToPlay = true;
    guesses = 0;
      while (wantsToPlay && guesses < MAX_NUMBER){  
        printf("Guess a number between 1-100: ");
    scanf("%d", &number);
    
    if (number > 100 ||number < 1){
        printf("Only between 1-100");
        continue;
    }
    guesses++;

    if(number < random){
        printf("Your guess is to low\n");

    }else if(number > random){
           
        printf("Your guess is to high\n");

    }
    else{ 
        printf("You have guessed the correct number with %d guesses\n",guesses);
    wantsToPlay = false;
    break;}
   }


    if(guesses > MAX_NUMBER && number != random){
        printf("You have guessed to much");
    }
   
    printf("Press y if you want to play again");
    scanf(" %c", &playagain);
    }while(playagain == 'y');

    return 0;
    
}
