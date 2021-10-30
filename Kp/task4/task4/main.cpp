#include <stdio.h>

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

    int first;
    int length = 0;

    for(int i = 0; i < N; ++i){
        int sum = 0;
        for(int j = 0; sum < K; ++j){
            sum += arr[i + j];
            if(sum == K){
                first = i;
                length = j + 1;
                break;
            }
        }

        if(length != 0){
            for(int i = 0; i < length; ++i){
                printf("%d ", arr[first + i]);
            }
            length = 0;
            printf("\n");
        }

    }


    delete [] arr;

    return 0;
}
