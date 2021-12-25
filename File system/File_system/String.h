#ifndef STRING_H
#define STRING_H

struct String {
    char* data;
    unsigned int size;
};

String* Create_string();
String* Add_string(String* dest,  char* src);
int Delete_string(String* str);
int String_equal(String* dest, String* src);
int Strlen(char* str);


#endif // STRING_H
