// Include all sections
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Checks if any input is provided and if its a decimal or if its not negative
int isDecimal(const char *str) {
    // if it doesnt point at anything or if the value is negative we return 0
    if (str == NULL) { 
        return 0; // exit
    }
    while (*str) { // As long as the input is not a digit then exit return 0
        if (!isdigit((unsigned char)*str)) {
            return 0; // exit
        }
        str++; // incerement the pointer that points at the input string
    }
    return 1; // error
}

// This function counts the amount of bits
int countBit(int bits) {
    int count = 0, i; // we set count and i to 0 
    if (bits == 0) return 8; // If the number is 0, exit as no bits are needed

    for (i = 0; i < 32; i++) { // Iterate through each bit position (up to 32 bits)
        if ((1 << i) & bits) // Check if the bit at position 'i' is set, shifting bits
            count = i; // Update count to the current bit position
    }
       
    return count + 1 > 8 ? count + 1 : 8; // Return the position of the highest set bit plus one
}



// Inspiration from https://www.scaler.com/topics/decimal-to-binary-in-c/
// The function for converting decimal to its binary representation
// It takes in the number we provided which then converts to a char binarystr
void binaryConversion(long number, char *binaryStr, int bits) {
    int index = 0;

    // Fill the string with leading zeros based on the required number of bits
    for (int i = bits - 1; i >= 0; i--) {
        binaryStr[index++] = (number & (1L << i)) ? '1' : '0'; 
    }

    binaryStr[index] = '\0'; // Null-terminate the string
}



int main(int argc, char const *argv[]) {

    // if we dont provide one argument we return 2
    if (argc != 2) {
        printf("provide a number for conversion\n");
        return 2; // return error
    }
    // we check if the string is equal to -h and then we print and exit
    if (strcmp(argv[1], "-h") == 0) {
        printf("Enter a decimal number to convert to its binary and hexdecimal representation.\n");
        return 0; // exit
    }
    // if the input we provided is a decimal (we use the function i set up above)
    if (isDecimal(argv[1])) {
        long number = strtol(argv[1], NULL, 10); // Convert the input string to a long integer with base 10.



        int bits = countBit(number); // Use countBit to determine the number of bits required
        char binaryStr[33]; // declaring a char array to count up to 32 bit
        binaryConversion(number, binaryStr, bits); // using the function to convert with all arguments required


       printf("%s", binaryStr);

        printf("\n");
        // exit
        return 0;
    } else {

        printf("Unsuccessful conversion\n");
        // return 2 and exit
        return 2;
    }
}