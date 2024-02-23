#include <stdio.h>




int main(int argc, char const *argv[])
{   
    int input[5];
    char grade;
    int total = 0;
    float average;
    printf("Input marks of five subjects:");
    for (int i = 0; i < 5; i++)
    {  
        scanf("%d", &input[i]);
        total += input[i];

    }
    average = total/5;
    
  

    if(average >= 90){
        grade= 'A';

    }
    else if(average >= 80){
        grade= 'B';

    }
    else if(average >= 70){
        grade= 'C';

    }
    else if(average >= 60){
        grade= 'D';

    }
    else if(average >= 40){
        grade= 'E';

    }
    else{
        grade= 'F';

    }

    printf("Percentage = %0.2f ", average);
    printf("Grade = %c ", grade);
    return 0;
}
