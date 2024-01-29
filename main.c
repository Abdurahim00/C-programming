#include <stdio.h>
#include <unistd.h> 
#include <string.h>

enum weekDays{Mon, Tue, Wed, Thur, Fri, Sat, Sun, NUM_DAYS};
enum weeks{week1, week2, week3, week4, week5, NUM_WEEKS};

// This is so i can get the position when the user enter a weekday string
enum weekDays getWeekDayFromString(const char *ptrInputDay) {
    if (strcmp(ptrInputDay, "Mon") == 0) return Mon;
    if (strcmp(ptrInputDay, "Tue") == 0) return Tue;
    if (strcmp(ptrInputDay, "Wed") == 0) return Wed;
    if (strcmp(ptrInputDay, "Thur") == 0) return Thur;
    if (strcmp(ptrInputDay, "Fri") == 0) return Fri;
    if (strcmp(ptrInputDay, "Sat") == 0) return Sat;
    if (strcmp(ptrInputDay, "Sun") == 0) return Sun;
    return NUM_DAYS; // Invalid input
}

const char* getStringFromDay(enum weekDays day) {
    switch(day) {
        case Mon: return "Monday";
        case Tue: return "Tuesday";
        case Wed: return "Wednesday";
        case Thur: return "Thursday";
        case Fri: return "Friday";
        case Sat: return "Saturday";
        case Sun: return "Sunday";
        default: return "Invalid";
    }
}



int main(int argc, char const *argv[])
{       enum weekDays wd;
        enum weeks w;
        enum weekDays *ptrWeekDays = &wd;
        enum weeks *ptrWeeks = &w;
        
    int inputWeek;
    char inputDay[10]; // Buffer to store the input day as a string

    printf("Provide starting week: ");
    scanf("%d", &inputWeek);
    if(inputWeek < 1 && inputWeek >5){
        printf("invalid week");
    } 
    
    

    printf("Provide starting day: ");
    scanf("%s", inputDay);


 enum weekDays dayValue = getWeekDayFromString(inputDay);
    if (dayValue == NUM_DAYS) {
        printf("invalid day");

    }
    

    *ptrWeekDays = dayValue;
    *ptrWeeks = inputWeek; 

    while (*ptrWeeks <NUM_WEEKS && *ptrWeekDays <= Sun) {
        
        printf("Week %d, %s\n", *ptrWeeks + 1, getStringFromDay(*ptrWeekDays));

        sleep(1); // Delay for 1 second

        if (*ptrWeekDays == Sun) {
            *ptrWeekDays = Mon;
            if (*ptrWeeks < week5) {
                (*ptrWeeks)++;
            }
        } else {
            (*ptrWeekDays)++;
             printf("Week %d, %s\n", *ptrWeeks + 1, getStringFromDay(*ptrWeekDays));
        }
    }

    return 0;
}
