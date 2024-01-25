#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void game(int *gamecounter); // Updated prototype
void playAgain(bool *again); // Updated prototype

// method that handles game logic, gamecounter is passed as a pointer from main
void game(int *gamecounter) {
    int random_number = rand() % 100 + 1;
    int answer = 0;
    int guesses = 0;

    while (answer != random_number) {
        printf("\nGuess a number between 1-100: ");
        scanf("%d", &answer);
        guesses++;

        if (answer > random_number) {
            printf("Your guess is too high.\n");
        } else if (answer < random_number) {
            printf("Your guess is too low.\n");
        } else {
            printf("You have guessed %d times and your guess is correct.\n", guesses);
            if (*gamecounter == 0) {
                bool again = true;
                playAgain(&again);
                if (!again) {
                    break;
                }
            }
            (*gamecounter)++;
        }
    }
}

void playAgain(bool *again) {
    char play[10];
    printf("Do you want to play again? \n");
    scanf("%s", play);

    if (!(strcmp(play, "yes") == 0 || strcmp(play, "y") == 0 || strcmp(play, "Y") == 0)) {
        *again = false;
    }
}

int main(int argc, char const *argv[]) {
    srand(time(NULL)); // Initialize random number generator only once
    int gamecounter = 0;

    do {
        game(&gamecounter);
    } while (gamecounter < 2);

    return 0;
}
