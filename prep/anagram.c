#include <stdio.h>
#include <string.h>

void anagram(char *string1, char *string2, int size1, int size2) {
    if (size1 != size2) {
        printf("They are not anagrams\n");
        return;
    }

    int count[256] = {0}; // Assuming ASCII

    // Count characters in string1
    for (int i = 0; i < size1; i++) {
        count[(unsigned char)string1[i]]++;
    }

    // Subtract counts for characters in string2
    for (int i = 0; i < size2; i++) {
        count[(unsigned char)string2[i]]--;
        if (count[(unsigned char)string2[i]] < 0) {
            printf("%s and %s are not anagrams\n", string1, string2);
            return;
        }
    }

    // If all counts are zero, the strings are anagrams
    printf("%s and %s are anagrams\n", string1, string2);
}

int main() {
    char string1[100];
    char string2[100];

    printf("Enter first string: ");
    scanf("%99s", string1); // Corrected to prevent buffer overflow

    printf("Enter second string: ");
    scanf("%99s", string2); // Corrected to prevent buffer overflow

    int size1 = strlen(string1);
    int size2 = strlen(string2);
    anagram(string1, string2, size1, size2);

    return 0;
}
