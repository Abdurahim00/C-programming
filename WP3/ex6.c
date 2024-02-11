#include <stdio.h>
#include <string.h>
#include <stdint.h>

void copyString(char *str, char *copyOfstr)
{
    for (int i = 0; i < strlen(str); i++)
    {
        copyOfstr[i] = str[i];
    }
    copyOfstr[strlen(str)] = '\0';
}

int main(int argc, char const *argv[])
{

    char str[21];
    char copyOfstr[21];

    printf("Enter a string: ");
    scanf("%20s", str);

    strcpy(copyOfstr, str);
    printf("Copied string: %s\n", copyOfstr);


 memset(copyOfstr, 0, sizeof(copyOfstr)); // reset for testing the copystring function


    copyString(str, copyOfstr);
    printf("Copied string (copyString function): %s\n", copyOfstr);

    return 0;
}
