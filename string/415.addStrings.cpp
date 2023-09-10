/*
 @filename   string/415.addStrings.cpp
 @author     caonan
 @date       2023-09-09 11:00:47
 @reference  leetcode
 @url      https://leetcode.cn/problems/add-strings/description/
 @brief   字符串操作
*/
#include <cassert>
#include <climits>
#include <cstdio>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    string ans;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
      int x = i >= 0 ? num1[i] - '0' : 0;
      int y = j >= 0 ? num2[j] - '0' : 0;
      int sum = x + y + carry;
      ans.push_back(sum % 10 + '0');
      carry = sum / 10;
      i--, j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  string a = "123";
  string b = "45";
  Solution s;
  auto ret = s.addStrings(a, b);
  cout << ret << endl;
  return 0;
}
