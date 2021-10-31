#include <stdio.h>

int find(int N);

int main()
{

    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    printf("%d\n", find(N));

    return 0;
}

int find(int N){
    int max = 0;
    for(int i = 10; N > 0; i *= 10){
        if(N % 10 > max){
            max = N % 10;
        }
        N /= 10;
    }
    return max;
}
