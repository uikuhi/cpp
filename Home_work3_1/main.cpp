// Count number length

#include <stdio.h>

int main()
{
    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    int count = 0;
    for(; N >= 1; count++)
        N /= 10;

    printf("Number length: %d\n", count);

    return 0;
}
