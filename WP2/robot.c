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
    enum DIRECTION dir;
    enum DIRECTION *ptrDir = &dir;


     ROBOT robot1 = {xpos, ypos, dir};
     ROBOT robots[] = {robot1};
    
    
     printf("Pick a starting X position ranging between 0-99 ");
     scanf("%d", &xpos );  
    printf("Pick a starting Y position ranging between 0-99 ");
    scanf("%d", &ypos);
    move(&robot1.xpos, &robot1.ypos, robot1.dir);

 //printf("Move one step with m or rotate with t ");
    printf("pick m to move or t to turn ");
    
    scanf("%s", &dir);
    turn(&robot1.dir);


    for (int i = 0; i < sizeof(robots)/sizeof(robots[0]); i++)
    {
        printf("%d\n", robots[i].xpos);
        printf("%d\n", robots[i].ypos);
        printf("%d\n", robots[i].dir);

    }

   
    /* code */
    return 0;
}
