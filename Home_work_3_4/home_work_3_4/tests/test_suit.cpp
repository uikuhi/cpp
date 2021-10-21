#include "gtest/gtest.h"
#include "../Translate.h"

TEST( TestForTranslate, num){
    char one[]                      = "00000000000000000000000000000001";
    char check_one[ (sizeof(int) * CHAR_BIT) + 1 ] = {};

    char two[]                      = "00000000000000000000000000000010";
    char check_two[ (sizeof(int) * CHAR_BIT) + 1 ] = {};

    char one_hundred_twenty_seven[] = "00000000000000000000000001111111";
    char check_one_hundred_twenty_seven[ (sizeof(int) * CHAR_BIT) + 1 ] = {};

    translateDecToBin(1, check_one);
    translateDecToBin(2, check_two);
    translateDecToBin(127, check_one_hundred_twenty_seven);

    EXPECT_STREQ(one, check_one);
    EXPECT_STREQ(two, check_two);
    EXPECT_STREQ(one_hundred_twenty_seven, check_one_hundred_twenty_seven);


}

