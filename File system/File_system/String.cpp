#include "String.h"
#include <stdio.h>

String* Create_string(){
    String* str = new String;
    str->data = nullptr;
    str->size = 0;

    return str;
}

int Strlen(char *str){
    int index = 0;
    while(str[index] != '\0')
        index++;

    return index;
}

String *Add_string(String* dest, char *src){
    if(dest == nullptr)
        return 0;

    const unsigned int size = dest->size + Strlen(src);
    char* tmp = new char[size+1];

    for(unsigned int i = 0; i < dest->size; ++i)
        tmp[i] = dest->data[i];

    const unsigned int tmp_size = Strlen(src);
    for(unsigned int i = 0; i < tmp_size; ++i)
        tmp[i + dest->size] = src[i];

    tmp[size] = '\0';

    delete dest->data;
    dest->data = tmp;
    dest->size = size;

    return dest;
}

int Delete_string(String* str){
    if(str == nullptr)
        return 1;

    delete[] str->data;
    delete str;

    return 0;
}

int String_equal(String* dest, String* src){
    if(dest == nullptr || src == nullptr || dest->size != src->size)
        return 2;

    for(unsigned int i = 0; i < dest->size; ++i){
        if(dest->data[i] != src->data[i])
            return 1;

    }

    return 0;
}
