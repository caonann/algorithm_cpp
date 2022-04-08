/*
 @filename   18.cpp
 @author     caonan
 @date       2022-03-31 15:07:30
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/XltzEq/
 @brief     给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。
            本题中，将空字符串定义为有效的 回文串
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
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        auto isLetterOrDig = [](char c) -> bool {
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') return true;
            return false;
        };
        while (left < right) {
            while (left < s.length() && !isLetterOrDig(s[left])) {
                left++;
            }
            while (right >= 0 && !isLetterOrDig(s[right])) {
                right--;
            }
            if (left < right && std::tolower(s[left++]) != std::tolower(s[right--])) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    assert(s.isPalindrome("abcba"));
    assert(!s.isPalindrome("abcb"));
    assert(s.isPalindrome("amanaplanacanalpanama"));
    assert(s.isPalindrome("A man, a plan, a canal: Panama"));
    assert(!s.isPalindrome("race a car"));
    assert(s.isPalindrome(""));
    assert(s.isPalindrome(" "));
    return 0;
}
