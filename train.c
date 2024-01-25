#include <stdio.h>



void customshift(int *ptrNum, int *ptrShifts, char *ptrDirection){

}



int main(int argc, char const *argv[])
{

    int number;
    int *ptrNum = &number;
    int shifts;
    int *ptrShifts = &shifts;
    char direction;
    char *ptrDirection = &direction;
    printf("Enter a number: ");
        scanf("%d", ptrNum);
    printf("Enter number of shifts: ");
        scanf("%d", ptrShifts);
    printf("Enter which direction L or R: ");
        scanf(" %cd", ptrDirection);
    customshift(ptrNum, ptrShifts, ptrDirection);

    return 0;
}
