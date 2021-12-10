#ifndef STRING_H
#define STRING_H

struct String {
    char* data;
    unsigned int size;
};

String* create_string();
int add_string(String* dest,  char* src);
int delete_string(String* str);
int string_equal(String* dest, String* src);


#endif // STRING_H
