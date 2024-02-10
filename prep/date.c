#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{   int year;
int months;
int day;
    printf("Enter a date: ");
    scanf("%d %d %d", &months,&day, &year);
    
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if( (year%4 == 0 && year % 100 != 0) || (year % 400 == 0)){

        monthDays[1] = 29;
    }

    int dayNumber = 0;
    for (int i = 0; i < months-1; i++)
    {
        dayNumber= dayNumber + monthDays[i];
    }
     dayNumber = dayNumber + day;
    printf("Day number of the year: %d\n", dayNumber);
    return 0;

    
}
