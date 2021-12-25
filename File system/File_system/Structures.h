#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "File_system_structures.h"
#include "String.h"

struct List{
    String* name;
    i_node* node;
    List* next;
};

List* Create_list();
int Add_element_list(List* list, i_node* node);
int Delete_element_list(List* list, String name);
int Remove_list(List* list);
List* Get_list(List* list, String* name);

struct Vector {
    unsigned int size;
    unsigned int mem_size;
    List **data;
};

Vector* Create_vector();
int Delete_element_vector(Vector* vector, unsigned int index);
int Add_element_vector(Vector* vector,unsigned int index, List* data);
int Remove_vector(Vector* vector);
List* Get_vector(Vector* vector, unsigned int index);

struct Hash_Table {
    List* hs[20];
};

Hash_Table* Create_hash_table();
int Add_hash_table(Hash_Table *hs_table, i_node *element);
int Delete_element_hash_table(Hash_Table* hs_table, String* name);
int Remove_hash_table(Hash_Table *hs_table);
i_node* Get_hash_table(Hash_Table* hs_table, String* name);

#endif // STRUCTURES_H



