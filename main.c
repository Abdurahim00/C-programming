// Include all sections
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Defining weekdays as enum for clarity mainly
enum weekDays
{  
    Mon, // modnday 
    Tue, // tuesday
    Wed, // wednesday
    Thur, // thursday
    Fri, // friday
    Sat, // saturday
    Sun // sunday
};

// Defining weeks as enum for clarity (and its the assignment (:))
enum weeks
{
    week1, // 1
    week2, // 2
    week3, // 3
    week4, // 4
    week5 // 5
};

void clearBuffer(void); // used for the mistake codegrade makes, ignores \n

// This method returns the character version of the returned enum above. Cause im not allowed to store in an array of strings :)
const char *getStringFromDay(enum weekDays day)
{
    switch (day) // if a day is provided we enter the switch
    {
    case Mon:
        return "Monday"; // If returned Mon then return the string "Monday"
    case Tue:
        return "Tuesday"; // If returned Tue then return the string "Tuesday"
    case Wed:
        return "Wednesday"; // If returned wed then return the string "Wednesday"
    case Thur:
        return "Thursday"; // If returned Thur then return the string "Thursday"
    case Fri:
        return "Friday"; // If returned Fri then return the string "Friday"
    case Sat:
        return "Saturday"; // If returned Sat then return the string "Saturday"
    case Sun:
        return "Sunday"; // If returned Sun then return the string "Sunday"
    default:
        return "Invalid"; // otherwise if nothing is returned we give invalid
    }
}


int main(int argc, char const *argv[])
{
    enum weekDays wd = Mon; // Initialize to Monday
    enum weeks w = week1; // initial enum week1
    enum weekDays *ptrWeekDays = &wd; // pointer for days to be able to access outside main
    enum weeks *ptrWeeks = &w; // pointer for weeks to be able to access outside main

    int inputWeek; // used for inputing the week nr 1-5
    int inputDay;  // Buffer to store the input day

    scanf("%d", &inputWeek); // The user will enter an int and it will be stored in the address of the input
    clearBuffer(); // to ignore \n

    // if the user inputs a number less or more than 5 we print invalid
    if (inputWeek < 1 || inputWeek > 5)
    {
        printf("invalid week\n");
        return 0; // exit
    }

    scanf("%d", &inputDay); // user enters a day as a string like Mon, Tue etc
    clearBuffer(); // to ignore \n
    //if we input a day outside the range 1-7 we give invalid day
    if (inputDay > 7 || inputDay < 1)
    {
        printf("invalid day\n");
        return 0; // and we exit
    }

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
            // else the days will keep on incrementing
            (*ptrWeekDays)++;
        }
    }

    return 0; // exit
}

// This is for codeGrade counting in \n
void clearBuffer()
{
    int temp; // declare an int temp
    while ((temp = getchar()) != '\n' && temp != EOF); // When temp stumbles accross \n at end of file we clear
        
}