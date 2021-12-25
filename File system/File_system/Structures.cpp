#include "functions_external.h"
#include "Structures.h"
#include "String.h"

Vector* Create_vector(){
    Vector* result = new Vector;
    result->size = 0;
    result->mem_size = 10;
    result->data = new List*[result->mem_size];

    return result;
}

int Delete_element_vector(Vector* vector, unsigned int index){
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

int Add_element_vector(Vector* vector,unsigned int index, List* data){
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

        return Add_element_vector(vector, index,data);

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

            return 1;
        }
    }
}

List* Get_vector(Vector* vector, unsigned int index){
    if(vector == nullptr || vector->size <= index){
        return nullptr;
    }

    return vector->data[index];
}


int Remove_vector(Vector* vector){
    if(vector == nullptr)
        return 0;

    delete[] vector->data;
    delete vector;

    return 0;
}


List* Create_list(){
    List* list = new List;
    list->name = Create_string();
    list->node = nullptr;
    list->next = nullptr;

    return list;
}

int Add_element_list(List* list, i_node* node){
        List* tmp = list;
 //       printf("list name\t%s\nnode name\t%s\n", list->name->data, node->name->data);
    while(tmp->next != nullptr)
        tmp = tmp->next;
//printf("bool tmp eq\t%d\nbool str eq\t%d\n", tmp != list || String_equal(list->name, node->name));
    if(tmp != list || String_equal(list->name, node->name) ){
    //    printf("1node\t%c %s %s %d\n",node->type, node->name->data, node->owner->data, node->id);
        List* last = Create_list();
        last->node = node;
        Add_string(last->name, node->name->data);
        tmp->next = last;
        //printf("lart name\t%s\n", last->name->data);
    } else {
        list->node = node;
        Add_string(list->name, node->name->data);

    }
       // Add_string(list->name, node->name->data);


    return 0;
}

List* Get_list(List* list, String* name){
    if(list != nullptr){
        List* tmp;
        tmp = list;
//printf("!!!!tmp_name\t%s\tname\t%s\n", tmp->name->data, name->data);
//printf("bool\t%d\n", String_equal(tmp->name, name) != 0);
        while( String_equal(tmp->name, name) != 0 ){
            //printf("tmp_name\t%s\n", tmp->name->data);
            if(tmp->next == nullptr)
                return nullptr;
            tmp = tmp->next;
        }

        return tmp;
    }

    return nullptr;
}

int Delete_element_list(List* list, String name){
    if(list != nullptr){

       bool found = false;
       List* old_ptr = list;

       do {
           if( String_equal(list->name, &name) == 0 )
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

int Remove_list(List* list){
    List* tmp;
    tmp = list;
    bool all = false;
    while(!all){
        while(tmp->next != nullptr)
            tmp = tmp->next;

        Delete_string(tmp->name);
        // delete node
        delete tmp->next;

        if(tmp ==  list){
            all = true;
            delete tmp;
        }
    }
    return 0;
}

Hash_Table* Create_hash_table(){
    Hash_Table* tmp = new Hash_Table;
    for(unsigned int i = 0; i < 20; ++i)
        tmp->hs[i] = nullptr;

    return tmp;
}

int Add_hash_table(Hash_Table* hs_table, i_node* element){
    int index = 0; //Hash(element->name, hs_table->vector->mem_size);
//printf("1node\t%c %s %s %d\n",element->type, element->name->data, element->owner->data, element->id);
    if(hs_table->hs[index] == nullptr){
     //   printf("q\n");

        hs_table->hs[index] = Create_list();
        Add_element_list(hs_table->hs[index], element);

    } else {
    //    printf("p\n");
        Add_element_list(hs_table->hs[index], element);
    }

    return 0;
}

int Delete_element_hash_table(Hash_Table* hs_table, String name){
    int index = 0; //Hash(&name, hs_table->vector->mem_size);

    if(hs_table->hs[index] != nullptr){
        Delete_element_list(hs_table->hs[index], name);
    }

    return 0;
}

i_node* Get_hash_table(Hash_Table* hs_table, String* name){
    int index = 0; //Hash(&name, hs_table->vector->mem_size);
    if(hs_table->hs[index] != nullptr){
        List *tmp;
      //  printf("name hs\t%s\n", hs_table->hs[0]->node->name->data);

        tmp = Get_list(hs_table->hs[index], name);
      // printf("list name\t%s\n", tmp->node->name->data);
        if( tmp != nullptr)
            return tmp->node;
        else
            return nullptr;
        delete tmp;
    }

    return nullptr;
}
int Remove_hash_table(Hash_Table *hs_table){
    for(unsigned int i = 0; i < 20; ++i){
        if( hs_table->hs[i] != nullptr)
            Remove_list(hs_table->hs[i]);
    }
    delete hs_table;

    return 0;
}
