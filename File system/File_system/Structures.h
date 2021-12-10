#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "File_system_structures.h"
#include "String.h"




struct List{
    String* name;
    i_node* node;
    List* next;
};

List* create_list();
int delete_element_list(List* list, String name);
int add_element_list(List* list, i_node* node);
List* get_list(List* list, String* name);
int remove_list(List* list);


struct Vector {
    unsigned int size;
    unsigned int mem_size;
    List **data;
};

Vector* create_vector();
int delete_element_vector(Vector* vector, unsigned int index);
int add_element_vector(Vector* vector,unsigned int index, List* data);
List* get_vector(Vector* vector, unsigned int index);
int remove_vector(Vector* vector);


struct hash_table{
    Vector* vector;
};

hash_table* create_hash_table();
int add_hash_table(hash_table hs_table, i_node element);
void delete_element_hash_table(hash_table* hs_table, String name);
i_node* get_hash_table(hash_table* hs_table, String name);
int remove_hash_table(hash_table *hs_table);

#endif // STRUCTURES_H



