#include <stdio.h>

unsigned rightrot(unsigned x, unsigned n);

main()
{
    printf("%u\n", rightrot(077, 1));
}

unsigned rightrot(unsigned x, unsigned n)
{
    return ((x & ~(~0 << n)) << (32 - n)) | (x >> n);
}
