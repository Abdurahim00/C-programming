#include <stdio.h>
#include <stdlib.h>

int stringLength(char *string)
{

    int length = 0;

    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

char*stringCopy(char *string1, char *string2)
{
    int length1 = stringLength(string1);
    int length2 = stringLength(string2);

    char *concatenated = malloc(length1 + length2);
    if (concatenated == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }


    for (int i = 0; i < length1; i++)
    {
        concatenated[i] = string1[i];
    }
    for (int i = 0; i < length2; i++)
    {
        concatenated[length1 + i] = string2[i];
    }
    return concatenated;
}

int main(int argc, char const *argv[])
{

    char string1[100];
    char string2[100];

    printf("Input string1: ");
    scanf("%s", string1);

    printf("\nInput string2: ");
    scanf("%s", string2);

    char *concatenaded = stringCopy(string1, string2);
    if (concatenaded != NULL)
    {
        printf("Concatenated string: %s\n", concatenaded);
        free(concatenaded);
    }

    return 0;
}
