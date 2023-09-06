/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   1.3_chkRotation.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/
#include "common_define.h"
// https://www.nowcoder.com/study/vod/1/1/4

class Rotation
{
public:
    bool chkRotation(string A, int lena, string B, int lenb)
    {
        // write code here
        if (A.size() != B.size() || lena != lenb)
        {
            return false;
        }

        std::string c = A + A;

        if (c.find(B) != std::string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    bool kmp(string &a, string &b)
    {
        return true;
    }
};

// g++ 1.3_chkRotation.cpp  -lgtest_main -lgtest -lpthread -std=c++11
namespace
{

TEST(NiuKeBatTests, CHKRotaiton)
{
    Rotation r;
    EXPECT_TRUE(r.chkRotation("1234", 4, "2341", 4)) << "1234 is  2341 's rotate arr";
    EXPECT_FALSE(r.chkRotation("1234", 4, "2134", 4)) << "1234 is not 2134 's rotate arr";
    // EXPECT_TRUE(r.chkRotation("1234",4,"2134",4));
}

}
