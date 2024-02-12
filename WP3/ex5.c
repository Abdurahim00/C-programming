#include <stdio.h>

#define MAX 10

int main(int argc, char const *argv[])
{
    int array[MAX];
    int *ptrArray = array;

    srand(time(0));


    for (int i = 0; i < MAX; i++)
    {
        array[i] = (rand() % 99) +1;
    }

        printf("The value of the address of the array (pointer) is: %p\n", (void*)array);
    printf("First integer in the array is (array[0]): %d\n", array[0]);
    printf("The last integer in the array is: %d\n", array[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(int));
    printf("The size of the whole array in bytes is: %lu\n", sizeof(array));

    
    printf("Array values and double the values: \n");
    for (int i = 0; i < MAX; i++)
    {
       printf("Value %d, Double: %d\n", *ptrArray, *ptrArray *2);
       ptrArray++; 
    }
    
    /* code */
    return 0;
}
