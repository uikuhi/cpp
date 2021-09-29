#include <stdio.h>
#include <math.h>

int main(){

    double sc;
    double st;
    double ss;

    double R;
    printf("Enter R: ");
    scanf("%lf", &R);

    double a;
    printf("Enter a: ");
    scanf("%lf", &a);

    double d;
    printf("Enter d: ");
    scanf("%lf", &d);

    sc = M_PI * R * R;
    st = a * sqrt(3) / 4.;
    ss = d * d;

    double max = sc > st
                    ? sc > ss
                        ? sc
                        : ss
                    : st > ss
                        ? st
                        : ss;
    printf("Max: %lf\n", max);


    return 0;
}
