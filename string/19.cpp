/*
 @filename   19.cpp
 @author     caonan
 @date       2022-03-31 16:10:15
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/RQku0D/
 @brief   给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。
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
    // todo:用lamada实现递归
    bool validPalindrome(string s)
    {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                break;
            }
            l++;
            r--;
        }
        return r - l <= 1 || isPalindromeStr(s.substr(l + 1, r - l)) || isPalindromeStr(s.substr(l, r - l));
    }

   private:
    bool isPalindromeStr(const string& s)
    {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    assert(s.validPalindrome("aba"));
    assert(s.validPalindrome("abca"));
    assert(!s.validPalindrome("abc"));
    assert(s.validPalindrome(""));
    assert(s.validPalindrome("deeee"));
    assert(s.validPalindrome("eedeeee"));
    assert(s.validPalindrome("aydmda"));
    return 0;
}
