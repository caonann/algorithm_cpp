/*
 @filename   75.sortColors.cpp
 @author     caonan
 @date       2022-04-26 15:42:12
 @reference  leetcode
 @url      https://leetcode-cn.com/problems/sort-colors/
 @brief  给定一个包含红色、白色和蓝色、共 n
个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库的sort函数的情况下解决这个问题。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  // 单指针两次遍历
  void sortColors(vector<int> &nums) {
    int head_index = 0;
    for (auto &n : nums) {
      if (n == 0) {
        std::swap(nums[head_index++], n);
      }
    }

    for (auto &n : nums) {
      if (n == 1) {
        std::swap(nums[head_index++], n);
      }
    }
  }
};

class Solution1 : public Solution {
public:
  // 双指针单次遍历
  void sortColors(vector<int> &nums) {
    int p0 = 0, p1 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        swap(nums[i], nums[p1++]);
      } else if (nums[i] == 0) {
        swap(nums[i], nums[p0]);
        if (p0 < p1) {
          swap(nums[i], nums[p1]);
        }
        p0++;
        p1++;
      }
    }
  }
};
int main() { return 0; }
