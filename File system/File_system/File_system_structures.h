#ifndef FILE_SYSTEM_STRUCTURES_H
#define FILE_SYSTEM_STRUCTURES_H

#include "String.h"

struct Block{
    char arr[524288] = {};
};

struct i_node {
    String* name;
    String* owner;
    Block *array[5];
};

struct Info_addres {
    char i_node_array_status[21] = {};
    char block_array_status[101] = {};
};

struct SuperBlock {
    char name[16];
    int block_size = 524288; // size block 512k = 524'288 byte 4'194'304 bit.
    int i_node_count = 160; //  One block for i-node => i-node count 4'194'304.
    int block_count = 800; // Three block for block_status => block_count = 1'572'864.
    i_node Root_directory;
    Info_addres* info;
};



#endif // FILE_SYSTEM_STRUCTURES_H
