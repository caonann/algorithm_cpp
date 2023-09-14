/*
 @filename   16.cpp
 @author     caonan
 @date       2022-03-28 14:45:21
 @reference   剑指offer专项
 @url      https://leetcode-cn.com/problems/wtcaE1/
 @brief   给定一个字符串 s ，请你找出其中不含有重复字符的 最长连续子字符串的长度。
*/
#include <cassert>
#include <cstdio>

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    unordered_set<char> map_store;
    int left = 0;
    for (int right = 0; right < s.size();) {
      if (map_store.find(s[right]) == map_store.end()) {
        map_store.insert(s[right]);
        max_len = std::max(max_len, right - left + 1);
        ++right;
      } else {
        map_store.erase(s[left++]);
      }
    }

    return max_len;
  }

  // asii码有最多256个，可以用固定大小的的数组表示
  int lengthOfLongestSubstring1(string s) {
    vector<int> counts(256, 0);
    // 每次都遍历了整个数组，效率不高
    auto is_greater_than1 = [](const vector<int>& counts) -> bool {
      for (const auto& v : counts) {
        if (v > 1) {
          return true;
        }
      }
      return false;
    };
    int left = -1;
    int max_len = 0;
    for (int right = 0; right < s.size(); ++right) {
      counts[s[right]]++;
      while (is_greater_than1(counts)) {
        ++left;
        counts[s[left]]--;
      }
      max_len = std::max(max_len, right - left);
    }

    return max_len;
  }

  // 在lengthOfLongestSubstring1的基础上优化掉遍历counts的开销
  // 因为右边每次加入新元素，如果有重复，那必然大于1，于是left右移直到将counts[s[right]]减下去
  int lengthOfLongestSubstring2(string s) {
    vector<int> counts(256, 0);
    int left = -1;
    int max_len = 0;
    for (int right = 0; right < s.size(); ++right) {
      counts[s[right]]++;
      while (counts[s[right]] > 1) {
        ++left;
        counts[s[left]]--;
      }
      max_len = std::max(max_len, right - left);
    }

    return max_len;
  }
};

int main() {
  Solution s;
  assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
  assert(s.lengthOfLongestSubstring("bbbbb") == 1);
  assert(s.lengthOfLongestSubstring("pwwkew") == 3);
  assert(s.lengthOfLongestSubstring("tmmzuxt") == 5);

  assert(s.lengthOfLongestSubstring1("abcabcbb") == 3);
  assert(s.lengthOfLongestSubstring1("bbbbb") == 1);
  assert(s.lengthOfLongestSubstring1("pwwkew") == 3);
  assert(s.lengthOfLongestSubstring1("tmmzuxt") == 5);

  assert(s.lengthOfLongestSubstring2("abcabcbb") == 3);
  assert(s.lengthOfLongestSubstring2("bbbbb") == 1);
  assert(s.lengthOfLongestSubstring2("pwwkew") == 3);
  assert(s.lengthOfLongestSubstring2("tmmzuxt") == 5);
  return 0;
}
