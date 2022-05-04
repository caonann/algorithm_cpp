/*
 @filename   70.singleNonDuplicate.cpp
 @author     caonan
 @date       2022-05-04 08:24:23
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/skFtm2/
 @brief  给定一个只包含整数的有序数组 nums ，每个元素都会出现两次，唯有一个数只会出现一次，请找出这个唯一的数字。
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
    /*
    当 mid 是偶数时，mid&1 == 0
    当 mid 是奇数时，mid&1 == 1
    */
    int singleNonDuplicate(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            mid -= mid & 1;
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};

class Solution1 : public Solution
{
   public:
    /*
    当 mid 是偶数时 mid^=1 == mid+1
    当 mid 是奇数时 mid^=1 == mid-1
    */
    int singleNonDuplicate(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == nums[mid ^ 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};

int main() { return 0; }
