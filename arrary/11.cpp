/*
 @filename   11.cpp
 @author     caonan
 @date       2022-03-21 09:23:44
 @reference    剑指offer专项
 @url      https://leetcode-cn.com/problems/A1NYOS/
 @brief    给定一个二进制数组 nums , 找到含有相同数量的 0 和 1
 的最长连续子数组，并返回该子数组的长度。
*/
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    unordered_map<int, int> hash_map{
        {0, -1}}; // 这个初始化逻辑比较特殊，只有头元素需要特殊考虑 -1，1的情况
    int sum = 0;
    int max_len = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i] == 0 ? -1 : 1;
      if (hash_map.find(sum) != hash_map.end()) {
        max_len = std::max(max_len, i - hash_map[sum]);
      } else {
        hash_map[sum] = i;
      }
    }
    return max_len;
  }
};

int main() {
  Solution s;
  vector<int> nums{0, 1};
  assert(s.findMaxLength(nums) == 2);
  vector<int> nums1{0, 1, 0};
  assert(s.findMaxLength(nums1) == 2);
  return 0;
}
