#include "Structures.h"
#include "String.h"
#include "functions_external.h"


Vector* create_vector(){
    Vector* result = new Vector;
    result->size = 0;
    result->mem_size = 10;
    result->data = new List*[result->mem_size];
    return result;
}

int delete_element_vector(Vector* vector, unsigned int index){
    if(vector->size <= index){
            for(unsigned int i = index; i < vector->size-1; i++){
            vector->data[i] = vector->data[i+1];
        }
        --vector->size;
        return 0;
    } else {
        return 1;
    }
}

int add_element_vector(Vector* vector,unsigned int index, List* data){

    if(vector == nullptr)
        return 0;

    if(vector->mem_size == vector->size){
        vector->mem_size = 2 * vector->mem_size;
        List** new_mem = new List*[vector->mem_size];

        for(unsigned int i = 0; i < vector->size; ++i){
            new_mem[i] = vector->data[i];
        }
        delete[] vector->data;
        vector->data = new_mem;

        add_element_vector(vector, index,data);
    } else {

        if(index < vector->mem_size){
            if(index == vector->size){
                vector->data[index] = data;
                ++vector->size;
                return 0;
            }

            for(unsigned int i = vector->size; i > index; --i){
                vector->data[i] = vector->data[i-1];
            }

            vector->data[index] = data;
            ++vector->size;
            return 0;
        } else {
            return 3;
        }
    }
}

List* get_vector(Vector* vector, unsigned int index){
    if(vector == nullptr || vector->size <= index){
        return nullptr;
    }

    return vector->data[index];
}


int remove_vector(Vector* vector){
    if(vector == nullptr)
        return 0;

    delete[] vector->data;
    delete vector;
    return 0;
}


List* create_list(){
    List* list = new List;
    list->name = create_string();
    list->node = nullptr;
    list->next = nullptr;

    return list;
}


int delete_element_list(List* list, String name){
    if(list != nullptr){
       bool found = false;
       List* old_ptr;
       do {
           if( string_equal(list->name, &name) == 0)
               found = true;

           if(!found)
               old_ptr = list;

           if(list->next != nullptr){
               list = list->next;
           }
       } while(list->next != nullptr && !found);

        if(found){
            if(list->next != nullptr){
                old_ptr->next = list;
            } else {
                old_ptr->next = nullptr;
            }
        }
    }
    return 0;
}

int add_element_list(List* list, i_node* node){
    while(list->next != nullptr)
        list = list->next;
    if(list->node != nullptr){
        List* last = create_list();
        last->node = node;
        add_string(last->name, node->name->data);
        list->next = last;
    } else {
        list->node = node;
        add_string(list->name, node->name->data);
    }
    return 0;
}

List* get_list(List* list, String* name){
    List* tmp = create_list();
    tmp = list;
    while( string_equal(tmp->name, name) != 0 || tmp->next == nullptr){
        if(tmp->next == nullptr)
            return nullptr;
        tmp = tmp->next;
    }
    return tmp;
}

int remove_list(List* list){
    List* tmp = create_list();
    tmp = list;
    while(tmp->next != nullptr)
        tmp = tmp->next;
    delete_string(tmp->name);
    delete tmp->next;
    delete tmp->name;
    // delete node
    delete tmp->node;
    return 0;
}


hash_table* create_hash_table(){
    hash_table* tmp = new hash_table;
    tmp->vector = create_vector();
    for(int i = 0; i < tmp->vector->size; ++i)
        tmp->vector->data[i] = nullptr;
    return tmp;
}

int add_hash_table(hash_table* hs_table, i_node* element){
    int index = hash(element->name, hs_table->vector->mem_size);
    if(hs_table->vector->data[index] == nullptr){
        hs_table->vector->data[index] = create_list();
        List* index_coll = create_list();
        add_element_list(index_coll, element);
        add_element_vector(hs_table->vector, index, index_coll);
    } else {
        add_element_list(hs_table->vector->data[index], element);
    }
    return 0;
}

void delete_element_hash_table(hash_table* hs_table, String name){
    int index = hash(&name, hs_table->vector->mem_size);
    if(hs_table->vector->data[index] != nullptr){
        delete_element_list(hs_table->vector->data[index], name);
    }
}

i_node* get_hash_table(hash_table* hs_table, String name){
    int index = hash(&name, hs_table->vector->mem_size);
    if(hs_table->vector->data[index] != nullptr){
        List *tmp;
        tmp = get_list(hs_table->vector->data[index], &name);
        if( tmp != nullptr)
            return tmp->node;
        else
            return nullptr;
        delete tmp;
    }
}
int remove_hash_table(hash_table *hs_table){
    for(int i = 0; i < hs_table->vector->mem_size; ++i){
        if( hs_table->vector->data[i] != nullptr)
            remove_list(hs_table->vector->data[i]);
    }
    remove_vector(hs_table->vector);

    return 0;
}





