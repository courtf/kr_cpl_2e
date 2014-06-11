#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

main()
{
    printf("%d\n", setbits(077, 4, 3, 0));
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    /*  1) (~0 << n)            -> all 1's, shifted left by n 0's
     *  2) ~#1                  -> n 1's, right adjusted (1's complement of above)
     *  3) y & #2               -> copies the right most n bits from y
     *  4) #3  << (p + 1 - n)   -> left shift the copied values from y
     *                             by the number of bit positions that
     *                             remain to the right of our selection
     *                             from x (position p, count n)
     *
     *  5) #2 << (p + 1 - n)    -> n 1's, shifted left by the same remaining
     *                             positions as above
     *
     *  6) ~#5                  -> all 1's with a gap of 0's, n wide at pos p
     *
     *  8) x & #6               -> clears n values from x, starting at pos p
     *
     *  7) #4 | #7              -> places the copied section of y into the
     *                             cleared section of x at pos p
     */
    return ((y & ~(~0 << n)) << (p + 1 - n)) | (x & ~(~(~0 << n) << (p + 1 - n)));
}
