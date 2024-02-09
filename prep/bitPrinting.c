#include <stdio.h>



void print_bin(unsigned int bits){

 for (int i = 0; i < 32; i++)
    {
        int bit = (bits>> (31-i)) & 1;
        printf("%d", bit);

    if(i%8 == 7 && i!=31){
        printf(".");
    }
        
    }

}
int main(int argc, char const *argv[])
{

    
   
    print_bin(43);

    return 0;
}
