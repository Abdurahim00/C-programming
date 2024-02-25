#include <stdio.h>


int main(int argc, char const *argv[])
{

int number;

do
{  printf("\nEnter a number between 1-5: ");
scanf("\n%d", &number);
    if(number == 1){
        printf("Hello 1");
    }
    
    if(number == 2){
        printf("Hello 2");
    }
    
    if(number == 3){
        printf("Hello 3");
    }
    
    if(number == 4){
        printf("Hello 4");
    }
    
    if(number == 5){
        printf("Hello 5");
    }
   
} while (number > 0 && number <= 5);

    return 0;
}
