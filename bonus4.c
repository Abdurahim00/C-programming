#include <stdio.h>
#include <string.h>



void swap(char *x, char *y){

    char temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

void permuation(char *str, int start, int end){

    int count;
    if(start == end){
        printf("%s", str);
    }
    else{
        for(count = start; count<=end; count++){

            swap((str + end), (str + count));
            permuation(str, count + 1, end);
            swap((str+start), (str + count));
        } 
    }
}



int main(int argc, char const *argv[])
{

    if (argc != 2)
    {

        printf("provide only 1 input");
    }


   char *inputString = argv[1];
    int n = strlen(inputString);
    if (n > 10) {
        printf("The input string exceeds the limit of 10 characters.\n");
        return 1;
    }

    return 0;
}
