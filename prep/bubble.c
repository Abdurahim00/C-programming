#include <stdio.h>
#include <stdbool.h>


int search_number(int number, int tab[], int size){
        for(int i = 0; i<size; i++){
            if(tab[i] == number){
                
                     return i;

            }
            

        }
                return -1;
            
}

void sort (int number, int tab[]){
    int min;
    int temp;
    for (int i = 0; i < number; i++)
    {
        for (int j = i+1; j < number; j++)
        {   
            if(tab[i]>=tab[j]){
                temp = tab[j];
                tab[j]=tab[i];
                tab[i]=temp;
           
        }
       
        

    }
    }
}

int main()
{
    int test[] = {1,2,34,5,67,3,23,12,13,10};
    int number;
    int size = sizeof(test)/sizeof(test[0]);

    printf("Choose a number: ");
    scanf("%d", &number);

    int index = search_number(number, test, size);
    sort(size, test);
    if(index != -1){
        printf("Number found at index %d\n", index);
    }
    else{
        printf("Number not found");
    }
    printf("sorted array is:\n");
    for (int i = 0; i < size; i++)
    {
       printf("%d", test[i]);
 printf("\n");
    }
   
    

    return 0;
}
