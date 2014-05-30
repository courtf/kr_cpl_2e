#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;     /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    // print a header for the table
    printf("%3c %6c\n", 'C', 'F');
    printf("___ ______\n");
    while (celsius <= upper) {
        fahr = ((9.0/5.0) * celsius) + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
} 
