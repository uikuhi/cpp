#ifndef FILE_SYSTEM_FUNCTIONS_H
#define FILE_SYSTEM_FUNCTIONS_H

#include "String.h"
#include "Structures.h"
#include "File_system_structures.h"
#include <cstdio>

void create_file_system(String name);
void create_dir(String path, String name);
void create_file(String path, String name);

#endif // FILE_SYSTEM_FUNCTIONS_H
