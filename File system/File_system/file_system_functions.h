#ifndef FILE_SYSTEM_FUNCTIONS_H
#define FILE_SYSTEM_FUNCTIONS_H

#include "String.h"
#include "Structures.h"
#include "File_system_structures.h"
#include <cstdio>
#include <stdio.h>

i_node* Create_node();
void Delete_node(i_node* node);
void Write_i_node(FILE* fs, i_node* node);
void Write_block_array(FILE* fs, int id_node, int count, int* block_id);
void Write_block(FILE* fs, Block* bl);
int Create_file_system(String *path, String* name);
User_info *Create_user(String* name, FILE* fs, Info_addres* inf_add);
void Delete_user(User_info* user);
User_info* Open_file_system(String* path, String *name);
int Close_file_system(FILE* fs);
String* Current_dir(User_info* user);

void Create_record(User_info* user, char* owner, char type);
String* Read_record(User_info* user, String* name, char type);
void Write_in_file_system(User_info* user, char type, String* name, String *data);

String* Read_i_node(User_info* user, String* name, char type);
String* Read_block_array(User_info* user, int id_node);
String* Read_block(User_info* user, int id_block);

void Create_file(User_info* user, char* name);
String* Read_file(User_info* user, String* name);
void Write_in_file(User_info* user, String* name, String* data);

void Create_dir(User_info* user, String* name);
String* Read_dir(User_info* user, String* name);
void Write_in_dir(User_info* user, String* name, String* data);


#endif // FILE_SYSTEM_FUNCTIONS_H
