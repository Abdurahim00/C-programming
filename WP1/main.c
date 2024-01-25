// Include section
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // If now argument is provided we print the line below
    if (argc != 2) {
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        return 0;
    }

// If we provide something
if (argc > 1){
    // We check if the argument is a valid decimal number
    // Iterating over each character in to check if its a digit and if its not null '\0'
    for (int i = 0; argv[1][i] != '\0'; i++) { 
        // If we encounter something thats not a digit we print error. 
        if (!isdigit(argv[1][i])) {
            printf("Error: Invalid number.\n");
           
        }}
    }

    // Convert the argument to an integer
    int number = atoi(argv[1]);

    printf("Number: %d\n", number);

    // Find the highest bit set in the number
    unsigned int mask = 0;
    // If the number is not zero
    if (number != 0) {
     mask = 1; // we assign mask to 1
     // as long as mask is less or equals to the number (which is our input)
     while (mask <= number) {
        mask <<= 1; // we left shift mask by 1
     }
      mask >>= 1; // we left shift mask by 1
    }  

    // Handle the case where the number is 0
    if (number == 0) {
        mask = 1; 
    }

    printf("Binary: 0b");
    int numberOfOnes = 0; // declare a counter to nr of ones
    int numberOfZeros = 0;// declare a counter to nr of zeros
    int finder = 0; // every time we find a 1 we increment
    // as long as mask is 1 we continue
    while (mask) {
        // if the input number is also 1 we print 1
        if (number & mask) {
            printf("1");
            // and we increment nr of ones
            numberOfOnes++;
            // becuase we found a match finder becomes 1
            finder = 1;
            // If we had already found 1 before we print 0
        } else if (finder) {

            printf("0");
            // and increment nr of zeros
            numberOfZeros++;
        }

        mask >>= 1; // left shift and assign 1
    }

    // If the number is 0, print 0
    if (!finder) {
        printf("0");
    }
    
    printf("\n");
    printf("Number of 0s: %d", numberOfZeros);
    printf("\nNumber of 1s: %d", numberOfOnes);
    printf("\n");

    return 0; // exit
}