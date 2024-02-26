// include sections

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 6) {
        printf("invalid");
        return 0;
    }

    // validate input values and parse them 
    unsigned int engine_on = atoi(argv[1]);
    unsigned int floor_pos = atoi(argv[2]);
    unsigned int door_pos = atoi(argv[3]);
    unsigned int brake1 = atoi(argv[4]);
    unsigned int brake2 = atoi(argv[5]);

    // check ranges for each input
    if (engine_on < 0 || engine_on > 1 ||
        floor_pos < 0 || floor_pos > 7 ||
        door_pos < 0 || door_pos > 3 ||
        brake1 < 0 || brake1 > 1 ||
        brake2 < 0 || brake2 > 1) {
        printf("invalid");
        return 0;

    }

    // Pack the bits into a single byte
    unsigned char packedByte = (engine_on << 7) | (floor_pos << 4) | (door_pos << 2) | (brake1 << 1) | brake2;

    // Print the packed byte in hexadecimal format
    printf("0x%02X\n", packedByte);

    return 0;
}