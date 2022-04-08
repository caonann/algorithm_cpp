/*
 @filename   14.cpp
 @author     caonan
 @date       2022-03-24 14:38:02
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/MPnaiL/
 @brief  给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。
         换句话说，第一个字符串的排列之一是第二个字符串的 子串 。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
   public:
    //时间复杂度o(n)~o(m*n) 空间复杂度o(2m)
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length()) {
            return false;
        }
        unordered_map<char, int> tmp;
        for (auto c : s1) {
            tmp[c]++;
        }

        int len = s1.length();
        for (int i = 0; i < s2.length(); i++) {
            int j = i;
            while (j < i + len && j < s2.length()) {
                if (tmp.find(s2[j]) == tmp.end()) {
                    break;
                }
                j++;
            }
            if (j == i + len) {
                unordered_map<char, int> tmp2;
                for (int k = j - len; k < j; k++) {
                    tmp2[s2[k]]++;
                }
                if (tmp2 == tmp) {
                    return true;
                }
            }
        }
        return false;
    }

    //进阶优化
    bool checkInclusion1(string s1, string s2)
    {
        if (s1.length() > s2.length()) {
            return false;
        }
        vector<int> counts(26, 0);
        auto areAllZero = [](const vector<int> &arr) -> bool {
            for (const auto &v : arr) {
                if (v != 0) {
                    return false;
                }
            }
            return true;
        };

        for (int i = 0; i < s1.length(); i++) {
            counts[s1[i] - 'a']++;
            counts[s2[i] - 'a']--;
        }

        if (areAllZero(counts)) {
            return true;
        }

        for (int i = s1.length(); i < s2.length(); i++) {
            counts[s2[i] - 'a']--;
            counts[s2[i - s1.length()] - 'a']++;
            if (areAllZero(counts)) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    assert(s.checkInclusion("aaa", "cdf") == false);
    assert(s.checkInclusion("ab", "eidbaooo") == true);
    assert(s.checkInclusion("ab", "eidboaoo") == false);
    assert(s.checkInclusion("ab", "cccccccba") == true);
    assert(s.checkInclusion("ab", "ba") == true);
    assert(s.checkInclusion("ab", "c") == false);
    assert(s.checkInclusion("aabbc", "aaabc") == false);
    assert(s.checkInclusion("hello", "ooolleoooleh") == false);

    assert(s.checkInclusion1("aaa", "cdf") == false);
    assert(s.checkInclusion1("ab", "eidbaooo") == true);
    assert(s.checkInclusion1("ab", "eidboaoo") == false);
    assert(s.checkInclusion1("ab", "cccccccba") == true);
    assert(s.checkInclusion1("ab", "ba") == true);
    assert(s.checkInclusion1("ab", "c") == false);
    assert(s.checkInclusion1("aabbc", "aaabc") == false);
    assert(s.checkInclusion1("hello", "ooolleoooleh") == false);
    return 0;
}
