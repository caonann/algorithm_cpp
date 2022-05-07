/*
 @filename   72.mySqrt.cpp
 @author     caonan
 @date       2022-05-05 15:06:53
 @reference   剑指offer专项
 @url      https://leetcode-cn.com/problems/jJ0w9p
 @brief  给定一个非负整数 x ，计算并返回 x 的平方根，即实现 int sqrt(int x) 函数。

正数的平方根有两个，只输出其中的正数平方根。

如果平方根不是整数，输出只保留整数的部分，小数部分将被舍去。
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
using namespace std;
class Solution
{
   public:
    int mySqrt(int x)
    {
        int l = 1;
        int r = x;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid <= x / mid && mid + 1 > x / (mid + 1)) {
                return mid;
            }
            if (mid < x / mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return 0;
    }
};
int main()
{
    Solution s;
    cout << "ret is " << s.mySqrt(1) << endl;
    return 0;
}
