// Translate dec -> bin
#include "Translate.h"

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    char num[ (sizeof(int) * CHAR_BIT) + 1 ] = {};

    translateDecToBin(n, num);
    printf("%s\n", num);

    return 0;
}
