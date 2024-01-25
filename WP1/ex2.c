#include <stdio.h> // Include the standard input/output library for basic I/O operations
#include <string.h>// Include the string library for functions related to string handling
#include <stdlib.h>// Include the standard library for general purpose functions, 
#include <ctype.h>// This is so i can access the uppercase and lowercase


void shift(int shifts) {
    // array of 100 slots for now
    char string[100]; 

    printf("Enter a text: \n");

    // User enters a string with the prescribed size and its standard input
    fgets(string, sizeof(string), stdin); 

    // loop over the string, character by character
    for (int i = 0; i < strlen(string); i++) {

        // If all the characters are from the alphabet
        if (isalpha(string[i])){
            
            char offset = isupper(string[i]) ? 'A' : 'a'; // Condition checks if each character is upper or lower

            int alphaIndex = string[i] - offset; // Converts to int in the 0-25 range
            int shiftedIndex = (alphaIndex + shifts) % 26; // applies shift and wrap around
            string[i] = shiftedIndex + offset; // It gets converted back to ASCII
    }}
    printf("Shifted text: %s\n", string);
}

int main(int argc, char *argv[]) {
   
   // used a while so the program doesnt exit until ctrl z
   while (argc > 1)
   {
     shift(atoi(argv[1])); // Triggers the function and converts argv to int

   }{
        printf("Please provide a shift value.\n");
}
    return 0;
}