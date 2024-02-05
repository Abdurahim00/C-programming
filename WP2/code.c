#include <stdio.h>
#include <string.h>

unsigned int hexToDecimal(const char *hex) {
    unsigned int result = 0;
    for (int i = 0; hex[i] != '\0'; i++) {
        result *= 16;
        if (hex[i] >= '0' && hex[i] <= '9') {
            result += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result += 10 + (hex[i] - 'A');
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result += 10 + (hex[i] - 'a');
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hexadecimal number>\n", argv[0]);
        return 1;
    }

    unsigned int packedByte = hexToDecimal(argv[1]);

    // Extract each value using bitwise operations
    unsigned int engine_on = (packedByte >> 7) & 1;
    unsigned int gear_pos = (packedByte >> 4) & 0x07;
    unsigned int key_pos = (packedByte >> 2) & 0x03;
    unsigned int brake1 = (packedByte >> 1) & 1;
    unsigned int brake2 = packedByte & 1;

    // Print the extracted values
    printf("Name       Value\n");
    printf("----------------\n");
    printf("engine_on  %u\n", engine_on);
    printf("gear_pos   %u\n", gear_pos);
    printf("key_pos    %u\n", key_pos);
    printf("brake1     %u\n", brake1);
    printf("brake2     %u\n", brake2);

    return 0;
}
