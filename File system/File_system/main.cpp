#include "file_system_functions.h"
#include "File_system_structures.h"
#include "String.h"
#include <stdio.h>
#include "system_cmd.h"
#include "shell.h"

int main(){

   String *path = Create_string();
   String *name = Create_string();
   Add_string(path , "/home/whoami/c++ course/cpp/File system/test/test_fs.txt");
   Add_string(name, "test_fs.txt");

   Shell();
   
   return 0;
}
