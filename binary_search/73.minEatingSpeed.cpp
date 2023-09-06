/*
 @filename   73.minEatingSpeed.cpp
 @author     caonan
 @date       2022-05-06 16:06:49
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/nZZqjQ
 @brief  狒狒喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。

狒狒可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k
根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉，下一个小时才会开始吃另一堆的香蕉。  

狒狒喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）
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
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int max = 0;
        for (auto n : piles) {
            max = std::max(max, n);
        }
        int l = 1;
        int r = max;
        auto getHours = [&piles](int eat_speed) -> int {
            int hours = 0;
            for (auto n : piles) {
                //向上取整
                hours += n % eat_speed ? n / eat_speed + 1 : n / eat_speed;
            }
            return hours;
        };

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (getHours(mid) <= h) {
                if (mid == 1 || getHours(mid - 1) > h) {
                    return mid;
                }
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return 0;
    }
};
int main() { return 0; }
