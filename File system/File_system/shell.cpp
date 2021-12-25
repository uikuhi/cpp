#include "shell.h"
#include <cstdlib>
#include "String.h"
#include "system_cmd.h"
#include "file_system_functions.h"
#include "File_system_structures.h"
void Shell(){
    FILE* fs;

String* help = Create_string();
String* create_fs = Create_string();
String* exit_str = Create_string();
String* open_fs = Create_string();
String* fs_list = Create_string();
Add_string(help, "help");
Add_string(create_fs, "createfs");
Add_string(exit_str, "exit");
Add_string(open_fs, "openfs");
Add_string(fs_list, "listfs");

        char cmd_str[128];
        char cmd_tmp[128] = {'\0'};
        String* cmd;
    do{

        printf("\n> ");
        scanf("%s", cmd_str);
        sscanf(cmd_str, "%s %*s", cmd_tmp);
        cmd = Create_string();
        Add_string(cmd, cmd_tmp);

        if( !String_equal(cmd, fs_list) ){
            if( (fs = fopen("./File_systems_list.txt", "r")) != nullptr){
                while( !feof(fs) ){
                    char tmp_path[128];
                    fgets(tmp_path, 128, fs);
                    printf("%s\n", tmp_path);
                }
                fclose(fs);
            }

        } else if( !String_equal(cmd, create_fs)){
            String* path = Create_string();
            char path_str[128];
            printf("Enter path: ");
            scanf("%s", path_str);
            printf("\n");
            Add_string(path, path_str);


            int fs_len_name = 0;
            int i = path->size;
            for(; path->data[i] != '/' && i >= 0; --i)
                ++fs_len_name;

            char* tmp_fs_name = new char[fs_len_name+1];

            for(i = 0; i < fs_len_name; ++i)
                tmp_fs_name[i] = path->data[ path->size - fs_len_name + i+ 1];
            String* fs_name = Create_string();
            Add_string(fs_name, tmp_fs_name);
            printf("fs name\t%s\n", fs_name->data);
            if( (fs = fopen(path->data, "w")) != nullptr){
                printf("path\t%s\n", path->data);
                Create_file_system(path, fs_name);
                fclose(fs);

                if( (fs = fopen("./File_systems_list.txt", "a")) != nullptr){
                    fputs(path_str, fs);
                    fputs("\n", fs);
                    fclose(fs);
                }
            }


        } else if( !String_equal(cmd, open_fs) ){
            String* path = Create_string();
            char path_str[128];
            printf("Enter path: ");
            scanf("%s", path_str);
            printf("\n");
            Add_string(path, path_str);



            if( (fs = fopen(path->data, "r")) != nullptr){
                String* login = Create_string();
                char tmp_login[128];
                printf("Enter login> ");
                scanf("%s", tmp_login);
                getchar();
                Add_string(login, tmp_login);
                User_info* user = Open_file_system(path, login);
                Hash_Table* hs = Create_hash_table();

                char fs_cmd_str[128] = {'\0'};
                char fs_cmd_str_tmp[128] = {'\0'};
                char fs_cmd_tmp[128] = {'\0'};
                char fs_cmd_data[128] = {'\0'};
                String* fs_cmd;
                String* name;

                String* Ls_str = Create_string();
                String* Cat_str = Create_string();
                String* Touch_str = Create_string();
                String* Mkdir_str = Create_string();
                String* Write_str= Create_string();
                String* Cd_str = Create_string();
                Add_string(Ls_str, "ls");
                Add_string(Cat_str, "cat");
                Add_string(Touch_str, "touch");
                Add_string(Mkdir_str, "mkdir");
                Add_string(Write_str, "write");
                Add_string(Cd_str, "cd");

                do{
                    printf("%s> ", user->path->data);
                    gets(fs_cmd_str);
                    sscanf(fs_cmd_str, "%s%*s", fs_cmd_tmp);
                    fs_cmd = Create_string();
                    Add_string(fs_cmd, fs_cmd_tmp);
             //       printf("cmd\t%s\ncmd data\t%s", fs_cmd->data, fs_cmd_data);
                    if( !String_equal(fs_cmd, Ls_str) ){
                        Ls(user);
                    } else if( !String_equal(fs_cmd, Cat_str) ){
                        sscanf(fs_cmd_str, "%*s %s", fs_cmd_data);
                        name = Create_string();
                        Add_string(name, fs_cmd_data);
                        String* data = Read_file(user, name);
                        if(data != nullptr)
                            printf("%s\n", data->data);
                    } else if( !String_equal(fs_cmd, Touch_str) ){
                        sscanf(fs_cmd_str, "%*s %s", fs_cmd_data);
                        name = Create_string();
                        Add_string(name, fs_cmd_data);
                        Create_file(user, name->data);
                    } else if( !String_equal(fs_cmd, Mkdir_str) ){
                        sscanf(fs_cmd_str, "%*s %s", fs_cmd_data);
                        name = Create_string();
                        Add_string(name, fs_cmd_data);
                        Create_dir(user, name);
                    } else if( !String_equal(fs_cmd, Write_str) ){
                        sscanf(fs_cmd_str, "%*s %s", fs_cmd_data);
                        name = Create_string();
                        Add_string(name, fs_cmd_data);
                        Write(user, name);
                    } else if( !String_equal(fs_cmd, Cd_str) ) {
                        sscanf(fs_cmd_str, "%*s %s", fs_cmd_data);
                        name = Create_string();
                        String* dp = Create_string();
                        Add_string(dp, "..");
                        Add_string(name, fs_cmd_data);
                        if( !String_equal(dp, name) ){
                            int len_pwd = Strlen(Current_dir(user)->data);
                            if(len_pwd > 1){
                                char* tmp_dir_name = new char[user->path->size - len_pwd +1];
                                printf("p-d %d\n", user->path->size - Current_dir(user)->size );
                                if( user->path->size - Current_dir(user)->size > 1 ){
                                    for(int i = 0; i < user->path->size - len_pwd-1; ++i)
                                        tmp_dir_name[i] = user->path->data[i];
                                } else {
                                    for(int i = 0; i < user->path->size - len_pwd; ++i)
                                        tmp_dir_name[i] = user->path->data[i];
                                }

                                user->path = Create_string();
                                Add_string(user->path, tmp_dir_name);
                            }
                        } else {
                            String* sl = Create_string();
                            Add_string(sl, "/");
                            if( String_equal(user->path, sl) )
                                Add_string(user->path, "/");
                            Add_string(user->path, name->data);
                        }
                    } else if( !String_equal(fs_cmd, help) ) {
                        printf("%s\n%s\n%s\n%s\n%s\n%s\n", help->data, Ls_str->data, Cat_str->data, Touch_str->data, Mkdir_str->data, Write_str->data, Cd_str->data);
                    } else if( !String_equal(fs_cmd, exit_str)){
                        break;
                    } else {
                        printf("Not found command\n");
                    }


                }while(1);


            }

        } else if( !String_equal(cmd, help) ){
            printf("%s\n%s\n%s\n%s\n%s", help->data, fs_list->data, create_fs->data, open_fs->data, exit_str->data);
            Delete_string(cmd);
        }
        else if( !String_equal(cmd, exit_str) ){
            exit(0);
        } else {
            printf("Not found command\n");
        }



    } while(1);
}
