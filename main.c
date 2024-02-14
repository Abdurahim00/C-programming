#include <stdio.h>
#include <string.h>
#define MAX 10
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permutation(char *a, int l, int r) {
    int i;
    if (l == r)
    
        printf("%s\n", a);
    else {
        for (i = l; i <= r; i++) {
            swap((a+l), (a+i)); // Swap the current index with the loop index
            permutation(a, l+1, r); // Recurse with the left index moved
            swap((a+l), (a+i)); // Swap back to backtrack
        }
    }
}

int main(int argc, char const *argv[]) {
        char str[MAX];

    if(argc != 2) {
        printf("invalid\n");
    }

    else if(strlen(argv[1]) >= MAX) {
        printf("invalid\n");
    }
    else{
    strncpy(str, argv[1], MAX-1);
    str[MAX-1] = '\0';
    int n = strlen(str);

    permutation(str, 0, n-1);}
    return 0;
}