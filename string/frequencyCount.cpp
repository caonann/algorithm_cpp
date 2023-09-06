/*
 @filename   frequency_count.cpp
 @author     caonan
 @date       2022-04-15 04:07:00
 @reference     群里收集的
 @url
 @brief  输入一个字符串，输出频率最高且最先出现的数字
 aabbbc 返回 b
 abbbaa 返回 a
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

char findFrequencyChar(string s)
{
    unordered_map<char, int> count_map;
    char ans;
    int max_count = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (++count_map[s[i]] >= max_count) {
            max_count = count_map[s[i]];
            ans = s[i];
        }
    }
    return ans;
}

int main() { 
    assert(findFrequencyChar("aabbbc") == 'b');
    assert(findFrequencyChar("abbbaa") == 'a');
    return 0; }
