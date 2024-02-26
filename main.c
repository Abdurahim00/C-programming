// include all sections

#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 5 // 5 input strings
#define MAX_LENGTH 1000 // max length 1000

// function to find and remove the shortest string
void findAndRemoveShortest(char arr[MAX_STRINGS][MAX_LENGTH], int *size) {
    int shortestLength = strlen(arr[0]); // declare shortestlength to be the first string in the array
    int index = 0; // declare index to 0 to keep track

    // Find the index of the shortest string
    for (int i = 1; i < *size; i++) {
        int currentLength = strlen(arr[i]); // the length of the string at position i in the array
        if (currentLength < shortestLength) { // if the string length is shorter than the first string in the array
            shortestLength = currentLength; // we make current the shortest
            index = i; // and we set index to i so we can keep track of its position
        }
    }

    printf("Shortest string removed: %s\n", arr[index]);

    // Remove the shortest string by shifting the rest
    for (int i = index; i < *size - 1; i++) {
        strcpy(arr[i], arr[i + 1]); // we copy over to next postion
    }

    *size -= 1; // Decrease the size of the array
}

int main() {
    // declare an array of max input 5 and 1000 length
    char strings[MAX_STRINGS][MAX_LENGTH];
    int currentSize = MAX_STRINGS; // current size 5

    // loop over the array
    for (int i = 0; i < MAX_STRINGS; i++) {
        // standard input with the maximum size 
        fgets(strings[i], MAX_LENGTH, stdin);
        strings[i][strcspn(strings[i], "\n")] = 0; // Remove newline character
    }

    // call the function
    findAndRemoveShortest(strings, &currentSize);

    printf("\nArray after removal:\n");
    // loop over the array after we removed the shortest
    for (int i = 0; i < currentSize; i++) {
        printf("%s\n", strings[i]);
    }

    return 0; // exit
}
