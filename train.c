#include <stdio.h>



void customshift(int *ptrNum, int *ptrShifts, char *ptrDirection){

 
    
        if(*ptrDirection =='L'){
          for (int i = 0; i < *ptrShifts; i++)
          {
            *ptrNum = *ptrNum*2;
          }}
          else if (*ptrDirection == 'R')
          {
            for (int i = 0; i < *ptrShifts; i++)
            {
                *ptrNum = *ptrNum/2;
            }
            
          }
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
        scanf(" %c", ptrDirection);
    customshift(ptrNum, ptrShifts, ptrDirection);
        printf("%d", *ptrNum);

    return 0;
}
