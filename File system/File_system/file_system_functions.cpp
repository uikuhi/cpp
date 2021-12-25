#include "file_system_functions.h"

int Create_file_system(String* path, String* name){
    FILE *fs;

    if( (fs = fopen(path->data, "w")) != nullptr){
        SuperBlock *sp = new SuperBlock;
        for(unsigned int i = 0; i < 16 && i < name->size; ++i)
            sp->name[i] = name->data[i];

        fprintf(fs, "%s %d %d %d\n", sp->name, sp->block_size, sp->i_node_count, sp->block_count);

        Info_addres *inf_add = new Info_addres;
        inf_add->offset_block_array = ftell(fs);
        for(int i = 0; i < sp->block_count; ++i)
            fputc(inf_add->block_array_status[i]+48, fs);

        fprintf(fs, "\n");
        inf_add->offset_i_node = ftell(fs);
        for(int i = 0; i < sp-> i_node_count; ++i){
            fputc(inf_add->i_node_array_status[i]+48, fs);
        }


        String* root_str = Create_string();
        Add_string(root_str, "root");
        User_info* root = Create_user(root_str, fs, inf_add);

        String* root_dir = Create_string();
        Add_string(root_dir, "/");
         Create_dir(root, root_dir);


        delete inf_add;
        delete sp;

        fclose(fs);
    }

    return 0;
}

User_info* Create_user(String* name, FILE* fs, Info_addres* inf_add){
    User_info* user = new User_info;
    user->fs = fs;
    user->inf_add = inf_add;
    user->name = Create_string();
    Add_string(user->name, name->data);
    user->path = Create_string();
    Add_string(user->path, "/");

    return user;
}

void Delete_user(User_info* user){
    Delete_string(user->name);
    Delete_string(user->path);
    delete user;
}

i_node* Create_node(){
    i_node* node = new i_node;
    node->name = Create_string();
    node->owner = Create_string();

    return node;
}

void Delete_node(i_node* node){
    Delete_string(node->name);
    Delete_string(node->owner);
    delete node;
}

User_info* Open_file_system(String* path, String* name){
    FILE* fs;

    if( (fs = fopen(path->data, "r+")) != nullptr){
        fseek(fs, 0, SEEK_SET);
        char sp[255];
        fgets(sp, 255, fs);
        Info_addres* inf_add = new Info_addres;

        inf_add->offset_block_array = ftell(fs);
        for(int i = 0; i < 800; ++i)
            inf_add->block_array_status[i] = fgetc(fs) - 48;

        inf_add->offset_i_node = ftell(fs);
        for(int i = 0; i < 160; ++i)
            inf_add->i_node_array_status[i] = fgetc(fs) - 48;

        fprintf(fs, "\n");
        User_info* user = Create_user(name, fs, inf_add);

        return user;
    }

    return nullptr;
}

int Close_file_system(FILE* fs){
    if(fs != nullptr){
        fclose(fs);
    }

    return 0;
}

void Write_i_node(FILE* fs, i_node* node){

    if(fs != nullptr && node != nullptr){
        fprintf(fs, "%c %s %s ", node->type, node->name->data, node->owner->data);

        if(node->id != 0){
            fprintf(fs, "%d ", node->id);
        } else {
            fprintf(fs, "%d ", 0);
        }
        fprintf(fs, "\n");
    }

}

void Write_block(FILE* fs, Block* bl){
    if(fs != nullptr && bl != nullptr)
        fprintf(fs, "%d %s\n", bl->id, bl->arr);
}

String* Current_dir(User_info* user){

    int len_curr_dir = 0;
    int i = user->path->size;
    for(; user->path->data[i] != '/' && i >= 0; --i)
        ++len_curr_dir;

    char* tmp_dir_name = new char[len_curr_dir+1];

    for(i = 0; i < len_curr_dir+1; ++i)
        tmp_dir_name[i] = user->path->data[ user->path->size - len_curr_dir + i];

    String* dir_name = Create_string();
    if( Strlen(tmp_dir_name) != 1){
        char tmp[128];
        sscanf(tmp_dir_name, "%*c%s", tmp);
        Add_string(dir_name, tmp);

    } else {
        Add_string(dir_name, tmp_dir_name);
    }

    return dir_name;
}

