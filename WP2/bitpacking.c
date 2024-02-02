#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    if (argc != 6)
    {

        printf("cant provide more than 5 arg");
    }

    int engine_on = atoi(argv[1]);
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);

    if (engine_on < 0 || engine_on > 1)
    {
        printf("Error: engine_on must be 0 or 1.\n");

        return 1;
    }

    if(gear_pos < 0 || gear_pos > 7){

         printf("Error: gear_pos must be 0 or 7.\n");

        return 1;
    }
    if(key_pos < 0 || key_pos > 3){

         printf("Error: key_pos must be 0 or 7.\n");

        return 1;
    }

     if (brake1 < 0 || brake1 > 1)
    {
        printf("Error: brake1 must be 0 or 1.\n");

        return 1;
    }
     if (brake2 < 0 || brake2 > 1)
    {
        printf("Error: brake2 must be 0 or 1.\n");

        return 1;
    }

    /* code */
    return 0;
}
