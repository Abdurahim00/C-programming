#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char const *argv[])
{   int number=0;
    if (argc != 2)
    {

        printf("provide 1 argument");
        return 1;
    }
    int length = strlen(argv[1]);

    for (int i = 0; i < length; i++)
    {
        
        number++;
    }
    printf("%d", number);
    
    


    return 0;
}