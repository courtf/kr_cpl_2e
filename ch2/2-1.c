#include <stdio.h>
#include <limits.h>
#include <float.h>

unsigned long binPow(const unsigned char exp);

main()
{
    printf("from constants:\n");
    printf("char range: %d  -  %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char range: %d  -  %u\n", 0, UCHAR_MAX);
    printf("short range: %d  -  %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short range: %d  -  %u\n", 0, USHRT_MAX);
    printf("int range: %d  -  %d\n", INT_MIN, INT_MAX);
    printf("unsigned int range: %d  -  %u\n", 0, UINT_MAX);
    printf("long range: %ld  -  %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long range: %d  -  %lu\n", 0, ULONG_MAX);

    printf("\ncalculated:\n");
    printf("char range: %ld  -  %ld\n", -1 * binPow(7), binPow(7) - 1);
    printf("unsigned char range: %d  -  %ld\n", 0, binPow(8) - 1);
    printf("short range: %ld  -  %ld\n", -1 * binPow(15), binPow(15) - 1);
    printf("unsigned short range: %d  -  %ld\n", 0, binPow(16) - 1);
    printf("int range: %ld  -  %ld\n", -1 * binPow(31), binPow(31) - 1);
    printf("unsigned int range: %d  -  %ld\n", 0, binPow(32) - 1);
    printf("long range: %ld  -  %ld\n", -1 * binPow(63), binPow(63) - 1);
    unsigned long max_lng = 0;
    int i = 63;
    for (; i >= 0; --i) {
        max_lng = max_lng + binPow(i);
    }
    printf("unsigned long range: %d  -  %lu\n", 0, max_lng);
}

unsigned long binPow(const unsigned char exp)
{
    unsigned long returnVal = 1;
    int i;
    for (i = 1; i <= exp; ++i) {
        returnVal = 2*returnVal;
    }
    return returnVal;
}
