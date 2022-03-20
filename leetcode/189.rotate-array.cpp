/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   189.rotate-array.cpp
 @author     root
 @version
 @date       2019/09/27 01:02
 @brief
 @details    2019/09/27 root create
*/
/*************************************************************************
    > File Name: 189.rotate-array.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 03 Aug 2019 03:15:17 AM UTC
 ************************************************************************/

#include <iostream>
#include <list>
#include <chrono>
#include <algorithm>
#include "common_define.h"
using namespace std;
using namespace chrono;
/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 */

class Solution
{
public:
    // solution 1 buff overflow
    void rotate(vector<int> &nums, int k)
    {
        if (k <= 0)
        {
            return;
        }

        std::list<int> tmplist;

        for (auto &v : nums)
        {
            tmplist.push_back(v);
        }

        if (tmplist.empty())
        {
            return;
        }

        for (int i = 0; i < k; i++)
        {
            int t = tmplist.back();
            tmplist.pop_back();
            tmplist.push_front(t);
        }

        nums.clear();

        for (auto &v : tmplist)
        {
            nums.push_back(v);
        }
    }

    void rotate2(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        std::reverse(nums.begin(), nums.begin() + n - k);
        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        std::reverse(nums.begin() + n - k, nums.begin() + n);
        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        std::reverse(nums.begin(), nums.begin() + n);
    }
};

int main()
{
    Solution s;
    std::vector<int> arr{1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < 10000000; i++)
    {
        arr.push_back(i);
    }

    auto start = system_clock::now();
    s.rotate2(arr, 3);
    auto end   = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout <<  "cost"
         << double(duration.count()) * microseconds::period::num / microseconds::period::den
         << "秒" << endl;
    return 0;
}

