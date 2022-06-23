#include <stdio.h>

float temp_convert(float fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}

int main(int argc, char *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;     /* lower limit of temperature table */
    upper = 300;   /* upper limit */
    step = 20;     /* step size */

    fahr = lower;
    printf("fahr celsius\n");
    while (fahr <= upper) {
        celsius = temp_convert(fahr);
	printf("%3.0f %6.1f\n", fahr, celsius);
	fahr = fahr + step;
    }

    return 0;
}
