#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(nullptr));

    constexpr size_t size = 40;
    int M[size] = {};
    for(size_t i = 0; i < size; ++i){
        M[i] = rand() % 20 - 10;
        printf("%d ", M[i]);
    }
    printf("\n");

    int max = M[0];
    int index1 = 0;

    int last_min = M[size-1];
    int index2 = size - 1;

    for(size_t i = 0; i < size; ++i){

        if(max < M[i]) {
            max = M[i];
            index1 = i;
        }

        if(last_min > 0 && M[size-1 - i] < 0){
            last_min = M[size-1 -i];
            index2 = size-1 - i;
        }
    }

    printf("max: %d\tindex1 %d\tlast_min: %d\tindex2: %d\n", max, index1, last_min, index2);

    int temp = last_min;
    M[index2] = max;
    M[index1] = temp;

    for(size_t i = 0; i < size; ++i){
        printf("%d ", M[i]);
    }
    printf("\n");


    return 0;
}
