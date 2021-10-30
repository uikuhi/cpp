#include <stdio.h>

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int *arr = new int[size];

    int alone = 0;

    for(int i = 0; i < size; ++i){
        printf("Enter number %d) ", i+1);
        scanf("%d", &arr[i]);


    }
    bool found;

    for(int i = 0; i < size; ++i){
        found = false;
        for(int j = 0; j < size; ++j){
            if(arr[j] == arr[i] && i != j){
                found = true;
                break;
           }
        }
        if(!found){
            alone = arr[i];
        }


    }

    printf("%d\n", alone);

    delete [] arr;

    return 0;
}
