/*
 @filename   151.reverseWords.cpp
 @author     caonan
 @date       2022-04-29 09:15:17
 @reference leetcode
 @url      https://leetcode-cn.com/problems/reverse-words-in-a-string/
 @brief  给你一个字符串 s ，颠倒字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串
s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
   public:
    string reverseWords(string s)
    {
        std::reverse(s.begin(), s.end());
        int idx = 0;
        int start = 0;
        while (start < s.size()) {
            if (s[start] != ' ') {
                if (idx != 0) s[idx++] = ' ';
                int end = start;
                while (end < s.size() && s[end] != ' ') s[idx++] = s[end++];
                std::reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
            start++;
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

int main()
{
    Solution s;
    s.reverseWords("  hello world hulk   ");
    return 0;
}
