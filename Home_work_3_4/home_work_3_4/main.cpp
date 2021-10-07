// Translate dec -> bin

#include <stdio.h>

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int result = 0;
    for(int degree = 1; n >= 1; degree *= 10){
        result += (n % 2) * degree;
        n /= 2;
    }

    printf("Result: %d\n", result);

    return 0;
}
