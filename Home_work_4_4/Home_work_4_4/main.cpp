#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(nullptr));

    constexpr size_t size = 5;
    int M[size][size];
    int sum = 0;

    for(size_t i = 0; i < size; ++i){
        for(size_t j = 0; j < size; ++j){

            M[i][j] = rand() % 5;
            printf("%d ", M[i][j]);

            if(i < (size-1) - j){
                sum += M[i][j];
            }

        }
        printf("\n");
    }

    printf("Sum: %d\n", sum);

    return 0;
}
