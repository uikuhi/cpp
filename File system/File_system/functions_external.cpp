#include "functions_external.h"

int hash(String* name, unsigned int size){
    int sum = 0;
    for(int i = 0; name->data[i] != '\0'; ++i)
        sum += name->data[i];
    sum %= size;

    return sum;
}
