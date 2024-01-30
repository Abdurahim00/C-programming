#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #### Constants #####
#define MAX 5

// ##### Typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function Declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

// ###### Main Program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;

    srand(time(0)); // Random seed

    // Creating a random list
    head = random_list();

    // Traversing the list and printing each element
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // Freeing the allocated memory
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

    top = malloc(sizeof(REGTYPE));
    top->number = rand() % 101;
    top->prev = NULL;
    top->next = NULL;
    old = top;

    for (i = 0; i < MAX; i++)
    {
        item = malloc(sizeof(REGTYPE));
        item->number = rand() % 101;
        item->prev = old;
        item->next = NULL;
        old->next = item;
        old = item;
    }

    return (top);
}
//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data)
{
}