#include <stdio.h>


int add(int *first, int *second){


return *first+ *second;


}


int main(int argc, char const *argv[])
{
    int first;
    int second;


    printf("Input the first number :");
    scanf("%d", &first);

    printf("Input the second number :");
    scanf("%d", &second);
        int new = add(&first, &second);

    printf("The sum of the entered numbers is: %d", new );
    return 0;
}
