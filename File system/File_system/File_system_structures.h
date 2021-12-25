#ifndef FILE_SYSTEM_STRUCTURES_H
#define FILE_SYSTEM_STRUCTURES_H

#include "String.h"
#include "Structures.h"
#include <cstdio>


struct Block{
    int id;
    char arr[524288] = {'\0'};
}; // 512 kbit

struct i_node {
    char type;
    String* name;
    String* owner;
    int id;
}; // 20bit name + 20bit owner + 8bit pointer * 5 = 80bit
// i node + block ~= 2.5 Mbit

struct Block_arry{
    int id;
    int* block_array;
};

struct Info_addres {
    int offset_i_node;
    int offset_block_array;
    int i_node_array_status[160] = {0};
    int block_array_status[800] = {0};
};

struct SuperBlock {
    char name[16];
    int block_size = 524288; // size block 512k = 524'288 byte 4'194'304 bit.
    int i_node_count = 160; //  One block for i-node => i-node count 4'194'304.
    int block_count = 800; // Three block for block_status => block_count = 1'572'864.
}; //

// sizeof information space

struct User_info{
    FILE* fs;
    Info_addres* inf_add;
    String* name;
    String* path;
};



#endif // FILE_SYSTEM_STRUCTURES_H
