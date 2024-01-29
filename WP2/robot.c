#include <stdio.h>

enum DIRECTION {N,O,S,W};

typedef struct {
int xpos;
int ypos;
enum DIRECTION dir;
} ROBOT;


void move(int *ptrXpos, int *ptrYpos, enum DIRECTION dir){

    if(dir == N && *ptrYpos < 99){
    (*ptrYpos)++;
}

else if(dir == S && *ptrYpos>0){

    (*ptrYpos)--;
}
else if (dir == O && *ptrXpos < 99)
{
        (*ptrXpos)++;

}
else if (dir == W && *ptrXpos>0)
{
        (*ptrXpos)--;

}

}

void turn(enum DIRECTION *ptrDir){

    (*ptrDir)++;


    // Check if the direction needs to wrap around
    if (*ptrDir > W) {
        *ptrDir = N;
    }
}



int main(int argc, char const *argv[])
{   
    int xpos;    
    int ypos;
    int *ptrXpos = &xpos;
    int *ptrYpos = &ypos;
    enum DIRECTION dir = N;
    enum DIRECTION *ptrDir = &dir;

      printf("Pick a starting X position ranging between 0-99 ");
     scanf("%d", &xpos);  
    printf("Pick a starting Y position ranging between 0-99 ");
    scanf("%d", &ypos);


ROBOT robot1 = {xpos, ypos, dir};
     ROBOT robots[] = {robot1};

     
    const char *directions[] = {"N", "O", "S", "W"};
    char choice = ' ';
    while (choice != 'e') {
    printf("Pick 'm' to move, 't' to turn, or 'e' to exit: ");
    scanf(" %c", &choice);

    if(choice == 'm'){
        move(&robot1.xpos, &robot1.ypos, robot1.dir);
    } else if (choice == 't') {
        turn(&robot1.dir);
    }

    // Print the current status of the robot
    printf("Robot Position: X = %d, Y = %d, Direction = %c\n", robot1.xpos, robot1.ypos, directions[robot1.dir]);

    if(choice == 'e'){
        break;  // Break the loop if e is entered
    }
}

 
 printf("Final position of the robot\n X: %d", robot1.xpos);
  printf("\n Y: %d", robot1.ypos); 
  return 0;
   }
   

