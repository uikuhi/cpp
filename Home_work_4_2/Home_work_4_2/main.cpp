#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

    srand(time(nullptr));

    constexpr size_t size_a = 30;
    int A[size_a] = {};
    for(size_t i = 0; i < size_a; ++i){
        A[i] = rand() % 10 + 5;
        printf("%u) %d  ", i , A[i]);
    }
    printf("\n");

    constexpr size_t size_b = 15;
    int B[size_b] = {};
    for(size_t i = 0; i < size_b; ++i){
        B[i] = rand() % 10;
        printf("%u) %d  ", i , B[i]);
    }
    printf("\n");

    printf("Result index: ");
    for(size_t i = 0; i < size_a; ++i){

        bool found = false;

        for(size_t j = 0; !found && j < size_b; ++j){
            if(A[i] == B[j]){
                found = true;
            }
        }

        if(!found){
            printf("%u ", i);
        }
    }
    printf("\n");

    return 0;
}