void Create_record(User_info* user,  char *name, char type){
    i_node* node = Create_node();
    Add_string(node->name, name);
    Add_string(node->owner, user->name->data);
    node->type = type;

    int index_node = 0;
    while(user->inf_add->i_node_array_status[index_node] != 0 && index_node < 160)
        index_node++;

    if(user->inf_add->i_node_array_status[index_node] == 0){
        fseek(user->fs, user->inf_add->offset_i_node+index_node, SEEK_SET);
        fputc(49, user->fs);
        user->inf_add->i_node_array_status[index_node] = 1;
        node->id = index_node+1;

        fseek(user->fs, 0, SEEK_END);
        Write_i_node(user->fs, node);
    }

    Delete_node(node);
}

void Write_block_array(FILE* fs, int id_node, int count, int* block_id){
    if(fs != nullptr && block_id != nullptr){
        fprintf(fs, "bl_arr_id %d ", id_node);
        for(int i = 0; i < count; ++i)
            fprintf(fs, "%d ", block_id[i]);

        fprintf(fs, "\n");
    }
}

String* Read_i_node(User_info* user, String* name, char type){
    if(user->fs != nullptr && name != nullptr && user->inf_add != nullptr){
        fseek(user->fs, user->inf_add->offset_i_node+161, SEEK_SET);
        String* node_name;
        char node_str[255];
        char tmp_type;
        int id_node;
        char tmp_node_name[64], node_owner[64];
        do{
            fgets(node_str, 255, user->fs);
            sscanf(node_str, "%c %s %s %d", &tmp_type, tmp_node_name, node_owner, &id_node);
            node_name = Create_string();
            Add_string(node_name, tmp_node_name);
        }while(String_equal(name, node_name) || tmp_type != type && !feof(user->fs) );

        if(!String_equal(node_name, name)){
            String* return_data = Create_string();
            Add_string(return_data, node_str);
            return return_data;
        }
    }

    return nullptr;
}

String* Read_block_array(User_info* user, int id_node){
    if(user->fs != nullptr && user->inf_add != nullptr){
        fseek(user->fs, user->inf_add->offset_i_node+161, SEEK_SET);

        char bl_arr_str[255];
        int id_bl_arr, id_bl;

        do{
            fgets(bl_arr_str, 255, user->fs);
            sscanf(bl_arr_str, "%*s %d %d", &id_bl_arr, &id_bl);
        }while( id_bl_arr != id_node && !feof(user->fs) );


        if( id_bl_arr == id_node ){
            String* return_data = Create_string();
            Add_string(return_data, bl_arr_str);
            return return_data;
        }
    }

    return nullptr;
}

String* Read_block(User_info* user, int id_block){
    if(user->fs != nullptr && user->inf_add != nullptr){
        fseek(user->fs, user->inf_add->offset_i_node+161, SEEK_SET);

        char block_str[255];
        int tmp_id_block = -1;

        do{
            fgets(block_str, 255, user->fs);
            sscanf(block_str, "%d%*s", &tmp_id_block);
        }while( tmp_id_block != id_block && !feof(user->fs) );


        if( tmp_id_block == id_block ){
            String* return_data = Create_string();
            Add_string(return_data, block_str);
            return return_data;
        }
    }

    return nullptr;
}

String* Read_record(User_info* user, String* name, char type){
    if(user->fs != nullptr && name != nullptr && user->inf_add != nullptr){
        String* node_str = Read_i_node(user, name, type);
        if(node_str != nullptr){
            int id_node;
            sscanf(node_str->data, "%*c %*s %*s %d", &id_node);
            String* bl_arr_str = Read_block_array(user, id_node);
            if(bl_arr_str != nullptr){
                int id_block;
                sscanf(bl_arr_str->data, "%*s %*d %d", &id_block);
                String* block_str = Read_block(user, id_block);
               // printf("bl str\t%s\n", block_str->data);

                if(block_str != nullptr){

                    char* data = new char[block_str->size];
                    sscanf(block_str->data, "%*d %s", data);
                    String* return_data = Create_string();
                    Add_string(return_data, data);
                    return return_data;
                }
            }
        }
    }

    return nullptr;
}

