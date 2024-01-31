// Include all sections
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Defining weekdays as enum for clarity mainly, NUM_DAYS is used as an end enum
enum weekDays
{NUM_DAYS,
    Mon,
    Tue,
    Wed,
    Thur,
    Fri,
    Sat,
    Sun
};

// Defining weeks as enum for clarity mainly
enum weeks
{
    week1,
    week2,
    week3,
    week4,
    week5
};
void clearBuffer(void);
// This is so i can get the position when the user enter a weekday string
/*enum weekDays getWeekDayFromString(const char *ptrInputDay) {
    if (strcmp(ptrInputDay, "Mon") == 0) return Mon; // compare the string input with Mon if true return Mon
    if (strcmp(ptrInputDay, "Tue") == 0) return Tue; // compare the string input with Tue if true return Tue
    if (strcmp(ptrInputDay, "Wed") == 0) return Wed; // compare the string input with Wed if true return Wed
    if (strcmp(ptrInputDay, "Thur") == 0) return Thur; // compare the string input with Thur if true return Thur
    if (strcmp(ptrInputDay, "Fri") == 0) return Fri; // compare the string input with Fri if true return Fri
    if (strcmp(ptrInputDay, "Sat") == 0) return Sat; // compare the string input with Sat if true return Sat
    if (strcmp(ptrInputDay, "Sun") == 0) return Sun; // compare the string input with Sun if true return Sun
    return NUM_DAYS; // Invalid input
}*/

// This method returns the character version of the returned enum above. Cause im not allowed to store in an array of strings :)
const char *getStringFromDay(enum weekDays day)
{
    switch (day)
    {
    case Mon:
        return "Monday"; // If the above method returned Mon then return the string "Monday"
    case Tue:
        return "Tuesday"; // If the above method returned Tue then return the string "Monday"
    case Wed:
        return "Wednesday"; // If the above method returned wed then return the string "Monday"
    case Thur:
        return "Thursday"; // If the above method returned Thur then return the string "Monday"
    case Fri:
        return "Friday"; // If the above method returned Fri then return the string "Monday"
    case Sat:
        return "Saturday"; // If the above method returned Sat then return the string "Monday"
    case Sun:
        return "Sunday"; // If the above method returned Sun then return the string "Monday"
    default:
        return "Invalid"; // otherwise if nothing is returned we give invalid
    }
}


int main(int argc, char const *argv[])
{
    enum weekDays wd;
    enum weeks w;
    enum weekDays *ptrWeekDays = &wd;
    enum weeks *ptrWeeks = &w;

    int inputWeek; // used for inputing the week nr 1-5
    int inputDay;  // Buffer to store the input day as a string

    scanf("%d", &inputWeek); // The user will enter an int and it will be stored in the address of the input
    clearBuffer();

    // if the user inputs a number less or more than 5 we print invalid
    if (inputWeek < 1 || inputWeek > 5)
    {
        printf("invalid week\n");
        return 0;
    }

    scanf("%d", &inputDay); // user enters a day as a string like Mon, Tue etc
    clearBuffer();
    if (inputDay > 7 || inputDay < 1)
    {
        printf("invalid day\n");
        return 0;
    }
    // we assign the dayvalue to be *ptrWeekDay found in the beginning of main
    *ptrWeeks = inputWeek - 1; // we assing *ptrWeeks to be inputWeek -1 so we can input week 1 for instance instead of 0

    // as long as the *ptrWeeks is less or equal than week 5 and the days are less or equal to Sun we keep looping
    while (*ptrWeeks <= week5 && *ptrWeekDays <= Sun)
    {

        printf("Week %d, %s\n", *ptrWeeks + 1, getStringFromDay(*ptrWeekDays));

        sleep(1); // To print every Second

        // If we reach the day sunday
        if (*ptrWeekDays == Sun)
        {
            // We go back to monday
            *ptrWeekDays = Mon;
            // And if the weeks are less or equals to 5 we keep incrementing
            if (*ptrWeeks <= week5)
            {
                (*ptrWeeks)++; // incrementing
            }
        }
        else
        {
            // else we days will keep on incrementing
            (*ptrWeekDays)++;
        }
    }

    return 0; // exit
}
void clearBuffer()
{
    int temp;
    while ((temp = getchar()) != '\n' && temp != EOF);
        
}