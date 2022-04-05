/*
 @filename   20.cpp
 @author     caonan
 @date       2022-04-01 01:56:02
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/a7VOhD/
 @brief     给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。
    具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
    s 由小写英文字母组成
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
   public:
    //时间o(n^2) 空间o(1)
    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            int kl = i, kr = i;
            while (kl >= 0 && kr < s.length() && s[kl--] == s[kr++]) {
                count++;
            }
            kl = i, kr = i + 1;
            while (kl >= 0 && kr < s.length() && s[kl--] == s[kr++]) {
                count++;
            }
        }
        return count;
    }
    //进阶，Manacher 算法 时间o(n) 空间o(n)
    // Manacher 算法是在线性时间内求解最长回文子串的算法
    int countSubstrings1(string s) {}

    // dp方法 todo:
    int countSubstrings2(string s) {}
};

int main()
{
    Solution s;
    assert(3 == s.countSubstrings("abc"));
    assert(6 == s.countSubstrings("aaa"));
    assert(6 == s.countSubstrings("fdsklf"));
    return 0;
}
