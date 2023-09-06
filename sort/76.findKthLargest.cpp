/*
 @filename   76.findKthLargest.cpp
 @author     caonan
 @date       2022-05-11 16:20:32
 @reference    剑指offer专项
 @url      https://leetcode.cn/problems/xx4gT2/
 @brief  给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/
#include <assert.h>
#include <stdio.h>

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

#include "../util/util.h"
using namespace std;
//用快排的思路去做
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int start = 0;
    int end = nums.size() - 1;
    int ipos = nums.size() - k;

    while (true) {
      int pos = partition(start, end, nums);
      if (pos == ipos) {
        break;
      }
      if (pos < ipos) {
        start = pos + 1;
      } else {
        end = pos - 1;
      }
    }
    return nums[ipos];
  }

 private:
  int partition(int start, int end, vector<int>& nums) {
    int random = start;
    std::swap(nums[random], nums[end]);
    int p1 = start - 1;
    for (int p2 = start; p2 < end; p2++) {
      if (nums[p2] < nums[end]) {
        p1++;
        std::swap(nums[p1], nums[p2]);
      }
    }
    p1++;
    std::swap(nums[p1], nums[end]);
    return p1;
  }
};

int main() {
  Solution s;
  vector<int> in{3, 2, 1, 5, 6, 4};
  int ret = s.findKthLargest(in, 2);
  cout << "ret is " << ret << endl;
  return 0;
}
