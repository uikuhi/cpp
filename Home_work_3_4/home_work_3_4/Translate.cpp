#include "Translate.h"

void translateDecToBin(int n, char* num){

    for(int i = (sizeof(n) * CHAR_BIT) - 1; i >= 0; --i){
        num[(sizeof(n) * CHAR_BIT) - 1 - i] = ( n & (1 << i)) ? '1' : '0';
    }

    num[ (sizeof(n) * CHAR_BIT) ] = '\0';
}
