/*
 @filename   39.cpp
 @author     caonan
 @date       2022-04-12 06:24:37
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/0ynMMM/
 @brief  给定非负整数数组 heights ，数组中的数字用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
   public:
    //初始化-1是本题的精髓，优化了很多边界条件，单调栈的用法
    int largestRectangleArea(vector<int>& heights)
    {
        if (heights.empty()) return 0;
        vector<int> stack_increase{-1};
        int max = heights[0];
        for (int i = 0; i < heights.size(); i++) {
            while (stack_increase.back() != -1 && heights[i] <= heights[stack_increase.back()]) {
                int height = heights[stack_increase.back()];
                stack_increase.pop_back();
                int width = i - stack_increase.back() - 1;
                max = std::max(max, height * width);
            }
            stack_increase.push_back(i);
        }

        while (stack_increase.back() != -1) {
            int height = heights[stack_increase.back()];
            stack_increase.pop_back();
            int width = heights.size() - stack_increase.back() - 1;
            max = std::max(max, height * width);
        }
        return max;
    }
};

class Solution1 : public Solution
{
   public:
    //分治方法,平均nlogn最差n^2
    int largestRectangleArea(vector<int>& heights)
    {
        if (heights.size() < 1) return 0;
        return getMax(heights, 0, heights.size() - 1);
    }

   private:
    int getMax(const vector<int>& heights, int start, int end)
    {
        if (start == end) return heights[start];
        if (start > end) return 0;
        int height_min = start;
        for (int i = start + 1; i <= end; i++) {
            if (heights[height_min] > heights[i]) {
                height_min = i;
            }
        }

        int cur_max = (end - start + 1) * heights[height_min];
        int max_left = getMax(heights, start, height_min - 1);
        int max_right = getMax(heights, height_min + 1, end);

        cur_max = std::max(cur_max, max_left);
        cur_max = std::max(cur_max, max_right);
        return cur_max;
    }
};

void uinttest(vector<int> arr, int except_val)
{
    Solution1 s;
    int ret = s.largestRectangleArea(arr);
    // assert(except_val == ret);
    printf("except_val:%d,ret:%d\n", except_val, ret);
}
int main()
{
    uinttest(vector<int>{2, 1, 5, 6, 2, 3}, 10);
    uinttest(vector<int>{2, 2}, 4);
    uinttest(vector<int>{0, 2, 0}, 2);
    uinttest(vector<int>{0, 0}, 0);
    uinttest(vector<int>{2, 0, 2}, 2);
    uinttest(vector<int>{2, 1, 2}, 3);
    uinttest(vector<int>{3, 6, 5, 7, 4, 8, 1, 0}, 20);

    return 0;
}
