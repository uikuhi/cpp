#include <stdio.h>

int find(int *arr, int size);

int main()
{

    constexpr int size = 5;
    int arr[size] = {1,1,2,2,3};
    printf("Alone: %d\n", find(arr, size));


    return 0;
}


int find(int *arr, int size){
    int alone = 0;
    for(int i = 0; i < size; ++i){
        alone ^= arr[i];
    }

    return alone;
}
