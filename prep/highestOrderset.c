#include <stdio.h>

int main() {
    int number;
    printf("Input any number: ");
    scanf("%d", &number);

    if (number == 0) {
        printf("No set bits. The number is 0.\n");
        return 0;
    }

    int position = 0; // To track the position of the highest set bit
    int tempNumber = number; // Temporary variable to hold the number for manipulation

    while (tempNumber != 0) {
        position++; // Increment position as we're about to shift
        tempNumber = tempNumber >> 1; // Shift the bits to the right
    }

    printf("Highest order set bit in %d is %d.\n", number, position);
    return 0;
}
