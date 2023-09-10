/*
 @filename   arrary/46.permute.cpp
 @author     caonan
 @date       2023-09-10 03:51:44
 @reference  leetcode
 @url      https://leetcode.cn/problems/permutations/
 @brief
 全排列,这篇解答不错https://leetcode.cn/problems/permutations/solutions/9914/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
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
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    dfs(nums, path, res, used);
    return res;
  }

 private:
  void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, vector<bool>& used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) {
        continue;
      }
      path.push_back(nums[i]);
      used[i] = true;
      dfs(nums, path, res, used);
      path.pop_back();
      used[i] = false;
    }
  }
};

int main() {
  vector<int> input = {1, 2, 3};
  Solution s;
  auto ret = s.permute(input);
  for (auto& v : ret) {
    for (auto& i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
