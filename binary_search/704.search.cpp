/*
 @filename   704.search.cpp
 @author     caonan
 @date       2022-04-27 03:34:38
 @reference   leetcode
 @url      https://leetcode-cn.com/problems/binary-search/
 @brief  给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的
 target，如果目标值存在返回下标，否则返回 -1。
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
class Solution
{
   public:
    int search(vector<int>& nums, int target)
    {
        search(0, nums.size() - 1, target, nums);
        return index;
    }

   private:
    void search(int head, int end, int k, const vector<int>& nums)
    {
        if (head > end) return;
        int mid = head + (end - head) / 2;
        if (nums[mid] == k) {
            index = mid;
            return;
        } else if (nums[mid] < k) {
            search(mid + 1, end, k, nums);
        } else {
            search(head, mid - 1, k, nums);
        }
    }
    int index{-1};
};

//迭代版本
class Solution1 : public Solution
{
   public:
    int search(vector<int>& nums, int target)
    {
        int head = 0;
        int end = nums.size() - 1;
        while (head <= end) {
            int mid = head + (end - head) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                head = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> in{-1, 0, 3, 5, 9, 12};
    Solution1 s;
    int ret = s.search(in, 9);
    cout << "ret: " << ret << endl;
    return 0;
}
