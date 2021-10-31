#include <stdio.h>

int main()
{

    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    int i = 1;
    int num = 0;
    int temp = 0;

    printf("%d = \n", N);
    while(N - num > 0){
        printf("N - temp: %d\n", N - temp);
        while( (N - temp - i >= 0) && ( (num % i)  != 1))
            i *= 10;

        i /= 10;
        num += i;
        printf("num: %d\ti: %d\tN: %d\n", num,i, N);

        temp = num;

        if(i == 1 || i == 0){
           N -= num;
           if(N > 0){
                printf("%d + ", num);
           } else {
                printf("%d\n", num);
           }
           num = 0;
           temp = 0;

        }

        i = 1;
    }



    return 0;
}
