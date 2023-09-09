/*
 @filename   arrary/48.rotate.cpp
 @author     caonan
 @date       2023-09-09 05:02:02
 @reference 顺时针旋转数组
 @url    https://leetcode.cn/problems/rotate-image/solutions/526980/xuan-zhuan-tu-xiang-by-leetcode-solution-vu3m/
 @brief
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
  // 借助了辅助数组，不是最优解
  void rotate(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
      return;
    }
    int h = matrix.size();
    int w = matrix[0].size();
    vector<vector<int>> ans(w, vector<int>(h));

    for (int j = 0; j < w; ++j) {
      for (int i = h - 1; i >= 0; --i) {
        ans[j][h - i - 1] = matrix[i][j];
      }
    }

    matrix.swap(ans);
  }
};

int main() {
  vector<vector<int>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  Solution s;
  s.rotate(input);
  return 0;
}
