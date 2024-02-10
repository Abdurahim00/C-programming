// include nesseccarry libraries
#include <stdio.h>
#include <stdlib.h>


int matrix1[4][4], matrix2[4][4], sum[4][4]; // declaring the arrays with the prescribed size
int rows, cols; // declaring the rows and columns

int main() {
    printf("Input the size: ");
    // If the input we provide for rows and cols is not 2 arguments or rows is less than 1 
    // or columns is less than 1 or rows is more than the array size 4 or cols is more than array size 4
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 1 || cols <= 1 || rows > 4 || cols > 4) {
        printf("Invalid size.\n");
        return 0; // exit
    }

    printf("Input elements of matrix 1: ");
    // loop over the rows
    for (int i = 0; i < rows; i++) {
        // loop over the columns
        for (int j = 0; j < cols; j++) {
            // if our input for matrix 1 is not 1 which means its not a number
            if (scanf("%d", &matrix1[i][j]) != 1) {
                printf("Invalid input\n");
                return 0; // Exit if the input is not a number
            }
        }
    }

    printf("Input elements of matrix 2: ");
    // loop over the rows
    for (int i = 0; i < rows; i++) {
         // loop over the columns
        for (int j = 0; j < cols; j++) {
            // if our input for matrix 2 is not 1 which means its not a number
            if (scanf("%d", &matrix2[i][j]) != 1) {
                printf("Invalid input\n");
                return 0; // Exit if the input is not a number
            }
        }
    }

    // Calculate the sum of matrix1 and matrix2
    // Looping over rows
    for (int i = 0; i < rows; i++) {
        // looping over columns
        for (int j = 0; j < cols; j++) {
            // We add matrix 1 with matrix 2, the sum is our new array
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the sum matrix
    printf("The sum is: \n");
    // we print by looping over rows
    for (int i = 0; i < rows; i++) {
        // also loop over columns
        for (int j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
            // if we reach the end of the columns we print a new line for formating
            if (j == cols - 1) {
                printf("\n");
            }
        }
    }

    return 0; // exit
}
