#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #### Constants #####
#define MAX 5
// ##### typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;
// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
// ###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    head = add_first(head, 10); 
    head = add_first(head, 20); // Add a node with number 20
    head = add_first(head, 30); // Add a node with number 30
   // srand(time(0)); // Random seed
    //head = random_list();
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
        
    }
    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }
    return 0;
}
// ==== End of main ======================================
REGTYPE *random_list(void)
{
    int nr, i = 0;
    REGTYPE *top, *old, *item;
    top = NULL;
    old = NULL;

    for (int i = 0; i < MAX; i++)
    {

        REGTYPE *item = (REGTYPE *)malloc(sizeof(REGTYPE)); // allocate memory
        if (item == NULL)
        {

            printf("clear memorty");
            break;
        }

        item->number = rand() % 101;
        item->next = NULL;
        item->prev = NULL;

        if (top == NULL)
        {
            top = item;
        }
        if (old != NULL)
        {
            old->next = item;
            item->prev = old;
        }
        old = item;
    }

    return (top);
}
//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data)
{    REGTYPE *newNode = (REGTYPE *)malloc(sizeof(REGTYPE));

     if (newNode == NULL) {
        return;
    }

    newNode->number = data;
    newNode->next = temp;
    newNode->prev = NULL;

    if (temp != NULL) {
        temp->prev = newNode;
    }

    return newNode;

}