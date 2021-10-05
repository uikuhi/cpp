// Finds the minimal common divisor

#include <stdio.h>

int main()
{

    int number_1;
    printf("Enter number_1: ");
    scanf("%d", &number_1);

    int number_2;
    printf("Enter number_2: ");
    scanf("%d", &number_2);

    int number_3;
    printf("Enter number_3: ");
    scanf("%d", &number_3);

    int count = 2;
    for(;; count++){

        if( number_1 >= count || number_2 >= count || number_3 >= count ){

            if( number_1 % count == 0 && number_2 % count == 0 && number_3 % count == 0){
                break;
            }

        } else {
            count  = 1;
            break;
        }

    }

    printf("\nMinimal common divisor: %d\n", count);

    return 0;
}
