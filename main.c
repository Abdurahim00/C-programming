#include <stdio.h>
#include <stdlib.h>


int matrix1[4][4], matrix2[4][4], sum[4][4];
int rows, cols;

int main() {
    printf("Input the size: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 1 || cols <= 1 || rows > 4 || cols > 4) {
        printf("Invalid size.\n");
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
                printf("Input elements of matrix 1: ");

           if(scanf("%d", &matrix1[i][j]) != 1){
                printf("Invalid input\n");
                return 0; // Exit if the input is not a number
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
                printf("Input elements of matrix 2: ");

            if (scanf("%d", &matrix2[i][j]) != 1) {
                printf("Invalid input\n");
                return 0; // Exit if the input is not a number
            }
        }
    }

    // Calculate the sum of matrix1 and matrix2
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the sum matrix
    printf("The sum is: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
            if (j == cols - 1) {
                printf("\n");
            }
        }
    }

    return 0;
}
