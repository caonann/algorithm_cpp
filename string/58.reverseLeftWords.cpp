// https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/?envType=study-plan-v2&envId=coding-interviews

#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    std::reverse(s.begin(), s.end());
    std::reverse(s.begin(), s.begin() + n);
    std::reverse(s.begin() + n, s.end());
    return s;
  }
};
