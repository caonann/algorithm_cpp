/*
 @filename   33.cpp
 @author     caonan
 @date       2022-04-10 15:28:58
 @reference   剑指offer专项
 @url      https://leetcode-cn.com/problems/sfvd7V/
 @brief  给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。
注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。
*/
#include <cassert>
#include <cstdio>

#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  //自己写的第一版，统计字符串出现次数后作为hash的key
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hash_map;
    auto counts_to_key = [](const array<int, 26>& arr) -> string {
      string key;
      for (auto n : arr) {
        key += std::to_string(n) + "#";
      }
      return key;
    };
    for (const auto& str : strs) {
      array<int, 26> counts{};
      for (const auto c : str) {
        counts[c - 'a']++;
      }
      string key = counts_to_key(counts);
      hash_map[key].emplace_back(str);  //放入key时，会自动创建vector<string>所以不用判断元素是否存在
    }
    vector<vector<string>> ans;
    ans.reserve(hash_map.size());
    for (const auto& item : hash_map) {
      ans.emplace_back(item.second);
    }
    return ans;
  }
};

class Solution1 : public Solution {
 public:
  //基于排序的方法
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hash_map;
    for (const auto& str : strs) {
      string key = str;
      std::sort(key.begin(), key.end());
      hash_map[key].emplace_back(str);
    }

    vector<vector<string>> ans;
    for (const auto& item : hash_map) {
      ans.emplace_back(item.second);
    }
    return ans;
  }
};

class Solution2 : public Solution {
 public:
  //计数方法的另一种简化写法,这种方法计算hash值比最开始的solution快
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    auto hashfunc = [fn = hash<int>{}](const array<int, 26>& arr) -> size_t {
      return accumulate(arr.cbegin(), arr.cend(), 0,
                        [&fn](int total, int num) -> int { return (total << 1) ^ fn(num); });
    };

    unordered_map<array<int, 26>, int, decltype(hashfunc)> hash_map(0, hashfunc);
    vector<vector<string>> ans;
    for (const auto& str : strs) {
      array<int, 26> counts{};
      for (const auto& c : str) {
        counts[c - 'a']++;
      }
      if (hash_map.find(counts) != hash_map.end()) {
        ans[hash_map[counts]].emplace_back(str);
      } else {
        hash_map[counts] = ans.size();
        ans.emplace_back(vector<string>{str});
      }
    }
    return ans;
  }
};
int main() {
  Solution2 s;
  vector<string> in{"bdddddddddd", "bbbbbbbbbbc"};
  auto ans = s.groupAnagrams(in);
  for (const auto& v : ans) {
    for (const auto& vv : v) {
      cout << vv << " ";
    }
  }
  return 0;
}
