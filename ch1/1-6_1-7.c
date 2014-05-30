#include <stdio.h>

main()
{
    printf("EOF = %d\n", EOF);
    printf("Press Ctrl+d to generate EOF, or Enter to generate non-EOF.\n");
    printf("Value of (getchar() != EOF): %d\n", (getchar() != EOF));
}
