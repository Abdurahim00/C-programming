#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{

    if(argc != 2){

        printf("Only 1 arg allowed");
        return 1;
    }

    unsigned int packedByte = strtol(argv[1], NULL, 16);

    unsigned int engine_on = (packedByte >> 7) & 1;


    /* code */
    return 0;
}
