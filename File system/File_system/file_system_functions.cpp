#include "file_system_functions.h"

void create_file_system(String name){
    FILE *fs;
    if( (fs = fopen(name.data, "w")) != nullptr){
        SuperBlock *sp = new SuperBlock;
        for(int i = 0; i < 16 && i < name.size; ++i){
            sp->name[i] = name.data[i];
        }

        fwrite(sp, sizeof(struct SuperBlock), 1, fs);

        Info_addres *inf_add = new Info_addres;
        fwrite(inf_add, sizeof(struct Info_addres), 1, fs);
    }
}
