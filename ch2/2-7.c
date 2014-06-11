#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n);

main()
{
    printf("%u\n", invert(077, 4, 3));
}

unsigned invert(unsigned x, unsigned p, unsigned n)
{
    return x & ~(~(~0 << n) << (p+1-n));
}
