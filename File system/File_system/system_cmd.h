#ifndef SYSTEM_CMD_H
#define SYSTEM_CMD_H

#include "file_system_functions.h"

void Ls(User_info *user);
void Cat(User_info* user, String* name);
void Touch(User_info* user, String* name);
void Mkdir(User_info* user, String* name);
void Write(User_info* user, String* name);


#endif // SYSTEM_CMD_H
