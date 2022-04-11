/*
 @filename   34.cpp
 @author     caonan
 @date       2022-04-11 06:20:49
 @reference   剑指offer专项
 @url      https://leetcode-cn.com/problems/lwyVBB/
 @brief  某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。
给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回
true；否则，返回 false
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
   public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        if (words.size() <= 1) {
            return true;
        }
        unordered_map<char, int> weight_map;
        int w = 0;
        for (const auto& c : order) {
            weight_map[c] = w++;
        }
        auto compare_str = [&weight_map](const string& s1, const string& s2) -> bool {
            auto it1 = s1.cbegin();
            auto it2 = s2.cbegin();
            while (it1 != s1.cend() && it2 != s2.cend()) {
                if (weight_map[*it1] == weight_map[*it2]) {
                    ++it1;
                    ++it2;
                    continue;
                }
                return weight_map[*it1] > weight_map[*it2] ? false : true;
            }

            if (it1 != s1.cend()) return false;
            return true;
        };
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compare_str(words[i], words[i + 1])) return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<string> in{"hello", "leetcode"};
    assert(s.isAlienSorted(in, "hlabcdefgijkmnopqrstuvwxyz"));
    return 0;
}
