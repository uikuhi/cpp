#include "String.h"

String* create_string(){
    String* str = new String;
    str->data = nullptr;
    str->size = 0;
    return str;
}

int add_string(String* dest, char *src){
    if(dest == nullptr)
        return 0;

    const unsigned int size = dest->size + sizeof(*src);
    char* tmp = new char[size+1];

    for(unsigned int i = 0; i < dest->size; ++i)
        tmp[i] = dest->data[i];

    for(unsigned int i = 0; i < sizeof(*src); ++i)
        tmp[i + dest->size] = src[i];

    tmp[size] = '\0';

    delete dest->data;
    dest->data = tmp;
    dest->size = size;

    return 0;
}

int string_equal(String* dest, String* src){
    if(dest == nullptr || src == nullptr || dest->size != src->size)
        return 1;

    for(unsigned int i = 0; i < dest->size; ++i){
        if(dest->data[i] != src->data[i])
            return 1;
    }

    return 0;
}

int delete_string(String* str){
    if(str == nullptr)
        return 0;

    delete[] str->data;
    delete str;

    return 0;
}
