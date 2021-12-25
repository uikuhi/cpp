#include "file_system_functions.h"
#include "File_system_structures.h"
#include "String.h"
#include <stdio.h>
#include "system_cmd.h"
#include "shell.h"

int main(){
// /whoami/c++ course/cpp/File system/test/test_fs.txt
   String *path = Create_string();
   String *name = Create_string();
   Add_string(path , "/home/whoami/c++ course/cpp/File system/test/test_fs.txt");
   Add_string(name, "test_fs.txt");
//    Add_string(str, "home");
//    printf("%s\n", str->data);
   Shell();

//    String* user_name = Create_string();
//    Add_string(user_name, "misha");
//    User_info* user = Open_file_system(path, user_name);
//    Hash_Table* hs = Create_hash_table();


//    String* file = Create_string();
//    Add_string(file, "test");
//    Touch(user, file);
//    Write(user, file);
//    Cat(user, file);
//    Ls(user, hs);
//    String* dir = Create_string();
//    Add_string(dir, "home");
//    Mkdir(user, dir);

//    Ls(user, hs);



//    String* file = Create_string();
//    Add_string(file, "test");
//    Create_file(user, file->data);


//    String* data = Create_string();
//    Add_string(data, "test");
//    Write_in_file(user, file, data);
//    data = Create_string();
//    Add_string(data, "qwerty");
//    Write_in_file(user, file, data);

//    file = Create_string();
//    Add_string(file, "test2");
//    Create_file(user, file->data);

//    data = Create_string();
//    Add_string(data, "qwerty");
////    Write_in_file(user, file, data);

//    String* dir = Create_string();
//    Add_string(dir, "home");
//    Create_dir(user, dir);
//    dir = Create_string();
//        Add_string(dir, "/");
//    Hash_Table* hs = Create_hash_table();
//    Ls(user, dir, hs);
//    Create_record(user, file->data, 'f');
//    String* node_str = Read_i_node(user, file, 'f');
//  // rintf("i node\t%s\n", node_str->data);
//    String* data1 = Create_string();
//    Add_string(data1, "qwerty");
//    Write_in_file_system(user, 'f', file, data1);
//    data1 = Create_string();
//        Add_string(data1, "test");
//        Write_in_file_system(user, 'f', file, data1);
//    String* data = Read_record(user, file, 'f');
//  printf("data\t%s\n", data->data);






    return 0;
}
