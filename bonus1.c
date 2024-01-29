#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        return 0;
    }

if (argc > 1){
    // We check if the argument is a valid decimal number
    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (!isdigit(argv[1][i])) {
            printf("Error: Invalid number.\n");
           
        }}
    }

    // Convert the argument to an integer
    int number = atoi(argv[1]);

    printf("Number: %d\n", number);

    // Find the highest bit set in the number
    unsigned int mask = 0;
    if (number != 0) {
     mask = 1;
     while (mask <= number) {
        mask <<= 1;
     }
      mask >>= 1;
    }  

    // Handle the case where the number is 0
    if (number == 0) {
        mask = 1;
    }

    printf("Binary: 0b");
    int numberOfOnes = 0;
    int numberOfZeros = 0;
    int finder = 0;
    while (mask) {
        if (number & mask) {
            printf("1");
            numberOfOnes++;
            finder = 1;
        } else if (finder) {
            printf("0");
            numberOfZeros++;
        }

        mask >>= 1;
    }

    // If the number is 0, print 0
    if (!finder) {
        printf("0");
    }
    
    printf("\n");
    printf("Number of 0s: %d", numberOfZeros);
    printf("\nNumber of 1s: %d", numberOfOnes);

    return 0;
}
