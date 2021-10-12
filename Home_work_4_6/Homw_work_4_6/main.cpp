#include <stdio.h>

int main()
{

    constexpr size_t size = 255;
    char str[size];
    printf("Enter bracket expression: ");
    gets(str);

    int count_parenthesis       = 0;
    int count_square_bracket    = 0;
    int count_brace             = 0;

    for(char *current = str; *current; ++current){
        switch(*current){

            case '(':
                ++count_parenthesis;
                break;

            case ')':
                --count_parenthesis;
                break;

            case '[':
                ++count_square_bracket;
                break;

            case ']':
                --count_square_bracket;
                break;

            case '{':
                ++count_brace;
                break;

            case '}':
                --count_brace;

        }
    }

    printf("%d () | %d [] | %d {}\n", count_parenthesis, count_square_bracket, count_brace);

    if( count_brace || count_parenthesis || count_square_bracket){
        printf("Error\n");
    } else {
        printf("All right\n");
    }

    return 0;
}
