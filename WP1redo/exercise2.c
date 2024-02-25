#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void shifts(int shifts){

    char string[100];
printf("Enter a word or ctrl z to end\n");

    fgets(string, sizeof(string), stdin);

    for (int i = 0; i < strlen(string); i++)
    {
        
        if(isalpha(string[i])){
            char offset = isupper(string[i]) ? 'A' : 'a';
            int alphaIndex = string[i] - offset;
            int shiftedIndex = (alphaIndex + shifts) % 26;
         string[i] = shiftedIndex + offset;
        }
    }
    printf("Shifted text: %s\n", string);

}

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("Only 1 argument allowed");
    }

    int shift = atoi(argv[1]);
    int c;

    

    while (argc > 1)
    {
        shifts(shift);

    }
    
    return 0;
}
