#include <stdio.h>

int main(int argc, char const *argv[])
{
    int bit;
    int number;
    printf("Input a number: ");
    scanf("%d", &number);

    printf("Input nth bit to toggle: ");
    scanf("%d", &bit);

    int mask = 1 << bit;

    int toggledNumber = number ^ mask;

    printf("After toggling nth bit: %d (in decimal)\n", toggledNumber);

    return 0;
}
