#include "gtest/gtest.h"
#include "../Task.h"

TEST( TestForTask_3_3, OnlyNum ){
    int n = Task_3_3(1234);
    int res = 4231;

    EXPECT_EQ(n, res);
}

//TEST( TestForTask_3_3, InputNumWithChars){
//    int n = Task_3_3("1234 test1234");
//}