void Write_in_file_system(User_info* user, char type, String* name, String* data){
    if(user->fs != nullptr && name != nullptr && data != nullptr){
        String* node_str = Read_i_node(user, name, type);
        if(node_str != nullptr){
            int id_node;
            sscanf(node_str->data, "%*c %*s %*s %d", &id_node);
            String* old_data = Read_record(user, name, type);
            if(old_data != nullptr){

                data = Add_string(old_data, data->data);
                fseek(user->fs, user->inf_add->offset_i_node+161, SEEK_SET);
                int id_bl_arr = -1;
                int id_nodes = -1;
                int offset;
                char file_str[255];
                do{
                    offset = ftell(user->fs);
                    fgets(file_str, 255, user->fs);
                    sscanf(file_str, "%*s%d%d", &id_bl_arr, &id_nodes);
                }while(id_bl_arr != id_node && !feof(user->fs));

                if(id_bl_arr == id_node){
                    fseek(user->fs, offset, SEEK_SET);
                    for(int i = 0; i < Strlen(file_str)-1; ++i)
                        fputs("-", user->fs);

                    fseek(user->fs, user->inf_add->offset_i_node+161, SEEK_SET);
                    int bl_id = - 1;
                    char bl_data[64];
                    do{
                        offset = ftell(user->fs);
                        fgets(bl_data, 64, user->fs);

                        sscanf(bl_data, "%d%*s", &bl_id);

                    }while(bl_id != id_nodes && !feof(user->fs));

                    if(bl_id == id_nodes){
                        fseek(user->fs, offset, SEEK_SET);
                        for(unsigned int i = 0; i < old_data->size; ++i)
                            fputs("-", user->fs);
                        user->inf_add->block_array_status[bl_id] = 0;
                    }
                }
            }

            int count_block = data->size / 524288 + 1;

            Block_arry* bl_arr = new Block_arry;
            bl_arr->id = id_node;
            bl_arr->block_array = new int[count_block];

            for(int i = 0; i < count_block; ++i){
                int index_block = 0;

                while(user->inf_add->block_array_status[index_block] != 0 && index_block < 800)
                    index_block++;

                if(user->inf_add->block_array_status[index_block] == 0){
                    user->inf_add->block_array_status[index_block] = 1;
                    fseek(user->fs, user->inf_add->offset_block_array+index_block, SEEK_SET);
                    fputc(49, user->fs);
                    bl_arr->block_array[i] = index_block;

                    Block* bl = new Block;
                    bl->id = index_block;

                    for(unsigned int j = 0; j < 524288; ++j){
                        if(i* 524288 + j < data->size){
                            bl->arr[j] = data->data[i * 524288 + j];
                        } else {
                            break;
                        }

                    }

                    fseek(user->fs, 0, SEEK_END);
                    Write_block(user->fs, bl);
                    delete bl;
                }
            }
            Write_block_array(user->fs, bl_arr->id, count_block, bl_arr->block_array);
            delete[] bl_arr->block_array;
            delete bl_arr;


        }
    }
}





void Create_file(User_info* user, char* name){
   // printf("user name %s\nfile name %s\n", user->name->data, name);
    Create_record(user, name, 'f');
    String* tmp_name = Create_string();
    Add_string(tmp_name, name);
    String* node = Read_i_node(user, tmp_name, 'f');
    if(node != nullptr){
        char tmp_node_str[255];
        char name[64], owner[64], type;
        int id;
        sscanf(node->data, "%c%s%s%d", &type, name, owner, &id);
        sprintf(tmp_node_str ,"%c_%s_%s_%d", type, name, owner, id);
        String* node_str = Create_string();
        Add_string(node_str, tmp_node_str);
        String *dir_name = Current_dir(user);
        Write_in_dir(user, dir_name, node_str);
    }
}

String* Read_file(User_info* user, String* name){
    return Read_record(user, name, 'f');
}
void Write_in_file(User_info* user, String* name, String* data){
    Write_in_file_system(user, 'f', name, data);
}



void Create_dir(User_info* user, String* name){
    Create_record(user, name->data, 'd' );
    String* sl = Create_string();
    Add_string(sl, "/");

    if(String_equal(name, sl)){
        String* node = Read_i_node(user, name, 'd');
        char tmp_node_str[255];
        char name[64], owner[64], type;
        int id;
        sscanf(node->data, "%c%s%s%d", &type, name, owner, &id);
        sprintf(tmp_node_str, "%c_%s_%s_%d", type, name, owner, id);
        String* node_str = Create_string();
        Add_string(node_str, tmp_node_str);
        String* curr_dir =  Current_dir(user);
        Write_in_dir(user, curr_dir, node_str);
    }

}

String* Read_dir(User_info* user, String* name){
    String* data = Read_record(user, name, 'd');

    return data;
}

void Write_in_dir(User_info* user, String* name, String* data){

    String* ch = Create_string();
    Add_string(ch, ":");
    data = Add_string(data, ch->data);

    Write_in_file_system(user, 'd', name, data);
}


