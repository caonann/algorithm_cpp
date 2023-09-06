/*
 @filename   32.cpp
 @author     caonan
 @date       2022-04-10 15:03:59
 @reference   剑指offer专项
 @url      https://leetcode-cn.com/problems/dKk3P7/
 @brief  给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）。
注意：若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同，则称 s 和 t 互为变位词（字母异位词）。
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
    bool isAnagram(string s, string t)
    {
        vector<int> hash_set(26,0);
        for (auto c : s) {
            hash_set[c - 'a']++;
        }
        for (auto c : t) {
            hash_set[c - 'a']--;
        }
        for (auto n : hash_set) {
            if (n != 0) {
                return false;
            }
        }
        if (s == t) return false;
        return true;
    }
};

int main() { 
    Solution s;
    assert(s.isAnagram("anagram","nagaram"));
    assert(!s.isAnagram("rat","car"));
    assert(!s.isAnagram("a","a"));
    return 0; }
