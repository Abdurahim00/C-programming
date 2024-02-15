// Include all sections
#include <stdio.h>
#include <string.h>
#define MAX 10 // the array input that can hold 10 char

// this function basically just swaps 2 char
void swap(char *x, char *y) {
    // initialize a temp char to x
    char temp = *x;
    // x becomes y
    *x = *y;
    // y becomes temp which is x
    *y = temp;
}


void permutation(char *a, int start, int end) {
    int i; // declare i
    if (start == end)  // if the start pointer and end pointer meet we print the char at then new position
    
        printf("%s\n", a);
    else {
        // else we loop while start iterates until end
        for (i = start; i <= end; i++) {
            // we call swap and set the a pointer as start pointer
            swap((a+start), (a+i)); // Swap the current index with the loop index
            permutation(a, start+1, end); // Recurse with the left index moved
            swap((a+start), (a+i)); // Swap back to backtrack
        }
    }
}

int main(int argc, char const *argv[]) {
        char str[MAX]; // initialize the array that holds all the permutations

// if there is 2 arguments its invalid
    if(argc != 2) {
        printf("invalid\n");
    }
    // else if the lenght of the string is more or equals to 10 its invalid
    else if(strlen(argv[1]) >= MAX) {
        printf("invalid\n");
    }
    else{
        // else we copy our input to the array with the MAX-1 size 
    strncpy(str, argv[1], MAX-1);
    str[MAX-1] = '\0'; // Null termination
    int n = strlen(str); // n is the length of the array

    permutation(str, 0, n-1); // we call the permutation method with the array and starting and ending pos
    }
    return 0; // exit
}