/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   1-1_compare_a_b.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/

#include "common_define.h"

// 1.给定两个数a和b，如何不用比较运算符，返回较大的数。

int flip(int n)
{
    // 和1取亦或 1变0，0变1
    return n ^ 1;
}

// 正数的符号位是0
// 负数的符号位一直是1（最左边一位）

int sign(int n)
{
    return flip((n >> 31) & 1);
}

// 这个版本是有溢出风险的
int compare(int a, int b)
{
    //a b异号 有溢出风险
    int c = a - b;
    int symbola = sign(c);
    // cout << "symbola" << symbola << endl;
    int symbolb = flip(symbola);
    return symbola * a + symbolb * b;
}

// 这个版本解决了溢出风险
int not_overflow_compare(int a, int b)
{
    int c = a - b;
    int symbola = sign(a);
    int symbolb = sign(b);
    int symbolc = sign(c);
    int diffa = symbola ^ symbolb;
    int diffb = flip(diffa);
    int returnA = symbola * diffa + symbolc * diffb;
    int returnB = flip(returnA);
    return returnA * a + returnB * b;
}

int normal_flip(int a, int b)
{
    return a > b ? a : b;
}

TEST(NiuKeAdvancedTests, Flip)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(30, 100);
    int a = u(e);
    int b = u(e);
    EXPECT_TRUE(normal_flip(a, b) == not_overflow_compare(a, b)) << "NiuKeAdvancedTests";
}