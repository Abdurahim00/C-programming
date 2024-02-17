#include <stdio.h>
#include <string.h>



void count(char *text, int *countVowels, int *countConsonants)
{char vowels[] = 
{
   "aeiouy"
};

char consonants[] = {
    "bcdfghjklmnpqrstvwxz"
};
 *countVowels = 0;
    *countConsonants = 0;
    int size = strlen(text);
    for (int i = 0; i < size; i++)
    { char c = text[i];
        if (strchr(vowels, c))
        {
            (*countVowels)++;
        }else if(strchr(consonants, c)){

            (*countConsonants)++;
        }
    

      
    }return 0;

}

int main(int argc, char const *argv[])
{
    char text[100];
    int countVowels = 0;
    int countConsonants = 0;

    printf("Enter a string: ");
    scanf("%s", text);

   count(text, &countVowels, &countConsonants);
    
    printf("The number of vowels is %d and consonants are %d\n", countVowels, countConsonants);

    return 0;
}
