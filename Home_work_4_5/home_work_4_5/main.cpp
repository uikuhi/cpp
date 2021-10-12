#include <stdio.h>

int main()
{
    constexpr size_t size = 255;
    char str[size] = {};
    printf("Enter string: ");
    gets(str);

    char result[size] = {};
    char *current_res = result;

    char *sub_start = str;
    int count = 0;
    for(char *current = str; ; ++current){

        if(*current == ' ' || !(*current)){
            ++current;
            count = current - sub_start;

            if( count % 2 != 0){
                for(int i = 0; i < count; ++i){
                    *current_res = *(sub_start + i);
                    ++current_res;
                }
            }
            sub_start = current;
        }

        if( !(*current)){
            break;
        }
    }

    printf("\n==============================\n\n");
    printf("%s\n\n", result);

    return 0;
}
