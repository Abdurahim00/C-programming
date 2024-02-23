#include <stdio.h>


int main(int argc, char const *argv[])
{
    
    int number;

    printf("Input any number: ");
    scanf("%d", &number);

    if(number & 1){

        printf("%d is odd\n", number);
    }
    else{
        printf("%d is even\n", number);
    }

    return 0;
}
