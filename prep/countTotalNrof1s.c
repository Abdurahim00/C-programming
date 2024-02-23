#include <stdio.h>


int main(int argc, char const *argv[])
{
    int number;
    int count1 = 0;
    int count0 = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    int totalBits = sizeof(number)*8;
    int processedBits = 0;

    while(number !=0 || processedBits < totalBits){

        if(number & 1){
            count1++;
        }
         else{
            count0++;
            
            
        }
        number = number >> 1;
        processedBits++;
    }


    printf("Output number of ones: %d\n", count1);
    printf("Output number of zeros: %d", count0);

    /* code */
    return 0;
}