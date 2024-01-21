#include <stdio.h>




int main(int argc, char const *argv[])
{
int array[] = {1,2,3,4,5,7};

int *pointer = array;

int length = sizeof(array)/sizeof(array[0]);


for ( int i = 0; i < length; i++)
{
    printf("the value is %d\n", *pointer);
    pointer++;
}


}
