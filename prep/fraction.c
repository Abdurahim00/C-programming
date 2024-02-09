#include <stdlib.h>
#include <stdio.h>

int addFraction(int a, int c, int b, int d){
    if(a>0 && c > 0 && b > 0 && d > 0){
            int sum = (a*d)/(b*d)+(c*b)/(d*b);
    return sum;

    }
    printf("No negative values allowed");
   return 1;
}
int subFraction(int a, int c, int b, int d){
  if(a>0 && c > 0 && b > 0 && d > 0){
            int sum = (a*d)/(b*d)-(c*b)/(d*b);
    return sum;

    }
    printf("No negative values allowed");
   return 1;

}
int mulFraction(int a, int c, int b, int d){

    if(a>0 && c > 0 && b > 0 && d > 0){
            int sum = (a/b)*(c/d);
    return sum;

    }
    return 0;

}

int main(int argc, char const *argv[])
{

printf("%d", addFraction(100,2,3,4));
printf("\n");
printf("%d", subFraction(10,2,3,4));
printf("\n");
printf("%d", subFraction(10,2,3,4));
printf("\n");

    return 0;
}
