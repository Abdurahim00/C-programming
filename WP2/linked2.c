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
    head = random_list();

    head = add_first(head, 10); 
    head = add_first(head, 20); // Add a node with number 20
    head = add_first(head, 30); // Add a node with number 30
    srand(time(0)); // Random seed
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
    REGTYPE *top, *old, *item; // declaration
    top = NULL; // Will point at NULL when there is nothing
    old = NULL; // Will point at NULL when there is nothing

    // Where looping to the max prescribed size which is 5
    for (int i = 0; i < MAX; i++)
    {

        REGTYPE *item = (REGTYPE *)malloc(sizeof(REGTYPE)); // we allocate memory

        // If were not adding anything item will be NULL
        if (item == NULL)
        {
            // so we can clear memory, just a print statement for now
            printf("clear memory");
            break; // There is no need to continue the loop
        }

        
        item->number = rand() % 101; // item will point at the number which is random 1-100
        item->next = NULL; // Initially it will point at nothning
        item->prev = NULL; // Initially it will point at nothning

        // If the top is empty
        if (top == NULL)
        {
            // the new created item will be at top which is head
            top = item;
        }
        // when old is not equal to NULL
        if (old != NULL)
        {   
            // the last item which is placed in old will point at the next coming item
            old->next = item;
            item->prev = old; // while obviously the items prev pointer will be at old
        }
        // If the condition above is not satisfied then the newly created node is item
        old = item;
    }

    // we return top which points at the other nodes, so we can see everything
    return (top);
}
//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data)
{   // allocate memory for the newnode 
    REGTYPE *newNode = (REGTYPE *)malloc(sizeof(REGTYPE));

    // if its NULL we exit
     if (newNode == NULL) {
        return 0; // exit
    }

    // as stated above the newNode is similiar to item
    // We point new node to number which is random
    newNode->number = data;
    newNode->next = temp; // the newNodes next pointer will point at temp which is the first 
    newNode->prev = NULL; // because it will be first, its prev will be NULL

    // if there is a temp 
    if (temp != NULL) {
        // the temp will prev will point at the new newNode
        temp->prev = newNode;
    }

    // Then we return the newNode
    return newNode;

}