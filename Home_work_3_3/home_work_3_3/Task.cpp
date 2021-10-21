#include "Task.h"

int Task_3_3(int N){
    int count = 0;
    int temp = N;
    for(; temp >= 1; count++){
        temp /= 10;
    }

    temp = N / 10;
    int min = N % 10;
    int result = 0;

    int degree = 10;
    for(int i = 0; i < count-2; i++){
        result += (temp % 10) * degree;
        degree *= 10;
        temp /= 10;
    }

    result += temp;
    result += min * degree;

    return result;
}
