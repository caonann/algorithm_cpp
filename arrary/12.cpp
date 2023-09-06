/*
 @filename   12.cpp
 @author     caonan
 @date       2022-03-22 03:37:17
 @reference   剑指offer专项
 @url       https://leetcode-cn.com/problems/tvdfij/
 @brief
*/
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int total_sum = 0;
    for (const auto &num : nums) {
      total_sum += num;
    }
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum - nums[i] == total_sum - sum) {
        return i;
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums{1, 7, 3, 6, 5, 6};
  assert(s.pivotIndex(nums) == 3);
  vector<int> nums1{1, 2, 3};
  assert(s.pivotIndex(nums1) == -1);
  vector<int> nums2{2, 1, -1};
  assert(s.pivotIndex(nums2) == 0);
  return 0;
}
