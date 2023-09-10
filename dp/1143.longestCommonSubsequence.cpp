/*
 @filename   arrary/1143.longestCommonSubsequence.cpp
 @author     caonan
 @date       2023-09-09 10:00:30
 @reference  leetcode
 @url      https://leetcode.cn/problems/longest-common-subsequence/
 @brief 需要用到二维DP,dp的关键在于推导转移方程，本质上是遍历的过程中记录中间结果，减少重复计算
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
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    // dp这里在初始化的时候借了一位，目的是表示text[i]在字符为空时 text[i][0],text[0][j]都表示0个公共子串
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
      char s_m = text1[i - 1];
      for (int j = 1; j <= n; ++j) {
        char s_n = text2[j - 1];
        if (s_m == s_n) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};

int main() { return 0; }
