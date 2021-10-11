#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(nullptr));

    constexpr size_t size = 7;
    int M[size][size];
    for(size_t i = 0; i < size; ++i){
        for(size_t j = 0; j < size; ++j){
            M[i][j] = rand() % 10;
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    int k;
    printf("Enter k( 0 < k < %d: ", size);
    scanf("%d",&k);

    int temp;
    for(size_t i = 0; i < size; ++i){
        temp = M[k][i];
        M[k][i] = M[i][k];
        M[i][k] = temp;
    }

    for(size_t i = 0; i < size; ++i){
        for(size_t j = 0; j < size; ++j){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
