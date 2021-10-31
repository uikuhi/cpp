#include <stdio.h>

bool find(int *arr, int size, int child, int count);

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int *arr = new int[size];

    for(int i = 0; i < size; ++i){
        printf("Enter candy's count for %d child: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int child;
    printf("Enter child's index betwen 1-%d: ", size);
    scanf("%d", &child);
    child = (child - 1) % size;

    int count;
    printf("Enter candy's count: ");
    scanf("%d", &count);

    if( find(arr, size, child, count) ){
         printf("%d child have max candy\n", child+1);
    } else {
         printf("%d child have not max candy\n", child+1);
    }

    delete [] arr;

    return 0;
}

bool find(int *arr, int size, int child, int count){

    bool result;
    int max = arr[0];
    for(int i = 1; i < size; ++i){
        if(max < arr[i])
            max = arr[i];
    }

    if(max < (arr[child] + count) ){
        result = true;
    } else {
        result = false;
    }

    return result;
}
