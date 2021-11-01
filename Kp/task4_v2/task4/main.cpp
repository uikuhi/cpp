#include <stdio.h>

struct Pair{
    int first;
    int second;
};

Pair find(int *arr, int N, int k);

int main()
{

    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    int *arr = new int[N];
    for(int i = 0; i < N; ++i){
        printf("Enter %d) " , i+1);
        scanf("%d", &arr[i]);
    }

    int K;
    printf("Enter K: ");
    scanf("%d", &K);

    Pair obj = find(arr, N, K);

    if(obj.second  != -1 ){
        for(int i = 0; i < obj.second - obj.first + 1 ; ++i){
            printf("%d ", arr[obj.first + i]);
        }
    }


    delete [] arr;

    return 0;
}


Pair find(int *arr, int N, int K){
    Pair obj;
    obj.second = -1;

    for(int i = 0; i < N; ++i){
        int sum = 0;
        for(int j = 0; sum < K; ++j){
            sum += arr[i + j];
            if(sum == K){
                obj.first = i;
                obj.second = j;
                break;
            }
        }
    }

    return obj;
}
