#include <stdio.h>
#include <stdlib.h>

// method to check what number the user typed and print according to it. 
void number(int numbers){

    // number provided is 1
   if(numbers==1){
        printf("how are you\n");
    }
    // if number provided is 2
    else if(numbers==2){
    printf("how is it\n");

    }
    // if number provided is 2
    else if(numbers==3){
    printf("how u doing\n");

    }
     // if number provided is 2
     else if(numbers==4){
    printf("how were you\n");

    }
     // if number provided is 2
    else if(numbers==5){
    printf("how come?\n");

    } 
}

// main
int main(int argc, char *argv[])
{   
    int num; // declare int num
   
   // execute whats inside the curly brackets
  do {
        printf("Enter a number between 1-5: ");
    
        scanf("%d", &num); // input format is int
        // if num1 is 1 or more and if num is less or equals to 5
        if (num >= 1 && num <= 5) {
            number(num); // Trigger the method number(num) with num as parameter
        }
    } while (num >= 1 && num <= 5); // as long as the num is between 1-5 keep asking the user

    return 0;
}
    

