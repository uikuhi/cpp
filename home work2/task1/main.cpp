#include <stdio.h>
#include <cmath>

int main()
{
    double f;
    printf("Enter f:");
    scanf("%lf", &f);

    const double hisl = cos(f *f - M_PI/4. ) - 1;
    const double znam = sqrt(2) / 2 / sqrt(3) + pow( sin(2 * f + M_PI/6), 2);
    const double result = log( fabs(hisl / znam));

    printf("Reslt: %f\n", result);

    return 0;
}
