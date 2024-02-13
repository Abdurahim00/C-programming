// Include sections
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Efficiently copies a string from str to copyOfstr
void copyString(char *str, char *copyOfstr)
{
    int len = strlen(str); // Calculate length once for efficiency
    // Copy each character
    for (int i = 0; i < len; i++)
    { // copy over to copyOfstr
        copyOfstr[i] = str[i];
    } // Null-terminate the copied string
    copyOfstr[strlen(str)] = '\0';
}

int main(int argc, char const *argv[])
{

    char str[21];       // initialize an array
    char copyOfstr[21]; // another array for the copies

    printf("Enter a string: ");
    scanf("%20s", str); // input to the str array with 20 char

    strcpy(copyOfstr, str); // we copy over from str to copyOfstr array
    printf("Copied string: %s\n", copyOfstr);

    memset(copyOfstr, 0, sizeof(copyOfstr)); // reset for testing the copystring function

    copyString(str, copyOfstr); // we copy from copyOfstr to str
    printf("Copied string (copyString function): %s\n", copyOfstr);

    return 0; // exit
}
