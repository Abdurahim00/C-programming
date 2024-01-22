#include <stdio.h>
#include <stdlib.h>

// inspiration from https://www.prepbytes.com/blog/c-programming/c-program-to-convert-decimal-numbers-to-binary-numbers/ 
// function to convert decimal to binary, takes in the number we provide
long binaryConversion(long number){

long count = 1;
int rest;
long binaryNum = 0;

while(number!= 0){
    rest = number %2; // thats how we calculate the rest with modulo 2 for binary
    number = number /2;
    binaryNum = binaryNum + rest * count;
    count = count * 10;
}
return binaryNum;
}

int main(int argc, char const *argv[]){

if(argc == 2){
    long number = strtol(argv[1], NULL, 10); // to convert the input from string to long
    long final = binaryConversion(number);

printf("%ld ", final);
return 0;
} else{
        printf("Unsuccessful conversion");

        return 2;
}


}
