#include <stdio.h>



int main(int argc, char const *argv[])
{
    int number;
    int count = 0;
    printf("Enter a number: ");
    scanf("%d", &number);


        while(number != 0){
            
           
            if((number & 1)==0){
                count++; 
                number= number>>1;

            }else{
                break;
            }

            }
        printf("Trailing zeros are %d", count);
    
    return 0;
}
