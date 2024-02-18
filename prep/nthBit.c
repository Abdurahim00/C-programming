#include <stdio.h>
#include <stdint.h>

void nthBit(int number, int bit){

int mask = 1 << bit;

    if(number & mask){
        printf("%d bit of %d is set (1)\n", bit, number);
    }
    else {
        printf("%d bit of %d is not set (0)\n", bit, number);
    }

}



int main(int argc, char const *argv[])
{

 int number;
 int bit;

 printf("Choose a number: ");
 scanf("%d", &number);

 printf("Choose nth bit: ");
 scanf("%d", &bit);

 nthBit(number, bit);
 
    /* code */
    return 0;
}
