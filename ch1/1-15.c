#include <stdio.h>

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */

float fahrToCelsius(float fahr);

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;     /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    // print a header for the table
    printf("%3c %6c\n", 'F', 'C');
    printf("___ ______\n");
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fahrToCelsius(fahr));
        fahr = fahr + step;
    }
} 

float fahrToCelsius(float fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}
