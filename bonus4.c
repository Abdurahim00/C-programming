#include <stdio.h>
#include <string.h>
#define MAX 10
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r) {
    int i;
    if (l == r)
        printf("%s\n", a);
    else {
        for (i = l; i <= r; i++) {
            swap((a+l), (a+i)); // Swap the current index with the loop index
            permute(a, l+1, r); // Recurse with the left index moved
            swap((a+l), (a+i)); // Swap back to backtrack
        }
    }
}

int main() {
    char str[MAX]; 
    
    printf("type a string: ");
    scanf("%s", str);
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}
