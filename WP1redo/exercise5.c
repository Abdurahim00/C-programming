#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include for seeding random number generator

#define MAX 100 // Defines the maximum number of values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------
void create_random(int *tab);
void count_frequency(int *tab, int *freq);
void draw_histogram(int *freq);

// ------ Function definitions ----------
void create_random(int *tab) {
    for(int i = 0; i < MAX; i++) {
        tab[i] = rand() % (MAXNUMBER + 1); // Generates random number between 0 and MAXNUMBER
    }
}

void count_frequency(int *tab, int *freq) {
    for(int i = 0; i <= MAXNUMBER; i++) {
        freq[i] = 0; // Initialize frequencies to 0
    }

    for(int i = 0; i < MAX; i++) {
        freq[tab[i]]++; // Increment frequency count for each number
    }
}

void draw_histogram(int *freq) {
    for(int i = 0; i <= MAXNUMBER; i++) {
        if(freq[i] > 0) { // Only print numbers with a frequency > 0
            printf("%d ", i);
            for(int j = 0; j < freq[i]; j++) {
                printf("x");
            }
            printf("\n");
        }
    }
}

// ------ Main --------------------------
int main(void) {
    srand(time(NULL)); // Seed the random number generator

    int table[MAX];
    int frequency[MAXNUMBER + 1] = {0}; // Initialize all elements to 0

    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);

    return 0;
}
