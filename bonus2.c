#include <stdio.h>

enum weekDays{Mon, Tue, Wed, Thur, Fri, Sat, Sun};
enum weeks{week1, week2, week3, week4, week5};

void weekDays(){
    enum weekDays wd;
    switch (wd)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }

}
void weeks(){
    enum weeks w;
    switch (w)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }

}

int main(int argc, char const *argv[])
{       enum weekDays wd;
        enum weeks w;
        enum *ptrWeekDays = &wd;
        enum *ptrWeeks = &w;
        
    printf("Provide starting week: ");
    scanf("%d", weeks)
    printf("Provide starting day: ");
    scanf("%c", weekDays)


    /* code */
    return 0;
}
