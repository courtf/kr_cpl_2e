#include <stdio.h>

/*
 *  x &= (x - 1) == x = x & (x - 1)
 *
 *  This deletes the right-most 1 bit because it first
 *  converts that bit to a zero in order to complete
 *  the subtraction. The bits to the right were previously
 *  zero, but are then flipped to be ones as well as part
 *  of the subtraction. When x is negative, the bits to
 *  the right remain as 0's in order to satisfy the two's
 *  complement.
 *
 *  All of the bits to the right of the original right-most
 *  1 back to the zero position contain 1's or 0's, whereas
 *  previously they all contained 0's. So after a bitwise
 *  AND, those bits remain 0's.
 */

unsigned bitcount(unsigned x);

main()
{
    printf("%u\n", bitcount(077));
}

unsigned bitcount(unsigned x)
{
    int b = 0;

    while (x != 0) {
        x &= (x -1);
        b++;
    }

    return b;
}
