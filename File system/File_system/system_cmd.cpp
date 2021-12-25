#include "system_cmd.h"

void Ls(User_info *user){
    String* dir = Current_dir(user);
    String* data = Read_dir(user, dir);

    char node_sub[256], another_node_sub[265], tmp_node_sub[256], node_name[64], owner[64], type;
    int id;

    if(data != nullptr){
        i_node* node;
        String* pointer = Create_string();
        String* tmp_nd_sub;
        Add_string(pointer, ":");
        do{
            node = Create_node();
            tmp_nd_sub = Create_string();
            sscanf(data->data, "%[^:] %s", node_sub, tmp_node_sub);
            Add_string(tmp_nd_sub, tmp_node_sub);
            sscanf(node_sub, "%[^_]%*c%[^_]%*c%[^_]%*c%d", &type, node_name, owner, &id);

            node->type = type;
            Add_string(node->name, node_name);
            Add_string(node->owner, owner);
            node->id = id;

            printf("%c %s %s\n",node->type, node->name->data, node->owner->data);

            sscanf(tmp_node_sub, "%*c%s", another_node_sub);
            data = Create_string();
            Add_string(data, another_node_sub);

        } while( String_equal(pointer, tmp_nd_sub) );
    }
}

void Cat(User_info* user, String* name){
    String* data = Read_file(user, name);
    printf("%s\n", data->data);
}

void Touch(User_info* user, String* name){
    Create_file(user, name->data);
}

void Mkdir(User_info* user, String* name){
    Create_dir(user, name);
}

void Write(User_info* user, String* name){

    String* dir_str = Read_dir(user, Current_dir(user));
    char node_sub[256], another_node_sub[265], tmp_node_sub[256], node_name[64], owner[64], type;
    int id;

    if(dir_str != nullptr){
        i_node* node;
        String* pointer = Create_string();
        String* tmp_nd_sub;
        Add_string(pointer, ":");
        do{
            node = Create_node();
            tmp_nd_sub = Create_string();
            sscanf(dir_str->data, "%[^:] %s", node_sub, tmp_node_sub);
            Add_string(tmp_nd_sub, tmp_node_sub);
            sscanf(node_sub, "%[^_]%*c%[^_]%*c%[^_]%*c%d", &type, node_name, owner, &id);

            node->type = type;
            Add_string(node->name, node_name);
            Add_string(node->owner, owner);
            node->id = id;
            sscanf(tmp_node_sub, "%*c%s", another_node_sub);
            dir_str = Create_string();
            Add_string(dir_str, another_node_sub);
        } while( String_equal(pointer, tmp_nd_sub) && String_equal(node->name, name) );

        if(!String_equal(node->name, name)){
            char str[512];
            printf("Enter data> ");
            scanf("%s", str);
            printf("\n");
            String* data = Create_string();
            Add_string(data, str);
            Write_in_file(user, name, data);
        }
        getchar();

    }
}
