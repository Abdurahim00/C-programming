#include <stdio.h>
#include <string.h>


#define MAX 10

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}



void permute(char *c, int start, int end){

    int i;
    if(start == end){
        printf("The permutations %s\n", c);
    }else{
    for (i = start; i <= end; i++)
    {
        swap((c + start), (c + i));
        permute(c, start +1, end);
        swap(c+start, c +i);

    }}
    



}





int main(int argc, char const *argv[])
{

    char arr[MAX];

    printf("input ur string: ");
    scanf("%s", arr);
    int length = strlen(arr);

    permute(arr, 0, length-1);

    return 0;
}
