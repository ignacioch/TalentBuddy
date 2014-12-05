#include <stdio.h>
#include <stdlib.h>

//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}

void fizzbuzz(int n) {
    // Write your code here

    // Using a mask
    //  11 indicates a multiply of both 3 and 5
    //  10 indicates a multiply of 5
    //  01 indicates a multiply of 3
    //  30 bit number is :11 00 00 01 00 10 01 00 00 01 10 00 01 00 00 (15 pairs)
    int mask = 810092048;   // 32 bit reprsenation of the mask
    int x    = 3;   
    int keep_2_msb_zeros = 1073741823 ; // 1100_000....       

    int i;
    for (i=1;i<=n;i++) {
        int val = mask & 3;    // logical end with 11 - we keep only the 2 LSBs
        printBits(sizeof(mask), &mask);
        printf("%d : val => %d\n",i,val);
        if (val == 3)   printf("FizzBuzz\n" );
        else if (val == 2 ) printf("Buzz\n");
        else if (val == 1 ) printf("Fizz\n");
        else printf("%d\n",i );
        // circular shift of the mask - size is 32 but the 2 MSB are always 0
        int mask_l2  = mask >> 2;
        int mask_r28 = mask << 28;
        
        mask = mask_l2 | (mask_r28 & keep_2_msb_zeros) ;
        printf ("Mask >> 2 : ");
        printBits(sizeof(mask), &mask_l2);
        printf("Mask << 28: ");
        printBits(sizeof(mask), &mask_r28);
        printf("\n");
    }
}


// Circular shift implementation
// Rollover right.
// C++ implementation
//  template<class T>
//  T ror(T x, unsigned int moves)
//  {
//    return (x >> moves) | (x << sizeof(T)*8 - moves);
//  }
//
//  Arithmetic example
//   x = 0111
//      x  >> 1     = 0011
//      x  << (4-1) = 1000
//                  ---------- || (Logical OR)
//                    1011

int main( int argc, char *argv[] )  
{
    if (argc != 2) {
        printf ("Please provide argument with the top limit");
        exit(1);
    } else {
        if ((atoi(argv[1])) > 1000) {
            printf("Input should be restrained to 1000");
            exit (1);
        } 
        printf("Running FizzBuzz with n = %s\n",argv[1]);
        fizzbuzz(atoi(argv[1]));
    } 
}
