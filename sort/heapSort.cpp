/*
 @filename   heapSort.cpp
 @author     caonan
 @date       2022-04-20 00:55:59
 @reference     leetcode
 @url      https://leetcode-cn.com/problems/sort-an-array/
 @brief  实现一个堆排序
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
void printList(const vector<int>& n) {
  for (auto v : n) {
    cout << v << " ";
  }
  cout << endl;
}

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    //构建初始堆
    for (int i = nums.size() / 2 - 1; i >= 0; i--) {
      createHeap(nums, i);
    }
    for (int i = nums.size() - 1; i > 0; i--) {
      std::swap(nums[0], nums[i]);
      adjust(nums, i);
    }
    return nums;
  }
  void createHeap(vector<int>& nums, int length) {
    for (int i = length; i >= 0;) {
      int left = 2 * i + 1;
      if (left >= nums.size()) {
        return;
      }
      int right = left + 1;
      if (right < nums.size()) {
        int big_index = nums[left] > nums[right] ? left : right;
        if (nums[big_index] > nums[i]) {
          std::swap(nums[big_index], nums[i]);
          i = big_index;
        } else {
          break;
        }
      } else {
        if (nums[left] > nums[i]) {
          std::swap(nums[left], nums[i]);
          i = left;
        } else {
          break;
        }
      }
    }
  }

 private:
  void adjust(vector<int>& nums, int length) {
    for (int i = 0; i <= length / 2 - 1;) {
      int left = 2 * i + 1;
      if (left > length) {
        break;
      }
      int right = left + 1;
      if (right < length) {
        int big_index = nums[left] > nums[right] ? left : right;
        if (nums[i] < nums[big_index]) {
          std::swap(nums[i], nums[big_index]);
          i = big_index;
        } else {
          break;
        }
      } else {
        if (nums[i] < nums[left]) {
          std::swap(nums[i], nums[left]);
          i = left;
        } else {
          break;
        }
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> in{5, 2, 3, 8, 9, 3, 10, 10, 1, 10};
  auto ans = s.sortArray(in);
  printList(ans);
  return 0;
}
