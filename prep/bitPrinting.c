#include <stdio.h>
#include <stdint.h>


void print_bin(unsigned int value);
uint16_t make_16bit(uint8_t least_significant, uint8_t most_significant);

uint16_t make_16bit(uint8_t least_significant, uint8_t
                                                   most_significant)
{
       uint16_t most_right = most_significant << 8;
       uint16_t sum = most_right | least_significant;

       return sum;
}

int main(int argc, char const *argv[])
{

    print_bin(43);
    printf("\n");
    print_bin(make_16bit(7, 1)); 
    return 0;
}
void print_bin(unsigned int bits)
{

    for (int i = 0; i < 32; i++) // loop over the 32 bits
    {
        int bit = (bits >> (31 - i)) & 1; // we shift the bits to the right 31-i and mask with 1
        printf("%d", bit);

        if (i % 8 == 7 && i != 31) // every 8th bit print .
        {
            printf(".");
        }
    }
}

