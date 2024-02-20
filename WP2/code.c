#include <stdio.h>
#include <stdlib.h>

// Function to pack the bits and print the result
void packBits(unsigned int engine_on, unsigned int gear_pos, unsigned int key_pos, unsigned int brake1, unsigned int brake2) {
    // Validate input ranges
    if(engine_on > 1 || gear_pos > 4 || key_pos > 2 || brake1 > 1 || brake2 > 1) {
        printf("Input values are out of range.\n");
        return;
    }
    // Pack the bits into a single byte
    unsigned char packedByte = (engine_on << 7) | (gear_pos << 4) | (key_pos << 2) | (brake1 << 1) | brake2;

    // Print the packed byte in hexadecimal format
    printf("Packed byte: %02X\n", packedByte);
}

int main(int argc, char *argv[]) {
    if(argc != 6) {
        printf("Usage: %s engine_on gear_pos key_pos brake1 brake2\n", argv[0]);
        return 1;
    }

    // Convert arguments to unsigned integers and call packBits
    unsigned int engine_on = atoi(argv[1]);
    unsigned int gear_pos = atoi(argv[2]);
    unsigned int key_pos = atoi(argv[3]);
    unsigned int brake1 = atoi(argv[4]);
    unsigned int brake2 = atoi(argv[5]);

    packBits(engine_on, gear_pos, key_pos, brake1, brake2);

    return 0;
}